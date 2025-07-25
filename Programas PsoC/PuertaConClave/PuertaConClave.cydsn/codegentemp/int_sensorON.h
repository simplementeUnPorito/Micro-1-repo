/*******************************************************************************
* File Name: int_sensorON.h
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
#if !defined(CY_ISR_int_sensorON_H)
#define CY_ISR_int_sensorON_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void int_sensorON_Start(void);
void int_sensorON_StartEx(cyisraddress address);
void int_sensorON_Stop(void);

CY_ISR_PROTO(int_sensorON_Interrupt);

void int_sensorON_SetVector(cyisraddress address);
cyisraddress int_sensorON_GetVector(void);

void int_sensorON_SetPriority(uint8 priority);
uint8 int_sensorON_GetPriority(void);

void int_sensorON_Enable(void);
uint8 int_sensorON_GetState(void);
void int_sensorON_Disable(void);

void int_sensorON_SetPending(void);
void int_sensorON_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the int_sensorON ISR. */
#define int_sensorON_INTC_VECTOR            ((reg32 *) int_sensorON__INTC_VECT)

/* Address of the int_sensorON ISR priority. */
#define int_sensorON_INTC_PRIOR             ((reg8 *) int_sensorON__INTC_PRIOR_REG)

/* Priority of the int_sensorON interrupt. */
#define int_sensorON_INTC_PRIOR_NUMBER      int_sensorON__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable int_sensorON interrupt. */
#define int_sensorON_INTC_SET_EN            ((reg32 *) int_sensorON__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the int_sensorON interrupt. */
#define int_sensorON_INTC_CLR_EN            ((reg32 *) int_sensorON__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the int_sensorON interrupt state to pending. */
#define int_sensorON_INTC_SET_PD            ((reg32 *) int_sensorON__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the int_sensorON interrupt. */
#define int_sensorON_INTC_CLR_PD            ((reg32 *) int_sensorON__INTC_CLR_PD_REG)


#endif /* CY_ISR_int_sensorON_H */


/* [] END OF FILE */
