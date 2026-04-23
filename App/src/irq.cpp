//-------------------------------------------------------------------------------------------------
//
//  File : irq.cpp
//
//-------------------------------------------------------------------------------------------------
//
// Copyright(c) 2024 Alain Royer.
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

//-------------------------------------------------------------------------------------------------
// Include file(s)
//-------------------------------------------------------------------------------------------------

#include "bsp.h"

//-------------------------------------------------------------------------------------------------

extern "C"
{

//-------------------------------------------------------------------------------------------------
//
//  DDDDD  MM    MM  AAAA
//  DD  DD MMM  MMM AA  AA
//  DD  DD MMMMMMMM AAAAAA
//  DD  DD MM MM MM AA  AA
//  DDDDD  MM    MM AA  AA
//
//-------------------------------------------------------------------------------------------------

NOS_ISR(DMA2_Stream6_IRQHandler)
{
	myUART_Terminal.DMA_TX_IRQ_Handler();
}

NOS_ISR(DMA2_Stream0_IRQHandler)
{
	SPI_Driver::DMA_RX_IRQ_Handler(DRIVER_SPI2_ID);
}

NOS_ISR(DMA2_Stream3_IRQHandler)
{
	SPI_Driver::DMA_TX_IRQ_Handler(DRIVER_SPI2_ID);
}

//-------------------------------------------------------------------------------------------------
//
//   SSSSS  PPPPP  IIII
//  SS      PP  PP  II
//   SSSSS  PPPPPP  II
//       SS PP      II
//   SSSSS  PP     IIII
//
//-------------------------------------------------------------------------------------------------
#if (USE_SPI_DRIVER == DEF_ENABLED)
//NOS_ISR(SPI2_IRQHandler)
//{
    //mySPI_ForDAC.IRQ_Handler();
 //   mySPI_ForVFD.IRQ_Handler();
//}

#endif

//-------------------------------------------------------------------------------------------------
//
//  UU  UU  AAAA  RRRRR  TTTTTT
//  UU  UU AA  AA RR  RR   TT
//  UU  UU AAAAAA RRRRR    TT
//  UU  UU AA  AA RR RR    TT
//   UUUU  AA  AA RR  RR   TT
//
//-------------------------------------------------------------------------------------------------

NOS_ISR(USART6_IRQHandler)
{
    myUART_Terminal.IRQ_Handler();
}

//-------------------------------------------------------------------------------------------------
/*
__attribute__((naked))
void MemManage_Handler(void)
{
    __asm volatile
    (
        "tst lr, #4        \n"
        "ite eq            \n"
        "mrseq r0, msp     \n"
        "mrsne r0, psp     \n"
        "b Fault_C     \n"
    );
}

__attribute__((naked))
void BusFault_Handler(void)
{
    __asm volatile
    (
        "tst lr, #4        \n"
        "ite eq            \n"
        "mrseq r0, msp     \n"
        "mrsne r0, psp     \n"
        "b Fault_C     \n"
    );
}

__attribute__((naked))
void HardFault_Handler(void)
{
    __asm volatile
    (
        "tst lr, #4        \n"
        "ite eq            \n"
        "mrseq r0, msp     \n"
        "mrsne r0, psp     \n"
        "b Fault_C     \n"
    );
}

__attribute__((naked))
void UsageFault_Handler(void)
{
    __asm volatile
    (
        "tst lr, #4        \n"
        "ite eq            \n"
        "mrseq r0, msp     \n"
        "mrsne r0, psp     \n"
        "b Fault_C         \n"
    );
}


void Fault_C(uint32_t *stack)
{
    volatile uint32_t r0  = stack[0];
    volatile uint32_t r1  = stack[1];
    volatile uint32_t r2  = stack[2];
    volatile uint32_t r3  = stack[3];
    volatile uint32_t r12 = stack[4];
    volatile uint32_t lr  = stack[5];
    volatile uint32_t pc  = stack[6];
    volatile uint32_t psr = stack[7];

volatile uint32_t cfsr = SCB->CFSR;

    while (1)
    {
        __asm("nop");
    }
}
*/
//-------------------------------------------------------------------------------------------------

} // extern "C"

//-------------------------------------------------------------------------------------------------
