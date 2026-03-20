//-------------------------------------------------------------------------------------------------
//
//  File : task_main.cpp
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

//-------------------------------------------------------------------------------------------------
// Include file(s)
//-------------------------------------------------------------------------------------------------

#define TASK_MAIN_GLOBAL
#include "./lib_digini.h"
#undef  TASK_MAIN_GLOBAL
#include "task_main.h"

//-------------------------------------------------------------------------------------------------
//
//  Name:           TaskMain_Wrapper
//
//  Parameter(s):   void* pvParameters
//  Return:         void
//
//  Description:    main() for the TaskMain
//
//  Note(s):
//
//-------------------------------------------------------------------------------------------------
extern "C" void TaskMain_Wrapper(void* pvParameters)
{
    (static_cast<TaskMain*>(pvParameters))->Run();
}

//-------------------------------------------------------------------------------------------------
//
//  Name:           Initialize
//
//  Parameter(s):   void
//  Return:         nOS_Error
//
//  Description:    Initialize
//
//  Note(s):
//
//-------------------------------------------------------------------------------------------------
SystemState_e TaskMain::Initialize(void)
{
    nOS_Error Error = NOS_OK;

     DEBUG_PrintSerialLog(SYS_DEBUG_LEVEL_APPLICATION, "Initializing TaskMain\n");

    Error = nOS_ThreadCreate(&m_Handle,
                             TaskMain_Wrapper,
                             this,
                             &m_Stack[0],
                             TASK_MAIN_STACK_SIZE,
                             TASK_MAIN_PRIO,
                             "Task Main");

    return (Error != NOS_OK) ? SYS_ERROR : SYS_READY;
}

//-------------------------------------------------------------------------------------------------
//
//  Name:           Run
//
//  Parameter(s):   void
//  Return:         void
//
//  Description:    main() loop of Main
//
//-------------------------------------------------------------------------------------------------
void TaskMain::Run(void)
{
    for(;;)
    {
        nOS_Sleep(10);
        LED_Toggle(IO_LED_GREEN_STATUS);
    }
}

//-------------------------------------------------------------------------------------------------
