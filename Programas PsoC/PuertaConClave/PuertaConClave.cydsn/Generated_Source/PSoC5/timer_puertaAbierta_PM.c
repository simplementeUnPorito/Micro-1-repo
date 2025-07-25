/*******************************************************************************
* File Name: timer_puertaAbierta_PM.c
* Version 2.80
*
*  Description:
*     This file provides the power management source code to API for the
*     Timer.
*
*   Note:
*     None
*
*******************************************************************************
* Copyright 2008-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#include "timer_puertaAbierta.h"

static timer_puertaAbierta_backupStruct timer_puertaAbierta_backup;


/*******************************************************************************
* Function Name: timer_puertaAbierta_SaveConfig
********************************************************************************
*
* Summary:
*     Save the current user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  timer_puertaAbierta_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void timer_puertaAbierta_SaveConfig(void) 
{
    #if (!timer_puertaAbierta_UsingFixedFunction)
        timer_puertaAbierta_backup.TimerUdb = timer_puertaAbierta_ReadCounter();
        timer_puertaAbierta_backup.InterruptMaskValue = timer_puertaAbierta_STATUS_MASK;
        #if (timer_puertaAbierta_UsingHWCaptureCounter)
            timer_puertaAbierta_backup.TimerCaptureCounter = timer_puertaAbierta_ReadCaptureCount();
        #endif /* Back Up capture counter register  */

        #if(!timer_puertaAbierta_UDB_CONTROL_REG_REMOVED)
            timer_puertaAbierta_backup.TimerControlRegister = timer_puertaAbierta_ReadControlRegister();
        #endif /* Backup the enable state of the Timer component */
    #endif /* Backup non retention registers in UDB implementation. All fixed function registers are retention */
}


/*******************************************************************************
* Function Name: timer_puertaAbierta_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  timer_puertaAbierta_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void timer_puertaAbierta_RestoreConfig(void) 
{   
    #if (!timer_puertaAbierta_UsingFixedFunction)

        timer_puertaAbierta_WriteCounter(timer_puertaAbierta_backup.TimerUdb);
        timer_puertaAbierta_STATUS_MASK =timer_puertaAbierta_backup.InterruptMaskValue;
        #if (timer_puertaAbierta_UsingHWCaptureCounter)
            timer_puertaAbierta_SetCaptureCount(timer_puertaAbierta_backup.TimerCaptureCounter);
        #endif /* Restore Capture counter register*/

        #if(!timer_puertaAbierta_UDB_CONTROL_REG_REMOVED)
            timer_puertaAbierta_WriteControlRegister(timer_puertaAbierta_backup.TimerControlRegister);
        #endif /* Restore the enable state of the Timer component */
    #endif /* Restore non retention registers in the UDB implementation only */
}


/*******************************************************************************
* Function Name: timer_puertaAbierta_Sleep
********************************************************************************
*
* Summary:
*     Stop and Save the user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  timer_puertaAbierta_backup.TimerEnableState:  Is modified depending on the
*  enable state of the block before entering sleep mode.
*
*******************************************************************************/
void timer_puertaAbierta_Sleep(void) 
{
    #if(!timer_puertaAbierta_UDB_CONTROL_REG_REMOVED)
        /* Save Counter's enable state */
        if(timer_puertaAbierta_CTRL_ENABLE == (timer_puertaAbierta_CONTROL & timer_puertaAbierta_CTRL_ENABLE))
        {
            /* Timer is enabled */
            timer_puertaAbierta_backup.TimerEnableState = 1u;
        }
        else
        {
            /* Timer is disabled */
            timer_puertaAbierta_backup.TimerEnableState = 0u;
        }
    #endif /* Back up enable state from the Timer control register */
    timer_puertaAbierta_Stop();
    timer_puertaAbierta_SaveConfig();
}


/*******************************************************************************
* Function Name: timer_puertaAbierta_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  timer_puertaAbierta_backup.enableState:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void timer_puertaAbierta_Wakeup(void) 
{
    timer_puertaAbierta_RestoreConfig();
    #if(!timer_puertaAbierta_UDB_CONTROL_REG_REMOVED)
        if(timer_puertaAbierta_backup.TimerEnableState == 1u)
        {     /* Enable Timer's operation */
                timer_puertaAbierta_Enable();
        } /* Do nothing if Timer was disabled before */
    #endif /* Remove this code section if Control register is removed */
}


/* [] END OF FILE */
