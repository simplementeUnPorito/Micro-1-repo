/*******************************************************************************
* File Name: POT_SAR_PM.c
* Version 3.10
*
* Description:
*  This file provides Sleep/WakeUp APIs functionality.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "POT_SAR.h"


/***************************************
* Local data allocation
***************************************/

static POT_SAR_BACKUP_STRUCT  POT_SAR_backup =
{
    POT_SAR_DISABLED
};


/*******************************************************************************
* Function Name: POT_SAR_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the current user configuration.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void POT_SAR_SaveConfig(void)
{
    /* All configuration registers are marked as [reset_all_retention] */
}


/*******************************************************************************
* Function Name: POT_SAR_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void POT_SAR_RestoreConfig(void)
{
    /* All congiguration registers are marked as [reset_all_retention] */
}


/*******************************************************************************
* Function Name: POT_SAR_Sleep
********************************************************************************
*
* Summary:
*  This is the preferred routine to prepare the component for sleep.
*  The POT_SAR_Sleep() routine saves the current component state,
*  then it calls the ADC_Stop() function.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  POT_SAR_backup - The structure field 'enableState' is modified
*  depending on the enable state of the block before entering to sleep mode.
*
*******************************************************************************/
void POT_SAR_Sleep(void)
{
    if((POT_SAR_PWRMGR_SAR_REG  & POT_SAR_ACT_PWR_SAR_EN) != 0u)
    {
        if((POT_SAR_SAR_CSR0_REG & POT_SAR_SAR_SOF_START_CONV) != 0u)
        {
            POT_SAR_backup.enableState = POT_SAR_ENABLED | POT_SAR_STARTED;
        }
        else
        {
            POT_SAR_backup.enableState = POT_SAR_ENABLED;
        }
        POT_SAR_Stop();
    }
    else
    {
        POT_SAR_backup.enableState = POT_SAR_DISABLED;
    }
}


/*******************************************************************************
* Function Name: POT_SAR_Wakeup
********************************************************************************
*
* Summary:
*  This is the preferred routine to restore the component to the state when
*  POT_SAR_Sleep() was called. If the component was enabled before the
*  POT_SAR_Sleep() function was called, the
*  POT_SAR_Wakeup() function also re-enables the component.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  POT_SAR_backup - The structure field 'enableState' is used to
*  restore the enable state of block after wakeup from sleep mode.
*
*******************************************************************************/
void POT_SAR_Wakeup(void)
{
    if(POT_SAR_backup.enableState != POT_SAR_DISABLED)
    {
        POT_SAR_Enable();
        #if(POT_SAR_DEFAULT_CONV_MODE != POT_SAR__HARDWARE_TRIGGER)
            if((POT_SAR_backup.enableState & POT_SAR_STARTED) != 0u)
            {
                POT_SAR_StartConvert();
            }
        #endif /* End POT_SAR_DEFAULT_CONV_MODE != POT_SAR__HARDWARE_TRIGGER */
    }
}


/* [] END OF FILE */
