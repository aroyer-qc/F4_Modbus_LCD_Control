//-------------------------------------------------------------------------------------------------
//
//  File : bsp_io_def.h
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
// Define(s)
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
//
//          IO_CFG_DEF(X_IO_CFG)
//
//          This is common configuration for IO_DEF pin declaration.
//          It help reduce code size by sharing configuration.
//
//          Parameter 1:  ENUM ID of the configuration
//
//          Parameter 2:  MODE for the pin
//                          IO_MODE_INPUT
//                          IO_MODE_OUTPUT
//                          IO_MODE_ALTERNATE
//                          IO_MODE_ANALOG
//          Parameter 3:  TYPE for the pin
//                          IO_TYPE_PIN_DRIVE_MASK
//                          IO_TYPE_PIN_DRIVE_SHIFT
//                          IO_TYPE_PIN_PP
//                          IO_TYPE_PIN_OD
//          Parameter 4:  SPEED for the pin
//                          IO_SPEED_FREQ_LOW
//                          IO_SPEED_FREQ_MEDIUM
//                          IO_SPEED_FREQ_HIGH
//                          IO_SPEED_FREQ_VERY_HIGH
//          Parameter 5:  EXTRA info for the pin
//                          If mode is IO_MODE_INPUT,        This is not used. Put 0 there
//                          If mode is IO_MODE_OUTPUT,       This is the default level on the pin at initialization. Put level 0 or 1
//                          If mode is IO_MODE_ALTERNATE,    This is the alternate setting
//                                                               Example: GPIO_AF7_USART3  -  See lib_STM3F4_io.h
//                          If mode is IO_MODE_ANALOG,       This is used to select the ADC input               // to be validated!!!
//
//-------------------------------------------------------------------------------------------------

#define IO_CFG_DEF(X_IO_CFG) \
/*            ENUM ID IO CFG,                           Mode,               Pin type,              IO Speed,                 Pin Option           */\
/* input IO's CFG --------------------------------------------------------------------------------------------------------------------------------*/\
    X_IO_CFG( IO_CFG_INPUT_NP_LS,                       IO_MODE_INPUT,      IO_TYPE_PIN_NO_PULL,   IO_SPEED_FREQ_LOW,        0)                     \
/* Output IO's CFG -------------------------------------------------------------------------------------------------------------------------------*/\
    X_IO_CFG( IO_CFG_OUTPUT_PP_LS_DEF0,                 IO_MODE_OUTPUT,     IO_TYPE_PIN_PP,        IO_SPEED_FREQ_LOW,        0)                     \
    X_IO_CFG( IO_CFG_OUTPUT_PP_LS_DEF1,                 IO_MODE_OUTPUT,     IO_TYPE_PIN_PP,        IO_SPEED_FREQ_LOW,        1)                     \
    X_IO_CFG( IO_CFG_OUTPUT_PP_MS_DEF0,                 IO_MODE_OUTPUT,     IO_TYPE_PIN_PP,        IO_SPEED_FREQ_HIGH,       0)                     \
    X_IO_CFG( IO_CFG_OUTPUT_PP_MS_DEF1,                 IO_MODE_OUTPUT,     IO_TYPE_PIN_PP,        IO_SPEED_FREQ_MEDIUM,     1)                     \
    X_IO_CFG( IO_CFG_OUTPUT_PP_HS_DEF1,                 IO_MODE_OUTPUT,     IO_TYPE_PIN_PP,        IO_SPEED_FREQ_HIGH,       1)                     \
/* ADC IO's CFG ----------------------------------------------------------------------------------------------------------------------------------*/\
    X_IO_CFG( IO_CFG_ADC,                               IO_MODE_ANALOG,     IO_TYPE_PIN_NO_PULL,   IO_SPEED_FREQ_LOW,        IO_AF0)                \
/* FMC IO's CFG ----------------------------------------------------------------------------------------------------------------------------------*/\
    X_IO_CFG( IO_CFG_FMC,                               IO_MODE_ALTERNATE,  IO_TYPE_PIN_PP,        IO_SPEED_FREQ_VERY_HIGH,  IO_AF12_FMC)           \
/* CAN IO's CFG ----------------------------------------------------------------------------------------------------------------------------------*/\
    X_IO_CFG( IO_CFG_CAN_AF9,                           IO_MODE_ALTERNATE,  IO_TYPE_PIN_PP,        IO_SPEED_FREQ_VERY_HIGH,  IO_AF9_CAN1)           \
/* MCO IO's CFG ----------------------------------------------------------------------------------------------------------------------------------*/\
    X_IO_CFG( IO_CFG_MCO_OUTPUT,                        IO_MODE_ALTERNATE,  IO_TYPE_PIN_PP,        IO_SPEED_FREQ_HIGH,       IO_AF0_MCO)            \
/* PWM IO's CFG ----------------------------------------------------------------------------------------------------------------------------------*/\
    X_IO_CFG( IO_CFG_PWM_AF1,                           IO_MODE_ALTERNATE,  IO_TYPE_PIN_PP,        IO_SPEED_FREQ_MEDIUM,     IO_AF1_TIM2)           \
/* SPI IO's CFG ----------------------------------------------------------------------------------------------------------------------------------*/\
    X_IO_CFG( IO_CFG_SPI_AF5,                           IO_MODE_ALTERNATE,  IO_TYPE_PIN_PP,        IO_SPEED_FREQ_VERY_HIGH,  IO_AF5_SPI)            \
/* USART IO's CFG --------------------------------------------------------------------------------------------------------------------------------*/\
    X_IO_CFG( IO_CFG_USART6_AF8,                        IO_MODE_ALTERNATE,  IO_TYPE_PIN_PP,        IO_SPEED_FREQ_MEDIUM,     IO_AF8_USART6)         \
/* UART IO's CFG ---------------------------------------------------------------------------------------------------------------------------------*/\
    X_IO_CFG( IO_CFG_UART4_AF8,                         IO_MODE_ALTERNATE,  IO_TYPE_PIN_PP,        IO_SPEED_FREQ_MEDIUM,     IO_AF8_UART4)          \
/* USB IO's CFG ----------------------------------------------------------------------------------------------------------------------------------*/\
    X_IO_CFG( IO_CFG_USB_AF10,                          IO_MODE_ALTERNATE,  IO_TYPE_PIN_PP,        IO_SPEED_FREQ_HIGH,       IO_AF10_OTG_FS)        \
/* -----------------------------------------------------------------------------------------------------------------------------------------------*/


//    X_IO_CFG( IO_CFG_OUTPUT_OC_LS_DEF0,                 IO_MODE_OUTPUT,     IO_TYPE_PIN_OD,        IO_SPEED_FREQ_LOW,        0)
    //X_IO_CFG( IO_CFG_OUTPUT_OC_LS_DEF1,                 IO_MODE_OUTPUT,     IO_TYPE_PIN_OD,        IO_SPEED_FREQ_LOW,        1)

//-------------------------------------------------------------------------------------------------
//
//          IO_DEF(X_IO)
//
//          Parameter 1:  This is the ID of the IO pin
//          Parameter 2:  Port for the PIN
//                          GPIOx to invalidate this IO temporarily
//          Parameter 3:  IO number for the PIN
//          Parameter 4:  IO CFG to used for this pin
//
//-------------------------------------------------------------------------------------------------

#define IO_DEF(X_IO) \
/* ---------------------------------------------------------------------------------------------*/\
/*        ENUM ID of the IO,    IO Port,    IO Pin,         IO Config                           */\
/* Output IO's ---------------------------------------------------------------------------------*/\
    X_IO( IO_LED_GREEN_STATUS,  GPIOB,      IO_PIN_11,      IO_CFG_OUTPUT_PP_LS_DEF1)             \
    X_IO( IO_LED_RED_STATUS,    GPIOB,      IO_PIN_10,      IO_CFG_OUTPUT_PP_LS_DEF1)             \
    X_IO( IO_BUZZER,            GPIOB,      IO_PIN_0,       IO_CFG_OUTPUT_PP_LS_DEF0)             \
    X_IO( IO_PS0,               GPIOC,      IO_PIN_0,       IO_CFG_OUTPUT_PP_LS_DEF0)             \
    X_IO( IO_PS1,               GPIOC,      IO_PIN_1,       IO_CFG_OUTPUT_PP_LS_DEF1)             \
    X_IO( IO_PS2,               GPIOC,      IO_PIN_2,       IO_CFG_OUTPUT_PP_LS_DEF0)             \
    X_IO( IO_PS3,               GPIOC,      IO_PIN_3,       IO_CFG_OUTPUT_PP_LS_DEF0)             \
/* ADC IO's ------------------------------------------------------------------------------------*/\
    X_IO( IO_ADC_X1,            GPIOC,      IO_PIN_5,       IO_CFG_ADC)                           \
    X_IO( IO_ADC_X2,            GPIOA,      IO_PIN_7,       IO_CFG_ADC)                           \
    X_IO( IO_ADC_Y1,            GPIOA,      IO_PIN_6,       IO_CFG_ADC)                           \
    X_IO( IO_ADC_Y2,            GPIOC,      IO_PIN_4,       IO_CFG_ADC)                           \
/* RS485 IO's ----------------------------------------------------------------------------------*/\
    X_IO( IO_RS485_DE,          GPIOC,      IO_PIN_12,      IO_CFG_OUTPUT_PP_MS_DEF0)             \
/* LCD IO's ------------------------------------------------------------------------------------*/\
    X_IO( IO_LCD_RESET,         GPIOD,      IO_PIN_6,       IO_CFG_OUTPUT_PP_LS_DEF0)             \
    X_IO( IO_LCD_TFT_BL_PWM,    GPIOA,      IO_PIN_5,       IO_CFG_PWM_AF1)                       \
    X_IO( IO_LCD_TFT_BL_ADC,    GPIOA,      IO_PIN_4,       IO_CFG_ADC)                           \
/* TOUCH IO's ----------------------------------------------------------------------------------*/\
    X_IO( IO_TOUCH_Y1_SWITCH,   GPIOE,      IO_PIN_2,       IO_CFG_OUTPUT_PP_LS_DEF1)             \
    X_IO( IO_TOUCH_X2_SWITCH,   GPIOE,      IO_PIN_3,       IO_CFG_OUTPUT_PP_LS_DEF1)             \
    X_IO( IO_TOUCH_Y2_SWITCH,   GPIOE,      IO_PIN_4,       IO_CFG_OUTPUT_PP_LS_DEF0)             \
    X_IO( IO_TOUCH_X1_SWITCH,   GPIOE,      IO_PIN_5,       IO_CFG_OUTPUT_PP_LS_DEF0)             \
/* MCO -----------------------------------------------------------------------------------------*/\
    X_IO( IO_MCO_1,             GPIOA,      IO_PIN_8,       IO_CFG_MCO_OUTPUT)                    \
/* ---------------------------------------------------------------------------------------------*/


//-------------------------------------------------------------------------------------------------
//
//  IO_GROUP is useful for pin sharing configuration and they are not used individually at run time
//  because they are control by module.
//
//    Examples: LCD, SDRAM, ETH, etc...
//
//  Notes : Some group might share same config
//
//-------------------------------------------------------------------------------------------------

//--------------------------------------------
// CAN grouping configuration
#define CAN_PIN_ON_PORT_B       (IO_PIN_8  | IO_PIN_9)

//--------------------------------------------
// FMC for LCD grouping configuration
#define LCD_PIN_ON_PORT_D       (IO_PIN_0  | IO_PIN_1  | IO_PIN_4  | IO_PIN_5  | IO_PIN_7  | IO_PIN_8  | IO_PIN_9  | IO_PIN_10 | IO_PIN_11 | IO_PIN_14 | IO_PIN_15)
#define LCD_PIN_ON_PORT_E       (IO_PIN_7  | IO_PIN_8  | IO_PIN_9  | IO_PIN_10 | IO_PIN_11 | IO_PIN_12 | IO_PIN_13 | IO_PIN_14 | IO_PIN_15)

//---------------------------------------------------------
// SPI2 grouping configuration
#define SPI2_PIN_ON_PORT_B      (IO_PIN_12 | IO_PIN_13 | IO_PIN_14 | IO_PIN_15)

//--------------------------------------------
// USART1 grouping configuration
#define USART6_PIN_ON_PORT_C    (IO_PIN_6  | IO_PIN_7)

//--------------------------------------------
// UART4 grouping configuration
#define UART4_PIN_ON_PORT_C     (IO_PIN_10 | IO_PIN_11)

//--------------------------------------------
// USB grouping configuration
#define USB_PIN_ON_PORT_A       (IO_PIN_9  | IO_PIN_10 | IO_PIN_11 | IO_PIN_12)


//---------------------------------------------------------------------------------------
#define IO_GROUP_DEF(X_IO_GROUP) \
/* ------------------------------------------------------------------------------------------------------*/\
/*              ENUM ID of the Group,   IO Port,    IO Group Pin,               IO ConfigMode            */\
/* CAN --------------------------------------------------------------------------------------------------*/\
    X_IO_GROUP( IO_CAN_ON_PORT_B,		GPIOB,      CAN_PIN_ON_PORT_B,          IO_CFG_CAN_AF9)            \
/* FMC LCD ----------------------------------------------------------------------------------------------*/\
    X_IO_GROUP( IO_LCD_ON_PORT_D,       GPIOD,      LCD_PIN_ON_PORT_D,          IO_CFG_FMC)                \
    X_IO_GROUP( IO_LCD_ON_PORT_E,       GPIOE,      LCD_PIN_ON_PORT_E,          IO_CFG_FMC)                \
/* SPI --------------------------------------------------------------------------------------------------*/\
    X_IO_GROUP( IO_SPI2_ON_PORT_B,      GPIOB,      SPI2_PIN_ON_PORT_B,         IO_CFG_SPI_AF5)            \
/* USART ------------------------------------------------------------------------------------------------*/\
    X_IO_GROUP( IO_USART6_ON_PORT_C,    GPIOC,      USART6_PIN_ON_PORT_C,       IO_CFG_USART6_AF8)         \
/* UART -------------------------------------------------------------------------------------------------*/\
    X_IO_GROUP( IO_UART4_ON_PORT_C,     GPIOC,      UART4_PIN_ON_PORT_C,        IO_CFG_UART4_AF8)          \
/* USB --------------------------------------------------------------------------------------------------*/\
    X_IO_GROUP( IO_USB_ON_PORT_A,       GPIOA,      USB_PIN_ON_PORT_A,          IO_CFG_USB_AF10)           \
/* ------------------------------------------------------------------------------------------------------*/

//-------------------------------------------------------------------------------------------------
//
//          Parameter 1:  This is the ID of the IO IRQ pin
//
//          Parameter 2:  This is the ID of the IO pin used for this IRQ IO
//                          GPIOx
//
//          Parameter 3:    EXTI0_IRQn                  EXTI Line0 Interrupt
//                          EXTI1_IRQn                  EXTI Line1 Interrupt
//                          EXTI2_IRQn                  EXTI Line2 Interrupt
//                          EXTI3_IRQn                  EXTI Line3 Interrupt
//                          EXTI4_IRQn                  EXTI Line4 Interrupt
//                          EXTI9_5_IRQn                External Line[9:5] Interrupts
//                          EXTI15_10_IRQn              External Line[15:10] Interrupts
//
//          Parameter 4:    Priority
//
//          Parameter 5:    IO_EXTI_TRIGGER_RISING
//                          IO_EXTI_TRIGGER_FALLING
//                          IO_EXTI_TRIGGER_RISING_FALLING
//
//          Parameter 6:    Callback function pointer
//
//          Parameter 7:    Argument pointer for callback
//
//-------------------------------------------------------------------------------------------------
#if 0 // none on this board
#define IO_IRQ_DEF(X_IO_IRQ) \
/* ----------------------------------------------------------------------------------------------------------------------------------------------------------*/\
/*           Enum ID                Pin ID              EXTI Pin Source  Priority    Trigger                             CallBack                Argument    */\
/* ----------------------------------------------------------------------------------------------------------------------------------------------------------*/\
    X_IO_IRQ(IO_IRQ_xxxx,           IO_xxx,             EXTIx_x_IRQn,    4,          IO_EXTI_TRIGGER_RISING,             nullptr,                nullptr)      \
/* ---------------------------------------------------------------------------------------------------------------------------------------------------------*/
#endif

//-------------------------------------------------------------------------------------------------

