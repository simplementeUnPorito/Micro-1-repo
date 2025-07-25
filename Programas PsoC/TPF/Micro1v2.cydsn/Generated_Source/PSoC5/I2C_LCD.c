/*******************************************************************************
* File Name: I2C_LCD.c
* Version 3.50
*
* Description:
*  This file provides the source code of APIs for the I2C component.
*  The actual protocol and operation code resides in the interrupt service
*  routine file.
*
*******************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "I2C_LCD_PVT.h"


/**********************************
*      System variables
**********************************/

uint8 I2C_LCD_initVar = 0u; /* Defines if component was initialized */

volatile uint8 I2C_LCD_state;  /* Current state of I2C FSM */


/*******************************************************************************
* Function Name: I2C_LCD_Init
********************************************************************************
*
* Summary:
*  Initializes I2C registers with initial values provided from customizer.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global variables:
*  None.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void I2C_LCD_Init(void) 
{
#if (I2C_LCD_FF_IMPLEMENTED)
    /* Configure fixed function block */
    I2C_LCD_CFG_REG  = I2C_LCD_DEFAULT_CFG;
    I2C_LCD_XCFG_REG = I2C_LCD_DEFAULT_XCFG;
    I2C_LCD_ADDR_REG = I2C_LCD_DEFAULT_ADDR;
    I2C_LCD_CLKDIV1_REG = LO8(I2C_LCD_DEFAULT_DIVIDE_FACTOR);
    I2C_LCD_CLKDIV2_REG = HI8(I2C_LCD_DEFAULT_DIVIDE_FACTOR);

#else
    uint8 intState;

    /* Configure control and interrupt sources */
    I2C_LCD_CFG_REG      = I2C_LCD_DEFAULT_CFG;
    I2C_LCD_INT_MASK_REG = I2C_LCD_DEFAULT_INT_MASK;

    /* Enable interrupt generation in status */
    intState = CyEnterCriticalSection();
    I2C_LCD_INT_ENABLE_REG |= I2C_LCD_INTR_ENABLE;
    CyExitCriticalSection(intState);

    /* Configure bit counter */
    #if (I2C_LCD_MODE_SLAVE_ENABLED)
        I2C_LCD_PERIOD_REG = I2C_LCD_DEFAULT_PERIOD;
    #endif  /* (I2C_LCD_MODE_SLAVE_ENABLED) */

    /* Configure clock generator */
    #if (I2C_LCD_MODE_MASTER_ENABLED)
        I2C_LCD_MCLK_PRD_REG = I2C_LCD_DEFAULT_MCLK_PRD;
        I2C_LCD_MCLK_CMP_REG = I2C_LCD_DEFAULT_MCLK_CMP;
    #endif /* (I2C_LCD_MODE_MASTER_ENABLED) */
#endif /* (I2C_LCD_FF_IMPLEMENTED) */

#if (I2C_LCD_TIMEOUT_ENABLED)
    I2C_LCD_TimeoutInit();
#endif /* (I2C_LCD_TIMEOUT_ENABLED) */

    /* Configure internal interrupt */
    CyIntDisable    (I2C_LCD_ISR_NUMBER);
    CyIntSetPriority(I2C_LCD_ISR_NUMBER, I2C_LCD_ISR_PRIORITY);
    #if (I2C_LCD_INTERN_I2C_INTR_HANDLER)
        (void) CyIntSetVector(I2C_LCD_ISR_NUMBER, &I2C_LCD_ISR);
    #endif /* (I2C_LCD_INTERN_I2C_INTR_HANDLER) */

    /* Set FSM to default state */
    I2C_LCD_state = I2C_LCD_SM_IDLE;

#if (I2C_LCD_MODE_SLAVE_ENABLED)
    /* Clear status and buffers index */
    I2C_LCD_slStatus = 0u;
    I2C_LCD_slRdBufIndex = 0u;
    I2C_LCD_slWrBufIndex = 0u;

    /* Configure matched address */
    I2C_LCD_SlaveSetAddress(I2C_LCD_DEFAULT_ADDR);
#endif /* (I2C_LCD_MODE_SLAVE_ENABLED) */

#if (I2C_LCD_MODE_MASTER_ENABLED)
    /* Clear status and buffers index */
    I2C_LCD_mstrStatus = 0u;
    I2C_LCD_mstrRdBufIndex = 0u;
    I2C_LCD_mstrWrBufIndex = 0u;
#endif /* (I2C_LCD_MODE_MASTER_ENABLED) */
}


/*******************************************************************************
* Function Name: I2C_LCD_Enable
********************************************************************************
*
* Summary:
*  Enables I2C operations.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global variables:
*  None.
*
*******************************************************************************/
void I2C_LCD_Enable(void) 
{
#if (I2C_LCD_FF_IMPLEMENTED)
    uint8 intState;

    /* Enable power to block */
    intState = CyEnterCriticalSection();
    I2C_LCD_ACT_PWRMGR_REG  |= I2C_LCD_ACT_PWR_EN;
    I2C_LCD_STBY_PWRMGR_REG |= I2C_LCD_STBY_PWR_EN;
    CyExitCriticalSection(intState);
#else
    #if (I2C_LCD_MODE_SLAVE_ENABLED)
        /* Enable bit counter */
        uint8 intState = CyEnterCriticalSection();
        I2C_LCD_COUNTER_AUX_CTL_REG |= I2C_LCD_CNT7_ENABLE;
        CyExitCriticalSection(intState);
    #endif /* (I2C_LCD_MODE_SLAVE_ENABLED) */

    /* Enable slave or master bits */
    I2C_LCD_CFG_REG |= I2C_LCD_ENABLE_MS;
#endif /* (I2C_LCD_FF_IMPLEMENTED) */

#if (I2C_LCD_TIMEOUT_ENABLED)
    I2C_LCD_TimeoutEnable();
#endif /* (I2C_LCD_TIMEOUT_ENABLED) */
}


/*******************************************************************************
* Function Name: I2C_LCD_Start
********************************************************************************
*
* Summary:
*  Starts the I2C hardware. Enables Active mode power template bits or clock
*  gating as appropriate. It is required to be executed before I2C bus
*  operation.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Side Effects:
*  This component automatically enables its interrupt.  If I2C is enabled !
*  without the interrupt enabled, it can lock up the I2C bus.
*
* Global variables:
*  I2C_LCD_initVar - This variable is used to check the initial
*                             configuration, modified on the first
*                             function call.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void I2C_LCD_Start(void) 
{
    if (0u == I2C_LCD_initVar)
    {
        I2C_LCD_Init();
        I2C_LCD_initVar = 1u; /* Component initialized */
    }

    I2C_LCD_Enable();
    I2C_LCD_EnableInt();
}


/*******************************************************************************
* Function Name: I2C_LCD_Stop
********************************************************************************
*
* Summary:
*  Disables I2C hardware and disables I2C interrupt. Disables Active mode power
*  template bits or clock gating as appropriate.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void I2C_LCD_Stop(void) 
{
    I2C_LCD_DisableInt();

#if (I2C_LCD_TIMEOUT_ENABLED)
    I2C_LCD_TimeoutStop();
#endif  /* End (I2C_LCD_TIMEOUT_ENABLED) */

#if (I2C_LCD_FF_IMPLEMENTED)
    {
        uint8 intState;
        uint16 blockResetCycles;

        /* Store registers effected by block disable */
        I2C_LCD_backup.addr    = I2C_LCD_ADDR_REG;
        I2C_LCD_backup.clkDiv1 = I2C_LCD_CLKDIV1_REG;
        I2C_LCD_backup.clkDiv2 = I2C_LCD_CLKDIV2_REG;

        /* Calculate number of cycles to reset block */
        blockResetCycles = ((uint16) ((uint16) I2C_LCD_CLKDIV2_REG << 8u) | I2C_LCD_CLKDIV1_REG) + 1u;

        /* Disable block */
        I2C_LCD_CFG_REG &= (uint8) ~I2C_LCD_CFG_EN_SLAVE;
        /* Wait for block reset before disable power */
        CyDelayCycles((uint32) blockResetCycles);

        /* Disable power to block */
        intState = CyEnterCriticalSection();
        I2C_LCD_ACT_PWRMGR_REG  &= (uint8) ~I2C_LCD_ACT_PWR_EN;
        I2C_LCD_STBY_PWRMGR_REG &= (uint8) ~I2C_LCD_STBY_PWR_EN;
        CyExitCriticalSection(intState);

        /* Enable block */
        I2C_LCD_CFG_REG |= (uint8) I2C_LCD_ENABLE_MS;

        /* Restore registers effected by block disable. Ticket ID#198004 */
        I2C_LCD_ADDR_REG    = I2C_LCD_backup.addr;
        I2C_LCD_ADDR_REG    = I2C_LCD_backup.addr;
        I2C_LCD_CLKDIV1_REG = I2C_LCD_backup.clkDiv1;
        I2C_LCD_CLKDIV2_REG = I2C_LCD_backup.clkDiv2;
    }
#else

    /* Disable slave or master bits */
    I2C_LCD_CFG_REG &= (uint8) ~I2C_LCD_ENABLE_MS;

#if (I2C_LCD_MODE_SLAVE_ENABLED)
    {
        /* Disable bit counter */
        uint8 intState = CyEnterCriticalSection();
        I2C_LCD_COUNTER_AUX_CTL_REG &= (uint8) ~I2C_LCD_CNT7_ENABLE;
        CyExitCriticalSection(intState);
    }
#endif /* (I2C_LCD_MODE_SLAVE_ENABLED) */

    /* Clear interrupt source register */
    (void) I2C_LCD_CSR_REG;
#endif /* (I2C_LCD_FF_IMPLEMENTED) */

    /* Disable interrupt on stop (enabled by write transaction) */
    I2C_LCD_DISABLE_INT_ON_STOP;
    I2C_LCD_ClearPendingInt();

    /* Reset FSM to default state */
    I2C_LCD_state = I2C_LCD_SM_IDLE;

    /* Clear busy statuses */
#if (I2C_LCD_MODE_SLAVE_ENABLED)
    I2C_LCD_slStatus &= (uint8) ~(I2C_LCD_SSTAT_RD_BUSY | I2C_LCD_SSTAT_WR_BUSY);
#endif /* (I2C_LCD_MODE_SLAVE_ENABLED) */
}


/* [] END OF FILE */
