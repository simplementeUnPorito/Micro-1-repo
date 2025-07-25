/*******************************************************************************
* File Name: keyboard_out.h  
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

#if !defined(CY_PINS_keyboard_out_ALIASES_H) /* Pins keyboard_out_ALIASES_H */
#define CY_PINS_keyboard_out_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define keyboard_out_0			(keyboard_out__0__PC)
#define keyboard_out_0_INTR	((uint16)((uint16)0x0001u << keyboard_out__0__SHIFT))

#define keyboard_out_1			(keyboard_out__1__PC)
#define keyboard_out_1_INTR	((uint16)((uint16)0x0001u << keyboard_out__1__SHIFT))

#define keyboard_out_2			(keyboard_out__2__PC)
#define keyboard_out_2_INTR	((uint16)((uint16)0x0001u << keyboard_out__2__SHIFT))

#define keyboard_out_3			(keyboard_out__3__PC)
#define keyboard_out_3_INTR	((uint16)((uint16)0x0001u << keyboard_out__3__SHIFT))

#define keyboard_out_4			(keyboard_out__4__PC)
#define keyboard_out_4_INTR	((uint16)((uint16)0x0001u << keyboard_out__4__SHIFT))

#define keyboard_out_INTR_ALL	 ((uint16)(keyboard_out_0_INTR| keyboard_out_1_INTR| keyboard_out_2_INTR| keyboard_out_3_INTR| keyboard_out_4_INTR))

#endif /* End Pins keyboard_out_ALIASES_H */


/* [] END OF FILE */
