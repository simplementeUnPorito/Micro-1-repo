/*******************************************************************************
* File Name: enableTimer_PM.c
* Version 1.80
*
* Description:
*  This file contains the setup, control, and status commands to support 
*  the component operation in the low power mode. 
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "enableTimer.h"

/* Check for removal by optimization */
#if !defined(enableTimer_Sync_ctrl_reg__REMOVED)

static enableTimer_BACKUP_STRUCT  enableTimer_backup = {0u};

    
/*******************************************************************************
* Function Name: enableTimer_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void enableTimer_SaveConfig(void) 
{
    enableTimer_backup.controlState = enableTimer_Control;
}


/*******************************************************************************
* Function Name: enableTimer_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*
*******************************************************************************/
void enableTimer_RestoreConfig(void) 
{
     enableTimer_Control = enableTimer_backup.controlState;
}


/*******************************************************************************
* Function Name: enableTimer_Sleep
********************************************************************************
*
* Summary:
*  Prepares the component for entering the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void enableTimer_Sleep(void) 
{
    enableTimer_SaveConfig();
}


/*******************************************************************************
* Function Name: enableTimer_Wakeup
********************************************************************************
*
* Summary:
*  Restores the component after waking up from the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void enableTimer_Wakeup(void)  
{
    enableTimer_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
