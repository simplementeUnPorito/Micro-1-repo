/*******************************************************************************
* File Name: enableTimer256ms_PM.c
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

#include "enableTimer256ms.h"

/* Check for removal by optimization */
#if !defined(enableTimer256ms_Sync_ctrl_reg__REMOVED)

static enableTimer256ms_BACKUP_STRUCT  enableTimer256ms_backup = {0u};

    
/*******************************************************************************
* Function Name: enableTimer256ms_SaveConfig
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
void enableTimer256ms_SaveConfig(void) 
{
    enableTimer256ms_backup.controlState = enableTimer256ms_Control;
}


/*******************************************************************************
* Function Name: enableTimer256ms_RestoreConfig
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
void enableTimer256ms_RestoreConfig(void) 
{
     enableTimer256ms_Control = enableTimer256ms_backup.controlState;
}


/*******************************************************************************
* Function Name: enableTimer256ms_Sleep
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
void enableTimer256ms_Sleep(void) 
{
    enableTimer256ms_SaveConfig();
}


/*******************************************************************************
* Function Name: enableTimer256ms_Wakeup
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
void enableTimer256ms_Wakeup(void)  
{
    enableTimer256ms_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
