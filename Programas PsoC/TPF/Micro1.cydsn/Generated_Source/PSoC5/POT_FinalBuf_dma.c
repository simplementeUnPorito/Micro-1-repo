/***************************************************************************
* File Name: POT_FinalBuf_dma.c  
* Version 1.70
*
*  Description:
*   Provides an API for the DMAC component. The API includes functions
*   for the DMA controller, DMA channels and Transfer Descriptors.
*
*
*   Note:
*     This module requires the developer to finish or fill in the auto
*     generated funcions and setup the dma channel and TD's.
*
********************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/
#include <CYLIB.H>
#include <CYDMAC.H>
#include <POT_FinalBuf_dma.H>



/****************************************************************************
* 
* The following defines are available in Cyfitter.h
* 
* 
* 
* POT_FinalBuf__DRQ_CTL_REG
* 
* 
* POT_FinalBuf__DRQ_NUMBER
* 
* Number of TD's used by this channel.
* POT_FinalBuf__NUMBEROF_TDS
* 
* Priority of this channel.
* POT_FinalBuf__PRIORITY
* 
* True if POT_FinalBuf_TERMIN_SEL is used.
* POT_FinalBuf__TERMIN_EN
* 
* TERMIN interrupt line to signal terminate.
* POT_FinalBuf__TERMIN_SEL
* 
* 
* True if POT_FinalBuf_TERMOUT0_SEL is used.
* POT_FinalBuf__TERMOUT0_EN
* 
* 
* TERMOUT0 interrupt line to signal completion.
* POT_FinalBuf__TERMOUT0_SEL
* 
* 
* True if POT_FinalBuf_TERMOUT1_SEL is used.
* POT_FinalBuf__TERMOUT1_EN
* 
* 
* TERMOUT1 interrupt line to signal completion.
* POT_FinalBuf__TERMOUT1_SEL
* 
****************************************************************************/


/* Zero based index of POT_FinalBuf dma channel */
uint8 POT_FinalBuf_DmaHandle = DMA_INVALID_CHANNEL;

/*********************************************************************
* Function Name: uint8 POT_FinalBuf_DmaInitalize
**********************************************************************
* Summary:
*   Allocates and initialises a channel of the DMAC to be used by the
*   caller.
*
* Parameters:
*   BurstCount.
*       
*       
*   ReqestPerBurst.
*       
*       
*   UpperSrcAddress.
*       
*       
*   UpperDestAddress.
*       
*
* Return:
*   The channel that can be used by the caller for DMA activity.
*   DMA_INVALID_CHANNEL (0xFF) if there are no channels left. 
*
*
*******************************************************************/
uint8 POT_FinalBuf_DmaInitialize(uint8 BurstCount, uint8 ReqestPerBurst, uint16 UpperSrcAddress, uint16 UpperDestAddress) 
{

    /* Allocate a DMA channel. */
    POT_FinalBuf_DmaHandle = (uint8)POT_FinalBuf__DRQ_NUMBER;

    /* Configure the channel. */
    (void)CyDmaChSetConfiguration(POT_FinalBuf_DmaHandle,
                                  BurstCount,
                                  ReqestPerBurst,
                                  (uint8)POT_FinalBuf__TERMOUT0_SEL,
                                  (uint8)POT_FinalBuf__TERMOUT1_SEL,
                                  (uint8)POT_FinalBuf__TERMIN_SEL);

    /* Set the extended address for the transfers */
    (void)CyDmaChSetExtendedAddress(POT_FinalBuf_DmaHandle, UpperSrcAddress, UpperDestAddress);

    /* Set the priority for this channel */
    (void)CyDmaChPriority(POT_FinalBuf_DmaHandle, (uint8)POT_FinalBuf__PRIORITY);
    
    return POT_FinalBuf_DmaHandle;
}

/*********************************************************************
* Function Name: void POT_FinalBuf_DmaRelease
**********************************************************************
* Summary:
*   Frees the channel associated with POT_FinalBuf.
*
*
* Parameters:
*   void.
*
*
*
* Return:
*   void.
*
*******************************************************************/
void POT_FinalBuf_DmaRelease(void) 
{
    /* Disable the channel */
    (void)CyDmaChDisable(POT_FinalBuf_DmaHandle);
}

