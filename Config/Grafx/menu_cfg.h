//-------------------------------------------------------------------------------------------------
//
//  File :  Menu_cfg.h
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
//  Global Variable(s)
//-------------------------------------------------------------------------------------------------

#ifdef GFX_GLOBAL

const PageWidget_t PageBootScreen       [] =  { {   BACK_SCREEN,             INVALID_LINK        },
                                                {   BTN_TEST1,               INVALID_LINK        },
                                                {   BTN_TEST2,               INVALID_LINK        },
                                                {   BTN_TEST3,               INVALID_LINK        },
                                                {   BTN_TEST4,               INVALID_LINK        },
                                                {   BTN_TEST5,               INVALID_LINK        },
                                                {   BTN_TEST6,               INVALID_LINK        },
                                                {   ICON_LED_GREEN,          INVALID_LINK        },
                                                {   ICON_LED_RED,            INVALID_LINK        },
                                                {   ICON_LED_YELLOW,         INVALID_LINK        },
                                                {   ICON_LED_BLUE,           INVALID_LINK        },
                                                {   LABEL_TEST,              INVALID_LINK        },
                                                {   INVALID_WIDGET,          INVALID_LINK        }
                                              };

const PageWidget_t PageMainHub          [] =  {
                                                {   INVALID_WIDGET,          INVALID_LINK        }
                                              };

const PageWidget_t PageMenu             [] =  { //{   VIRTUAL_JOG_HUB,         INVALID_LINK        },
                                                {   INVALID_WIDGET,          INVALID_LINK        }
                                              };

const PageWidget_t PageDiagnostic    [] =  { //{   BACK_DIAMOND,            INVALID_LINK        },      // Background
                                                //{   BOX_1_3,                 LINK_AXIS_X         },      // Yellow box around axis X information
                                                //{   BOX_2_3,                 LINK_AXIS_Y         },      //   " Y
                                                //{   BOX_3_3,                 LINK_SPINDLE        },      //   " Spindle
                                                //{   LABEL_AXIS_X_1_3_BACK,   INVALID_LINK        },      // Background digit in dark gray for OFF display segment for X
                                                //{   LABEL_AXIS_Y_2_3_BACK,   INVALID_LINK        },      //   " for Y
                                                //{   LABEL_SPEED_3_3_BACK,    INVALID_LINK        },      //   " for Spindle speed
                                                //{   LABEL_AXIS_X_1_3,        INVALID_LINK        },      // Fix label 'Axis X'
                                                //{   LABEL_AXIS_Y_2_3,        INVALID_LINK        },      // Fix label 'Axis Y'
                                                //{   LABEL_SPINDLE_3_3,       INVALID_LINK        },      // Fix label 'Spindle'
                                                //{   LABEL_ENABLE,            INVALID_LINK        },      // Fix label 'Enable'
                                                //{   LABEL_COOLANT,           INVALID_LINK        },      // Fix label 'Coolant'
                                                //{   LABEL_MIST,              INVALID_LINK        },      // Fix label 'Mist'
                                                //{   LABEL_MM_INCH_X_1_3,     INVALID_LINK        },      // Label 'mm' or 'inch' for X
                                                //{   LABEL_MM_INCH_Y_2_3,     INVALID_LINK        },      // Label 'mm' or 'inch' for Y
                                                //{   LABEL_RPM_3_3,           INVALID_LINK        },      // Fix label 'RPM' for Spindle unit
                                                //{   LABEL_SYS_COORD_X_1_3,   INVALID_LINK        },      // Label 'ABS' or 'REL' or 'MAC' for X
                                                //{   LABEL_SYS_COORD_Y_2_3,   INVALID_LINK        },      // Label 'ABS' or 'REL' or 'MAC' for Y
                                                //{   BTN_SETTING,             LINK_MAIN_MENU      },      // Button to go to setting menu
// add Jog button to page                       {   BTN_JOG,                 LINK_JOG_HUB        },      // Yellow box around axis X information
                                                //{   LABEL_X_1_3,             INVALID_LINK        },      // Axis X position for configure display setting (ABS, REL, MAC)
                                                //{   LABEL_Y_2_3,             INVALID_LINK        },      // Axis Y    "
                                                //{   LABEL_SPEED_3_3,         INVALID_LINK        },      // Actual Spindle speed
                                                //{   LABEL_x_1_3,             INVALID_LINK        },      // X machine position if enable
                                                //{   LABEL_y_2_3,             INVALID_LINK        },      // Y machine position if enable
                                                //{   LABEL_SYS_COORD_x_1_3,   INVALID_LINK        },      // Label 'ABS' or 'REL' or 'MAC' for X
                                                //{   LABEL_SYS_COORD_y_2_3,   INVALID_LINK        },      // Label 'ABS' or 'REL' or 'MAC' for Y
                                                //{   ICON_LED_LIMIT_X_3,      INVALID_LINK        },      // X Led limit
                                                //{   ICON_LED_LIMIT_Y_3,      INVALID_LINK        },      // Y Led limit
                                                //{   ICON_LED_SPINDLE_3_3,    INVALID_LINK        },      // LED enable for Spindle
                                                //{   ICON_LED_ENABLE,         INVALID_LINK        },      // LED Enable
                                                //{   ICON_LED_COOLANT,        INVALID_LINK        },      // LED coolant active
                                                //{   ICON_LED_MIST,           INVALID_LINK        },      // LED mist active
                                                {   INVALID_WIDGET,          INVALID_LINK        }
                                              };

const PageWidget_t PageTerminal         [] =  { //{   BACK_DIAMOND,            INVALID_LINK        },      // Background
                                                //{   BTN_RETURN,              LINK_MAIN_HUB       },      // Button to go to setting menu
                                                //{   TERM_GCODE_FULL,         INVALID_LINK        },      // LED coolant active
                                                {   INVALID_WIDGET,          INVALID_LINK        }
                                              };

const PageWidget_t PageInfo             [] =  { //{   BACK_DIAMOND,            INVALID_LINK        },
                                                //{   BTN_RETURN_DOWN,         PREVIOUS_LINK       },
                                                //{   LABEL_INFO,              INVALID_LINK        },
                                                //{   LABEL_FW_NAME_INFO,      INVALID_LINK        },
                                                //{   LABEL_FW_VERSION_INFO,   INVALID_LINK        },
                                                //{   LABEL_GUI_NAME_INFO,     INVALID_LINK        },
                                                //{   LABEL_GUI_VERSION_INFO,  INVALID_LINK        },
                                                //{   LABEL_HARDWARE_INFO,     INVALID_LINK        },
                                                //{   LABEL_SERIAL_INFO,       INVALID_LINK        },
                                                //{   LABEL_COMPILE_DATE_INFO, INVALID_LINK        },
                                                //{   LABEL_INFO_FIRMWARE,     INVALID_LINK        },
                                                //{   LABEL_INFO_VERSION,      INVALID_LINK        },
                                                //{   LABEL_INFO_GUI_FIRMWARE, INVALID_LINK        },
                                                //{   LABEL_INFO_GUI_VERSION,  INVALID_LINK        },
                                                //{   LABEL_INFO_HARDWARE,     INVALID_LINK        },
                                                //{   LABEL_INFO_SERIAL,       INVALID_LINK        },
                                                //{   LABEL_INFO_DATE,         INVALID_LINK        },
                                                {   INVALID_WIDGET,          INVALID_LINK        }
                                              };

#endif  // GFX_GLOBAL

//-------------------------------------------------------------------------------------------------




