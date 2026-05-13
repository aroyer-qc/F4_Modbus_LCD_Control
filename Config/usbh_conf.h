/**
  ******************************************************************************
  * @file    usbh_conf_template.h
  * @author  MCD Application Team
  * @brief   Header file for usbh_conf_template.c
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2015 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

//-------------------------------------------------------------------------------------------------
// Include(s)
//-------------------------------------------------------------------------------------------------

#include "stm32f4xx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "./inc/usb_defines.h"
#include "./Digini/Memory/inc/lib_c_memory_wrapper.h"

//-------------------------------------------------------------------------------------------------
// Define(s)
//-------------------------------------------------------------------------------------------------

#define UNUSED(v)                           ((void)(v))

#define USBH_MAX_NUM_ENDPOINTS              2U
#define USBH_MAX_NUM_INTERFACES             2U
#define USBH_MAX_NUM_CONFIGURATION          1U
#define USBH_KEEP_CFG_DESCRIPTOR            1U
#define USBH_MAX_NUM_SUPPORTED_CLASS        1U
#define USBH_MAX_SIZE_CONFIGURATION         0x200U
#define USBH_MAX_DATA_BUFFER                0x200U
#define USBH_DEBUG_LEVEL                    0U                // No Log
#define USBH_USE_OS                         0U				// Not compatible with nOS
#define USBH_IN_NAK_PROCESS                 0

// Memory management macros
#define USBH_malloc(SIZE)         			(MSC_HandleTypeDef*)MemoryPool_Alloc(SIZE)
#define USBH_free(PTR)            			MemoryPool_Free(PTR)
#define USBH_memset               			memset
#define USBH_memcpy              		 	memcpy
#define HAL_Delay(d)			  			

// DEBUG macros
#if (USBH_DEBUG_LEVEL > 0U)
#define  USBH_UsrLog(...)   do { \
                                 printf(__VA_ARGS__); \
                                 printf("\n"); \
                               } while (0)
#else
#define USBH_UsrLog(...) do {} while (0)
#endif

#if (USBH_DEBUG_LEVEL > 1U)

#define  USBH_ErrLog(...) do { \
                               printf("ERROR: "); \
                               printf(__VA_ARGS__); \
                               printf("\n"); \
                             } while (0)
#else
#define USBH_ErrLog(...) do {} while (0)
#endif

#if (USBH_DEBUG_LEVEL > 2U)
#define  USBH_DbgLog(...)   do { \
                                 printf("DEBUG : "); \
                                 printf(__VA_ARGS__); \
                                 printf("\n"); \
                               } while (0)
#else
#define USBH_DbgLog(...) do {} while (0)
#endif

#ifdef __cplusplus
}
#endif
