/*******************************************************************************
* File Name: int_timer256ms.h
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
#if !defined(CY_ISR_int_timer256ms_H)
#define CY_ISR_int_timer256ms_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void int_timer256ms_Start(void);
void int_timer256ms_StartEx(cyisraddress address);
void int_timer256ms_Stop(void);

CY_ISR_PROTO(int_timer256ms_Interrupt);

void int_timer256ms_SetVector(cyisraddress address);
cyisraddress int_timer256ms_GetVector(void);

void int_timer256ms_SetPriority(uint8 priority);
uint8 int_timer256ms_GetPriority(void);

void int_timer256ms_Enable(void);
uint8 int_timer256ms_GetState(void);
void int_timer256ms_Disable(void);

void int_timer256ms_SetPending(void);
void int_timer256ms_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the int_timer256ms ISR. */
#define int_timer256ms_INTC_VECTOR            ((reg32 *) int_timer256ms__INTC_VECT)

/* Address of the int_timer256ms ISR priority. */
#define int_timer256ms_INTC_PRIOR             ((reg8 *) int_timer256ms__INTC_PRIOR_REG)

/* Priority of the int_timer256ms interrupt. */
#define int_timer256ms_INTC_PRIOR_NUMBER      int_timer256ms__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable int_timer256ms interrupt. */
#define int_timer256ms_INTC_SET_EN            ((reg32 *) int_timer256ms__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the int_timer256ms interrupt. */
#define int_timer256ms_INTC_CLR_EN            ((reg32 *) int_timer256ms__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the int_timer256ms interrupt state to pending. */
#define int_timer256ms_INTC_SET_PD            ((reg32 *) int_timer256ms__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the int_timer256ms interrupt. */
#define int_timer256ms_INTC_CLR_PD            ((reg32 *) int_timer256ms__INTC_CLR_PD_REG)


#endif /* CY_ISR_int_timer256ms_H */


/* [] END OF FILE */
