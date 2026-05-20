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

#include "./lib_digini.h"
#define TASK_MAIN_GLOBAL
#include "task_main.h"
#undef  TASK_MAIN_GLOBAL

//-------------------------------------------------------------------------------------------------
// Define(s)
//-------------------------------------------------------------------------------------------------

#define MODBUS_REQUEST_DELAY    1000

bool CheckAndFormatDrive(uint8_t drive);

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
    TickCount_t Tick = GetTick();

	// Check if the drive has a file system, then if no error but it has no file system it will be formatted.
	CheckAndFormatDrive(DISK_SPI_FLASH);
	CheckAndFormatDrive(DISK_USB_KEY);

    for(;;)
    {
        nOS_Sleep(200);
        LED_Toggle(IO_LED_GREEN_STATUS);

        if(TickHasTimeOut(Tick, MODBUS_REQUEST_DELAY) == true)
        {
            Tick = GetTick();
            myMODBUS_Application.MasterRequest(0, 200, 10);
        }

    }
}

//-------------------------------------------------------------------------------------------------
// support function... must be move into service call for FatFs
bool CheckAndFormatDrive(uint8_t drive)
{
    FATFS fs;
    FATFS* pfs;
    DWORD freeClusters;

    char path[4];
    snprintf(path, sizeof(path), "%u:", drive);

    // Tentative de montage
    FRESULT res = f_mount(&fs, path, 1);

    if (res != FR_OK)
    {
        // failed to mount -> Do not format
        return false;
    }

    //  Check if drive is formatted
    res = f_getfree(path, &freeClusters, &pfs);

    if (res == FR_OK)
    {
        // The drive is formatted -> OK
        f_mount(NULL, path, 1);
        return true;
    }

    if (res == FR_NO_FILESYSTEM)
    {
        DRESULT dres = FatFS_DiskIO.IO_Ctrl((DiskMedia_e)drive, CTRL_FORMAT, nullptr);
        f_mount(NULL, path, 1);
        return (dres == RES_OK);
    }

    // any other error -> Do not format
    f_mount(NULL, path, 1);
    return false;
}
