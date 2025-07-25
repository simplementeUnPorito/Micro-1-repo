/*******************************************************************************
* File Name: Servo.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Servo_ALIASES_H) /* Pins Servo_ALIASES_H */
#define CY_PINS_Servo_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define Servo_0			(Servo__0__PC)
#define Servo_0_INTR	((uint16)((uint16)0x0001u << Servo__0__SHIFT))

#define Servo_1			(Servo__1__PC)
#define Servo_1_INTR	((uint16)((uint16)0x0001u << Servo__1__SHIFT))

#define Servo_2			(Servo__2__PC)
#define Servo_2_INTR	((uint16)((uint16)0x0001u << Servo__2__SHIFT))

#define Servo_3			(Servo__3__PC)
#define Servo_3_INTR	((uint16)((uint16)0x0001u << Servo__3__SHIFT))

#define Servo_INTR_ALL	 ((uint16)(Servo_0_INTR| Servo_1_INTR| Servo_2_INTR| Servo_3_INTR))

#endif /* End Pins Servo_ALIASES_H */


/* [] END OF FILE */
