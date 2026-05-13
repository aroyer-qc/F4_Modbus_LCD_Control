//-------------------------------------------------------------------------------------------------
//
//  File : task_usb_host.h
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

#pragma once

//-------------------------------------------------------------------------------------------------

#include "./USB_Host/Core/Inc/usbh_core.h"
#include "./USB_Host/Class/MSC/Inc/usbh_msc.h"
#include "./module_STM32F4xx/Inc/stm32f4xx_hal_hcd.h"

//-------------------------------------------------------------------------------------------------
// Global Macro
//-------------------------------------------------------------------------------------------------

#ifdef TASK_USB_HOST_GLOBAL
    #define TASK_USB_HOST_EXTERN
#else
    #define TASK_USB_HOST_EXTERN extern
#endif


// will need according to feature user want to enable or disable code section

//-------------------------------------------------------------------------------------------------
// Define(s)
//-------------------------------------------------------------------------------------------------

#define TASK_USB_HOST_STACK_SIZE	1024
#define TASK_USB_HOST_PRIO			7

// ---------------------------------------------------------------------------------------------------------

// Status of the application.
typedef enum
{
  APPLICATION_IDLE = 0,
  APPLICATION_START,
  APPLICATION_READY,
  APPLICATION_DISCONNECT
} ApplicationTypeDef;

//-------------------------------------------------------------------------------------------------
// Class definition(s)
//-------------------------------------------------------------------------------------------------

class TaskUSB_Host
{
    public:

								TaskUSB_Host                    ()                      {};
							   ~TaskUSB_Host                    ()                      {};

        SystemState_e   		Initialize                  	(void);
        void            		Run                         	(void);
		ApplicationTypeDef      GetState                    	(void)                          			{ return m_ApplicationState; }
        MSC_LUNTypeDef*         GetLUN_Info                     (void)                                      { return &m_LUN_Info; }

        static TaskUSB_Host*	GetInstance         			(void)                          			{ return TaskUSB_Host::m_Instance; }

    private:

		void    				USBH_UserProcess    			(USBH_HandleTypeDef* pHost, uint8_t ID);
        void    				MSC_Process		     			(void);

		static void 			USBH_UserProcessCallBack		(USBH_HandleTypeDef *pHost, uint8_t ID);


        nOS_Thread              m_Handle;
        nOS_Stack               m_Stack                     	[TASK_USB_HOST_STACK_SIZE];

		//bool					m_CDC_Connected;
		//bool					m_HID_Connected;
		bool					m_MSC_Connected;

        ApplicationTypeDef  	m_ApplicationState;
        USBH_HandleTypeDef  	m_HandleUSB_HostFS;
		MSC_LUNTypeDef		 	m_LUN_Info;

		static TaskUSB_Host*	m_Instance;
};

//-------------------------------------------------------------------------------------------------
// Global variable(s) and constant(s)
//-------------------------------------------------------------------------------------------------

#ifdef TASK_USB_HOST_GLOBAL
    TaskUSB_Host          	USB_HostTask;
    TaskUSB_Host*           pUSB_HostTask = &USB_HostTask;
#else
    extern TaskUSB_Host*    pUSB_HostTask;
#endif

//-------------------------------------------------------------------------------------------------

#if 0

class DiskIO_USBMSC : public DiskIO_DeviceInterface
{
public:
    virtual DSTATUS Initialize();
    virtual DSTATUS Status();
    virtual DRESULT Read(uint8_t* pBuffer, uint32_t Sector, uint16_t Count);
    virtual DRESULT Write(const uint8_t* pBuffer, uint32_t Sector, uint16_t Count);
    virtual DRESULT IO_Ctrl(uint8_t Command, void* pBuffer);
};


DSTATUS DiskIO_USBMSC::Initialize()
{
    if(USBH_MSC_IsReady(&hUsbHostFS))
        return RES_OK;

    return STA_NOINIT;
}

DSTATUS DiskIO_USBMSC::Status()
{
    return USBH_MSC_IsReady(&hUsbHostFS) ? RES_OK : STA_NOINIT;
}

DRESULT DiskIO_USBMSC::Read(uint8_t* pBuffer, uint32_t Sector, uint16_t Count)
{
    if(USBH_MSC_Read(&hUsbHostFS, 0, pBuffer, Sector, Count) == USBH_OK)
        return RES_OK;

    return RES_ERROR;
}

DRESULT DiskIO_USBMSC::Write(const uint8_t* pBuffer, uint32_t Sector, uint16_t Count)
{
    if(USBH_MSC_Write(&hUsbHostFS, 0, (uint8_t*)pBuffer, Sector, Count) == USBH_OK)
        return RES_OK;

    return RES_ERROR;
}

DRESULT DiskIO_USBMSC::IO_Ctrl(uint8_t Command, void* pBuffer)
{
    switch(Command)
    {
        case CTRL_SYNC:
            return RES_OK;

        case GET_SECTOR_COUNT:
        {
            USBH_MSC_LUNTypeDef info;
            USBH_MSC_GetLUNInfo(&hUsbHostFS, 0, &info);
            *(DWORD*)pBuffer = info.capacity.block_nbr;
            return RES_OK;
        }

        case GET_SECTOR_SIZE:
        {
            USBH_MSC_LUNTypeDef info;
            USBH_MSC_GetLUNInfo(&hUsbHostFS, 0, &info);
            *(WORD*)pBuffer = info.capacity.block_size;
            return RES_OK;
        }

        case GET_BLOCK_SIZE:
            *(DWORD*)pBuffer = 1;
            return RES_OK;
    }

    return RES_PARERR;
}

DiskIO::GetInstance().RegisterDrive(DISK_USB, new DiskIO_USBMSC());
ou la macro.
#endif
