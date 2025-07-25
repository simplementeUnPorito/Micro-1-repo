;
; File Name: cyfitteriar.inc
; 
; PSoC Creator  4.4
;
; Description:
; 
;
;-------------------------------------------------------------------------------
; Copyright (c) 2007-2020 Cypress Semiconductor.  All rights reserved.
; You may use this file only in accordance with the license, terms, conditions, 
; disclaimers, and limitations in the end user license agreement accompanying 
; the software package with which this file was provided.
;-------------------------------------------------------------------------------

#ifndef INCLUDED_CYFITTERIAR_INC
#define INCLUDED_CYFITTERIAR_INC
    INCLUDE cydeviceiar.inc
    INCLUDE cydeviceiar_trm.inc

/* PC */
PC_BUART_sRX_RxBitCounter__16BIT_CONTROL_AUX_CTL_REG EQU CYREG_B1_UDB09_10_ACTL
PC_BUART_sRX_RxBitCounter__16BIT_CONTROL_CONTROL_REG EQU CYREG_B1_UDB09_10_CTL
PC_BUART_sRX_RxBitCounter__16BIT_CONTROL_COUNT_REG EQU CYREG_B1_UDB09_10_CTL
PC_BUART_sRX_RxBitCounter__16BIT_COUNT_CONTROL_REG EQU CYREG_B1_UDB09_10_CTL
PC_BUART_sRX_RxBitCounter__16BIT_COUNT_COUNT_REG EQU CYREG_B1_UDB09_10_CTL
PC_BUART_sRX_RxBitCounter__16BIT_MASK_MASK_REG EQU CYREG_B1_UDB09_10_MSK
PC_BUART_sRX_RxBitCounter__16BIT_MASK_PERIOD_REG EQU CYREG_B1_UDB09_10_MSK
PC_BUART_sRX_RxBitCounter__16BIT_PERIOD_MASK_REG EQU CYREG_B1_UDB09_10_MSK
PC_BUART_sRX_RxBitCounter__16BIT_PERIOD_PERIOD_REG EQU CYREG_B1_UDB09_10_MSK
PC_BUART_sRX_RxBitCounter__CONTROL_AUX_CTL_REG EQU CYREG_B1_UDB09_ACTL
PC_BUART_sRX_RxBitCounter__CONTROL_REG EQU CYREG_B1_UDB09_CTL
PC_BUART_sRX_RxBitCounter__CONTROL_ST_REG EQU CYREG_B1_UDB09_ST_CTL
PC_BUART_sRX_RxBitCounter__COUNT_REG EQU CYREG_B1_UDB09_CTL
PC_BUART_sRX_RxBitCounter__COUNT_ST_REG EQU CYREG_B1_UDB09_ST_CTL
PC_BUART_sRX_RxBitCounter__MASK_CTL_AUX_CTL_REG EQU CYREG_B1_UDB09_MSK_ACTL
PC_BUART_sRX_RxBitCounter__PER_CTL_AUX_CTL_REG EQU CYREG_B1_UDB09_MSK_ACTL
PC_BUART_sRX_RxBitCounter__PERIOD_REG EQU CYREG_B1_UDB09_MSK
PC_BUART_sRX_RxBitCounter_ST__16BIT_STATUS_AUX_CTL_REG EQU CYREG_B1_UDB09_10_ACTL
PC_BUART_sRX_RxBitCounter_ST__16BIT_STATUS_REG EQU CYREG_B1_UDB09_10_ST
PC_BUART_sRX_RxBitCounter_ST__MASK_REG EQU CYREG_B1_UDB09_MSK
PC_BUART_sRX_RxBitCounter_ST__MASK_ST_AUX_CTL_REG EQU CYREG_B1_UDB09_MSK_ACTL
PC_BUART_sRX_RxBitCounter_ST__PER_ST_AUX_CTL_REG EQU CYREG_B1_UDB09_MSK_ACTL
PC_BUART_sRX_RxBitCounter_ST__STATUS_AUX_CTL_REG EQU CYREG_B1_UDB09_ACTL
PC_BUART_sRX_RxBitCounter_ST__STATUS_CNT_REG EQU CYREG_B1_UDB09_ST_CTL
PC_BUART_sRX_RxBitCounter_ST__STATUS_CONTROL_REG EQU CYREG_B1_UDB09_ST_CTL
PC_BUART_sRX_RxBitCounter_ST__STATUS_REG EQU CYREG_B1_UDB09_ST
PC_BUART_sRX_RxShifter_u0__16BIT_A0_REG EQU CYREG_B1_UDB10_11_A0
PC_BUART_sRX_RxShifter_u0__16BIT_A1_REG EQU CYREG_B1_UDB10_11_A1
PC_BUART_sRX_RxShifter_u0__16BIT_D0_REG EQU CYREG_B1_UDB10_11_D0
PC_BUART_sRX_RxShifter_u0__16BIT_D1_REG EQU CYREG_B1_UDB10_11_D1
PC_BUART_sRX_RxShifter_u0__16BIT_DP_AUX_CTL_REG EQU CYREG_B1_UDB10_11_ACTL
PC_BUART_sRX_RxShifter_u0__16BIT_F0_REG EQU CYREG_B1_UDB10_11_F0
PC_BUART_sRX_RxShifter_u0__16BIT_F1_REG EQU CYREG_B1_UDB10_11_F1
PC_BUART_sRX_RxShifter_u0__A0_A1_REG EQU CYREG_B1_UDB10_A0_A1
PC_BUART_sRX_RxShifter_u0__A0_REG EQU CYREG_B1_UDB10_A0
PC_BUART_sRX_RxShifter_u0__A1_REG EQU CYREG_B1_UDB10_A1
PC_BUART_sRX_RxShifter_u0__D0_D1_REG EQU CYREG_B1_UDB10_D0_D1
PC_BUART_sRX_RxShifter_u0__D0_REG EQU CYREG_B1_UDB10_D0
PC_BUART_sRX_RxShifter_u0__D1_REG EQU CYREG_B1_UDB10_D1
PC_BUART_sRX_RxShifter_u0__DP_AUX_CTL_REG EQU CYREG_B1_UDB10_ACTL
PC_BUART_sRX_RxShifter_u0__F0_F1_REG EQU CYREG_B1_UDB10_F0_F1
PC_BUART_sRX_RxShifter_u0__F0_REG EQU CYREG_B1_UDB10_F0
PC_BUART_sRX_RxShifter_u0__F1_REG EQU CYREG_B1_UDB10_F1
PC_BUART_sRX_RxSts__16BIT_STATUS_AUX_CTL_REG EQU CYREG_B1_UDB10_11_ACTL
PC_BUART_sRX_RxSts__16BIT_STATUS_REG EQU CYREG_B1_UDB10_11_ST
PC_BUART_sRX_RxSts__3__MASK EQU 0x08
PC_BUART_sRX_RxSts__3__POS EQU 3
PC_BUART_sRX_RxSts__4__MASK EQU 0x10
PC_BUART_sRX_RxSts__4__POS EQU 4
PC_BUART_sRX_RxSts__5__MASK EQU 0x20
PC_BUART_sRX_RxSts__5__POS EQU 5
PC_BUART_sRX_RxSts__MASK EQU 0x38
PC_BUART_sRX_RxSts__MASK_REG EQU CYREG_B1_UDB10_MSK
PC_BUART_sRX_RxSts__STATUS_AUX_CTL_REG EQU CYREG_B1_UDB10_ACTL
PC_BUART_sRX_RxSts__STATUS_REG EQU CYREG_B1_UDB10_ST
PC_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_A0_REG EQU CYREG_B0_UDB08_09_A0
PC_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_A1_REG EQU CYREG_B0_UDB08_09_A1
PC_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_D0_REG EQU CYREG_B0_UDB08_09_D0
PC_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_D1_REG EQU CYREG_B0_UDB08_09_D1
PC_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_DP_AUX_CTL_REG EQU CYREG_B0_UDB08_09_ACTL
PC_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_F0_REG EQU CYREG_B0_UDB08_09_F0
PC_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_F1_REG EQU CYREG_B0_UDB08_09_F1
PC_BUART_sTX_sCLOCK_TxBitClkGen__A0_A1_REG EQU CYREG_B0_UDB08_A0_A1
PC_BUART_sTX_sCLOCK_TxBitClkGen__A0_REG EQU CYREG_B0_UDB08_A0
PC_BUART_sTX_sCLOCK_TxBitClkGen__A1_REG EQU CYREG_B0_UDB08_A1
PC_BUART_sTX_sCLOCK_TxBitClkGen__D0_D1_REG EQU CYREG_B0_UDB08_D0_D1
PC_BUART_sTX_sCLOCK_TxBitClkGen__D0_REG EQU CYREG_B0_UDB08_D0
PC_BUART_sTX_sCLOCK_TxBitClkGen__D1_REG EQU CYREG_B0_UDB08_D1
PC_BUART_sTX_sCLOCK_TxBitClkGen__DP_AUX_CTL_REG EQU CYREG_B0_UDB08_ACTL
PC_BUART_sTX_sCLOCK_TxBitClkGen__F0_F1_REG EQU CYREG_B0_UDB08_F0_F1
PC_BUART_sTX_sCLOCK_TxBitClkGen__F0_REG EQU CYREG_B0_UDB08_F0
PC_BUART_sTX_sCLOCK_TxBitClkGen__F1_REG EQU CYREG_B0_UDB08_F1
PC_BUART_sTX_TxShifter_u0__16BIT_A0_REG EQU CYREG_B0_UDB09_10_A0
PC_BUART_sTX_TxShifter_u0__16BIT_A1_REG EQU CYREG_B0_UDB09_10_A1
PC_BUART_sTX_TxShifter_u0__16BIT_D0_REG EQU CYREG_B0_UDB09_10_D0
PC_BUART_sTX_TxShifter_u0__16BIT_D1_REG EQU CYREG_B0_UDB09_10_D1
PC_BUART_sTX_TxShifter_u0__16BIT_DP_AUX_CTL_REG EQU CYREG_B0_UDB09_10_ACTL
PC_BUART_sTX_TxShifter_u0__16BIT_F0_REG EQU CYREG_B0_UDB09_10_F0
PC_BUART_sTX_TxShifter_u0__16BIT_F1_REG EQU CYREG_B0_UDB09_10_F1
PC_BUART_sTX_TxShifter_u0__A0_A1_REG EQU CYREG_B0_UDB09_A0_A1
PC_BUART_sTX_TxShifter_u0__A0_REG EQU CYREG_B0_UDB09_A0
PC_BUART_sTX_TxShifter_u0__A1_REG EQU CYREG_B0_UDB09_A1
PC_BUART_sTX_TxShifter_u0__D0_D1_REG EQU CYREG_B0_UDB09_D0_D1
PC_BUART_sTX_TxShifter_u0__D0_REG EQU CYREG_B0_UDB09_D0
PC_BUART_sTX_TxShifter_u0__D1_REG EQU CYREG_B0_UDB09_D1
PC_BUART_sTX_TxShifter_u0__DP_AUX_CTL_REG EQU CYREG_B0_UDB09_ACTL
PC_BUART_sTX_TxShifter_u0__F0_F1_REG EQU CYREG_B0_UDB09_F0_F1
PC_BUART_sTX_TxShifter_u0__F0_REG EQU CYREG_B0_UDB09_F0
PC_BUART_sTX_TxShifter_u0__F1_REG EQU CYREG_B0_UDB09_F1
PC_BUART_sTX_TxSts__0__MASK EQU 0x01
PC_BUART_sTX_TxSts__0__POS EQU 0
PC_BUART_sTX_TxSts__1__MASK EQU 0x02
PC_BUART_sTX_TxSts__1__POS EQU 1
PC_BUART_sTX_TxSts__16BIT_STATUS_AUX_CTL_REG EQU CYREG_B0_UDB09_10_ACTL
PC_BUART_sTX_TxSts__16BIT_STATUS_REG EQU CYREG_B0_UDB09_10_ST
PC_BUART_sTX_TxSts__2__MASK EQU 0x04
PC_BUART_sTX_TxSts__2__POS EQU 2
PC_BUART_sTX_TxSts__3__MASK EQU 0x08
PC_BUART_sTX_TxSts__3__POS EQU 3
PC_BUART_sTX_TxSts__MASK EQU 0x0F
PC_BUART_sTX_TxSts__MASK_REG EQU CYREG_B0_UDB09_MSK
PC_BUART_sTX_TxSts__STATUS_AUX_CTL_REG EQU CYREG_B0_UDB09_ACTL
PC_BUART_sTX_TxSts__STATUS_REG EQU CYREG_B0_UDB09_ST
PC_IntClock__CFG0 EQU CYREG_CLKDIST_DCFG1_CFG0
PC_IntClock__CFG1 EQU CYREG_CLKDIST_DCFG1_CFG1
PC_IntClock__CFG2 EQU CYREG_CLKDIST_DCFG1_CFG2
PC_IntClock__CFG2_SRC_SEL_MASK EQU 0x07
PC_IntClock__INDEX EQU 0x01
PC_IntClock__PM_ACT_CFG EQU CYREG_PM_ACT_CFG2
PC_IntClock__PM_ACT_MSK EQU 0x02
PC_IntClock__PM_STBY_CFG EQU CYREG_PM_STBY_CFG2
PC_IntClock__PM_STBY_MSK EQU 0x02

/* Led */
Led__0__INTTYPE EQU CYREG_PICU0_INTTYPE0
Led__0__MASK EQU 0x01
Led__0__PC EQU CYREG_PRT0_PC0
Led__0__PORT EQU 0
Led__0__SHIFT EQU 0
Led__1__INTTYPE EQU CYREG_PICU0_INTTYPE1
Led__1__MASK EQU 0x02
Led__1__PC EQU CYREG_PRT0_PC1
Led__1__PORT EQU 0
Led__1__SHIFT EQU 1
Led__2__INTTYPE EQU CYREG_PICU0_INTTYPE2
Led__2__MASK EQU 0x04
Led__2__PC EQU CYREG_PRT0_PC2
Led__2__PORT EQU 0
Led__2__SHIFT EQU 2
Led__AG EQU CYREG_PRT0_AG
Led__AMUX EQU CYREG_PRT0_AMUX
Led__BIE EQU CYREG_PRT0_BIE
Led__BIT_MASK EQU CYREG_PRT0_BIT_MASK
Led__BYP EQU CYREG_PRT0_BYP
Led__CTL EQU CYREG_PRT0_CTL
Led__DM0 EQU CYREG_PRT0_DM0
Led__DM1 EQU CYREG_PRT0_DM1
Led__DM2 EQU CYREG_PRT0_DM2
Led__DR EQU CYREG_PRT0_DR
Led__INP_DIS EQU CYREG_PRT0_INP_DIS
Led__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU0_BASE
Led__LCD_COM_SEG EQU CYREG_PRT0_LCD_COM_SEG
Led__LCD_EN EQU CYREG_PRT0_LCD_EN
Led__MASK EQU 0x07
Led__PORT EQU 0
Led__PRT EQU CYREG_PRT0_PRT
Led__PRTDSI__CAPS_SEL EQU CYREG_PRT0_CAPS_SEL
Led__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT0_DBL_SYNC_IN
Led__PRTDSI__OE_SEL0 EQU CYREG_PRT0_OE_SEL0
Led__PRTDSI__OE_SEL1 EQU CYREG_PRT0_OE_SEL1
Led__PRTDSI__OUT_SEL0 EQU CYREG_PRT0_OUT_SEL0
Led__PRTDSI__OUT_SEL1 EQU CYREG_PRT0_OUT_SEL1
Led__PRTDSI__SYNC_OUT EQU CYREG_PRT0_SYNC_OUT
Led__PS EQU CYREG_PRT0_PS
Led__SHIFT EQU 0
Led__SLW EQU CYREG_PRT0_SLW

/* Rx_1 */
Rx_1__0__INTTYPE EQU CYREG_PICU12_INTTYPE6
Rx_1__0__MASK EQU 0x40
Rx_1__0__PC EQU CYREG_PRT12_PC6
Rx_1__0__PORT EQU 12
Rx_1__0__SHIFT EQU 6
Rx_1__AG EQU CYREG_PRT12_AG
Rx_1__BIE EQU CYREG_PRT12_BIE
Rx_1__BIT_MASK EQU CYREG_PRT12_BIT_MASK
Rx_1__BYP EQU CYREG_PRT12_BYP
Rx_1__DM0 EQU CYREG_PRT12_DM0
Rx_1__DM1 EQU CYREG_PRT12_DM1
Rx_1__DM2 EQU CYREG_PRT12_DM2
Rx_1__DR EQU CYREG_PRT12_DR
Rx_1__INP_DIS EQU CYREG_PRT12_INP_DIS
Rx_1__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU12_BASE
Rx_1__MASK EQU 0x40
Rx_1__PORT EQU 12
Rx_1__PRT EQU CYREG_PRT12_PRT
Rx_1__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT12_DBL_SYNC_IN
Rx_1__PRTDSI__OE_SEL0 EQU CYREG_PRT12_OE_SEL0
Rx_1__PRTDSI__OE_SEL1 EQU CYREG_PRT12_OE_SEL1
Rx_1__PRTDSI__OUT_SEL0 EQU CYREG_PRT12_OUT_SEL0
Rx_1__PRTDSI__OUT_SEL1 EQU CYREG_PRT12_OUT_SEL1
Rx_1__PRTDSI__SYNC_OUT EQU CYREG_PRT12_SYNC_OUT
Rx_1__PS EQU CYREG_PRT12_PS
Rx_1__SHIFT EQU 6
Rx_1__SIO_CFG EQU CYREG_PRT12_SIO_CFG
Rx_1__SIO_DIFF EQU CYREG_PRT12_SIO_DIFF
Rx_1__SIO_HYST_EN EQU CYREG_PRT12_SIO_HYST_EN
Rx_1__SIO_REG_HIFREQ EQU CYREG_PRT12_SIO_REG_HIFREQ
Rx_1__SLW EQU CYREG_PRT12_SLW

/* Tx_1 */
Tx_1__0__INTTYPE EQU CYREG_PICU12_INTTYPE7
Tx_1__0__MASK EQU 0x80
Tx_1__0__PC EQU CYREG_PRT12_PC7
Tx_1__0__PORT EQU 12
Tx_1__0__SHIFT EQU 7
Tx_1__AG EQU CYREG_PRT12_AG
Tx_1__BIE EQU CYREG_PRT12_BIE
Tx_1__BIT_MASK EQU CYREG_PRT12_BIT_MASK
Tx_1__BYP EQU CYREG_PRT12_BYP
Tx_1__DM0 EQU CYREG_PRT12_DM0
Tx_1__DM1 EQU CYREG_PRT12_DM1
Tx_1__DM2 EQU CYREG_PRT12_DM2
Tx_1__DR EQU CYREG_PRT12_DR
Tx_1__INP_DIS EQU CYREG_PRT12_INP_DIS
Tx_1__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU12_BASE
Tx_1__MASK EQU 0x80
Tx_1__PORT EQU 12
Tx_1__PRT EQU CYREG_PRT12_PRT
Tx_1__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT12_DBL_SYNC_IN
Tx_1__PRTDSI__OE_SEL0 EQU CYREG_PRT12_OE_SEL0
Tx_1__PRTDSI__OE_SEL1 EQU CYREG_PRT12_OE_SEL1
Tx_1__PRTDSI__OUT_SEL0 EQU CYREG_PRT12_OUT_SEL0
Tx_1__PRTDSI__OUT_SEL1 EQU CYREG_PRT12_OUT_SEL1
Tx_1__PRTDSI__SYNC_OUT EQU CYREG_PRT12_SYNC_OUT
Tx_1__PS EQU CYREG_PRT12_PS
Tx_1__SHIFT EQU 7
Tx_1__SIO_CFG EQU CYREG_PRT12_SIO_CFG
Tx_1__SIO_DIFF EQU CYREG_PRT12_SIO_DIFF
Tx_1__SIO_HYST_EN EQU CYREG_PRT12_SIO_HYST_EN
Tx_1__SIO_REG_HIFREQ EQU CYREG_PRT12_SIO_REG_HIFREQ
Tx_1__SLW EQU CYREG_PRT12_SLW

/* Clock_1 */
Clock_1__CFG0 EQU CYREG_CLKDIST_DCFG0_CFG0
Clock_1__CFG1 EQU CYREG_CLKDIST_DCFG0_CFG1
Clock_1__CFG2 EQU CYREG_CLKDIST_DCFG0_CFG2
Clock_1__CFG2_SRC_SEL_MASK EQU 0x07
Clock_1__INDEX EQU 0x00
Clock_1__PM_ACT_CFG EQU CYREG_PM_ACT_CFG2
Clock_1__PM_ACT_MSK EQU 0x01
Clock_1__PM_STBY_CFG EQU CYREG_PM_STBY_CFG2
Clock_1__PM_STBY_MSK EQU 0x01

/* keyboard_in */
keyboard_in__0__INTTYPE EQU CYREG_PICU1_INTTYPE4
keyboard_in__0__MASK EQU 0x10
keyboard_in__0__PC EQU CYREG_PRT1_PC4
keyboard_in__0__PORT EQU 1
keyboard_in__0__SHIFT EQU 4
keyboard_in__1__INTTYPE EQU CYREG_PICU1_INTTYPE5
keyboard_in__1__MASK EQU 0x20
keyboard_in__1__PC EQU CYREG_PRT1_PC5
keyboard_in__1__PORT EQU 1
keyboard_in__1__SHIFT EQU 5
keyboard_in__2__INTTYPE EQU CYREG_PICU1_INTTYPE6
keyboard_in__2__MASK EQU 0x40
keyboard_in__2__PC EQU CYREG_PRT1_PC6
keyboard_in__2__PORT EQU 1
keyboard_in__2__SHIFT EQU 6
keyboard_in__3__INTTYPE EQU CYREG_PICU1_INTTYPE7
keyboard_in__3__MASK EQU 0x80
keyboard_in__3__PC EQU CYREG_PRT1_PC7
keyboard_in__3__PORT EQU 1
keyboard_in__3__SHIFT EQU 7
keyboard_in__AG EQU CYREG_PRT1_AG
keyboard_in__AMUX EQU CYREG_PRT1_AMUX
keyboard_in__BIE EQU CYREG_PRT1_BIE
keyboard_in__BIT_MASK EQU CYREG_PRT1_BIT_MASK
keyboard_in__BYP EQU CYREG_PRT1_BYP
keyboard_in__CTL EQU CYREG_PRT1_CTL
keyboard_in__DM0 EQU CYREG_PRT1_DM0
keyboard_in__DM1 EQU CYREG_PRT1_DM1
keyboard_in__DM2 EQU CYREG_PRT1_DM2
keyboard_in__DR EQU CYREG_PRT1_DR
keyboard_in__INP_DIS EQU CYREG_PRT1_INP_DIS
keyboard_in__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU1_BASE
keyboard_in__LCD_COM_SEG EQU CYREG_PRT1_LCD_COM_SEG
keyboard_in__LCD_EN EQU CYREG_PRT1_LCD_EN
keyboard_in__MASK EQU 0xF0
keyboard_in__PORT EQU 1
keyboard_in__PRT EQU CYREG_PRT1_PRT
keyboard_in__PRTDSI__CAPS_SEL EQU CYREG_PRT1_CAPS_SEL
keyboard_in__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT1_DBL_SYNC_IN
keyboard_in__PRTDSI__OE_SEL0 EQU CYREG_PRT1_OE_SEL0
keyboard_in__PRTDSI__OE_SEL1 EQU CYREG_PRT1_OE_SEL1
keyboard_in__PRTDSI__OUT_SEL0 EQU CYREG_PRT1_OUT_SEL0
keyboard_in__PRTDSI__OUT_SEL1 EQU CYREG_PRT1_OUT_SEL1
keyboard_in__PRTDSI__SYNC_OUT EQU CYREG_PRT1_SYNC_OUT
keyboard_in__PS EQU CYREG_PRT1_PS
keyboard_in__SHIFT EQU 4
keyboard_in__SLW EQU CYREG_PRT1_SLW

/* timer_clock */
timer_clock__CFG0 EQU CYREG_CLKDIST_DCFG2_CFG0
timer_clock__CFG1 EQU CYREG_CLKDIST_DCFG2_CFG1
timer_clock__CFG2 EQU CYREG_CLKDIST_DCFG2_CFG2
timer_clock__CFG2_SRC_SEL_MASK EQU 0x07
timer_clock__INDEX EQU 0x02
timer_clock__PM_ACT_CFG EQU CYREG_PM_ACT_CFG2
timer_clock__PM_ACT_MSK EQU 0x04
timer_clock__PM_STBY_CFG EQU CYREG_PM_STBY_CFG2
timer_clock__PM_STBY_MSK EQU 0x04

/* SensorPuerta */
SensorPuerta__0__INTTYPE EQU CYREG_PICU2_INTTYPE5
SensorPuerta__0__MASK EQU 0x20
SensorPuerta__0__PC EQU CYREG_PRT2_PC5
SensorPuerta__0__PORT EQU 2
SensorPuerta__0__SHIFT EQU 5
SensorPuerta__AG EQU CYREG_PRT2_AG
SensorPuerta__AMUX EQU CYREG_PRT2_AMUX
SensorPuerta__BIE EQU CYREG_PRT2_BIE
SensorPuerta__BIT_MASK EQU CYREG_PRT2_BIT_MASK
SensorPuerta__BYP EQU CYREG_PRT2_BYP
SensorPuerta__CTL EQU CYREG_PRT2_CTL
SensorPuerta__DM0 EQU CYREG_PRT2_DM0
SensorPuerta__DM1 EQU CYREG_PRT2_DM1
SensorPuerta__DM2 EQU CYREG_PRT2_DM2
SensorPuerta__DR EQU CYREG_PRT2_DR
SensorPuerta__INP_DIS EQU CYREG_PRT2_INP_DIS
SensorPuerta__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU2_BASE
SensorPuerta__LCD_COM_SEG EQU CYREG_PRT2_LCD_COM_SEG
SensorPuerta__LCD_EN EQU CYREG_PRT2_LCD_EN
SensorPuerta__MASK EQU 0x20
SensorPuerta__PORT EQU 2
SensorPuerta__PRT EQU CYREG_PRT2_PRT
SensorPuerta__PRTDSI__CAPS_SEL EQU CYREG_PRT2_CAPS_SEL
SensorPuerta__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT2_DBL_SYNC_IN
SensorPuerta__PRTDSI__OE_SEL0 EQU CYREG_PRT2_OE_SEL0
SensorPuerta__PRTDSI__OE_SEL1 EQU CYREG_PRT2_OE_SEL1
SensorPuerta__PRTDSI__OUT_SEL0 EQU CYREG_PRT2_OUT_SEL0
SensorPuerta__PRTDSI__OUT_SEL1 EQU CYREG_PRT2_OUT_SEL1
SensorPuerta__PRTDSI__SYNC_OUT EQU CYREG_PRT2_SYNC_OUT
SensorPuerta__PS EQU CYREG_PRT2_PS
SensorPuerta__SHIFT EQU 5
SensorPuerta__SLW EQU CYREG_PRT2_SLW

/* int_sensorON */
int_sensorON__INTC_CLR_EN_REG EQU CYREG_NVIC_CLRENA0
int_sensorON__INTC_CLR_PD_REG EQU CYREG_NVIC_CLRPEND0
int_sensorON__INTC_MASK EQU 0x08
int_sensorON__INTC_NUMBER EQU 3
int_sensorON__INTC_PRIOR_NUM EQU 7
int_sensorON__INTC_PRIOR_REG EQU CYREG_NVIC_PRI_3
int_sensorON__INTC_SET_EN_REG EQU CYREG_NVIC_SETENA0
int_sensorON__INTC_SET_PD_REG EQU CYREG_NVIC_SETPEND0

/* keyboard_out */
keyboard_out__0__INTTYPE EQU CYREG_PICU2_INTTYPE0
keyboard_out__0__MASK EQU 0x01
keyboard_out__0__PC EQU CYREG_PRT2_PC0
keyboard_out__0__PORT EQU 2
keyboard_out__0__SHIFT EQU 0
keyboard_out__1__INTTYPE EQU CYREG_PICU2_INTTYPE1
keyboard_out__1__MASK EQU 0x02
keyboard_out__1__PC EQU CYREG_PRT2_PC1
keyboard_out__1__PORT EQU 2
keyboard_out__1__SHIFT EQU 1
keyboard_out__2__INTTYPE EQU CYREG_PICU2_INTTYPE2
keyboard_out__2__MASK EQU 0x04
keyboard_out__2__PC EQU CYREG_PRT2_PC2
keyboard_out__2__PORT EQU 2
keyboard_out__2__SHIFT EQU 2
keyboard_out__3__INTTYPE EQU CYREG_PICU2_INTTYPE3
keyboard_out__3__MASK EQU 0x08
keyboard_out__3__PC EQU CYREG_PRT2_PC3
keyboard_out__3__PORT EQU 2
keyboard_out__3__SHIFT EQU 3
keyboard_out__4__INTTYPE EQU CYREG_PICU2_INTTYPE4
keyboard_out__4__MASK EQU 0x10
keyboard_out__4__PC EQU CYREG_PRT2_PC4
keyboard_out__4__PORT EQU 2
keyboard_out__4__SHIFT EQU 4
keyboard_out__AG EQU CYREG_PRT2_AG
keyboard_out__AMUX EQU CYREG_PRT2_AMUX
keyboard_out__BIE EQU CYREG_PRT2_BIE
keyboard_out__BIT_MASK EQU CYREG_PRT2_BIT_MASK
keyboard_out__BYP EQU CYREG_PRT2_BYP
keyboard_out__CTL EQU CYREG_PRT2_CTL
keyboard_out__DM0 EQU CYREG_PRT2_DM0
keyboard_out__DM1 EQU CYREG_PRT2_DM1
keyboard_out__DM2 EQU CYREG_PRT2_DM2
keyboard_out__DR EQU CYREG_PRT2_DR
keyboard_out__INP_DIS EQU CYREG_PRT2_INP_DIS
keyboard_out__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU2_BASE
keyboard_out__LCD_COM_SEG EQU CYREG_PRT2_LCD_COM_SEG
keyboard_out__LCD_EN EQU CYREG_PRT2_LCD_EN
keyboard_out__MASK EQU 0x1F
keyboard_out__PORT EQU 2
keyboard_out__PRT EQU CYREG_PRT2_PRT
keyboard_out__PRTDSI__CAPS_SEL EQU CYREG_PRT2_CAPS_SEL
keyboard_out__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT2_DBL_SYNC_IN
keyboard_out__PRTDSI__OE_SEL0 EQU CYREG_PRT2_OE_SEL0
keyboard_out__PRTDSI__OE_SEL1 EQU CYREG_PRT2_OE_SEL1
keyboard_out__PRTDSI__OUT_SEL0 EQU CYREG_PRT2_OUT_SEL0
keyboard_out__PRTDSI__OUT_SEL1 EQU CYREG_PRT2_OUT_SEL1
keyboard_out__PRTDSI__SYNC_OUT EQU CYREG_PRT2_SYNC_OUT
keyboard_out__PS EQU CYREG_PRT2_PS
keyboard_out__SHIFT EQU 0
keyboard_out__SLW EQU CYREG_PRT2_SLW

/* int_debouncer */
int_debouncer__INTC_CLR_EN_REG EQU CYREG_NVIC_CLRENA0
int_debouncer__INTC_CLR_PD_REG EQU CYREG_NVIC_CLRPEND0
int_debouncer__INTC_MASK EQU 0x01
int_debouncer__INTC_NUMBER EQU 0
int_debouncer__INTC_PRIOR_NUM EQU 7
int_debouncer__INTC_PRIOR_REG EQU CYREG_NVIC_PRI_0
int_debouncer__INTC_SET_EN_REG EQU CYREG_NVIC_SETENA0
int_debouncer__INTC_SET_PD_REG EQU CYREG_NVIC_SETPEND0

/* int_sensorOFF */
int_sensorOFF__INTC_CLR_EN_REG EQU CYREG_NVIC_CLRENA0
int_sensorOFF__INTC_CLR_PD_REG EQU CYREG_NVIC_CLRPEND0
int_sensorOFF__INTC_MASK EQU 0x04
int_sensorOFF__INTC_NUMBER EQU 2
int_sensorOFF__INTC_PRIOR_NUM EQU 7
int_sensorOFF__INTC_PRIOR_REG EQU CYREG_NVIC_PRI_2
int_sensorOFF__INTC_SET_EN_REG EQU CYREG_NVIC_SETENA0
int_sensorOFF__INTC_SET_PD_REG EQU CYREG_NVIC_SETPEND0

/* timer_debouncer */
timer_debouncer_TimerHW__CAP0 EQU CYREG_TMR0_CAP0
timer_debouncer_TimerHW__CAP1 EQU CYREG_TMR0_CAP1
timer_debouncer_TimerHW__CFG0 EQU CYREG_TMR0_CFG0
timer_debouncer_TimerHW__CFG1 EQU CYREG_TMR0_CFG1
timer_debouncer_TimerHW__CFG2 EQU CYREG_TMR0_CFG2
timer_debouncer_TimerHW__CNT_CMP0 EQU CYREG_TMR0_CNT_CMP0
timer_debouncer_TimerHW__CNT_CMP1 EQU CYREG_TMR0_CNT_CMP1
timer_debouncer_TimerHW__PER0 EQU CYREG_TMR0_PER0
timer_debouncer_TimerHW__PER1 EQU CYREG_TMR0_PER1
timer_debouncer_TimerHW__PM_ACT_CFG EQU CYREG_PM_ACT_CFG3
timer_debouncer_TimerHW__PM_ACT_MSK EQU 0x01
timer_debouncer_TimerHW__PM_STBY_CFG EQU CYREG_PM_STBY_CFG3
timer_debouncer_TimerHW__PM_STBY_MSK EQU 0x01
timer_debouncer_TimerHW__RT0 EQU CYREG_TMR0_RT0
timer_debouncer_TimerHW__RT1 EQU CYREG_TMR0_RT1
timer_debouncer_TimerHW__SR0 EQU CYREG_TMR0_SR0

/* int_puertaAbierta */
int_puertaAbierta__INTC_CLR_EN_REG EQU CYREG_NVIC_CLRENA0
int_puertaAbierta__INTC_CLR_PD_REG EQU CYREG_NVIC_CLRPEND0
int_puertaAbierta__INTC_MASK EQU 0x02
int_puertaAbierta__INTC_NUMBER EQU 1
int_puertaAbierta__INTC_PRIOR_NUM EQU 7
int_puertaAbierta__INTC_PRIOR_REG EQU CYREG_NVIC_PRI_1
int_puertaAbierta__INTC_SET_EN_REG EQU CYREG_NVIC_SETENA0
int_puertaAbierta__INTC_SET_PD_REG EQU CYREG_NVIC_SETPEND0

/* timer_puertaAbierta */
timer_puertaAbierta_TimerHW__CAP0 EQU CYREG_TMR1_CAP0
timer_puertaAbierta_TimerHW__CAP1 EQU CYREG_TMR1_CAP1
timer_puertaAbierta_TimerHW__CFG0 EQU CYREG_TMR1_CFG0
timer_puertaAbierta_TimerHW__CFG1 EQU CYREG_TMR1_CFG1
timer_puertaAbierta_TimerHW__CFG2 EQU CYREG_TMR1_CFG2
timer_puertaAbierta_TimerHW__CNT_CMP0 EQU CYREG_TMR1_CNT_CMP0
timer_puertaAbierta_TimerHW__CNT_CMP1 EQU CYREG_TMR1_CNT_CMP1
timer_puertaAbierta_TimerHW__PER0 EQU CYREG_TMR1_PER0
timer_puertaAbierta_TimerHW__PER1 EQU CYREG_TMR1_PER1
timer_puertaAbierta_TimerHW__PM_ACT_CFG EQU CYREG_PM_ACT_CFG3
timer_puertaAbierta_TimerHW__PM_ACT_MSK EQU 0x02
timer_puertaAbierta_TimerHW__PM_STBY_CFG EQU CYREG_PM_STBY_CFG3
timer_puertaAbierta_TimerHW__PM_STBY_MSK EQU 0x02
timer_puertaAbierta_TimerHW__RT0 EQU CYREG_TMR1_RT0
timer_puertaAbierta_TimerHW__RT1 EQU CYREG_TMR1_RT1
timer_puertaAbierta_TimerHW__SR0 EQU CYREG_TMR1_SR0

/* Miscellaneous */
BCLK__BUS_CLK__HZ EQU 24000000
BCLK__BUS_CLK__KHZ EQU 24000
BCLK__BUS_CLK__MHZ EQU 24
CYDEV_CHIP_DIE_LEOPARD EQU 1
CYDEV_CHIP_DIE_PSOC4A EQU 26
CYDEV_CHIP_DIE_PSOC5LP EQU 2
CYDEV_CHIP_DIE_PSOC5TM EQU 3
CYDEV_CHIP_DIE_TMA4 EQU 4
CYDEV_CHIP_DIE_UNKNOWN EQU 0
CYDEV_CHIP_FAMILY_FM0P EQU 5
CYDEV_CHIP_FAMILY_FM3 EQU 6
CYDEV_CHIP_FAMILY_FM4 EQU 7
CYDEV_CHIP_FAMILY_PSOC3 EQU 1
CYDEV_CHIP_FAMILY_PSOC4 EQU 2
CYDEV_CHIP_FAMILY_PSOC5 EQU 3
CYDEV_CHIP_FAMILY_PSOC6 EQU 4
CYDEV_CHIP_FAMILY_UNKNOWN EQU 0
CYDEV_CHIP_FAMILY_USED EQU CYDEV_CHIP_FAMILY_PSOC5
CYDEV_CHIP_JTAG_ID EQU 0x2E161069
CYDEV_CHIP_MEMBER_3A EQU 1
CYDEV_CHIP_MEMBER_4A EQU 26
CYDEV_CHIP_MEMBER_4AA EQU 25
CYDEV_CHIP_MEMBER_4AB EQU 30
CYDEV_CHIP_MEMBER_4AC EQU 14
CYDEV_CHIP_MEMBER_4AD EQU 15
CYDEV_CHIP_MEMBER_4AE EQU 16
CYDEV_CHIP_MEMBER_4D EQU 20
CYDEV_CHIP_MEMBER_4E EQU 6
CYDEV_CHIP_MEMBER_4F EQU 27
CYDEV_CHIP_MEMBER_4G EQU 4
CYDEV_CHIP_MEMBER_4H EQU 24
CYDEV_CHIP_MEMBER_4I EQU 32
CYDEV_CHIP_MEMBER_4J EQU 21
CYDEV_CHIP_MEMBER_4K EQU 22
CYDEV_CHIP_MEMBER_4L EQU 31
CYDEV_CHIP_MEMBER_4M EQU 29
CYDEV_CHIP_MEMBER_4N EQU 11
CYDEV_CHIP_MEMBER_4O EQU 8
CYDEV_CHIP_MEMBER_4P EQU 28
CYDEV_CHIP_MEMBER_4Q EQU 17
CYDEV_CHIP_MEMBER_4R EQU 9
CYDEV_CHIP_MEMBER_4S EQU 12
CYDEV_CHIP_MEMBER_4T EQU 10
CYDEV_CHIP_MEMBER_4U EQU 5
CYDEV_CHIP_MEMBER_4V EQU 23
CYDEV_CHIP_MEMBER_4W EQU 13
CYDEV_CHIP_MEMBER_4X EQU 7
CYDEV_CHIP_MEMBER_4Y EQU 18
CYDEV_CHIP_MEMBER_4Z EQU 19
CYDEV_CHIP_MEMBER_5A EQU 3
CYDEV_CHIP_MEMBER_5B EQU 2
CYDEV_CHIP_MEMBER_6A EQU 33
CYDEV_CHIP_MEMBER_FM3 EQU 37
CYDEV_CHIP_MEMBER_FM4 EQU 38
CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE1 EQU 34
CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE2 EQU 35
CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE3 EQU 36
CYDEV_CHIP_MEMBER_UNKNOWN EQU 0
CYDEV_CHIP_MEMBER_USED EQU CYDEV_CHIP_MEMBER_5B
CYDEV_CHIP_DIE_EXPECT EQU CYDEV_CHIP_MEMBER_USED
CYDEV_CHIP_DIE_ACTUAL EQU CYDEV_CHIP_DIE_EXPECT
CYDEV_CHIP_REV_LEOPARD_ES1 EQU 0
CYDEV_CHIP_REV_LEOPARD_ES2 EQU 1
CYDEV_CHIP_REV_LEOPARD_ES3 EQU 3
CYDEV_CHIP_REV_LEOPARD_PRODUCTION EQU 3
CYDEV_CHIP_REV_PSOC4A_ES0 EQU 17
CYDEV_CHIP_REV_PSOC4A_PRODUCTION EQU 17
CYDEV_CHIP_REV_PSOC5LP_ES0 EQU 0
CYDEV_CHIP_REV_PSOC5LP_PRODUCTION EQU 0
CYDEV_CHIP_REV_PSOC5TM_ES0 EQU 0
CYDEV_CHIP_REV_PSOC5TM_ES1 EQU 1
CYDEV_CHIP_REV_PSOC5TM_PRODUCTION EQU 1
CYDEV_CHIP_REV_TMA4_ES EQU 17
CYDEV_CHIP_REV_TMA4_ES2 EQU 33
CYDEV_CHIP_REV_TMA4_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_3A_ES1 EQU 0
CYDEV_CHIP_REVISION_3A_ES2 EQU 1
CYDEV_CHIP_REVISION_3A_ES3 EQU 3
CYDEV_CHIP_REVISION_3A_PRODUCTION EQU 3
CYDEV_CHIP_REVISION_4A_ES0 EQU 17
CYDEV_CHIP_REVISION_4A_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_4AA_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4AB_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4AC_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4AD_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4AE_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4D_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4E_CCG2_NO_USBPD EQU 0
CYDEV_CHIP_REVISION_4E_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4F_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA EQU 0
CYDEV_CHIP_REVISION_4F_PRODUCTION_256K EQU 0
CYDEV_CHIP_REVISION_4G_ES EQU 17
CYDEV_CHIP_REVISION_4G_ES2 EQU 33
CYDEV_CHIP_REVISION_4G_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_4H_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4I_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4J_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4K_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4L_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4M_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4N_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4O_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4P_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4Q_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4R_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4S_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4T_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4U_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4V_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4W_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4X_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4Y_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4Z_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_5A_ES0 EQU 0
CYDEV_CHIP_REVISION_5A_ES1 EQU 1
CYDEV_CHIP_REVISION_5A_PRODUCTION EQU 1
CYDEV_CHIP_REVISION_5B_ES0 EQU 0
CYDEV_CHIP_REVISION_5B_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_6A_ES EQU 17
CYDEV_CHIP_REVISION_6A_NO_UDB EQU 33
CYDEV_CHIP_REVISION_6A_PRODUCTION EQU 33
CYDEV_CHIP_REVISION_FM3_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_FM4_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_PDL_FM0P_TYPE1_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_PDL_FM0P_TYPE2_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_PDL_FM0P_TYPE3_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_USED EQU CYDEV_CHIP_REVISION_5B_PRODUCTION
CYDEV_CHIP_REV_EXPECT EQU CYDEV_CHIP_REVISION_USED
CYDEV_CONFIG_FASTBOOT_ENABLED EQU 1
CYDEV_CONFIG_UNUSED_IO_AllowButWarn EQU 0
CYDEV_CONFIG_UNUSED_IO EQU CYDEV_CONFIG_UNUSED_IO_AllowButWarn
CYDEV_CONFIG_UNUSED_IO_AllowWithInfo EQU 1
CYDEV_CONFIG_UNUSED_IO_Disallowed EQU 2
CYDEV_CONFIGURATION_COMPRESSED EQU 1
CYDEV_CONFIGURATION_DMA EQU 0
CYDEV_CONFIGURATION_ECC EQU 1
CYDEV_CONFIGURATION_IMOENABLED EQU CYDEV_CONFIG_FASTBOOT_ENABLED
CYDEV_CONFIGURATION_MODE_COMPRESSED EQU 0
CYDEV_CONFIGURATION_MODE EQU CYDEV_CONFIGURATION_MODE_COMPRESSED
CYDEV_CONFIGURATION_MODE_DMA EQU 2
CYDEV_CONFIGURATION_MODE_UNCOMPRESSED EQU 1
CYDEV_DEBUG_ENABLE_MASK EQU 0x20
CYDEV_DEBUG_ENABLE_REGISTER EQU CYREG_MLOGIC_DEBUG
CYDEV_DEBUGGING_DPS_Disable EQU 3
CYDEV_DEBUGGING_DPS_JTAG_4 EQU 1
CYDEV_DEBUGGING_DPS_JTAG_5 EQU 0
CYDEV_DEBUGGING_DPS_SWD EQU 2
CYDEV_DEBUGGING_DPS_SWD_SWV EQU 6
CYDEV_DEBUGGING_DPS EQU CYDEV_DEBUGGING_DPS_SWD_SWV
CYDEV_DEBUGGING_ENABLE EQU 1
CYDEV_DEBUGGING_XRES EQU 0
CYDEV_DMA_CHANNELS_AVAILABLE EQU 24
CYDEV_ECC_ENABLE EQU 0
CYDEV_HEAP_SIZE EQU 0x80
CYDEV_INSTRUCT_CACHE_ENABLED EQU 1
CYDEV_INTR_RISING EQU 0x0000000E
CYDEV_IS_EXPORTING_CODE EQU 0
CYDEV_IS_IMPORTING_CODE EQU 0
CYDEV_PROJ_TYPE EQU 0
CYDEV_PROJ_TYPE_BOOTLOADER EQU 1
CYDEV_PROJ_TYPE_LAUNCHER EQU 5
CYDEV_PROJ_TYPE_LOADABLE EQU 2
CYDEV_PROJ_TYPE_LOADABLEANDBOOTLOADER EQU 4
CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER EQU 3
CYDEV_PROJ_TYPE_STANDARD EQU 0
CYDEV_PROTECTION_ENABLE EQU 0
CYDEV_STACK_SIZE EQU 0x0800
CYDEV_USE_BUNDLED_CMSIS EQU 1
CYDEV_VARIABLE_VDDA EQU 0
CYDEV_VDDA_MV EQU 5000
CYDEV_VDDD_MV EQU 5000
CYDEV_VDDIO0_MV EQU 5000
CYDEV_VDDIO1_MV EQU 5000
CYDEV_VDDIO2_MV EQU 5000
CYDEV_VDDIO3_MV EQU 5000
CYDEV_VIO0_MV EQU 5000
CYDEV_VIO1_MV EQU 5000
CYDEV_VIO2_MV EQU 5000
CYDEV_VIO3_MV EQU 5000
CYIPBLOCK_ARM_CM3_VERSION EQU 0
CYIPBLOCK_P3_ANAIF_VERSION EQU 0
CYIPBLOCK_P3_CAN_VERSION EQU 0
CYIPBLOCK_P3_CAPSENSE_VERSION EQU 0
CYIPBLOCK_P3_COMP_VERSION EQU 0
CYIPBLOCK_P3_DECIMATOR_VERSION EQU 0
CYIPBLOCK_P3_DFB_VERSION EQU 0
CYIPBLOCK_P3_DMA_VERSION EQU 0
CYIPBLOCK_P3_DRQ_VERSION EQU 0
CYIPBLOCK_P3_DSM_VERSION EQU 0
CYIPBLOCK_P3_EMIF_VERSION EQU 0
CYIPBLOCK_P3_I2C_VERSION EQU 0
CYIPBLOCK_P3_LCD_VERSION EQU 0
CYIPBLOCK_P3_LPF_VERSION EQU 0
CYIPBLOCK_P3_OPAMP_VERSION EQU 0
CYIPBLOCK_P3_PM_VERSION EQU 0
CYIPBLOCK_P3_SCCT_VERSION EQU 0
CYIPBLOCK_P3_TIMER_VERSION EQU 0
CYIPBLOCK_P3_USB_VERSION EQU 0
CYIPBLOCK_P3_VIDAC_VERSION EQU 0
CYIPBLOCK_P3_VREF_VERSION EQU 0
CYIPBLOCK_S8_GPIO_VERSION EQU 0
CYIPBLOCK_S8_IRQ_VERSION EQU 0
CYIPBLOCK_S8_SAR_VERSION EQU 0
CYIPBLOCK_S8_SIO_VERSION EQU 0
CYIPBLOCK_S8_UDB_VERSION EQU 0
DMA_CHANNELS_USED__MASK0 EQU 0x00000000
CYDEV_BOOTLOADER_ENABLE EQU 0

#endif /* INCLUDED_CYFITTERIAR_INC */
