/*******************************************************************************
* File Name: POT.h
* Version 3.10
*
* Description:
*  This file contains the function prototypes and constants used in
*  the Successive approximation ADC Component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/


#if !defined(CY_ADC_SAR_POT_H) /* CY_ADC_SAR_POT_H */
#define CY_ADC_SAR_POT_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
* Conditional Compilation Parameters
***************************************/

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component ADC_SAR_v3_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5LP) */


/***************************************
*      Data Struct Definition
***************************************/

/* Sleep Mode API Support */
typedef struct
{
    uint8 enableState;
} POT_BACKUP_STRUCT;


/***************************************
*        Function Prototypes
***************************************/

void POT_Start(void);
void POT_Stop(void);
void POT_SetPower(uint8 power);
void POT_SetResolution(uint8 resolution);

uint8 POT_IsEndConversion(uint8 retMode);
int8 POT_GetResult8(void);
int16 POT_GetResult16(void);

void POT_SetOffset(int16 offset);
void POT_SetScaledGain(int32 adcGain);
int16 POT_CountsTo_mVolts(int16 adcCounts);
int32 POT_CountsTo_uVolts(int16 adcCounts);
float32 POT_CountsTo_Volts(int16 adcCounts);

void POT_Init(void);
void POT_Enable(void);

void POT_SaveConfig(void);
void POT_RestoreConfig(void);
void POT_Sleep(void);
void POT_Wakeup(void);

CY_ISR_PROTO( POT_ISR );

/* Obsolete API for backward compatibility.
*  Should not be used in new designs.
*/
void POT_SetGain(int16 adcGain);


/***************************************
* Global variables external identifier
***************************************/

extern uint8 POT_initVar;
extern volatile int16 POT_offset;
extern volatile int16 POT_countsPerVolt; /* Obsolete variable, do not modify in new design */
extern volatile int32 POT_countsPer10Volt;
extern volatile int16 POT_shift;


/**************************************
*           API Constants
**************************************/

/* Resolution setting constants  */
#define POT__BITS_12 12
#define POT__BITS_10 10
#define POT__BITS_8 8


/*   Constants for IsEndConversion() "retMode" parameter  */
#define POT_RETURN_STATUS              (0x01u)
#define POT_WAIT_FOR_RESULT            (0x00u)

/* Constants for SetPower(power), "power" paramter */
#define POT__HIGHPOWER 0
#define POT__MEDPOWER 1
#define POT__LOWPOWER 2
#define POT__MINPOWER 3

#define POT_SAR_API_POWER_MASK         (0x03u)

/* Constants for Sleep mode states */
#define POT_STARTED                    (0x02u)
#define POT_ENABLED                    (0x01u)
#define POT_DISABLED                   (0x00u)

#define POT_MAX_FREQUENCY              (18000000)       /* 18Mhz */

#define POT_10V_COUNTS                 (10.0F)
#define POT_10MV_COUNTS                (10000)
#define POT_10UV_COUNTS                (10000000L)



/**************************************
*    Enumerated Types and Parameters
**************************************/

/*  Reference constants */
#define POT__INT_REF_NOT_BYPASSED 0
#define POT__INT_REF_BYPASS 1
#define POT__EXT_REF 2

/*  Input Range setting constants */
#define POT__VSS_TO_VREF 0
#define POT__VSSA_TO_VDDA 1
#define POT__VSSA_TO_VDAC 2
#define POT__VNEG_VREF_DIFF 3
#define POT__VNEG_VDDA_DIFF 4
#define POT__VNEG_VDDA_2_DIFF 5
#define POT__VNEG_VDAC_DIFF 6

/*  Sample Mode setting constants */
#define POT__FREERUNNING 0
#define POT__TRIGGERED 1

/*  Extended Sample Mode setting constants */
#define POT__FREE_RUNNING 0
#define POT__SOFTWARE_TRIGGER 1
#define POT__HARDWARE_TRIGGER 2

/*  Clock Source setting constants */
#define POT__INTERNAL 1
#define POT__EXTERNAL 0



/**************************************
*    Initial Parameter Constants
**************************************/

/* Default config values from user parameters */
#define POT_DEFAULT_RESOLUTION     (12u)   /* ADC resolution selected with parameters.*/
#define POT_DEFAULT_CONV_MODE      (1u)        /* Default conversion method */
#define POT_DEFAULT_INTERNAL_CLK   (1u)             /* Default clock selection */
#define POT_DEFAULT_REFERENCE      (0u)         /* Default reference */
#define POT_DEFAULT_RANGE          (1u)       /* ADC Input Range selection */
#define POT_CLOCK_FREQUENCY        (1600000u)   /* Clock frequency */
#define POT_NOMINAL_CLOCK_FREQ     (1600000)  /* Nominal Clock Frequency */
#define POT_HIGH_POWER_PULSE       (1u)        /* Not zero when clock pulse > 50 ns */
#define POT_IRQ_REMOVE             (0u)                /* Removes internal interrupt */

/* Use VDDA voltage define directly from cyfitter.h when VDDA reference has been used */
#define POT_DEFAULT_REF_VOLTAGE \
                                   (((POT_DEFAULT_REFERENCE != (uint8)POT__EXT_REF) && \
                                    ((POT_DEFAULT_RANGE == (uint8)POT__VSSA_TO_VDDA) || \
                                     (POT_DEFAULT_RANGE == (uint8)POT__VNEG_VDDA_2_DIFF))) ? \
                                     (CYDEV_VDDA / 2) : \
                                   (((POT_DEFAULT_REFERENCE != (uint8)POT__EXT_REF) && \
                                     (POT_DEFAULT_RANGE == (uint8)POT__VNEG_VDDA_2_DIFF)) ? \
                                     CYDEV_VDDA : (2.5)))      /* ADC reference voltage. */
#define POT_DEFAULT_REF_VOLTAGE_MV \
                                   (((POT_DEFAULT_REFERENCE != (uint8)POT__EXT_REF) && \
                                    ((POT_DEFAULT_RANGE == (uint8)POT__VSSA_TO_VDDA) || \
                                     (POT_DEFAULT_RANGE == (uint8)POT__VNEG_VDDA_2_DIFF))) ? \
                                     (CYDEV_VDDA_MV / 2) : \
                                  (((POT_DEFAULT_REFERENCE != (uint8)POT__EXT_REF) && \
                                    (POT_DEFAULT_RANGE == (uint8)POT__VNEG_VDDA_2_DIFF)) ? \
                                     CYDEV_VDDA_MV : (2500)))   /* ADC reference voltage in mV */
/* The power is set to normal power, 1/2, 1/4 power depend on the clock setting. */
#define POT_DEFAULT_POWER \
       ((POT_NOMINAL_CLOCK_FREQ > (POT_MAX_FREQUENCY / 4)) ? POT__HIGHPOWER : \
       ((POT_NOMINAL_CLOCK_FREQ > (POT_MAX_FREQUENCY / 8)) ? POT__MEDPOWER : \
                                                                                       POT__MINPOWER))
/* Constant for a global usage */
/* Number of additional clocks for sampling data*/
#define POT_SAMPLE_PRECHARGE       (4u)


/***************************************
*    Optional Function Prototypes
***************************************/

#if(POT_DEFAULT_CONV_MODE != POT__HARDWARE_TRIGGER)
    void POT_StartConvert(void);
    void POT_StopConvert(void);
#endif /* End POT_DEFAULT_CONV_MODE != POT__HARDWARE_TRIGGER */


/***************************************
*              Registers
***************************************/

#define POT_SAR_TR0_REG                (* (reg8 *) POT_ADC_SAR__TR0 )
#define POT_SAR_TR0_PTR                (  (reg8 *) POT_ADC_SAR__TR0 )
#define POT_SAR_CSR0_REG               (* (reg8 *) POT_ADC_SAR__CSR0 )
#define POT_SAR_CSR0_PTR               (  (reg8 *) POT_ADC_SAR__CSR0 )
#define POT_SAR_CSR1_REG               (* (reg8 *) POT_ADC_SAR__CSR1 )
#define POT_SAR_CSR1_PTR               (  (reg8 *) POT_ADC_SAR__CSR1 )
#define POT_SAR_CSR2_REG               (* (reg8 *) POT_ADC_SAR__CSR2 )
#define POT_SAR_CSR2_PTR               (  (reg8 *) POT_ADC_SAR__CSR2 )
#define POT_SAR_CSR3_REG               (* (reg8 *) POT_ADC_SAR__CSR3 )
#define POT_SAR_CSR3_PTR               (  (reg8 *) POT_ADC_SAR__CSR3 )
#define POT_SAR_CSR4_REG               (* (reg8 *) POT_ADC_SAR__CSR4 )
#define POT_SAR_CSR4_PTR               (  (reg8 *) POT_ADC_SAR__CSR4 )
#define POT_SAR_CSR5_REG               (* (reg8 *) POT_ADC_SAR__CSR5 )
#define POT_SAR_CSR5_PTR               (  (reg8 *) POT_ADC_SAR__CSR5 )
#define POT_SAR_CSR6_REG               (* (reg8 *) POT_ADC_SAR__CSR6 )
#define POT_SAR_CSR6_PTR               (  (reg8 *) POT_ADC_SAR__CSR6 )
#define POT_SAR_SW0_REG                (* (reg8 *) POT_ADC_SAR__SW0 )
#define POT_SAR_SW0_PTR                (  (reg8 *) POT_ADC_SAR__SW0 )
#define POT_SAR_SW2_REG                (* (reg8 *) POT_ADC_SAR__SW2 )
#define POT_SAR_SW2_PTR                (  (reg8 *) POT_ADC_SAR__SW2 )
#define POT_SAR_SW3_REG                (* (reg8 *) POT_ADC_SAR__SW3 )
#define POT_SAR_SW3_PTR                (  (reg8 *) POT_ADC_SAR__SW3 )
#define POT_SAR_SW4_REG                (* (reg8 *) POT_ADC_SAR__SW4 )
#define POT_SAR_SW4_PTR                (  (reg8 *) POT_ADC_SAR__SW4 )
#define POT_SAR_SW6_REG                (* (reg8 *) POT_ADC_SAR__SW6 )
#define POT_SAR_SW6_PTR                (  (reg8 *) POT_ADC_SAR__SW6 )
#define POT_SAR_CLK_REG                (* (reg8 *) POT_ADC_SAR__CLK )
#define POT_SAR_CLK_PTR                (  (reg8 *) POT_ADC_SAR__CLK )
#define POT_SAR_WRK0_REG               (* (reg8 *) POT_ADC_SAR__WRK0 )
#define POT_SAR_WRK0_PTR               (  (reg8 *) POT_ADC_SAR__WRK0 )
#define POT_SAR_WRK1_REG               (* (reg8 *) POT_ADC_SAR__WRK1 )
#define POT_SAR_WRK1_PTR               (  (reg8 *) POT_ADC_SAR__WRK1 )
#define POT_SAR_WRK_PTR                (  (reg16 *) POT_ADC_SAR__WRK0 )
#define POT_PWRMGR_SAR_REG             (* (reg8 *) POT_ADC_SAR__PM_ACT_CFG )
#define POT_PWRMGR_SAR_PTR             (  (reg8 *) POT_ADC_SAR__PM_ACT_CFG )
#define POT_STBY_PWRMGR_SAR_REG        (* (reg8 *) POT_ADC_SAR__PM_STBY_CFG )
#define POT_STBY_PWRMGR_SAR_PTR        (  (reg8 *) POT_ADC_SAR__PM_STBY_CFG )

/* renamed registers for backward compatible */
#define POT_SAR_WRK0                   POT_SAR_WRK0_REG
#define POT_SAR_WRK1                   POT_SAR_WRK1_REG

/* This is only valid if there is an internal clock */
#if(POT_DEFAULT_INTERNAL_CLK)
    /* Clock Power manager Reg */
    #define POT_PWRMGR_CLK_REG         (* (reg8 *) POT_theACLK__PM_ACT_CFG )
    #define POT_PWRMGR_CLK_PTR         (  (reg8 *) POT_theACLK__PM_ACT_CFG )
    #define POT_STBY_PWRMGR_CLK_REG    (* (reg8 *) POT_theACLK__PM_STBY_CFG )
    #define POT_STBY_PWRMGR_CLK_PTR    (  (reg8 *) POT_theACLK__PM_STBY_CFG )
#endif /*End POT_DEFAULT_INTERNAL_CLK */


/**************************************
*       Register Constants
**************************************/
/* PM_ACT_CFG (Active Power Mode CFG Register) Power enable mask */
#define POT_ACT_PWR_SAR_EN             (uint8)(POT_ADC_SAR__PM_ACT_MSK)

/* PM_STBY_CFG (Alternate Active Power Mode CFG Register) Power enable mask */
#define POT_STBY_PWR_SAR_EN            (uint8)(POT_ADC_SAR__PM_STBY_MSK)

/* This is only valid if there is an internal clock */
#if(POT_DEFAULT_INTERNAL_CLK)
    /* Power enable mask */
    #define POT_ACT_PWR_CLK_EN         (uint8)(POT_theACLK__PM_ACT_MSK)
    /* Standby power enable mask */
    #define POT_STBY_PWR_CLK_EN        (uint8)(POT_theACLK__PM_STBY_MSK)
#endif /*End POT_DEFAULT_INTERNAL_CLK */

#if(POT_IRQ_REMOVE == 0u)

    /* Priority of the ADC_SAR_IRQ interrupt. */
    #define POT_INTC_PRIOR_NUMBER          (uint8)(POT_IRQ__INTC_PRIOR_NUM)

    /* ADC_SAR_IRQ interrupt number */
    #define POT_INTC_NUMBER                (uint8)(POT_IRQ__INTC_NUMBER)

#endif   /* End POT_IRQ_REMOVE */


/******************************************/
/* SAR.TR0 Trim Register 0 definitions    */
/******************************************/

/* Bit Field  SAR_CAP_TRIM_ENUM */
#define POT_SAR_CAP_TRIM_MASK          (0x07u)
#define POT_SAR_CAP_TRIM_0             (0x00u)    /*decrease attenuation capacitor by 0*/
#define POT_SAR_CAP_TRIM_1             (0x01u)    /*decrease by 0.5 LSB*/
#define POT_SAR_CAP_TRIM_2             (0x02u)    /*decrease by 2*0.5 LSB = 1 LSB*/
#define POT_SAR_CAP_TRIM_3             (0x03u)    /*decrease by 3*0.5 LSB = 1.5 LSB*/
#define POT_SAR_CAP_TRIM_4             (0x04u)    /*decrease by 4*0.5 LSB = 2 LSB*/
#define POT_SAR_CAP_TRIM_5             (0x05u)    /*decrease by 5*0.5 LSB = 2.5 LSB*/
#define POT_SAR_CAP_TRIM_6             (0x06u)    /*decrease by 6*0.5 LSB = 3 LSB*/
#define POT_SAR_CAP_TRIM_7             (0x07u)    /*decrease by 7*0.5 LSB = 3.5 LSB*/

#define POT_SAR_TRIMUNIT               (0x08u)    /*Increase by 6fF*/

/*******************************************************/
/* SAR.CSR0 Satatus and Control Register 0 definitions */
/*******************************************************/

/* Bit Field  SAR_ICONT_LV_ENUM */
#define POT_SAR_POWER_MASK             (0xC0u)
#define POT_SAR_POWER_SHIFT            (0x06u)
#define POT_ICONT_LV_0                 (0x00u)
#define POT_ICONT_LV_1                 (0x40u)
#define POT_ICONT_LV_2                 (0x80u)
#define POT_ICONT_LV_3                 (0xC0u)
#define POT_ICONT_FULL_CURRENT         (0x00u)

/* Bit Field SAR_RESET_SOFT_ENUM */
#define POT_SAR_RESET_SOFT_NOTACTIVE   (0x00u)
#define POT_SAR_RESET_SOFT_ACTIVE      (0x20u)

/* Bit Field  SAR_COHERENCY_EN_ENUM */
#define POT_SAR_COHERENCY_EN_NOLOCK    (0x00u)
#define POT_SAR_COHERENCY_EN_LOCK      (0x10u)

/* Bit Field  SAR_HIZ_ENUM */
#define POT_SAR_HIZ_RETAIN             (0x00u)
#define POT_SAR_HIZ_CLEAR              (0x08u)

/* Bit Field SAR_MX_SOF_ENUM */
#define POT_SAR_MX_SOF_BIT             (0x00u)
#define POT_SAR_MX_SOF_UDB             (0x04u)

/* Bit Field SAR_SOF_MODE_ENUM */
#define POT_SAR_SOF_MODE_LEVEL         (0x00u)
#define POT_SAR_SOF_MODE_EDGE          (0x02u)

/* Bit Field SAR_SOF_BIT_ENUM */
#define POT_SAR_SOF_STOP_CONV          (0x00u)            /* Disable conversion */
#define POT_SAR_SOF_START_CONV         (0x01u)            /* Enable conversion */

/*******************************************************/
/* SAR.CSR1 Satatus and Control Register 1 definitions */
/*******************************************************/

/* Bit Field  SAR_MUXREF_ENUM */
#define POT_SAR_MUXREF_MASK            (0xE0u)
#define POT_SAR_MUXREF_NONE            (0x00u)
#define POT_SAR_MUXREF_VDDA_2          (0x40u)
#define POT_SAR_MUXREF_DAC             (0x60u)
#define POT_SAR_MUXREF_1_024V          (0x80u)
#define POT_SAR_MUXREF_1_20V           (0xA0u)

/* Bit Field  SAR_SWVP_SRC_ENUM */
#define POT_SAR_SWVP_SRC_REG           (0x00u)
#define POT_SAR_SWVP_SRC_UDB           (0x10u)

/* Bit Field  SAR_SWVP_SRC_ENUM */
#define POT_SAR_SWVN_SRC_REG           (0x00u)
#define POT_SAR_SWVN_SRC_UDB           (0x08u)

/* Bit Field  SAR_IRQ_MODE_ENUM */
#define POT_SAR_IRQ_MODE_LEVEL         (0x00u)
#define POT_SAR_IRQ_MODE_EDGE          (0x04u)

/* Bit Field  SAR_IRQ_MASK_ENUM */
#define POT_SAR_IRQ_MASK_DIS           (0x00u)
#define POT_SAR_IRQ_MASK_EN            (0x02u)

/* Bit Field  SAR_EOF_ENUM */
#define POT_SAR_EOF_0                  (0x00u)
#define POT_SAR_EOF_1                  (0x01u)

/*******************************************************/
/* SAR.CSR2 Satatus and Control Register 2 definitions */
/*******************************************************/

/* Bit Field  SAR_RESOLUTION_ENUM */
#define POT_SAR_RESOLUTION_MASK        (0xC0u)
#define POT_SAR_RESOLUTION_SHIFT       (0x06u)
#define POT_SAR_RESOLUTION_12BIT       (0xC0u)
#define POT_SAR_RESOLUTION_10BIT       (0x80u)
#define POT_SAR_RESOLUTION_8BIT        (0x40u)

/* Bit Field SAR_SAMPLE_WIDTH_ENUM */
#define POT_SAR_SAMPLE_WIDTH_MASK      (0x3Fu)
#define POT_SAR_SAMPLE_WIDTH_MIN       (0x00u)   /* minimum sample time: +1 clock cycle */
#define POT_SAR_SAMPLE_WIDTH           (POT_SAMPLE_PRECHARGE - 0x02u)
#define POT_SAR_SAMPLE_WIDTH_MAX       (0x07u)   /* maximum sample time: +8 clock cycles */

/*******************************************************/
/* SAR.CSR3 Satatus and Control Register 3 definitions */
/*******************************************************/

/* Bit Field  SAR_EN_CP_ENUM */
#define POT_SAR_EN_CP_DIS              (0x00u)
#define POT_SAR_EN_CP_EN               (0x80u)

/* Bit Field  SAR_EN_RESVDA_ENUM */
#define POT_SAR_EN_RESVDA_DIS          (0x00u)
#define POT_SAR_EN_RESVDA_EN           (0x40u)

/* Bit Field  SAR_PWR_CTRL_VCM_ENUM */
#define POT_SAR_PWR_CTRL_VCM_MASK      (0x30u)
#define POT_SAR_PWR_CTRL_VCM_0         (0x00u)
#define POT_SAR_PWR_CTRL_VCM_1         (0x10u)
#define POT_SAR_PWR_CTRL_VCM_2         (0x20u)
#define POT_SAR_PWR_CTRL_VCM_3         (0x30u)

/* Bit Field  SAR_PWR_CTRL_VREF_ENUM */
#define POT_SAR_PWR_CTRL_VREF_MASK     (0x0Cu)
#define POT_SAR_PWR_CTRL_VREF_0        (0x00u)
#define POT_SAR_PWR_CTRL_VREF_DIV_BY2  (0x04u)
#define POT_SAR_PWR_CTRL_VREF_DIV_BY3  (0x08u)
#define POT_SAR_PWR_CTRL_VREF_DIV_BY4  (0x0Cu)

/* Bit Field  SAR_EN_BUF_VCM_ENUM */
#define POT_SAR_EN_BUF_VCM_DIS         (0x00u)
#define POT_SAR_EN_BUF_VCM_EN          (0x02u)

/* Bit Field  SAR_EN_BUF_VREF_ENUM */
#define POT_SAR_EN_BUF_VREF_DIS        (0x00u)
#define POT_SAR_EN_BUF_VREF_EN         (0x01u)

/*******************************************************/
/* SAR.CSR4 Satatus and Control Register 4 definitions */
/*******************************************************/

/* Bit Field  SAR_DFT_INC_ENUM */
#define POT_SAR_DFT_INC_MASK           (0x0Fu)
#define POT_SAR_DFT_INC_DIS            (0x00u)
#define POT_SAR_DFT_INC_EN             (0x0Fu)

/* Bit Field  SAR_DFT_INC_ENUM */
#define POT_SAR_DFT_OUTC_MASK          (0x70u)
#define POT_SAR_DFT_OUTC_DIS           (0x00u)
#define POT_SAR_DFT_OUTC_EN            (0x70u)

/*******************************************************/
/* SAR.CSR5 Satatus and Control Register 5 definitions */
/*******************************************************/

/* Bit Field  SAR_OVERRUN_DET_EN_ENUM */
#define POT_SAR_OVERRUN_DET_EN_EN      (0x80u)

/* Bit Field  SAR_DLY_INC_ENUM */
#define POT_SAR_DLY_INC                (0x40u)

/* Bit Field  SAR_DCEN_ENUM */
#define POT_SAR_DCEN                   (0x20u)

/* Bit Field  SAR_EN_CSEL_DFT_ENUM */
#define POT_SAR_EN_CSEL_DFT_DISABLED   (0x00u)
#define POT_SAR_EN_CSEL_DFT_ENABLED    (0x10u)

/* Bit Field  SAR_SEL_CSEL_DFT_ENUM */
#define POT_SAR_SEL_CSEL_DFT_MASK      (0x0Fu)
#define POT_SAR_SEL_CSEL_DFT_MIN       (0x00u)
#define POT_SAR_SEL_CSEL_DFT_MAX       (0x0Fu)
#define POT_SAR_SEL_CSEL_DFT_CHAR      (0x03u)

/*******************************************************/
/* SAR.CSR6 Satatus and Control Register 6 definitions */
/*******************************************************/
#define POT_INT_VREF                   (0x18u)
#define POT_INT_BYPASS_EXT_VREF        (0x04u)
#define POT_VDDA_VREF                  (0x80u)

/*******************************************************/
/* SAR.CSR7 Satatus and Control Register 7 definitions */
/*******************************************************/

/* Bit Field  SAR_REF_S_ENUM */
#define POT_SAR_REF_S_MSB_MASK         (0x3Fu)
#define POT_SAR_REF_S_MSB_DIS          (0x00u)
#define POT_SAR_REF_S8_MSB_DIS         (0x01u)
#define POT_SAR_REF_S9_MSB_EN          (0x02u)
#define POT_SAR_REF_S10_MSB_EN         (0x04u)
#define POT_SAR_REF_S11_MSB_EN         (0x08u)
#define POT_SAR_REF_S12_MSB_EN         (0x10u)
#define POT_SAR_REF_S13_MSB_EN         (0x20u)

/*******************************************************/
/* SAR.CLK SAR Clock Selection Register definitions    */
/*******************************************************/

/* Bit Field  MX_PUMPCLK_ENUM */
#define POT_SAR_MX_PUMPCLK_MASK        (0xE0u)
#define POT_SAR_MX_PUMPCLK_0           (0x00u)
#define POT_SAR_MX_PUMPCLK_1           (0x20u)
#define POT_SAR_MX_PUMPCLK_2           (0x40u)
#define POT_SAR_MX_PUMPCLK_3           (0x60u)
#define POT_SAR_MX_PUMPCLK_4           (0x80u)

/* Bit Field  BYPASS_SYNC_ENUM */
#define POT_SAR_BYPASS_SYNC_0          (0x00u)
#define POT_SAR_BYPASS_SYNC_1          (0x10u)

/* Bit Field  MX_CLK_EN_ENUM */
#define POT_SAR_MX_CLK_EN              (0x08u)

/* Bit Field  MX_CLK_ENUM  */
#define POT_SAR_MX_CLK_MASK            (0x07u)
#define POT_SAR_MX_CLK_0               (0x00u)
#define POT_SAR_MX_CLK_1               (0x01u)
#define POT_SAR_MX_CLK_2               (0x02u)
#define POT_SAR_MX_CLK_3               (0x03u)
#define POT_SAR_MX_CLK_4               (0x04u)

/*********************************************************/
/* ANAIF.WRK.SARS.SOF SAR Global Start-of-frame register */
/*********************************************************/

/* Bit Field  SAR_SOF_BIT_ENUM */
#define POT_SAR_SOFR_BIT_MASK          (0x03u)
#define POT_SAR_SOFR_BIT_0             (0x00u)
#define POT_SAR_SOFR_BIT_1             (0x01u)

/***********************************************/
/* SAR.SW3 SAR Analog Routing Register 3       */
/***********************************************/
#define POT_SAR_VP_VSSA                (0x04u)
#define POT_SAR_VN_AMX                 (0x10u)
#define POT_SAR_VN_VREF                (0x20u)
#define POT_SAR_VN_VSSA                (0x40u)
#define POT_SAR_VN_MASK                (0x60u)

/***********************************************/
/* SAR.WRKx SAR Working Register               */
/***********************************************/
#define POT_SAR_WRK_MAX                (0xFFFu)
#define POT_SAR_DIFF_SHIFT             (0x800u)

/* Absolute maximum counts equivalent reference voltage */
#define POT_SAR_WRK_MAX_12BIT          (0x00001000Lu)
#define POT_SAR_WRK_MAX_10BIT          (0x00000400Lu)
#define POT_SAR_WRK_MAX_8BIT           (0x00000100Lu)


#endif /* End CY_ADC_SAR_POT_H */


/* [] END OF FILE */
