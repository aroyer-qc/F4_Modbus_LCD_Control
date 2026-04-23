//-------------------------------------------------------------------------------------------------
//
//  File :  label_cfg.h
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

#pragma once

//-------------------------------------------------------------------------------------------------
// Define(s)
//-------------------------------------------------------------------------------------------------

// Notes some default label exist in the file "lib_label.h", some of them can be enable/disable in this configuratio

#define     DIGINI_USE_LABEL_DATE               DEF_ENABLED
#define     DIGINI_USE_LABEL_TIME               DEF_ENABLED
#define     DIGINI_USE_LABEL_PRODUCT_INFO       DEF_ENABLED
#define     DIGINI_USE_LABEL_DECIMAL_KEY        DEF_DISABLED            // Enable label 0-9 and dot, del, sign, sign inversion
#define     DIGINI_USE_LABEL_HEXADECIMAL_KEY    DEF_DISABLED            // Enable label A-F

#define USER_LABEL_LANGUAGE_DEF(X_LBL_CFG) \
    X_LBL_CFG( LBL_TEST_MENU,             "    Test Menu\r\n",                                                                                         "    Menu Des Tests\r\n"                   ) \
    X_LBL_CFG( LBL_TEST_OPT1,             "LED Control\r\n",                                                                                           "Contr\x93le LEDs\r\n"                     ) \
    X_LBL_CFG( LBL_TEST_OPT2,             "poutine Control\r\n",                                                                                       "Contr\x93le Poutine\r\n"                  ) \
    X_LBL_CFG( LBL_TEST_OPT4,             "Input Reading And Sensor\r\n",                                                                              "Lecture D'Entr\x82 et Capteur"            ) \
    X_LBL_CFG( LBL_TEST_OPT5,             "Bluetooth\r\n",                                                                                             nullptr                                    ) \
\
    X_LBL_CFG( LBL_LED_MENU,              "    LED Control Menu\r\n",                                                                                  "    Menu Contr\x93le LEDs\r\n"            ) \
    X_LBL_CFG( LBL_LED_GREEN,             "Test 1",                                                                                                    nullptr                                    ) \
    X_LBL_CFG( LBL_LED_RED,               "Poutine",                                                                                                   nullptr                                    ) \
    X_LBL_CFG( LBL_LED_BLUE,              "Hello!",                                                                                                    nullptr                                    ) \
    X_LBL_CFG( LBL_LED_YELLOW,            "coucou",                                                                                                    nullptr                                    ) \
\
    X_LBL_CFG( LBL_SETTING_MENU,          "    System Settings Menu\r\n",                                                                              "    Menu R\x82glage Syst\x8ame\r\n"       ) \
    X_LBL_CFG( LBL_SETTING_OPT1,          "Time and Date\r\n",                                                                                         "Heure et Date\r\n"                        ) \
\
    X_LBL_CFG( LBL_5_BACK,                "88888",                                                                                                     nullptr                                    ) \
    X_LBL_CFG( LBL_5_DEC,                 "%05d",                                                                                                      nullptr                                    ) \
\

//-------------------------------------------------------------------------------------------------
