//-------------------------------------------------------------------------------------------------
//
//  File :  tim_var.h
//
//-------------------------------------------------------------------------------------------------
//
// Copyright(c) 2020 Alain Royer.
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
//  Notes : TIM variables for STM32F4xx
//
//-------------------------------------------------------------------------------------------------

#ifdef TIM_DRIVER_GLOBAL

const TIM_Info_t TIM_Info[NB_OF_TIM_DRIVER] =
{
  #if (TIM_DRIVER_SUPPORT_TIM2_CFG == DEF_ENABLED)
    {
        TIM2,                                   // TIMx
        RCC_APB1ENR_TIM2EN,                     // RCC_APBxENR
        &RCC->APB1ENR,                          // Register
        ISR_NONE_IRQn,                          // IRQn_Channel
        7,                                      // PreempPrio
        LCD_BACKLIGHT_MODE,                     // See note for 7th parameter
        LCD_BACKLIGHT_PRESCALER,               	// Prescaler
        LCD_BACKLIGHT_RELOAD,	        	    // Reload
        TIM_IRQ_DMA_NO_SOURCE,
    },
  #endif
};

class TIM_Driver myTIM_LCD_Backlight(LCD_BACKLIGHT_TIMER);

#else // TIM_DRIVER_GLOBAL

extern const TIM_Info_t TIM_Info[NB_OF_TIM_DRIVER];
extern class TIM_Driver myTIM_LCD_Backlight;

#endif // TIM_DRIVER_GLOBAL

//-------------------------------------------------------------------------------------------------
