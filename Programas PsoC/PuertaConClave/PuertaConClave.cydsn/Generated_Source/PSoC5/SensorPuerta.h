/*******************************************************************************
* File Name: SensorPuerta.h  
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

#if !defined(CY_PINS_SensorPuerta_H) /* Pins SensorPuerta_H */
#define CY_PINS_SensorPuerta_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "SensorPuerta_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 SensorPuerta__PORT == 15 && ((SensorPuerta__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    SensorPuerta_Write(uint8 value);
void    SensorPuerta_SetDriveMode(uint8 mode);
uint8   SensorPuerta_ReadDataReg(void);
uint8   SensorPuerta_Read(void);
void    SensorPuerta_SetInterruptMode(uint16 position, uint16 mode);
uint8   SensorPuerta_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the SensorPuerta_SetDriveMode() function.
     *  @{
     */
        #define SensorPuerta_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define SensorPuerta_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define SensorPuerta_DM_RES_UP          PIN_DM_RES_UP
        #define SensorPuerta_DM_RES_DWN         PIN_DM_RES_DWN
        #define SensorPuerta_DM_OD_LO           PIN_DM_OD_LO
        #define SensorPuerta_DM_OD_HI           PIN_DM_OD_HI
        #define SensorPuerta_DM_STRONG          PIN_DM_STRONG
        #define SensorPuerta_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define SensorPuerta_MASK               SensorPuerta__MASK
#define SensorPuerta_SHIFT              SensorPuerta__SHIFT
#define SensorPuerta_WIDTH              1u

/* Interrupt constants */
#if defined(SensorPuerta__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in SensorPuerta_SetInterruptMode() function.
     *  @{
     */
        #define SensorPuerta_INTR_NONE      (uint16)(0x0000u)
        #define SensorPuerta_INTR_RISING    (uint16)(0x0001u)
        #define SensorPuerta_INTR_FALLING   (uint16)(0x0002u)
        #define SensorPuerta_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define SensorPuerta_INTR_MASK      (0x01u) 
#endif /* (SensorPuerta__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define SensorPuerta_PS                     (* (reg8 *) SensorPuerta__PS)
/* Data Register */
#define SensorPuerta_DR                     (* (reg8 *) SensorPuerta__DR)
/* Port Number */
#define SensorPuerta_PRT_NUM                (* (reg8 *) SensorPuerta__PRT) 
/* Connect to Analog Globals */                                                  
#define SensorPuerta_AG                     (* (reg8 *) SensorPuerta__AG)                       
/* Analog MUX bux enable */
#define SensorPuerta_AMUX                   (* (reg8 *) SensorPuerta__AMUX) 
/* Bidirectional Enable */                                                        
#define SensorPuerta_BIE                    (* (reg8 *) SensorPuerta__BIE)
/* Bit-mask for Aliased Register Access */
#define SensorPuerta_BIT_MASK               (* (reg8 *) SensorPuerta__BIT_MASK)
/* Bypass Enable */
#define SensorPuerta_BYP                    (* (reg8 *) SensorPuerta__BYP)
/* Port wide control signals */                                                   
#define SensorPuerta_CTL                    (* (reg8 *) SensorPuerta__CTL)
/* Drive Modes */
#define SensorPuerta_DM0                    (* (reg8 *) SensorPuerta__DM0) 
#define SensorPuerta_DM1                    (* (reg8 *) SensorPuerta__DM1)
#define SensorPuerta_DM2                    (* (reg8 *) SensorPuerta__DM2) 
/* Input Buffer Disable Override */
#define SensorPuerta_INP_DIS                (* (reg8 *) SensorPuerta__INP_DIS)
/* LCD Common or Segment Drive */
#define SensorPuerta_LCD_COM_SEG            (* (reg8 *) SensorPuerta__LCD_COM_SEG)
/* Enable Segment LCD */
#define SensorPuerta_LCD_EN                 (* (reg8 *) SensorPuerta__LCD_EN)
/* Slew Rate Control */
#define SensorPuerta_SLW                    (* (reg8 *) SensorPuerta__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define SensorPuerta_PRTDSI__CAPS_SEL       (* (reg8 *) SensorPuerta__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define SensorPuerta_PRTDSI__DBL_SYNC_IN    (* (reg8 *) SensorPuerta__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define SensorPuerta_PRTDSI__OE_SEL0        (* (reg8 *) SensorPuerta__PRTDSI__OE_SEL0) 
#define SensorPuerta_PRTDSI__OE_SEL1        (* (reg8 *) SensorPuerta__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define SensorPuerta_PRTDSI__OUT_SEL0       (* (reg8 *) SensorPuerta__PRTDSI__OUT_SEL0) 
#define SensorPuerta_PRTDSI__OUT_SEL1       (* (reg8 *) SensorPuerta__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define SensorPuerta_PRTDSI__SYNC_OUT       (* (reg8 *) SensorPuerta__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(SensorPuerta__SIO_CFG)
    #define SensorPuerta_SIO_HYST_EN        (* (reg8 *) SensorPuerta__SIO_HYST_EN)
    #define SensorPuerta_SIO_REG_HIFREQ     (* (reg8 *) SensorPuerta__SIO_REG_HIFREQ)
    #define SensorPuerta_SIO_CFG            (* (reg8 *) SensorPuerta__SIO_CFG)
    #define SensorPuerta_SIO_DIFF           (* (reg8 *) SensorPuerta__SIO_DIFF)
#endif /* (SensorPuerta__SIO_CFG) */

/* Interrupt Registers */
#if defined(SensorPuerta__INTSTAT)
    #define SensorPuerta_INTSTAT            (* (reg8 *) SensorPuerta__INTSTAT)
    #define SensorPuerta_SNAP               (* (reg8 *) SensorPuerta__SNAP)
    
	#define SensorPuerta_0_INTTYPE_REG 		(* (reg8 *) SensorPuerta__0__INTTYPE)
#endif /* (SensorPuerta__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_SensorPuerta_H */


/* [] END OF FILE */
