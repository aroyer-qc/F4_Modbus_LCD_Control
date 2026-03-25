//-------------------------------------------------------------------------------------------------
//
//  File :  dac_cfg.h
//
//-------------------------------------------------------------------------------------------------
//
// Copyright(c) 2026 Alain Royer.
// Email: aroyer.qc@gmail.com
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software
// and associated documentation files (the "Software"), to deal in the Software without
// restriction, including without limitation the rights to use, copy, modify, merge, publish,
// distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or
// substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
// INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
// AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//
//-------------------------------------------------------------------------------------------------
//
//  Notes: DAC configuration for STM32F746NG
//
//-------------------------------------------------------------------------------------------------

#pragma once

//-------------------------------------------------------------------------------------------------
// Global Define(s)
//-------------------------------------------------------------------------------------------------

#define CFG_DAC_DRIVER_CHANNEL_1                    DEF_ENABLED
#define CFG_DAC_DRIVER_SUPPORT_DMA_CHANNEL_1        DEF_DISABLED
#define CFG_DAC_DRIVER_CHANNEL_2                    DEF_DISABLED
#define CFG_DAC_DRIVER_SUPPORT_DMA_CHANNEL_2        DEF_DISABLED

#define CFG_DAC_CH1_TRIGGER                         DAC_TRIGGER_NONE
#define CFG_DAC_CH1_WAVE_GENERATION                 DAC_WAVE_GENERATION_NONE
#define CFG_DAC_CH1_LFSR_UNMASK_TRIANGLE_AMPLITUDE  DAC_TRIANGLE_AMPLITUDE_1
#define CFG_DAC_CH1_OUTPUT_BUFFER                   DAC_OUTPUT_BUFFER_ENABLE
#define CFG_DAC_CH1_DATA_HOLDING_REGISTER           DAC->DHR8R1                     // Can be DAC->DHR12R1, DAC->DHR8L1, DAC->DHR8R1

#define CFG_DAC_CH1_DMA_MODE                        DMA_MODE_NORMAL                 //  DMA_MODE_NORMAL or DMA_MODE_CIRCULAR
#define CFG_DAC_CH1_DMA_PERIPHERAL_SIZE             DMA_PERIPHERAL_SIZE_8_BITS      //  DMA_PERIPHERAL_SIZE_8_BITS or DMA_PERIPHERAL_SIZE_16_BITS
#define CFG_DAC_CH1_DMA_MEMORY_SIZE                 DMA_MEMORY_SIZE_8_BITS          //  DMA_MEMORY_SIZE_8_BITS or DMA_MEMORY_SIZE_16_BITS 

#define CFG_DAC_CH2_TRIGGER                         DAC_TRIGGER_NONE
#define CFG_DAC_CH2_WAVE_GENERATION                 DAC_WAVE_GENERATION_NONE
#define CFG_DAC_CH2_LFSR_UNMASK_TRIANGLE_AMPLITUDE  DAC_TRIANGLE_AMPLITUDE_1
#define CFG_DAC_CH2_OUTPUT_BUFFER                   DAC_OUTPUT_BUFFER_ENABLE
#define CFG_DAC_CH2_DATA_HOLDING_REGISTER           DAC->DHR8R2                     // Can be DAC->DHR12R2, DAC->DHR8L2, DAC->DHR8R2

#define CFG_DAC_CH2_DMA_MODE                        DMA_MODE_NORMAL                 //  DMA_MODE_NORMAL or DMA_MODE_CIRCULAR
#define CFG_DAC_CH2_DMA_PERIPHERAL_SIZE             DMA_PERIPHERAL_SIZE_8_BITS      //  DMA_PERIPHERAL_SIZE_8_BITS or DMA_PERIPHERAL_SIZE_16_BITS
#define CFG_DAC_CH2_DMA_MEMORY_SIZE                 DMA_MEMORY_SIZE_8_BITS          //  DMA_MEMORY_SIZE_8_BITS or DMA_MEMORY_SIZE_16_BITS

//-------------------------------------------------------------------------------------------------

