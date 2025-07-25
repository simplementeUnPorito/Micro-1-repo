/*******************************************************************************
* File Name: timer_debouncer_PM.c
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

#include "timer_debouncer.h"

static timer_debouncer_backupStruct timer_debouncer_backup;


/*******************************************************************************
* Function Name: timer_debouncer_SaveConfig
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
*  timer_debouncer_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void timer_debouncer_SaveConfig(void) 
{
    #if (!timer_debouncer_UsingFixedFunction)
        timer_debouncer_backup.TimerUdb = timer_debouncer_ReadCounter();
        timer_debouncer_backup.InterruptMaskValue = timer_debouncer_STATUS_MASK;
        #if (timer_debouncer_UsingHWCaptureCounter)
            timer_debouncer_backup.TimerCaptureCounter = timer_debouncer_ReadCaptureCount();
        #endif /* Back Up capture counter register  */

        #if(!timer_debouncer_UDB_CONTROL_REG_REMOVED)
            timer_debouncer_backup.TimerControlRegister = timer_debouncer_ReadControlRegister();
        #endif /* Backup the enable state of the Timer component */
    #endif /* Backup non retention registers in UDB implementation. All fixed function registers are retention */
}


/*******************************************************************************
* Function Name: timer_debouncer_RestoreConfig
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
*  timer_debouncer_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void timer_debouncer_RestoreConfig(void) 
{   
    #if (!timer_debouncer_UsingFixedFunction)

        timer_debouncer_WriteCounter(timer_debouncer_backup.TimerUdb);
        timer_debouncer_STATUS_MASK =timer_debouncer_backup.InterruptMaskValue;
        #if (timer_debouncer_UsingHWCaptureCounter)
            timer_debouncer_SetCaptureCount(timer_debouncer_backup.TimerCaptureCounter);
        #endif /* Restore Capture counter register*/

        #if(!timer_debouncer_UDB_CONTROL_REG_REMOVED)
            timer_debouncer_WriteControlRegister(timer_debouncer_backup.TimerControlRegister);
        #endif /* Restore the enable state of the Timer component */
    #endif /* Restore non retention registers in the UDB implementation only */
}


/*******************************************************************************
* Function Name: timer_debouncer_Sleep
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
*  timer_debouncer_backup.TimerEnableState:  Is modified depending on the
*  enable state of the block before entering sleep mode.
*
*******************************************************************************/
void timer_debouncer_Sleep(void) 
{
    #if(!timer_debouncer_UDB_CONTROL_REG_REMOVED)
        /* Save Counter's enable state */
        if(timer_debouncer_CTRL_ENABLE == (timer_debouncer_CONTROL & timer_debouncer_CTRL_ENABLE))
        {
            /* Timer is enabled */
            timer_debouncer_backup.TimerEnableState = 1u;
        }
        else
        {
            /* Timer is disabled */
            timer_debouncer_backup.TimerEnableState = 0u;
        }
    #endif /* Back up enable state from the Timer control register */
    timer_debouncer_Stop();
    timer_debouncer_SaveConfig();
}


/*******************************************************************************
* Function Name: timer_debouncer_Wakeup
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
*  timer_debouncer_backup.enableState:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void timer_debouncer_Wakeup(void) 
{
    timer_debouncer_RestoreConfig();
    #if(!timer_debouncer_UDB_CONTROL_REG_REMOVED)
        if(timer_debouncer_backup.TimerEnableState == 1u)
        {     /* Enable Timer's operation */
                timer_debouncer_Enable();
        } /* Do nothing if Timer was disabled before */
    #endif /* Remove this code section if Control register is removed */
}


/* [] END OF FILE */
