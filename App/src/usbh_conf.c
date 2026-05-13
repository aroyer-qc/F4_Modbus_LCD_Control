/**
  ******************************************************************************
  * @file    usbh_conf.c
  * @author  MCD Application Team
  * @brief   This file implements the board support package for the USB host library
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

/* Includes ------------------------------------------------------------------*/
#include "usbh_core.h"
#include "stm32f4xx_hal_hcd.h"


// Returns the USB status depending on the HAL status:
USBH_StatusTypeDef USBH_Get_USB_Status(HAL_StatusTypeDef hal_status)
{
    USBH_StatusTypeDef usb_status = USBH_OK;

    switch(hal_status)
    {
        case HAL_OK:      usb_status = USBH_OK;   break;
        case HAL_BUSY:    usb_status = USBH_BUSY; break;
        //case HAL_TIMEOUT:
        //case HAL_ERROR:
        // and all other
        default:          usb_status = USBH_FAIL; break;
    }

    return usb_status;
}


// Private variables
HCD_HandleTypeDef hhcd_USB_OTG_FS;

/**
  * @brief  USBH_LL_Init
  *         Initialize the Low Level portion of the Host driver.
  * @param  pHost: Host handle
  * @retval USBH Status
  */
USBH_StatusTypeDef USBH_LL_Init(USBH_HandleTypeDef *pHost)
{
    // Set the LL Driver parameters
    hhcd_USB_OTG_FS.Instance                 = USB_OTG_FS;
    hhcd_USB_OTG_FS.Init.Host_channels       = 8;
    hhcd_USB_OTG_FS.Init.speed               = HCD_SPEED_FULL;
    hhcd_USB_OTG_FS.Init.dma_enable          = DISABLE;
    hhcd_USB_OTG_FS.Init.phy_itface          = HCD_PHY_EMBEDDED;
    hhcd_USB_OTG_FS.Init.Sof_enable          = ENABLE;
    hhcd_USB_OTG_FS.Init.low_power_enable    = DISABLE;
    hhcd_USB_OTG_FS.Init.vbus_sensing_enable = ENABLE;

    // Link the driver to the stack
    hhcd_USB_OTG_FS.pData = pHost;
    pHost->pData = &hhcd_USB_OTG_FS;

    // Initialize LL Driver
    if(HAL_HCD_Init(&hhcd_USB_OTG_FS) != HAL_OK)
    {
         __asm("nop");
    }

    return USBH_OK;
}

/**
  * @brief  USBH_LL_DeInit
  *         De-Initialize the Low Level portion of the Host driver.
  * @param  pHost: Host handle
  * @retval USBH Status
  */
USBH_StatusTypeDef USBH_LL_DeInit(USBH_HandleTypeDef *pHost)
{
    USBH_StatusTypeDef usb_status =  USBH_Get_USB_Status(HAL_HCD_DeInit(pHost->pData));
    return usb_status;
}

/**
  * @brief  USBH_LL_Start
  *         Start the Low Level portion of the Host driver.
  * @param  pHost: Host handle
  * @retval USBH Status
  */
USBH_StatusTypeDef USBH_LL_Start(USBH_HandleTypeDef *pHost)
{
    USBH_StatusTypeDef usb_status = USBH_Get_USB_Status(HAL_HCD_Start(pHost->pData));
    return usb_status;
}

/**
  * @brief  USBH_LL_Stop
  *         Stop the Low Level portion of the Host driver.
  * @param  pHost: Host handle
  * @retval USBH Status
  */
USBH_StatusTypeDef USBH_LL_Stop(USBH_HandleTypeDef *pHost)
{
    USBH_StatusTypeDef usb_status = USBH_Get_USB_Status(HAL_HCD_Stop(pHost->pData));
    return usb_status;
}

/**
  * @brief  USBH_LL_GetSpeed
  *         Return the USB Host Speed from the Low Level Driver.
  * @param  pHost: Host handle
  * @retval USBH Speeds
  */
USBH_SpeedTypeDef USBH_LL_GetSpeed(USBH_HandleTypeDef *pHost)
{
    return USBH_SPEED_FULL;
}

/**
  * @brief  USBH_LL_ResetPort
  *         Reset the Host Port of the Low Level Driver.
  * @param  pHost: Host handle
  * @retval USBH Status
  */
USBH_StatusTypeDef USBH_LL_ResetPort(USBH_HandleTypeDef *pHost)
{
    USBH_StatusTypeDef usb_status = USBH_Get_USB_Status(HAL_HCD_ResetPort(pHost->pData));
    return usb_status;
}

/**
  * @brief  USBH_LL_GetLastXferSize
  *         Return the last transferred packet size.
  * @param  pHost: Host handle
  * @param  pipe: Pipe index
  * @retval Packet Size
  */
uint32_t USBH_LL_GetLastXferSize(USBH_HandleTypeDef *pHost, uint8_t pipe)
{
    return HAL_HCD_HC_GetXferCount(pHost->pData, pipe);
}

/**
  * @brief  USBH_LL_OpenPipe
  *         Open a pipe of the Low Level Driver.
  * @param  phost: Host handle
  * @param  pipe: Pipe index
  * @param  epnum: Endpoint Number
  * @param  dev_address: Device USB address
  * @param  speed: Device Speed
  * @param  ep_type: Endpoint Type
  * @param  mps: Endpoint Max Packet Size
  * @retval USBH Status
  */
USBH_StatusTypeDef USBH_LL_OpenPipe(USBH_HandleTypeDef *pHost,
                                    uint8_t pipe,
                                    uint8_t epnum,
                                    uint8_t dev_address,
                                    uint8_t speed,
                                    uint8_t ep_type,
                                    uint16_t mps)
{
    USBH_StatusTypeDef usb_status = USBH_Get_USB_Status(HAL_HCD_HC_Init(pHost->pData, pipe, epnum, dev_address, speed, ep_type, mps));
    return usb_status;
}

/**
  * @brief  USBH_LL_ClosePipe
  *         Close a pipe of the Low Level Driver.
  * @param  pHost: Host handle
  * @param  pipe: Pipe index
  * @retval USBH Status
  */
USBH_StatusTypeDef USBH_LL_ClosePipe(USBH_HandleTypeDef *pHost, uint8_t pipe)
{
    UNUSED(pipe);
    USBH_StatusTypeDef usb_status = USBH_Get_USB_Status(HAL_HCD_Stop(pHost->pData));
    return usb_status;
}

/**
  * @brief  USBH_LL_ActivatePipe
  *         Activate a pipe of the Low Level Driver.
  * @param  pHost: Host handle
  * @param  pipe: Pipe index
  * @retval USBH Status
  */
USBH_StatusTypeDef USBH_LL_ActivatePipe(USBH_HandleTypeDef *pHost, uint8_t pipe)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(pHost);
  UNUSED(pipe);

  return USBH_OK;
}

/**
  * @brief  USBH_LL_SubmitURB
  *         Submit a new URB to the low level driver.
  * @param  pHost: Host handle
  * @param  pipe: Pipe index
  *         This parameter can be a value from 1 to 15
  * @param  direction : Channel number
  *          This parameter can be one of the these values:
  *           0 : Output
  *           1 : Input
  * @param  ep_type : Endpoint Type
  *          This parameter can be one of the these values:
  *            @arg EP_TYPE_CTRL: Control type
  *            @arg EP_TYPE_ISOC: Isochronous type
  *            @arg EP_TYPE_BULK: Bulk type
  *            @arg EP_TYPE_INTR: Interrupt type
  * @param  token : Endpoint Type
  *          This parameter can be one of the these values:
  *            @arg 0: PID_SETUP
  *            @arg 1: PID_DATA
  * @param  pbuff : pointer to URB data
  * @param  length : Length of URB data
  * @param  do_ping : activate do ping protocol (for high speed only)
  *          This parameter can be one of the these values:
  *           0 : do ping inactive
  *           1 : do ping active
  * @retval Status
  */
USBH_StatusTypeDef USBH_LL_SubmitURB(USBH_HandleTypeDef *pHost,
                                     uint8_t pipe,
                                     uint8_t direction,
                                     uint8_t ep_type,
                                     uint8_t token,
                                     uint8_t *pbuff,
                                     uint16_t length,
                                     uint8_t do_ping)
{
  USBH_StatusTypeDef usb_status = USBH_Get_USB_Status(HAL_HCD_HC_SubmitRequest(pHost->pData, pipe, direction,
                                                                               ep_type, token, pbuff, length,
                                                                               do_ping));
  return usb_status;
}

/**
  * @brief  USBH_LL_GetURBState
  *         Get a URB state from the low level driver.
  * @param  pHost: Host handle
  * @param  pipe: Pipe index
  *         This parameter can be a value from 1 to 15
  * @retval URB state
  *          This parameter can be one of the these values:
  *            @arg URB_IDLE
  *            @arg URB_DONE
  *            @arg URB_NOTREADY
  *            @arg URB_NYET
  *            @arg URB_ERROR
  *            @arg URB_STALL
  */
USBH_URBStateTypeDef USBH_LL_GetURBState(USBH_HandleTypeDef *pHost, uint8_t pipe)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(pHost);
  UNUSED(pipe);

  return USBH_URB_IDLE;
}

/**
  * @brief  USBH_LL_DriverVBUS
  *         Drive VBUS.
  * @param  pHost: Host handle
  * @param  state : VBUS state
  *          This parameter can be one of the these values:
  *           0 : VBUS Inactive
  *           1 : VBUS Active
  * @retval Status
  */
USBH_StatusTypeDef USBH_LL_DriverVBUS(USBH_HandleTypeDef *pHost, uint8_t state)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(pHost);
  UNUSED(state);

  return USBH_OK;
}

/**
  * @brief  USBH_LL_SetToggle
  *         Set toggle for a pipe.
  * @param  phost: Host handle
  * @param  pipe: Pipe index
  * @param  pipe_num: Pipe index
  * @param  toggle: toggle (0/1)
  * @retval Status
  */
USBH_StatusTypeDef USBH_LL_SetToggle(USBH_HandleTypeDef *pHost, uint8_t pipe, uint8_t toggle)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(pHost);
  UNUSED(pipe);
  UNUSED(toggle);

  return USBH_OK;
}

/**
  * @brief  USBH_LL_GetToggle
  *         Return the current toggle of a pipe.
  * @param  pHost: Host handle
  * @param  pipe: Pipe index
  * @retval toggle (0/1)
  */
uint8_t USBH_LL_GetToggle(USBH_HandleTypeDef *pHost, uint8_t pipe)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(pHost);
  UNUSED(pipe);

  uint8_t toggle = 0U;

  return toggle;
}

/**
  * @brief  USBH_Delay
  *         Delay routine for the USB Host Library
  * @param  Delay: Delay in ms
  * @retval None
  */
void USBH_Delay(uint32_t Delay)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(Delay);
}
