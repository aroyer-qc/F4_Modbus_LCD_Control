//-------------------------------------------------------------------------------------------------
//
//  File : TaskIdle.cpp
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

//-------------------------------------------------------------------------------------------------
// Include file(s)
//-------------------------------------------------------------------------------------------------

#define TASK_IDLE_GLOBAL
#include "TaskIdle.h"
#undef  TASK_IDLE_GLOBAL
#include "bsp.h"
#include "./lib_digini.h"

//-------------------------------------------------------------------------------------------------
// Define(s)
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
// Variable(s) and constant(s)
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
// Function(s)
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
//
//  Name:           TaskIdle
//
//  Parameter(s):   none
//  Return:         void
//
//  Description:    main() for the idle task
//
//  Note(s):
//
//-------------------------------------------------------------------------------------------------
void TaskIdle(void)
{
    CRC_Driver Poutine;
    CRC_Driver Poutine2;

    Poutine.Initialize(CRC32_HW_MPEG_2);
    Poutine2.Initialize(CRC32_HW_MPEG_2);

    // --------------------------------------------------------------------------------------------
    // Low level main control loop
    while(1)
    {
        LIB_Delay_mSec(200);
        //nOS_Sleep(1);
    }
}
