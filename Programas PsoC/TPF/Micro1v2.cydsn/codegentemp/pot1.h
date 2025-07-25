/*******************************************************************************
* File Name: pot1.h  
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

#if !defined(CY_PINS_pot1_H) /* Pins pot1_H */
#define CY_PINS_pot1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "pot1_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 pot1__PORT == 15 && ((pot1__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    pot1_Write(uint8 value);
void    pot1_SetDriveMode(uint8 mode);
uint8   pot1_ReadDataReg(void);
uint8   pot1_Read(void);
void    pot1_SetInterruptMode(uint16 position, uint16 mode);
uint8   pot1_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the pot1_SetDriveMode() function.
     *  @{
     */
        #define pot1_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define pot1_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define pot1_DM_RES_UP          PIN_DM_RES_UP
        #define pot1_DM_RES_DWN         PIN_DM_RES_DWN
        #define pot1_DM_OD_LO           PIN_DM_OD_LO
        #define pot1_DM_OD_HI           PIN_DM_OD_HI
        #define pot1_DM_STRONG          PIN_DM_STRONG
        #define pot1_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define pot1_MASK               pot1__MASK
#define pot1_SHIFT              pot1__SHIFT
#define pot1_WIDTH              1u

/* Interrupt constants */
#if defined(pot1__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in pot1_SetInterruptMode() function.
     *  @{
     */
        #define pot1_INTR_NONE      (uint16)(0x0000u)
        #define pot1_INTR_RISING    (uint16)(0x0001u)
        #define pot1_INTR_FALLING   (uint16)(0x0002u)
        #define pot1_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define pot1_INTR_MASK      (0x01u) 
#endif /* (pot1__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define pot1_PS                     (* (reg8 *) pot1__PS)
/* Data Register */
#define pot1_DR                     (* (reg8 *) pot1__DR)
/* Port Number */
#define pot1_PRT_NUM                (* (reg8 *) pot1__PRT) 
/* Connect to Analog Globals */                                                  
#define pot1_AG                     (* (reg8 *) pot1__AG)                       
/* Analog MUX bux enable */
#define pot1_AMUX                   (* (reg8 *) pot1__AMUX) 
/* Bidirectional Enable */                                                        
#define pot1_BIE                    (* (reg8 *) pot1__BIE)
/* Bit-mask for Aliased Register Access */
#define pot1_BIT_MASK               (* (reg8 *) pot1__BIT_MASK)
/* Bypass Enable */
#define pot1_BYP                    (* (reg8 *) pot1__BYP)
/* Port wide control signals */                                                   
#define pot1_CTL                    (* (reg8 *) pot1__CTL)
/* Drive Modes */
#define pot1_DM0                    (* (reg8 *) pot1__DM0) 
#define pot1_DM1                    (* (reg8 *) pot1__DM1)
#define pot1_DM2                    (* (reg8 *) pot1__DM2) 
/* Input Buffer Disable Override */
#define pot1_INP_DIS                (* (reg8 *) pot1__INP_DIS)
/* LCD Common or Segment Drive */
#define pot1_LCD_COM_SEG            (* (reg8 *) pot1__LCD_COM_SEG)
/* Enable Segment LCD */
#define pot1_LCD_EN                 (* (reg8 *) pot1__LCD_EN)
/* Slew Rate Control */
#define pot1_SLW                    (* (reg8 *) pot1__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define pot1_PRTDSI__CAPS_SEL       (* (reg8 *) pot1__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define pot1_PRTDSI__DBL_SYNC_IN    (* (reg8 *) pot1__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define pot1_PRTDSI__OE_SEL0        (* (reg8 *) pot1__PRTDSI__OE_SEL0) 
#define pot1_PRTDSI__OE_SEL1        (* (reg8 *) pot1__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define pot1_PRTDSI__OUT_SEL0       (* (reg8 *) pot1__PRTDSI__OUT_SEL0) 
#define pot1_PRTDSI__OUT_SEL1       (* (reg8 *) pot1__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define pot1_PRTDSI__SYNC_OUT       (* (reg8 *) pot1__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(pot1__SIO_CFG)
    #define pot1_SIO_HYST_EN        (* (reg8 *) pot1__SIO_HYST_EN)
    #define pot1_SIO_REG_HIFREQ     (* (reg8 *) pot1__SIO_REG_HIFREQ)
    #define pot1_SIO_CFG            (* (reg8 *) pot1__SIO_CFG)
    #define pot1_SIO_DIFF           (* (reg8 *) pot1__SIO_DIFF)
#endif /* (pot1__SIO_CFG) */

/* Interrupt Registers */
#if defined(pot1__INTSTAT)
    #define pot1_INTSTAT            (* (reg8 *) pot1__INTSTAT)
    #define pot1_SNAP               (* (reg8 *) pot1__SNAP)
    
	#define pot1_0_INTTYPE_REG 		(* (reg8 *) pot1__0__INTTYPE)
#endif /* (pot1__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_pot1_H */


/* [] END OF FILE */
