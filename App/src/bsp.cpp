//-------------------------------------------------------------------------------------------------
//
//  File : bsp.cpp
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

//------ Note(s) ----------------------------------------------------------------------------------
//
//  BSP - Board support package for STM32F4-DISCO
//
//  this board has 128K RAM in CPU
//                 64K CCRAM in CPU
//
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
// Include file(s)
//-------------------------------------------------------------------------------------------------

#define BSP_GLOBAL
#include "bsp.h"
#undef  BSP_GLOBAL
#include "task_main.h"
#include "task_usb_host.h"


//-------------------------------------------------------------------------------------------------
// Const(s)
//-------------------------------------------------------------------------------------------------

// because for now we don't have eeprom for this test board
const TempUnit_e T_Unit = TEMP_CELSIUS;
const SystemDebugLevel_e DebugLvl = SYS_DEBUG_LEVEL_APPLICATION;
const Language_e Lang = LANG_ENGLISH;

//-------------------------------------------------------------------------------------------------
// Function(s)
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
//
//  Name:           BSP_Initialize
//  Parameter(s):   void
//  Return:         void
//
//  Description:    This function should be called by your application before anything else
//
//  Note(s):
//
//-------------------------------------------------------------------------------------------------
void BSP_Initialize(void)
{
    myADC2_Driver.Initialize();
    myTIM_LCD_Backlight.Initialize();
    myPWM_LCD_Backlight.Initialize();

    myPWM_LCD_Backlight.Start();
    myPWM_LCD_Backlight.SetDuty(20);
    myPWM_LCD_Backlight.SetDuty(21);
    //myPWM_LCD_Backlight.SetDuty(22);
    //myPWM_LCD_Backlight.SetDuty(23);
    //myPWM_LCD_Backlight.SetDuty(24);
    myPWM_LCD_Backlight.SetDuty(100);

    DIGINI_Initialize();
}

//-------------------------------------------------------------------------------------------------
//
//  Name:           BSP_PostOS_Initialize
//  Parameter(s):   void
//  Return:         SystemState_e       SystemState
//
//  Description:    This function should be called by your application After OS has being started
//
//  Note(s):        Example: class or driver using Semaphore
//
//-------------------------------------------------------------------------------------------------
SystemState_e BSP_PostOS_Initialize(void)
{
    SystemState_e State = SYS_READY;

    State = DIGINI_PostInitialize();
    pMainTask->Initialize();

  #if (USE_USB_DRIVER == DEF_ENABLED)
	pUSB_HostTask->Initialize();
  #endif

    return State;
}

//-------------------------------------------------------------------------------------------------
