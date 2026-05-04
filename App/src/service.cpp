//-------------------------------------------------------------------------------------------------
//
//  File : service.cpp
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

/*

Service type 2 - Return data array compose of 16 bits value. Array size define by SERVICE_TYPE2_SIZE_LIST
Service type 3 - Return link to new page
                        INVALID_LINK  - that instruct GUI to do nothing
                        REMOVE_WIDGET - remove the widget from the list of widget to refresh
Service type 4 - Return string array pointer. Array size define by SERVICE_TYPE4_SIZE_LIST
Service type 5 - Return data for an image -> Address, Size, Pixel format
Service type 6 - Return data to override position of a widget
Service type 7 - Return data to override position of a widget (Must be a memory block by allocation, it will be freed by widget)
*/

//-------------------------------------------------------------------------------------------------
// Include file(s)
//-------------------------------------------------------------------------------------------------`

#include "./Digini/lib_digini.h"
#if (DIGINI_USE_GRAFX == DEF_ENABLED)
#include "project_def.h"

//-------------------------------------------------------------------------------------------------
// Define(s)
//-------------------------------------------------------------------------------------------------`

#define SERVICE_PRINT_BUFFER_SIZE   80

//-------------------------------------------------------------------------------------------------
// external(s)
//-------------------------------------------------------------------------------------------------`

extern char GuiID		[];
extern char IP_Address	[];
extern char MAC_Address	[];

//-------------------------------------------------------------------------------------------------
// Support Function(s)
//-------------------------------------------------------------------------------------------------`

uint16_t GetIO_State(IO_ID_e LimitID)
{
    uint16_t State;

    if(IO_IsItValid(LimitID) == true)
    {
        State = uint16_t(IO_GetInputPin(LimitID));
    }
    else
    {
        State = 2;  // Grayout
    }

    return State;
}

//-------------------------------------------------------------------------------------------------
//
//  Name:           SERV_INFO
//
//  Parameter(s):   ServiceEvent_e*  pServiceState
//                  uint16_t         SubService
//  Return:         ServiceReturn_t
//
//  Description:    This function return information on software
//
//-------------------------------------------------------------------------------------------------
static ServiceReturn_t* SERV_INFO(ServiceEvent_e* pServiceState, uint16_t SubService)
{
    static char*     pBuffer               = nullptr;
    static bool      IsItFirstServiceStart = true;
    ServiceReturn_t* pService              = nullptr;

    // Handling of memory allocation while service is active (Shared for all active SERV_INFO SubService)
    if(*pServiceState == SERVICE_START)
    {
        if(IsItFirstServiceStart == true)
        {
            IsItFirstServiceStart = false;
            pBuffer = (char*)pMemoryPool->Alloc(SERVICE_PRINT_BUFFER_SIZE);
        }
    }

    if(*pServiceState == SERVICE_FINALIZE)
    {
        if(IsItFirstServiceStart == false)
        {
            IsItFirstServiceStart = true;
            pMemoryPool->Free((void**)&pBuffer);
        }
    }
    else
    {
        if((pService = GetServiceStruct(SERVICE_RETURN_TYPE4)) != nullptr)
        {
            switch(SubService)
            {
                case 0: snprintf(pBuffer, 24, "%s", OUR_FIRMWARE_NAME);           break;
                case 1: snprintf(pBuffer, 24, "%s", OUR_FIRMWARE_VERSION);        break;
                case 2: snprintf(pBuffer, 24, "%s", OUR_FIRMWARE_DIGINI_NAME);    break;
                case 3: snprintf(pBuffer, 24, "%s", OUR_FIRMWARE_DIGINI_VERSION); break;
                case 4: snprintf(pBuffer, 24, "%s", OEM_MODEL_NAME);              break;
                case 5: snprintf(pBuffer, 24, "%s", OEM_SERIAL_NUMBER);           break;
                case 6: snprintf(pBuffer, 24, "%s", OUR_FIRMWARE_BUILD_DATE);     break;
                // Add ... Config version

                case 7: snprintf(pBuffer, 24, "%s", GuiID);                       break;
                case 8: snprintf(pBuffer, 24, "%s", IP_Address);                  break;
                case 9: snprintf(pBuffer, 24, "%s", MAC_Address);                 break;
            }

            ((ServiceType4_t*)pService)->pString[0] = pBuffer;
            *pServiceState = SERVICE_REFRESH;
        }
    }

    return pService;
}

//-------------------------------------------------------------------------------------------------
//
//  Name:           SERV_LEDS
//
//  Parameter(s):   ServiceEvent_e*  pServiceState
//                  uint16_t         SubService
//  Return:         ServiceReturn_t
//
//  Description:    This function return information on software
//
//-------------------------------------------------------------------------------------------------
static ServiceReturn_t* SERV_LEDS(ServiceEvent_e* pServiceState, uint16_t SubService)
{
    static TickCount_t LedTimeOut[4]         = {350, 250, 300, 400};
    static bool        StateLed[4]           = {true, true, false, true};
    ServiceReturn_t*   pService              = nullptr;
    static TickCount_t Start[4]              = {0, 0, 0, 0};

    if((pService = GetServiceStruct(SERVICE_RETURN)) != nullptr)
    {
        switch(SubService)
        {
            case 0:
            {
                if(TickHasTimeOut(Start[0], LedTimeOut[0]) == true)
                {
                    Start[0] = GetTick();
                    LedTimeOut[0] = RNG_GetRandomFromRange(200, 800);
                    StateLed[0] = (StateLed[0] == false) ? true : false;
                }
                pService->IndexState = (StateLed[0] == false) ? 0 : 1;
                *pServiceState = SERVICE_REFRESH;
            }
            break;

            case 1:
            {
                if(TickHasTimeOut(Start[1], LedTimeOut[1]) == true)
                {
                    Start[1] = GetTick();
                    LedTimeOut[1] = RNG_GetRandomFromRange(200, 800);
                    StateLed[1] = (StateLed[1] == false) ? true : false;
                }
                pService->IndexState = (StateLed[1] == false) ? 0 : 1;
                *pServiceState = SERVICE_REFRESH;
            }
            break;

            case 2:
            {
                if(TickHasTimeOut(Start[2], LedTimeOut[2]) == true)
                {
                    Start[2] = GetTick();
                    LedTimeOut[2] = RNG_GetRandomFromRange(200, 800);
                    StateLed[2] = (StateLed[2] == false) ? true : false;
                }
                pService->IndexState = (StateLed[2] == false) ? 0 : 1;
                *pServiceState = SERVICE_REFRESH;
            }
            break;

            case 3:
            {
                if(TickHasTimeOut(Start[3], LedTimeOut[3]) == true)
                {
                    Start[3] = GetTick();
                    LedTimeOut[3] = RNG_GetRandomFromRange(200, 800);
                    StateLed[3] = (StateLed[0] == false) ? true : false;
                }
                pService->IndexState = (StateLed[3] == false) ? 0 : 1;
                *pServiceState = SERVICE_REFRESH;
            }
            break;
        }

    }

    return pService;
}

//-------------------------------------------------------------------------------------------------
//
//  Name:           SERV_TEST
//
//  Parameter(s):   ServiceEvent_e*  pServiceState
//                  uint16_t         SubService
//  Return:         ServiceReturn_t
//
//  Description:    This function increment a counter for a label test
//
//-------------------------------------------------------------------------------------------------
static ServiceReturn_t* SERV_TEST(ServiceEvent_e* pServiceState, uint16_t SubService)
{
    static TickCount_t Start = GetTick();
    ServiceReturn_t*   pService = nullptr;
    static uint16_t    Count = 0;

    if(TickHasTimeOut(Start, 10) == true)
    {
        Start = GetTick();
        Count++;
    }

    if((pService = GetServiceStruct(SERVICE_RETURN_TYPE1)) != nullptr)
    {
        ((ServiceType1_t*)pService)->Data = Count;
        *pServiceState = SERVICE_REFRESH;
    }

    return pService;
}

//-------------------------------------------------------------------------------------------------
//
//  Name:           ServiceCallApp
//  Parameter(s):   Service_t*       pService
//                  ServiceEvent_e*  pServiceState
//  Return:         ServiceReturn_t
//
//  Description:    Callback service provided for application side
//
//  Note(s):        Will Call any service from TaskGUI that are not generic
//
//-------------------------------------------------------------------------------------------------
ServiceReturn_t* ServiceCallApp(Service_t* pService, ServiceEvent_e* pServiceState)
{
    ServiceReturn_t* pServiceReturn = nullptr;
    uint32_t         ServiceRange;

    ServiceRange = pService->ID;

    switch(U32MACRO_A(ServiceRange))        // To speed up process
    {
        case 'A':
        {
            switch(pService->ID)
            {
                //case SERV_ID_AXIS:  pServiceReturn = SERV_AXIS(pServiceState, pService->SubID);  break;
            }
            break;
        }

        case 'C':
        {
            switch(pService->ID)
            {
                //case SERV_ID_COOR:  pServiceReturn = SERV_COOR(pServiceState, pService->SubID);  break;
            }
            break;
        }

        case 'E':
        {
            switch(pService->ID)
            {
                //case SERV_ID_ENBL:  pServiceReturn = SERV_ENBL(pServiceState, pService->SubID);  break;
            }
            break;
        }

        case 'G':
        {
            switch(pService->ID)
            {
                //case SERV_ID_GCOD:  pServiceReturn = SERV_GCOD(pServiceState, pService->SubID);  break;
            }
            break;

        }

        case 'I':
        {
            switch(pService->ID)
            {
                case SERV_ID_INFO:  pServiceReturn = SERV_INFO(pServiceState, pService->SubID);  break;
            }
            break;

        }

        case 'L':
        {
            switch(pService->ID)
            {
                case SERV_ID_LEDS:  pServiceReturn = SERV_LEDS(pServiceState, pService->SubID);  break;
            }
            break;

        }

        case 'M':
        {
            switch(pService->ID)
            {
                //case SERV_ID_MHUB:  pServiceReturn = SERV_MHUB(pServiceState);                   break;
                //case SERV_ID_MACH:  pServiceReturn = SERV_MACH(pServiceState, pService->SubID);  break;
            }
            break;
        }

        case 'T':
        {
            switch(pService->ID)
            {
                case SERV_ID_TEST:  pServiceReturn = SERV_TEST(pServiceState, pService->SubID);  break;
            }
            break;
        }
    }

    return pServiceReturn;
}


//-------------------------------------------------------------------------------------------------

#endif // DIGINI_USE_GRAFX
