/*******************************************************************************
* File Name: keyboard_out.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_keyboard_out_H) /* Pins keyboard_out_H */
#define CY_PINS_keyboard_out_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "keyboard_out_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 keyboard_out__PORT == 15 && ((keyboard_out__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    keyboard_out_Write(uint8 value);
void    keyboard_out_SetDriveMode(uint8 mode);
uint8   keyboard_out_ReadDataReg(void);
uint8   keyboard_out_Read(void);
void    keyboard_out_SetInterruptMode(uint16 position, uint16 mode);
uint8   keyboard_out_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the keyboard_out_SetDriveMode() function.
     *  @{
     */
        #define keyboard_out_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define keyboard_out_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define keyboard_out_DM_RES_UP          PIN_DM_RES_UP
        #define keyboard_out_DM_RES_DWN         PIN_DM_RES_DWN
        #define keyboard_out_DM_OD_LO           PIN_DM_OD_LO
        #define keyboard_out_DM_OD_HI           PIN_DM_OD_HI
        #define keyboard_out_DM_STRONG          PIN_DM_STRONG
        #define keyboard_out_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define keyboard_out_MASK               keyboard_out__MASK
#define keyboard_out_SHIFT              keyboard_out__SHIFT
#define keyboard_out_WIDTH              5u

/* Interrupt constants */
#if defined(keyboard_out__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in keyboard_out_SetInterruptMode() function.
     *  @{
     */
        #define keyboard_out_INTR_NONE      (uint16)(0x0000u)
        #define keyboard_out_INTR_RISING    (uint16)(0x0001u)
        #define keyboard_out_INTR_FALLING   (uint16)(0x0002u)
        #define keyboard_out_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define keyboard_out_INTR_MASK      (0x01u) 
#endif /* (keyboard_out__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define keyboard_out_PS                     (* (reg8 *) keyboard_out__PS)
/* Data Register */
#define keyboard_out_DR                     (* (reg8 *) keyboard_out__DR)
/* Port Number */
#define keyboard_out_PRT_NUM                (* (reg8 *) keyboard_out__PRT) 
/* Connect to Analog Globals */                                                  
#define keyboard_out_AG                     (* (reg8 *) keyboard_out__AG)                       
/* Analog MUX bux enable */
#define keyboard_out_AMUX                   (* (reg8 *) keyboard_out__AMUX) 
/* Bidirectional Enable */                                                        
#define keyboard_out_BIE                    (* (reg8 *) keyboard_out__BIE)
/* Bit-mask for Aliased Register Access */
#define keyboard_out_BIT_MASK               (* (reg8 *) keyboard_out__BIT_MASK)
/* Bypass Enable */
#define keyboard_out_BYP                    (* (reg8 *) keyboard_out__BYP)
/* Port wide control signals */                                                   
#define keyboard_out_CTL                    (* (reg8 *) keyboard_out__CTL)
/* Drive Modes */
#define keyboard_out_DM0                    (* (reg8 *) keyboard_out__DM0) 
#define keyboard_out_DM1                    (* (reg8 *) keyboard_out__DM1)
#define keyboard_out_DM2                    (* (reg8 *) keyboard_out__DM2) 
/* Input Buffer Disable Override */
#define keyboard_out_INP_DIS                (* (reg8 *) keyboard_out__INP_DIS)
/* LCD Common or Segment Drive */
#define keyboard_out_LCD_COM_SEG            (* (reg8 *) keyboard_out__LCD_COM_SEG)
/* Enable Segment LCD */
#define keyboard_out_LCD_EN                 (* (reg8 *) keyboard_out__LCD_EN)
/* Slew Rate Control */
#define keyboard_out_SLW                    (* (reg8 *) keyboard_out__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define keyboard_out_PRTDSI__CAPS_SEL       (* (reg8 *) keyboard_out__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define keyboard_out_PRTDSI__DBL_SYNC_IN    (* (reg8 *) keyboard_out__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define keyboard_out_PRTDSI__OE_SEL0        (* (reg8 *) keyboard_out__PRTDSI__OE_SEL0) 
#define keyboard_out_PRTDSI__OE_SEL1        (* (reg8 *) keyboard_out__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define keyboard_out_PRTDSI__OUT_SEL0       (* (reg8 *) keyboard_out__PRTDSI__OUT_SEL0) 
#define keyboard_out_PRTDSI__OUT_SEL1       (* (reg8 *) keyboard_out__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define keyboard_out_PRTDSI__SYNC_OUT       (* (reg8 *) keyboard_out__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(keyboard_out__SIO_CFG)
    #define keyboard_out_SIO_HYST_EN        (* (reg8 *) keyboard_out__SIO_HYST_EN)
    #define keyboard_out_SIO_REG_HIFREQ     (* (reg8 *) keyboard_out__SIO_REG_HIFREQ)
    #define keyboard_out_SIO_CFG            (* (reg8 *) keyboard_out__SIO_CFG)
    #define keyboard_out_SIO_DIFF           (* (reg8 *) keyboard_out__SIO_DIFF)
#endif /* (keyboard_out__SIO_CFG) */

/* Interrupt Registers */
#if defined(keyboard_out__INTSTAT)
    #define keyboard_out_INTSTAT            (* (reg8 *) keyboard_out__INTSTAT)
    #define keyboard_out_SNAP               (* (reg8 *) keyboard_out__SNAP)
    
	#define keyboard_out_0_INTTYPE_REG 		(* (reg8 *) keyboard_out__0__INTTYPE)
	#define keyboard_out_1_INTTYPE_REG 		(* (reg8 *) keyboard_out__1__INTTYPE)
	#define keyboard_out_2_INTTYPE_REG 		(* (reg8 *) keyboard_out__2__INTTYPE)
	#define keyboard_out_3_INTTYPE_REG 		(* (reg8 *) keyboard_out__3__INTTYPE)
	#define keyboard_out_4_INTTYPE_REG 		(* (reg8 *) keyboard_out__4__INTTYPE)
#endif /* (keyboard_out__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_keyboard_out_H */


/* [] END OF FILE */
