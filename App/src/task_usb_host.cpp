//-------------------------------------------------------------------------------------------------
//
//  File : task_usb_host.cpp
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
#define TASK_USB_HOST_GLOBAL
#include "task_usb_host.h"
#undef  TASK_USB_HOST_GLOBAL

//-------------------------------------------------------------------------------------------------
// Define(s)
//-------------------------------------------------------------------------------------------------

#define TASK_USB_HOST_SLEEP			2
#define TASK_USB_HOST_STACK_SIZE	1024
#define TASK_USB_HOST_PRIO			7

#define TASK_USB_HOST_FS  			0

//-------------------------------------------------------------------------------------------------

TaskUSB_Host* TaskUSB_Host::m_Instance = nullptr;

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
extern "C" void TaskUSB_Host_Wrapper(void* pvParameters)
{
    (static_cast<TaskUSB_Host*>(pvParameters))->Run();
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
SystemState_e TaskUSB_Host::Initialize(void)
{
    nOS_Error Error = NOS_OK;

    DEBUG_PrintSerialLog(SYS_DEBUG_LEVEL_APPLICATION, "Initializing TaskUSB_Host\n");

    Error = nOS_ThreadCreate(&m_Handle,
                             TaskUSB_Host_Wrapper,
                             this,
                             &m_Stack[0],
                             TASK_USB_HOST_STACK_SIZE,
                             TASK_USB_HOST_PRIO,
                             "Task USB Host");

    TaskUSB_Host::m_Instance = this;
	//m_CDC_Connected          = false;
	//m_HID_Connected          = false;
	m_MSC_Connected          = false;
    m_ApplicationState     	 = APPLICATION_IDLE;
    memset(&m_LUN_Info, 0, sizeof(MSC_LUNTypeDef));


    return (Error != NOS_OK) ? SYS_ERROR : SYS_READY;
}

//-------------------------------------------------------------------------------------------------
//
//  Name:           Run
//
//  Parameter(s):   void
//  Return:         void
//
//  Description:    main() loop of TaskUSB_Host
//
//-------------------------------------------------------------------------------------------------
void TaskUSB_Host::Run(void)
{
    //TickCount_t Tick = GetTick();

    // Init host Library, add supported class and start the library.
    if(USBH_Init(&m_HandleUSB_HostFS, &TaskUSB_Host::USBH_UserProcessCallBack, TASK_USB_HOST_FS) != USBH_OK)
    {
        __asm("nop");
    }

    if(USBH_RegisterClass(&m_HandleUSB_HostFS, USBH_MSC_CLASS) != USBH_OK)
    {
        __asm("nop");
    }

	//USBH_RegisterClass(&m_HandleUSB_HostFS, USBH_CDC_CLASS);
    //USBH_RegisterClass(&m_HandleUSB_HostFS, USBH_HID_CLASS);

    if(USBH_Start(&m_HandleUSB_HostFS) != USBH_OK)
    {
        __asm("nop");
    }

//    (" **** USB FS Host **** ");
//    ("USB Host library started.");
//    ("Starting MSC Application");

    for(;;)
    {
        USBH_Process(&m_HandleUSB_HostFS);
        MSC_Process();
		//CDC_Process();
        //HID_Process();
        nOS_Sleep(TASK_USB_HOST_SLEEP);
    }
}


// ---------------------------------------------------------------------------------------------------------

void TaskUSB_Host::MSC_Process(void)
{
    if (m_ApplicationState == APPLICATION_READY)
    {
        if(m_HandleUSB_HostFS.gState == HOST_ENUMERATION)
        {
            #if (USB_FULL_DEBUG == DEF_ENABLED)
            // ("Enumeration!");
            #endif
        }
    }

    switch (m_ApplicationState)
    {
        case APPLICATION_START:
		{
            // MSC class is active -> clé USB ready
            m_ApplicationState = APPLICATION_READY;
		}
        break;

        case APPLICATION_READY:
        {
            // Here we can mount FatFS or using callback
        }
        break;

        case APPLICATION_DISCONNECT:
        {
            m_ApplicationState = APPLICATION_IDLE;
        }
        break;

        default:
            break;
    }
}


// ---------------------------------------------------------------------------------------------------------

void TaskUSB_Host::USBH_UserProcessCallBack(USBH_HandleTypeDef *pHost, uint8_t ID)
{
    if(TaskUSB_Host::m_Instance)
    {
        TaskUSB_Host::m_Instance->USBH_UserProcess(pHost, ID);
    }
}

// ---------------------------------------------------------------------------------------------------------

void TaskUSB_Host::USBH_UserProcess(USBH_HandleTypeDef* pHost, uint8_t ID)
{
    VAR_UNUSED(pHost);

    switch(int(ID))
    {
        case int(HOST_USER_SELECT_CONFIGURATION):
            break;

        case int(HOST_USER_CONNECTION):
        {
            // The device is connected, but not yet ready
            m_ApplicationState = APPLICATION_IDLE;
			m_MSC_Connected = false;
            //m_CDC_Connected = false;
            //m_HID_Connected = false;
        }
        break;

        case int(HOST_USER_CLASS_ACTIVE):
        {
            uint8_t ActiveClass = USBH_GetActiveClass(pHost);

            switch(ActiveClass)
            {
/*
                case USB_CDC_CLASS:
				{
                    m_CDC_Connected = true;
				}
                break;

                case USB_HID_CLASS:
				{
                    m_HID_Connected = true;
				}
                break;
					
*/					
                case USB_MSC_CLASS:
				{
                    m_MSC_Connected = true;

					if(m_LUN_Info.capacity.block_nbr == 0)
					{
						if(USBH_MSC_GetLUNInfo(&m_HandleUSB_HostFS, 0, &m_LUN_Info) == USBH_OK)
						{
							// LUN info loaded
						}
					}
					// the MSC class is active -> USB Key Ready
				}
                break;
            }			

            m_ApplicationState = APPLICATION_START;
        }
        break;

        case int(HOST_USER_DISCONNECTION):
        {
			//if(m_CDC_Connected == true)
			//{
			//}
			
			//if(m_HID_Connected == true)
			//{
			//}

			if(m_MSC_Connected == true)
			{
				memset(&m_LUN_Info, 0, sizeof(MSC_LUNTypeDef));
			}

            m_ApplicationState = APPLICATION_DISCONNECT;
        }
        break;

        default:
            break;
    }
}

// ---------------------------------------------------------------------------------------------------------

bool USB_Host_Ready()
{
    ApplicationTypeDef currentState = ApplicationTypeDef::APPLICATION_DISCONNECT;

    if(TaskUSB_Host::GetInstance())
	{
        currentState = TaskUSB_Host::GetInstance()->GetState();
	}

    return (currentState == ApplicationTypeDef::APPLICATION_READY);
}

// ---------------------------------------------------------------------------------------------------------

extern "C"
{

// ---------------------------------------------------------------------------------------------------------

extern HCD_HandleTypeDef hhcd_USB_OTG_FS;

NOS_ISR(OTG_FS_IRQHandler)
{
    HAL_HCD_IRQHandler(&hhcd_USB_OTG_FS);
}

// ---------------------------------------------------------------------------------------------------------

void HAL_HCD_MspInit(HCD_HandleTypeDef *pHCD)
{
	if(pHCD->Instance == USB_OTG_FS)
	{
		RCC->AHB2ENR |= RCC_AHB2ENR_OTGFSEN;				// Enable USB OTG FS clock
		ISR_Init(OTG_FS_IRQn, 3);								// USB OTG FS interrupt Init
	}
}

// ---------------------------------------------------------------------------------------------------------

} // extern "C"

// ---------------------------------------------------------------------------------------------------------
