/*******************************************************************************
* File Name: POT_sdone.h
* Version 1.70
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_ISR_POT_sdone_H)
#define CY_ISR_POT_sdone_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void POT_sdone_Start(void);
void POT_sdone_StartEx(cyisraddress address);
void POT_sdone_Stop(void);

CY_ISR_PROTO(POT_sdone_Interrupt);

void POT_sdone_SetVector(cyisraddress address);
cyisraddress POT_sdone_GetVector(void);

void POT_sdone_SetPriority(uint8 priority);
uint8 POT_sdone_GetPriority(void);

void POT_sdone_Enable(void);
uint8 POT_sdone_GetState(void);
void POT_sdone_Disable(void);

void POT_sdone_SetPending(void);
void POT_sdone_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the POT_sdone ISR. */
#define POT_sdone_INTC_VECTOR            ((reg32 *) POT_sdone__INTC_VECT)

/* Address of the POT_sdone ISR priority. */
#define POT_sdone_INTC_PRIOR             ((reg8 *) POT_sdone__INTC_PRIOR_REG)

/* Priority of the POT_sdone interrupt. */
#define POT_sdone_INTC_PRIOR_NUMBER      POT_sdone__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable POT_sdone interrupt. */
#define POT_sdone_INTC_SET_EN            ((reg32 *) POT_sdone__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the POT_sdone interrupt. */
#define POT_sdone_INTC_CLR_EN            ((reg32 *) POT_sdone__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the POT_sdone interrupt state to pending. */
#define POT_sdone_INTC_SET_PD            ((reg32 *) POT_sdone__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the POT_sdone interrupt. */
#define POT_sdone_INTC_CLR_PD            ((reg32 *) POT_sdone__INTC_CLR_PD_REG)


#endif /* CY_ISR_POT_sdone_H */


/* [] END OF FILE */
