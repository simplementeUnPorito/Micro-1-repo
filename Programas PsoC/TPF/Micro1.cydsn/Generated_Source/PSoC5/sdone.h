/*******************************************************************************
* File Name: sdone.h
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
#if !defined(CY_ISR_sdone_H)
#define CY_ISR_sdone_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void sdone_Start(void);
void sdone_StartEx(cyisraddress address);
void sdone_Stop(void);

CY_ISR_PROTO(sdone_Interrupt);

void sdone_SetVector(cyisraddress address);
cyisraddress sdone_GetVector(void);

void sdone_SetPriority(uint8 priority);
uint8 sdone_GetPriority(void);

void sdone_Enable(void);
uint8 sdone_GetState(void);
void sdone_Disable(void);

void sdone_SetPending(void);
void sdone_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the sdone ISR. */
#define sdone_INTC_VECTOR            ((reg32 *) sdone__INTC_VECT)

/* Address of the sdone ISR priority. */
#define sdone_INTC_PRIOR             ((reg8 *) sdone__INTC_PRIOR_REG)

/* Priority of the sdone interrupt. */
#define sdone_INTC_PRIOR_NUMBER      sdone__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable sdone interrupt. */
#define sdone_INTC_SET_EN            ((reg32 *) sdone__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the sdone interrupt. */
#define sdone_INTC_CLR_EN            ((reg32 *) sdone__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the sdone interrupt state to pending. */
#define sdone_INTC_SET_PD            ((reg32 *) sdone__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the sdone interrupt. */
#define sdone_INTC_CLR_PD            ((reg32 *) sdone__INTC_CLR_PD_REG)


#endif /* CY_ISR_sdone_H */


/* [] END OF FILE */
