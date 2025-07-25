/*******************************************************************************
* File Name: Ayuda.h  
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

#if !defined(CY_PINS_Ayuda_H) /* Pins Ayuda_H */
#define CY_PINS_Ayuda_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Ayuda_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Ayuda__PORT == 15 && ((Ayuda__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Ayuda_Write(uint8 value);
void    Ayuda_SetDriveMode(uint8 mode);
uint8   Ayuda_ReadDataReg(void);
uint8   Ayuda_Read(void);
void    Ayuda_SetInterruptMode(uint16 position, uint16 mode);
uint8   Ayuda_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Ayuda_SetDriveMode() function.
     *  @{
     */
        #define Ayuda_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Ayuda_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Ayuda_DM_RES_UP          PIN_DM_RES_UP
        #define Ayuda_DM_RES_DWN         PIN_DM_RES_DWN
        #define Ayuda_DM_OD_LO           PIN_DM_OD_LO
        #define Ayuda_DM_OD_HI           PIN_DM_OD_HI
        #define Ayuda_DM_STRONG          PIN_DM_STRONG
        #define Ayuda_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Ayuda_MASK               Ayuda__MASK
#define Ayuda_SHIFT              Ayuda__SHIFT
#define Ayuda_WIDTH              1u

/* Interrupt constants */
#if defined(Ayuda__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Ayuda_SetInterruptMode() function.
     *  @{
     */
        #define Ayuda_INTR_NONE      (uint16)(0x0000u)
        #define Ayuda_INTR_RISING    (uint16)(0x0001u)
        #define Ayuda_INTR_FALLING   (uint16)(0x0002u)
        #define Ayuda_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Ayuda_INTR_MASK      (0x01u) 
#endif /* (Ayuda__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Ayuda_PS                     (* (reg8 *) Ayuda__PS)
/* Data Register */
#define Ayuda_DR                     (* (reg8 *) Ayuda__DR)
/* Port Number */
#define Ayuda_PRT_NUM                (* (reg8 *) Ayuda__PRT) 
/* Connect to Analog Globals */                                                  
#define Ayuda_AG                     (* (reg8 *) Ayuda__AG)                       
/* Analog MUX bux enable */
#define Ayuda_AMUX                   (* (reg8 *) Ayuda__AMUX) 
/* Bidirectional Enable */                                                        
#define Ayuda_BIE                    (* (reg8 *) Ayuda__BIE)
/* Bit-mask for Aliased Register Access */
#define Ayuda_BIT_MASK               (* (reg8 *) Ayuda__BIT_MASK)
/* Bypass Enable */
#define Ayuda_BYP                    (* (reg8 *) Ayuda__BYP)
/* Port wide control signals */                                                   
#define Ayuda_CTL                    (* (reg8 *) Ayuda__CTL)
/* Drive Modes */
#define Ayuda_DM0                    (* (reg8 *) Ayuda__DM0) 
#define Ayuda_DM1                    (* (reg8 *) Ayuda__DM1)
#define Ayuda_DM2                    (* (reg8 *) Ayuda__DM2) 
/* Input Buffer Disable Override */
#define Ayuda_INP_DIS                (* (reg8 *) Ayuda__INP_DIS)
/* LCD Common or Segment Drive */
#define Ayuda_LCD_COM_SEG            (* (reg8 *) Ayuda__LCD_COM_SEG)
/* Enable Segment LCD */
#define Ayuda_LCD_EN                 (* (reg8 *) Ayuda__LCD_EN)
/* Slew Rate Control */
#define Ayuda_SLW                    (* (reg8 *) Ayuda__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Ayuda_PRTDSI__CAPS_SEL       (* (reg8 *) Ayuda__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Ayuda_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Ayuda__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Ayuda_PRTDSI__OE_SEL0        (* (reg8 *) Ayuda__PRTDSI__OE_SEL0) 
#define Ayuda_PRTDSI__OE_SEL1        (* (reg8 *) Ayuda__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Ayuda_PRTDSI__OUT_SEL0       (* (reg8 *) Ayuda__PRTDSI__OUT_SEL0) 
#define Ayuda_PRTDSI__OUT_SEL1       (* (reg8 *) Ayuda__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Ayuda_PRTDSI__SYNC_OUT       (* (reg8 *) Ayuda__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Ayuda__SIO_CFG)
    #define Ayuda_SIO_HYST_EN        (* (reg8 *) Ayuda__SIO_HYST_EN)
    #define Ayuda_SIO_REG_HIFREQ     (* (reg8 *) Ayuda__SIO_REG_HIFREQ)
    #define Ayuda_SIO_CFG            (* (reg8 *) Ayuda__SIO_CFG)
    #define Ayuda_SIO_DIFF           (* (reg8 *) Ayuda__SIO_DIFF)
#endif /* (Ayuda__SIO_CFG) */

/* Interrupt Registers */
#if defined(Ayuda__INTSTAT)
    #define Ayuda_INTSTAT            (* (reg8 *) Ayuda__INTSTAT)
    #define Ayuda_SNAP               (* (reg8 *) Ayuda__SNAP)
    
	#define Ayuda_0_INTTYPE_REG 		(* (reg8 *) Ayuda__0__INTTYPE)
#endif /* (Ayuda__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Ayuda_H */


/* [] END OF FILE */
