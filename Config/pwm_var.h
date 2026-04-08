//-------------------------------------------------------------------------------------------------
//
//  File :  pwm_var.h
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
//  PWM variables for STM32F4xx
//
//  Notes : List of all the PWM channel use in this application
//          Prescaler value and reload are in the "tim_var.h" file
//
//-------------------------------------------------------------------------------------------------

#ifdef PWM_DRIVER_GLOBAL

const PWM_Info_t PWM_Info[NB_OF_PWM_CHANNEL] =
{
    // PWM_LCD_BACKLIGHT
    {
        IO_LCD_TFT_BL_PWM,                      // IO of the channel
        LCD_BACKLIGHT_TIMER,                    // ID of the timer for this channel
        TIM_CHANNEL_1,                          // Channel on the timer
        50,                                     // Initial duty of the PWM
    },
};
//use it in the x-macro mode
class PWM_Driver myPWM_LCD_Backlight(PWM_LCD_BACKLIGHT, &myTIM_LCD_Backlight);

#else // PWM_DRIVER_GLOBAL

extern const PWM_Info_t PWM_Info[NB_OF_PWM_CHANNEL];
extern class PWM_Driver myPWM_LCD_Backlight;

#endif // PWM_DRIVER_GLOBAL

//-------------------------------------------------------------------------------------------------
