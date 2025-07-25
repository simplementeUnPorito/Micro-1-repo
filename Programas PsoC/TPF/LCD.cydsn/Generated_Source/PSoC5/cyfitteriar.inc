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
PC_BUART_sRX_RxBitCounter__16BIT_CONTROL_AUX_CTL_REG EQU CYREG_B1_UDB10_11_ACTL
PC_BUART_sRX_RxBitCounter__16BIT_CONTROL_CONTROL_REG EQU CYREG_B1_UDB10_11_CTL
PC_BUART_sRX_RxBitCounter__16BIT_CONTROL_COUNT_REG EQU CYREG_B1_UDB10_11_CTL
PC_BUART_sRX_RxBitCounter__16BIT_COUNT_CONTROL_REG EQU CYREG_B1_UDB10_11_CTL
PC_BUART_sRX_RxBitCounter__16BIT_COUNT_COUNT_REG EQU CYREG_B1_UDB10_11_CTL
PC_BUART_sRX_RxBitCounter__16BIT_MASK_MASK_REG EQU CYREG_B1_UDB10_11_MSK
PC_BUART_sRX_RxBitCounter__16BIT_MASK_PERIOD_REG EQU CYREG_B1_UDB10_11_MSK
PC_BUART_sRX_RxBitCounter__16BIT_PERIOD_MASK_REG EQU CYREG_B1_UDB10_11_MSK
PC_BUART_sRX_RxBitCounter__16BIT_PERIOD_PERIOD_REG EQU CYREG_B1_UDB10_11_MSK
PC_BUART_sRX_RxBitCounter__CONTROL_AUX_CTL_REG EQU CYREG_B1_UDB10_ACTL
PC_BUART_sRX_RxBitCounter__CONTROL_REG EQU CYREG_B1_UDB10_CTL
PC_BUART_sRX_RxBitCounter__CONTROL_ST_REG EQU CYREG_B1_UDB10_ST_CTL
PC_BUART_sRX_RxBitCounter__COUNT_REG EQU CYREG_B1_UDB10_CTL
PC_BUART_sRX_RxBitCounter__COUNT_ST_REG EQU CYREG_B1_UDB10_ST_CTL
PC_BUART_sRX_RxBitCounter__MASK_CTL_AUX_CTL_REG EQU CYREG_B1_UDB10_MSK_ACTL
PC_BUART_sRX_RxBitCounter__PER_CTL_AUX_CTL_REG EQU CYREG_B1_UDB10_MSK_ACTL
PC_BUART_sRX_RxBitCounter__PERIOD_REG EQU CYREG_B1_UDB10_MSK
PC_BUART_sRX_RxBitCounter_ST__16BIT_STATUS_AUX_CTL_REG EQU CYREG_B1_UDB10_11_ACTL
PC_BUART_sRX_RxBitCounter_ST__16BIT_STATUS_REG EQU CYREG_B1_UDB10_11_ST
PC_BUART_sRX_RxBitCounter_ST__MASK_REG EQU CYREG_B1_UDB10_MSK
PC_BUART_sRX_RxBitCounter_ST__MASK_ST_AUX_CTL_REG EQU CYREG_B1_UDB10_MSK_ACTL
PC_BUART_sRX_RxBitCounter_ST__PER_ST_AUX_CTL_REG EQU CYREG_B1_UDB10_MSK_ACTL
PC_BUART_sRX_RxBitCounter_ST__STATUS_AUX_CTL_REG EQU CYREG_B1_UDB10_ACTL
PC_BUART_sRX_RxBitCounter_ST__STATUS_CNT_REG EQU CYREG_B1_UDB10_ST_CTL
PC_BUART_sRX_RxBitCounter_ST__STATUS_CONTROL_REG EQU CYREG_B1_UDB10_ST_CTL
PC_BUART_sRX_RxBitCounter_ST__STATUS_REG EQU CYREG_B1_UDB10_ST
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
PC_BUART_sRX_RxShifter_u0__MSK_DP_AUX_CTL_REG EQU CYREG_B1_UDB10_MSK_ACTL
PC_BUART_sRX_RxShifter_u0__PER_DP_AUX_CTL_REG EQU CYREG_B1_UDB10_MSK_ACTL
PC_BUART_sRX_RxSts__16BIT_STATUS_AUX_CTL_REG EQU CYREG_B1_UDB09_10_ACTL
PC_BUART_sRX_RxSts__16BIT_STATUS_REG EQU CYREG_B1_UDB09_10_ST
PC_BUART_sRX_RxSts__3__MASK EQU 0x08
PC_BUART_sRX_RxSts__3__POS EQU 3
PC_BUART_sRX_RxSts__4__MASK EQU 0x10
PC_BUART_sRX_RxSts__4__POS EQU 4
PC_BUART_sRX_RxSts__5__MASK EQU 0x20
PC_BUART_sRX_RxSts__5__POS EQU 5
PC_BUART_sRX_RxSts__MASK EQU 0x38
PC_BUART_sRX_RxSts__MASK_REG EQU CYREG_B1_UDB09_MSK
PC_BUART_sRX_RxSts__STATUS_AUX_CTL_REG EQU CYREG_B1_UDB09_ACTL
PC_BUART_sRX_RxSts__STATUS_REG EQU CYREG_B1_UDB09_ST
PC_BUART_sTX_sCLOCK_TxBitClkGen__A0_A1_REG EQU CYREG_B1_UDB11_A0_A1
PC_BUART_sTX_sCLOCK_TxBitClkGen__A0_REG EQU CYREG_B1_UDB11_A0
PC_BUART_sTX_sCLOCK_TxBitClkGen__A1_REG EQU CYREG_B1_UDB11_A1
PC_BUART_sTX_sCLOCK_TxBitClkGen__D0_D1_REG EQU CYREG_B1_UDB11_D0_D1
PC_BUART_sTX_sCLOCK_TxBitClkGen__D0_REG EQU CYREG_B1_UDB11_D0
PC_BUART_sTX_sCLOCK_TxBitClkGen__D1_REG EQU CYREG_B1_UDB11_D1
PC_BUART_sTX_sCLOCK_TxBitClkGen__DP_AUX_CTL_REG EQU CYREG_B1_UDB11_ACTL
PC_BUART_sTX_sCLOCK_TxBitClkGen__F0_F1_REG EQU CYREG_B1_UDB11_F0_F1
PC_BUART_sTX_sCLOCK_TxBitClkGen__F0_REG EQU CYREG_B1_UDB11_F0
PC_BUART_sTX_sCLOCK_TxBitClkGen__F1_REG EQU CYREG_B1_UDB11_F1
PC_BUART_sTX_TxShifter_u0__16BIT_A0_REG EQU CYREG_B1_UDB08_09_A0
PC_BUART_sTX_TxShifter_u0__16BIT_A1_REG EQU CYREG_B1_UDB08_09_A1
PC_BUART_sTX_TxShifter_u0__16BIT_D0_REG EQU CYREG_B1_UDB08_09_D0
PC_BUART_sTX_TxShifter_u0__16BIT_D1_REG EQU CYREG_B1_UDB08_09_D1
PC_BUART_sTX_TxShifter_u0__16BIT_DP_AUX_CTL_REG EQU CYREG_B1_UDB08_09_ACTL
PC_BUART_sTX_TxShifter_u0__16BIT_F0_REG EQU CYREG_B1_UDB08_09_F0
PC_BUART_sTX_TxShifter_u0__16BIT_F1_REG EQU CYREG_B1_UDB08_09_F1
PC_BUART_sTX_TxShifter_u0__A0_A1_REG EQU CYREG_B1_UDB08_A0_A1
PC_BUART_sTX_TxShifter_u0__A0_REG EQU CYREG_B1_UDB08_A0
PC_BUART_sTX_TxShifter_u0__A1_REG EQU CYREG_B1_UDB08_A1
PC_BUART_sTX_TxShifter_u0__D0_D1_REG EQU CYREG_B1_UDB08_D0_D1
PC_BUART_sTX_TxShifter_u0__D0_REG EQU CYREG_B1_UDB08_D0
PC_BUART_sTX_TxShifter_u0__D1_REG EQU CYREG_B1_UDB08_D1
PC_BUART_sTX_TxShifter_u0__DP_AUX_CTL_REG EQU CYREG_B1_UDB08_ACTL
PC_BUART_sTX_TxShifter_u0__F0_F1_REG EQU CYREG_B1_UDB08_F0_F1
PC_BUART_sTX_TxShifter_u0__F0_REG EQU CYREG_B1_UDB08_F0
PC_BUART_sTX_TxShifter_u0__F1_REG EQU CYREG_B1_UDB08_F1
PC_BUART_sTX_TxSts__0__MASK EQU 0x01
PC_BUART_sTX_TxSts__0__POS EQU 0
PC_BUART_sTX_TxSts__1__MASK EQU 0x02
PC_BUART_sTX_TxSts__1__POS EQU 1
PC_BUART_sTX_TxSts__16BIT_STATUS_AUX_CTL_REG EQU CYREG_B1_UDB08_09_ACTL
PC_BUART_sTX_TxSts__16BIT_STATUS_REG EQU CYREG_B1_UDB08_09_ST
PC_BUART_sTX_TxSts__2__MASK EQU 0x04
PC_BUART_sTX_TxSts__2__POS EQU 2
PC_BUART_sTX_TxSts__3__MASK EQU 0x08
PC_BUART_sTX_TxSts__3__POS EQU 3
PC_BUART_sTX_TxSts__MASK EQU 0x0F
PC_BUART_sTX_TxSts__MASK_REG EQU CYREG_B1_UDB08_MSK
PC_BUART_sTX_TxSts__STATUS_AUX_CTL_REG EQU CYREG_B1_UDB08_ACTL
PC_BUART_sTX_TxSts__STATUS_REG EQU CYREG_B1_UDB08_ST
PC_IntClock__CFG0 EQU CYREG_CLKDIST_DCFG0_CFG0
PC_IntClock__CFG1 EQU CYREG_CLKDIST_DCFG0_CFG1
PC_IntClock__CFG2 EQU CYREG_CLKDIST_DCFG0_CFG2
PC_IntClock__CFG2_SRC_SEL_MASK EQU 0x07
PC_IntClock__INDEX EQU 0x00
PC_IntClock__PM_ACT_CFG EQU CYREG_PM_ACT_CFG2
PC_IntClock__PM_ACT_MSK EQU 0x01
PC_IntClock__PM_STBY_CFG EQU CYREG_PM_STBY_CFG2
PC_IntClock__PM_STBY_MSK EQU 0x01

/* PWM1 */
PWM1_PWMUDB_genblk1_ctrlreg__16BIT_CONTROL_AUX_CTL_REG EQU CYREG_B0_UDB05_06_ACTL
PWM1_PWMUDB_genblk1_ctrlreg__16BIT_CONTROL_CONTROL_REG EQU CYREG_B0_UDB05_06_CTL
PWM1_PWMUDB_genblk1_ctrlreg__16BIT_CONTROL_COUNT_REG EQU CYREG_B0_UDB05_06_CTL
PWM1_PWMUDB_genblk1_ctrlreg__16BIT_COUNT_CONTROL_REG EQU CYREG_B0_UDB05_06_CTL
PWM1_PWMUDB_genblk1_ctrlreg__16BIT_COUNT_COUNT_REG EQU CYREG_B0_UDB05_06_CTL
PWM1_PWMUDB_genblk1_ctrlreg__16BIT_MASK_MASK_REG EQU CYREG_B0_UDB05_06_MSK
PWM1_PWMUDB_genblk1_ctrlreg__16BIT_MASK_PERIOD_REG EQU CYREG_B0_UDB05_06_MSK
PWM1_PWMUDB_genblk1_ctrlreg__16BIT_PERIOD_MASK_REG EQU CYREG_B0_UDB05_06_MSK
PWM1_PWMUDB_genblk1_ctrlreg__16BIT_PERIOD_PERIOD_REG EQU CYREG_B0_UDB05_06_MSK
PWM1_PWMUDB_genblk1_ctrlreg__7__MASK EQU 0x80
PWM1_PWMUDB_genblk1_ctrlreg__7__POS EQU 7
PWM1_PWMUDB_genblk1_ctrlreg__CONTROL_AUX_CTL_REG EQU CYREG_B0_UDB05_ACTL
PWM1_PWMUDB_genblk1_ctrlreg__CONTROL_REG EQU CYREG_B0_UDB05_CTL
PWM1_PWMUDB_genblk1_ctrlreg__CONTROL_ST_REG EQU CYREG_B0_UDB05_ST_CTL
PWM1_PWMUDB_genblk1_ctrlreg__COUNT_REG EQU CYREG_B0_UDB05_CTL
PWM1_PWMUDB_genblk1_ctrlreg__COUNT_ST_REG EQU CYREG_B0_UDB05_ST_CTL
PWM1_PWMUDB_genblk1_ctrlreg__MASK EQU 0x80
PWM1_PWMUDB_genblk1_ctrlreg__MASK_CTL_AUX_CTL_REG EQU CYREG_B0_UDB05_MSK_ACTL
PWM1_PWMUDB_genblk1_ctrlreg__PER_CTL_AUX_CTL_REG EQU CYREG_B0_UDB05_MSK_ACTL
PWM1_PWMUDB_genblk1_ctrlreg__PERIOD_REG EQU CYREG_B0_UDB05_MSK
PWM1_PWMUDB_genblk8_stsreg__0__MASK EQU 0x01
PWM1_PWMUDB_genblk8_stsreg__0__POS EQU 0
PWM1_PWMUDB_genblk8_stsreg__1__MASK EQU 0x02
PWM1_PWMUDB_genblk8_stsreg__1__POS EQU 1
PWM1_PWMUDB_genblk8_stsreg__16BIT_STATUS_AUX_CTL_REG EQU CYREG_B0_UDB05_06_ACTL
PWM1_PWMUDB_genblk8_stsreg__16BIT_STATUS_REG EQU CYREG_B0_UDB05_06_ST
PWM1_PWMUDB_genblk8_stsreg__2__MASK EQU 0x04
PWM1_PWMUDB_genblk8_stsreg__2__POS EQU 2
PWM1_PWMUDB_genblk8_stsreg__3__MASK EQU 0x08
PWM1_PWMUDB_genblk8_stsreg__3__POS EQU 3
PWM1_PWMUDB_genblk8_stsreg__MASK EQU 0x0F
PWM1_PWMUDB_genblk8_stsreg__MASK_REG EQU CYREG_B0_UDB05_MSK
PWM1_PWMUDB_genblk8_stsreg__MASK_ST_AUX_CTL_REG EQU CYREG_B0_UDB05_MSK_ACTL
PWM1_PWMUDB_genblk8_stsreg__PER_ST_AUX_CTL_REG EQU CYREG_B0_UDB05_MSK_ACTL
PWM1_PWMUDB_genblk8_stsreg__STATUS_AUX_CTL_REG EQU CYREG_B0_UDB05_ACTL
PWM1_PWMUDB_genblk8_stsreg__STATUS_CNT_REG EQU CYREG_B0_UDB05_ST_CTL
PWM1_PWMUDB_genblk8_stsreg__STATUS_CONTROL_REG EQU CYREG_B0_UDB05_ST_CTL
PWM1_PWMUDB_genblk8_stsreg__STATUS_REG EQU CYREG_B0_UDB05_ST
PWM1_PWMUDB_sP16_pwmdp_u0__16BIT_A0_REG EQU CYREG_B0_UDB04_05_A0
PWM1_PWMUDB_sP16_pwmdp_u0__16BIT_A1_REG EQU CYREG_B0_UDB04_05_A1
PWM1_PWMUDB_sP16_pwmdp_u0__16BIT_D0_REG EQU CYREG_B0_UDB04_05_D0
PWM1_PWMUDB_sP16_pwmdp_u0__16BIT_D1_REG EQU CYREG_B0_UDB04_05_D1
PWM1_PWMUDB_sP16_pwmdp_u0__16BIT_DP_AUX_CTL_REG EQU CYREG_B0_UDB04_05_ACTL
PWM1_PWMUDB_sP16_pwmdp_u0__16BIT_F0_REG EQU CYREG_B0_UDB04_05_F0
PWM1_PWMUDB_sP16_pwmdp_u0__16BIT_F1_REG EQU CYREG_B0_UDB04_05_F1
PWM1_PWMUDB_sP16_pwmdp_u0__A0_A1_REG EQU CYREG_B0_UDB04_A0_A1
PWM1_PWMUDB_sP16_pwmdp_u0__A0_REG EQU CYREG_B0_UDB04_A0
PWM1_PWMUDB_sP16_pwmdp_u0__A1_REG EQU CYREG_B0_UDB04_A1
PWM1_PWMUDB_sP16_pwmdp_u0__D0_D1_REG EQU CYREG_B0_UDB04_D0_D1
PWM1_PWMUDB_sP16_pwmdp_u0__D0_REG EQU CYREG_B0_UDB04_D0
PWM1_PWMUDB_sP16_pwmdp_u0__D1_REG EQU CYREG_B0_UDB04_D1
PWM1_PWMUDB_sP16_pwmdp_u0__DP_AUX_CTL_REG EQU CYREG_B0_UDB04_ACTL
PWM1_PWMUDB_sP16_pwmdp_u0__F0_F1_REG EQU CYREG_B0_UDB04_F0_F1
PWM1_PWMUDB_sP16_pwmdp_u0__F0_REG EQU CYREG_B0_UDB04_F0
PWM1_PWMUDB_sP16_pwmdp_u0__F1_REG EQU CYREG_B0_UDB04_F1
PWM1_PWMUDB_sP16_pwmdp_u1__16BIT_A0_REG EQU CYREG_B0_UDB05_06_A0
PWM1_PWMUDB_sP16_pwmdp_u1__16BIT_A1_REG EQU CYREG_B0_UDB05_06_A1
PWM1_PWMUDB_sP16_pwmdp_u1__16BIT_D0_REG EQU CYREG_B0_UDB05_06_D0
PWM1_PWMUDB_sP16_pwmdp_u1__16BIT_D1_REG EQU CYREG_B0_UDB05_06_D1
PWM1_PWMUDB_sP16_pwmdp_u1__16BIT_DP_AUX_CTL_REG EQU CYREG_B0_UDB05_06_ACTL
PWM1_PWMUDB_sP16_pwmdp_u1__16BIT_F0_REG EQU CYREG_B0_UDB05_06_F0
PWM1_PWMUDB_sP16_pwmdp_u1__16BIT_F1_REG EQU CYREG_B0_UDB05_06_F1
PWM1_PWMUDB_sP16_pwmdp_u1__A0_A1_REG EQU CYREG_B0_UDB05_A0_A1
PWM1_PWMUDB_sP16_pwmdp_u1__A0_REG EQU CYREG_B0_UDB05_A0
PWM1_PWMUDB_sP16_pwmdp_u1__A1_REG EQU CYREG_B0_UDB05_A1
PWM1_PWMUDB_sP16_pwmdp_u1__D0_D1_REG EQU CYREG_B0_UDB05_D0_D1
PWM1_PWMUDB_sP16_pwmdp_u1__D0_REG EQU CYREG_B0_UDB05_D0
PWM1_PWMUDB_sP16_pwmdp_u1__D1_REG EQU CYREG_B0_UDB05_D1
PWM1_PWMUDB_sP16_pwmdp_u1__DP_AUX_CTL_REG EQU CYREG_B0_UDB05_ACTL
PWM1_PWMUDB_sP16_pwmdp_u1__F0_F1_REG EQU CYREG_B0_UDB05_F0_F1
PWM1_PWMUDB_sP16_pwmdp_u1__F0_REG EQU CYREG_B0_UDB05_F0
PWM1_PWMUDB_sP16_pwmdp_u1__F1_REG EQU CYREG_B0_UDB05_F1
PWM1_PWMUDB_sP16_pwmdp_u1__MSK_DP_AUX_CTL_REG EQU CYREG_B0_UDB05_MSK_ACTL
PWM1_PWMUDB_sP16_pwmdp_u1__PER_DP_AUX_CTL_REG EQU CYREG_B0_UDB05_MSK_ACTL

/* PWM2 */
PWM2_PWMUDB_genblk1_ctrlreg__16BIT_CONTROL_AUX_CTL_REG EQU CYREG_B0_UDB03_04_ACTL
PWM2_PWMUDB_genblk1_ctrlreg__16BIT_CONTROL_CONTROL_REG EQU CYREG_B0_UDB03_04_CTL
PWM2_PWMUDB_genblk1_ctrlreg__16BIT_CONTROL_COUNT_REG EQU CYREG_B0_UDB03_04_CTL
PWM2_PWMUDB_genblk1_ctrlreg__16BIT_COUNT_CONTROL_REG EQU CYREG_B0_UDB03_04_CTL
PWM2_PWMUDB_genblk1_ctrlreg__16BIT_COUNT_COUNT_REG EQU CYREG_B0_UDB03_04_CTL
PWM2_PWMUDB_genblk1_ctrlreg__16BIT_MASK_MASK_REG EQU CYREG_B0_UDB03_04_MSK
PWM2_PWMUDB_genblk1_ctrlreg__16BIT_MASK_PERIOD_REG EQU CYREG_B0_UDB03_04_MSK
PWM2_PWMUDB_genblk1_ctrlreg__16BIT_PERIOD_MASK_REG EQU CYREG_B0_UDB03_04_MSK
PWM2_PWMUDB_genblk1_ctrlreg__16BIT_PERIOD_PERIOD_REG EQU CYREG_B0_UDB03_04_MSK
PWM2_PWMUDB_genblk1_ctrlreg__7__MASK EQU 0x80
PWM2_PWMUDB_genblk1_ctrlreg__7__POS EQU 7
PWM2_PWMUDB_genblk1_ctrlreg__CONTROL_AUX_CTL_REG EQU CYREG_B0_UDB03_ACTL
PWM2_PWMUDB_genblk1_ctrlreg__CONTROL_REG EQU CYREG_B0_UDB03_CTL
PWM2_PWMUDB_genblk1_ctrlreg__CONTROL_ST_REG EQU CYREG_B0_UDB03_ST_CTL
PWM2_PWMUDB_genblk1_ctrlreg__COUNT_REG EQU CYREG_B0_UDB03_CTL
PWM2_PWMUDB_genblk1_ctrlreg__COUNT_ST_REG EQU CYREG_B0_UDB03_ST_CTL
PWM2_PWMUDB_genblk1_ctrlreg__MASK EQU 0x80
PWM2_PWMUDB_genblk1_ctrlreg__MASK_CTL_AUX_CTL_REG EQU CYREG_B0_UDB03_MSK_ACTL
PWM2_PWMUDB_genblk1_ctrlreg__PER_CTL_AUX_CTL_REG EQU CYREG_B0_UDB03_MSK_ACTL
PWM2_PWMUDB_genblk1_ctrlreg__PERIOD_REG EQU CYREG_B0_UDB03_MSK
PWM2_PWMUDB_genblk8_stsreg__0__MASK EQU 0x01
PWM2_PWMUDB_genblk8_stsreg__0__POS EQU 0
PWM2_PWMUDB_genblk8_stsreg__1__MASK EQU 0x02
PWM2_PWMUDB_genblk8_stsreg__1__POS EQU 1
PWM2_PWMUDB_genblk8_stsreg__16BIT_STATUS_AUX_CTL_REG EQU CYREG_B0_UDB03_04_ACTL
PWM2_PWMUDB_genblk8_stsreg__16BIT_STATUS_REG EQU CYREG_B0_UDB03_04_ST
PWM2_PWMUDB_genblk8_stsreg__2__MASK EQU 0x04
PWM2_PWMUDB_genblk8_stsreg__2__POS EQU 2
PWM2_PWMUDB_genblk8_stsreg__3__MASK EQU 0x08
PWM2_PWMUDB_genblk8_stsreg__3__POS EQU 3
PWM2_PWMUDB_genblk8_stsreg__MASK EQU 0x0F
PWM2_PWMUDB_genblk8_stsreg__MASK_REG EQU CYREG_B0_UDB03_MSK
PWM2_PWMUDB_genblk8_stsreg__MASK_ST_AUX_CTL_REG EQU CYREG_B0_UDB03_MSK_ACTL
PWM2_PWMUDB_genblk8_stsreg__PER_ST_AUX_CTL_REG EQU CYREG_B0_UDB03_MSK_ACTL
PWM2_PWMUDB_genblk8_stsreg__STATUS_AUX_CTL_REG EQU CYREG_B0_UDB03_ACTL
PWM2_PWMUDB_genblk8_stsreg__STATUS_CNT_REG EQU CYREG_B0_UDB03_ST_CTL
PWM2_PWMUDB_genblk8_stsreg__STATUS_CONTROL_REG EQU CYREG_B0_UDB03_ST_CTL
PWM2_PWMUDB_genblk8_stsreg__STATUS_REG EQU CYREG_B0_UDB03_ST
PWM2_PWMUDB_sP16_pwmdp_u0__16BIT_A0_REG EQU CYREG_B0_UDB02_03_A0
PWM2_PWMUDB_sP16_pwmdp_u0__16BIT_A1_REG EQU CYREG_B0_UDB02_03_A1
PWM2_PWMUDB_sP16_pwmdp_u0__16BIT_D0_REG EQU CYREG_B0_UDB02_03_D0
PWM2_PWMUDB_sP16_pwmdp_u0__16BIT_D1_REG EQU CYREG_B0_UDB02_03_D1
PWM2_PWMUDB_sP16_pwmdp_u0__16BIT_DP_AUX_CTL_REG EQU CYREG_B0_UDB02_03_ACTL
PWM2_PWMUDB_sP16_pwmdp_u0__16BIT_F0_REG EQU CYREG_B0_UDB02_03_F0
PWM2_PWMUDB_sP16_pwmdp_u0__16BIT_F1_REG EQU CYREG_B0_UDB02_03_F1
PWM2_PWMUDB_sP16_pwmdp_u0__A0_A1_REG EQU CYREG_B0_UDB02_A0_A1
PWM2_PWMUDB_sP16_pwmdp_u0__A0_REG EQU CYREG_B0_UDB02_A0
PWM2_PWMUDB_sP16_pwmdp_u0__A1_REG EQU CYREG_B0_UDB02_A1
PWM2_PWMUDB_sP16_pwmdp_u0__D0_D1_REG EQU CYREG_B0_UDB02_D0_D1
PWM2_PWMUDB_sP16_pwmdp_u0__D0_REG EQU CYREG_B0_UDB02_D0
PWM2_PWMUDB_sP16_pwmdp_u0__D1_REG EQU CYREG_B0_UDB02_D1
PWM2_PWMUDB_sP16_pwmdp_u0__DP_AUX_CTL_REG EQU CYREG_B0_UDB02_ACTL
PWM2_PWMUDB_sP16_pwmdp_u0__F0_F1_REG EQU CYREG_B0_UDB02_F0_F1
PWM2_PWMUDB_sP16_pwmdp_u0__F0_REG EQU CYREG_B0_UDB02_F0
PWM2_PWMUDB_sP16_pwmdp_u0__F1_REG EQU CYREG_B0_UDB02_F1
PWM2_PWMUDB_sP16_pwmdp_u1__16BIT_A0_REG EQU CYREG_B0_UDB03_04_A0
PWM2_PWMUDB_sP16_pwmdp_u1__16BIT_A1_REG EQU CYREG_B0_UDB03_04_A1
PWM2_PWMUDB_sP16_pwmdp_u1__16BIT_D0_REG EQU CYREG_B0_UDB03_04_D0
PWM2_PWMUDB_sP16_pwmdp_u1__16BIT_D1_REG EQU CYREG_B0_UDB03_04_D1
PWM2_PWMUDB_sP16_pwmdp_u1__16BIT_DP_AUX_CTL_REG EQU CYREG_B0_UDB03_04_ACTL
PWM2_PWMUDB_sP16_pwmdp_u1__16BIT_F0_REG EQU CYREG_B0_UDB03_04_F0
PWM2_PWMUDB_sP16_pwmdp_u1__16BIT_F1_REG EQU CYREG_B0_UDB03_04_F1
PWM2_PWMUDB_sP16_pwmdp_u1__A0_A1_REG EQU CYREG_B0_UDB03_A0_A1
PWM2_PWMUDB_sP16_pwmdp_u1__A0_REG EQU CYREG_B0_UDB03_A0
PWM2_PWMUDB_sP16_pwmdp_u1__A1_REG EQU CYREG_B0_UDB03_A1
PWM2_PWMUDB_sP16_pwmdp_u1__D0_D1_REG EQU CYREG_B0_UDB03_D0_D1
PWM2_PWMUDB_sP16_pwmdp_u1__D0_REG EQU CYREG_B0_UDB03_D0
PWM2_PWMUDB_sP16_pwmdp_u1__D1_REG EQU CYREG_B0_UDB03_D1
PWM2_PWMUDB_sP16_pwmdp_u1__DP_AUX_CTL_REG EQU CYREG_B0_UDB03_ACTL
PWM2_PWMUDB_sP16_pwmdp_u1__F0_F1_REG EQU CYREG_B0_UDB03_F0_F1
PWM2_PWMUDB_sP16_pwmdp_u1__F0_REG EQU CYREG_B0_UDB03_F0
PWM2_PWMUDB_sP16_pwmdp_u1__F1_REG EQU CYREG_B0_UDB03_F1
PWM2_PWMUDB_sP16_pwmdp_u1__MSK_DP_AUX_CTL_REG EQU CYREG_B0_UDB03_MSK_ACTL
PWM2_PWMUDB_sP16_pwmdp_u1__PER_DP_AUX_CTL_REG EQU CYREG_B0_UDB03_MSK_ACTL

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

/* SCL_1 */
SCL_1__0__INTTYPE EQU CYREG_PICU12_INTTYPE0
SCL_1__0__MASK EQU 0x01
SCL_1__0__PC EQU CYREG_PRT12_PC0
SCL_1__0__PORT EQU 12
SCL_1__0__SHIFT EQU 0
SCL_1__AG EQU CYREG_PRT12_AG
SCL_1__BIE EQU CYREG_PRT12_BIE
SCL_1__BIT_MASK EQU CYREG_PRT12_BIT_MASK
SCL_1__BYP EQU CYREG_PRT12_BYP
SCL_1__DM0 EQU CYREG_PRT12_DM0
SCL_1__DM1 EQU CYREG_PRT12_DM1
SCL_1__DM2 EQU CYREG_PRT12_DM2
SCL_1__DR EQU CYREG_PRT12_DR
SCL_1__INP_DIS EQU CYREG_PRT12_INP_DIS
SCL_1__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU12_BASE
SCL_1__MASK EQU 0x01
SCL_1__PORT EQU 12
SCL_1__PRT EQU CYREG_PRT12_PRT
SCL_1__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT12_DBL_SYNC_IN
SCL_1__PRTDSI__OE_SEL0 EQU CYREG_PRT12_OE_SEL0
SCL_1__PRTDSI__OE_SEL1 EQU CYREG_PRT12_OE_SEL1
SCL_1__PRTDSI__OUT_SEL0 EQU CYREG_PRT12_OUT_SEL0
SCL_1__PRTDSI__OUT_SEL1 EQU CYREG_PRT12_OUT_SEL1
SCL_1__PRTDSI__SYNC_OUT EQU CYREG_PRT12_SYNC_OUT
SCL_1__PS EQU CYREG_PRT12_PS
SCL_1__SHIFT EQU 0
SCL_1__SIO_CFG EQU CYREG_PRT12_SIO_CFG
SCL_1__SIO_DIFF EQU CYREG_PRT12_SIO_DIFF
SCL_1__SIO_HYST_EN EQU CYREG_PRT12_SIO_HYST_EN
SCL_1__SIO_REG_HIFREQ EQU CYREG_PRT12_SIO_REG_HIFREQ
SCL_1__SLW EQU CYREG_PRT12_SLW

/* SDA_1 */
SDA_1__0__INTTYPE EQU CYREG_PICU12_INTTYPE1
SDA_1__0__MASK EQU 0x02
SDA_1__0__PC EQU CYREG_PRT12_PC1
SDA_1__0__PORT EQU 12
SDA_1__0__SHIFT EQU 1
SDA_1__AG EQU CYREG_PRT12_AG
SDA_1__BIE EQU CYREG_PRT12_BIE
SDA_1__BIT_MASK EQU CYREG_PRT12_BIT_MASK
SDA_1__BYP EQU CYREG_PRT12_BYP
SDA_1__DM0 EQU CYREG_PRT12_DM0
SDA_1__DM1 EQU CYREG_PRT12_DM1
SDA_1__DM2 EQU CYREG_PRT12_DM2
SDA_1__DR EQU CYREG_PRT12_DR
SDA_1__INP_DIS EQU CYREG_PRT12_INP_DIS
SDA_1__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU12_BASE
SDA_1__MASK EQU 0x02
SDA_1__PORT EQU 12
SDA_1__PRT EQU CYREG_PRT12_PRT
SDA_1__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT12_DBL_SYNC_IN
SDA_1__PRTDSI__OE_SEL0 EQU CYREG_PRT12_OE_SEL0
SDA_1__PRTDSI__OE_SEL1 EQU CYREG_PRT12_OE_SEL1
SDA_1__PRTDSI__OUT_SEL0 EQU CYREG_PRT12_OUT_SEL0
SDA_1__PRTDSI__OUT_SEL1 EQU CYREG_PRT12_OUT_SEL1
SDA_1__PRTDSI__SYNC_OUT EQU CYREG_PRT12_SYNC_OUT
SDA_1__PS EQU CYREG_PRT12_PS
SDA_1__SHIFT EQU 1
SDA_1__SIO_CFG EQU CYREG_PRT12_SIO_CFG
SDA_1__SIO_DIFF EQU CYREG_PRT12_SIO_DIFF
SDA_1__SIO_HYST_EN EQU CYREG_PRT12_SIO_HYST_EN
SDA_1__SIO_REG_HIFREQ EQU CYREG_PRT12_SIO_REG_HIFREQ
SDA_1__SLW EQU CYREG_PRT12_SLW

/* Servo */
Servo__0__INTTYPE EQU CYREG_PICU0_INTTYPE1
Servo__0__MASK EQU 0x02
Servo__0__PC EQU CYREG_PRT0_PC1
Servo__0__PORT EQU 0
Servo__0__SHIFT EQU 1
Servo__1__INTTYPE EQU CYREG_PICU0_INTTYPE2
Servo__1__MASK EQU 0x04
Servo__1__PC EQU CYREG_PRT0_PC2
Servo__1__PORT EQU 0
Servo__1__SHIFT EQU 2
Servo__2__INTTYPE EQU CYREG_PICU0_INTTYPE3
Servo__2__MASK EQU 0x08
Servo__2__PC EQU CYREG_PRT0_PC3
Servo__2__PORT EQU 0
Servo__2__SHIFT EQU 3
Servo__3__INTTYPE EQU CYREG_PICU0_INTTYPE4
Servo__3__MASK EQU 0x10
Servo__3__PC EQU CYREG_PRT0_PC4
Servo__3__PORT EQU 0
Servo__3__SHIFT EQU 4
Servo__AG EQU CYREG_PRT0_AG
Servo__AMUX EQU CYREG_PRT0_AMUX
Servo__BIE EQU CYREG_PRT0_BIE
Servo__BIT_MASK EQU CYREG_PRT0_BIT_MASK
Servo__BYP EQU CYREG_PRT0_BYP
Servo__CTL EQU CYREG_PRT0_CTL
Servo__DM0 EQU CYREG_PRT0_DM0
Servo__DM1 EQU CYREG_PRT0_DM1
Servo__DM2 EQU CYREG_PRT0_DM2
Servo__DR EQU CYREG_PRT0_DR
Servo__INP_DIS EQU CYREG_PRT0_INP_DIS
Servo__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU0_BASE
Servo__LCD_COM_SEG EQU CYREG_PRT0_LCD_COM_SEG
Servo__LCD_EN EQU CYREG_PRT0_LCD_EN
Servo__MASK EQU 0x1E
Servo__PORT EQU 0
Servo__PRT EQU CYREG_PRT0_PRT
Servo__PRTDSI__CAPS_SEL EQU CYREG_PRT0_CAPS_SEL
Servo__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT0_DBL_SYNC_IN
Servo__PRTDSI__OE_SEL0 EQU CYREG_PRT0_OE_SEL0
Servo__PRTDSI__OE_SEL1 EQU CYREG_PRT0_OE_SEL1
Servo__PRTDSI__OUT_SEL0 EQU CYREG_PRT0_OUT_SEL0
Servo__PRTDSI__OUT_SEL1 EQU CYREG_PRT0_OUT_SEL1
Servo__PRTDSI__SYNC_OUT EQU CYREG_PRT0_SYNC_OUT
Servo__PS EQU CYREG_PRT0_PS
Servo__SHIFT EQU 1
Servo__SLW EQU CYREG_PRT0_SLW

/* I2C_LCD */
I2C_LCD_I2C_FF__ADR EQU CYREG_I2C_ADR
I2C_LCD_I2C_FF__CFG EQU CYREG_I2C_CFG
I2C_LCD_I2C_FF__CLK_DIV1 EQU CYREG_I2C_CLK_DIV1
I2C_LCD_I2C_FF__CLK_DIV2 EQU CYREG_I2C_CLK_DIV2
I2C_LCD_I2C_FF__CSR EQU CYREG_I2C_CSR
I2C_LCD_I2C_FF__D EQU CYREG_I2C_D
I2C_LCD_I2C_FF__MCSR EQU CYREG_I2C_MCSR
I2C_LCD_I2C_FF__PM_ACT_CFG EQU CYREG_PM_ACT_CFG5
I2C_LCD_I2C_FF__PM_ACT_MSK EQU 0x04
I2C_LCD_I2C_FF__PM_STBY_CFG EQU CYREG_PM_STBY_CFG5
I2C_LCD_I2C_FF__PM_STBY_MSK EQU 0x04
I2C_LCD_I2C_FF__TMOUT_CFG0 EQU CYREG_I2C_TMOUT_CFG0
I2C_LCD_I2C_FF__TMOUT_CFG1 EQU CYREG_I2C_TMOUT_CFG1
I2C_LCD_I2C_FF__TMOUT_CSR EQU CYREG_I2C_TMOUT_CSR
I2C_LCD_I2C_FF__TMOUT_SR EQU CYREG_I2C_TMOUT_SR
I2C_LCD_I2C_FF__XCFG EQU CYREG_I2C_XCFG
I2C_LCD_I2C_IRQ__INTC_CLR_EN_REG EQU CYREG_NVIC_CLRENA0
I2C_LCD_I2C_IRQ__INTC_CLR_PD_REG EQU CYREG_NVIC_CLRPEND0
I2C_LCD_I2C_IRQ__INTC_MASK EQU 0x8000
I2C_LCD_I2C_IRQ__INTC_NUMBER EQU 15
I2C_LCD_I2C_IRQ__INTC_PRIOR_NUM EQU 7
I2C_LCD_I2C_IRQ__INTC_PRIOR_REG EQU CYREG_NVIC_PRI_15
I2C_LCD_I2C_IRQ__INTC_SET_EN_REG EQU CYREG_NVIC_SETENA0
I2C_LCD_I2C_IRQ__INTC_SET_PD_REG EQU CYREG_NVIC_SETPEND0

/* ClockPWM */
ClockPWM__CFG0 EQU CYREG_CLKDIST_DCFG1_CFG0
ClockPWM__CFG1 EQU CYREG_CLKDIST_DCFG1_CFG1
ClockPWM__CFG2 EQU CYREG_CLKDIST_DCFG1_CFG2
ClockPWM__CFG2_SRC_SEL_MASK EQU 0x07
ClockPWM__INDEX EQU 0x01
ClockPWM__PM_ACT_CFG EQU CYREG_PM_ACT_CFG2
ClockPWM__PM_ACT_MSK EQU 0x02
ClockPWM__PM_STBY_CFG EQU CYREG_PM_STBY_CFG2
ClockPWM__PM_STBY_MSK EQU 0x02

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
CYDEV_INTR_RISING EQU 0x00008000
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
