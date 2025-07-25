/*******************************************************************************
* File Name: Led.h  
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

#if !defined(CY_PINS_Led_ALIASES_H) /* Pins Led_ALIASES_H */
#define CY_PINS_Led_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define Led_0			(Led__0__PC)
#define Led_0_INTR	((uint16)((uint16)0x0001u << Led__0__SHIFT))

#define Led_1			(Led__1__PC)
#define Led_1_INTR	((uint16)((uint16)0x0001u << Led__1__SHIFT))

#define Led_2			(Led__2__PC)
#define Led_2_INTR	((uint16)((uint16)0x0001u << Led__2__SHIFT))

#define Led_INTR_ALL	 ((uint16)(Led_0_INTR| Led_1_INTR| Led_2_INTR))

#endif /* End Pins Led_ALIASES_H */


/* [] END OF FILE */
