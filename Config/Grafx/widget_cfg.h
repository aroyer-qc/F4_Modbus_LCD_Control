//-------------------------------------------------------------------------------------------------
//
//  File :  widget_cfg.h
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
//
//  Notes:
//
//  Px      -> Position X
//  Py      -> Position Y
//  Px1-Px4 -> Position Point X
//  Py1-Py4 -> Position Point Y
//  Sx      -> Size X
//  Sy      -> Size Y
//  TPx     -> Text Position X
//  TPy     -> Text Position Y
//  TSx     -> Text Size X
//  TSy     -> Text Size Y
//  GPx     -> Glyph Position X
//  GPy     -> Glyph Position Y
//  BC      -> Back Color
//  TC      -> Text Color
//  TAC     -> Text Alternate Color
//  TAC2    -> Text Alternate Color 2
//  TC_PR   -> Text Color for pressed button
//  TC_GR   -> Text Color for inactive button
//  PTC     -> Pressed Text Color
//  TOPx    -> Touch Position X
//  TOPy    -> Touch Position Y
//  TOSx    -> Touch Size X
//  TOSy    -> Touch Size Y
//  COx     -> Cursor Offset X
//  COy     -> Cursor Offset Y
//  CSV     -> Cursor Start Value      ex. 0%
//  CEV     -> Cursor End Value        ex. 100%
//  CPR     -> Cursor Pixel Range      ex. 0% to 100% = 384 Pixel
//  ResX    -> Resolution Widget X     Not necessarily in pixel ( Ex. SPECTRUM -> 16 line x 12 dot)
//  ResY    -> Resolution Widget Y
//
//
//-------------------------------------------------------------------------------------------------
//
//  'Timing' is for future development, so we can decide to refresh widget at different interval
//                  GRAFX_OPTION_MOVABLE_OBJECT future development
//
//-------------------------------------------------------------------------------------------------

#pragma once

//-------------------------------------------------------------------------------------------------
// Individual widget Definition
//-------------------------------------------------------------------------------------------------
//       Enum ID,         Service,      Sub, Px, Py, IMG0,             IMG_1,         IMG_2,         IMG_3,         IMG_4,         IMG_5,         IMG_6,         IMG_7,         IMG_8,         IMG_9,         IMG_10,        IMG_11,        IMG_12,        IMG_13,        IMG_14,        IMG_15,        Options
#define BACK_DEF(X_BACK)\
 X_BACK( BACK_SCREEN,     SERV_ID_RFSH, 0,   0,  0,  BACKGROUND,       INVALID_IMAGE, INVALID_IMAGE, INVALID_IMAGE, INVALID_IMAGE, INVALID_IMAGE, INVALID_IMAGE, INVALID_IMAGE, INVALID_IMAGE, INVALID_IMAGE, INVALID_IMAGE, INVALID_IMAGE, INVALID_IMAGE, INVALID_IMAGE, INVALID_IMAGE, INVALID_IMAGE, GRAFX_OPTION_DRAW_ONCE_AND_REMOVE )\

//      Enum ID,         Service,      Sub,                   Px,   Py,   Released btn,       Pressed button,      Inactive button,   GPx,  GPy,  Released glyph,     Pressed glyph,      Inactive glyph  TOPx, TOPy, TOSx, TOSy, TPx,  TPy,   TSx,  TSy,  TC,         TC_PR,        TC_GR,        Font ID,             Text Option,             Text Label,     Filter,                 Option,
#define BTN_DEF(X_BTN)                                                                                                                                                                                                                                                                                                                                                                                                                           \
 X_BTN( BTN_TEST1,       SERV_ID_BDEF, 0,                     4,    50,  BUTTON_MENU_NORMAL,  BUTTON_MENU_PRESSED, BUTTON_MENU_GRAY,  117,  9,    GLYPH_DIAGNOSTIC,   GLYPH_DIAGNOSTIC,   INVALID_IMAGE,  0,    5,    15,   4,    10,   10,    120,  15,   BROWN,      BLACK,        0,            FONT_ARIAL_10_B,     0,                       LBL_LED_GREEN,  SERVICE_FILTER_NORMAL,  GRAFX_OPTION_TOUCH_RECTANGLE | GRAFX_OPTION_BLEND_ALPHA)\
 X_BTN( BTN_TEST2,       SERV_ID_BDEF, 0,                     4,    100, BUTTON_MENU_NORMAL,  BUTTON_MENU_PRESSED, BUTTON_MENU_GRAY,  117,  9,    GLYPH_INFO,         GLYPH_INFO,         INVALID_IMAGE,  0,    10,   15,   4,    10,   10,    120,  15,   BROWN,      BLACK,        0,            FONT_ARIAL_10_B,     0,                       LBL_LED_RED,    SERVICE_FILTER_NORMAL,  GRAFX_OPTION_TOUCH_RECTANGLE | GRAFX_OPTION_BLEND_ALPHA)\
 X_BTN( BTN_TEST3,       SERV_ID_BDEF, 0,                     4,    150, BUTTON_MENU_NORMAL,  BUTTON_MENU_PRESSED, BUTTON_MENU_GRAY,  112,  9,    GLYPH_MEASURE,      GLYPH_MEASURE,      INVALID_IMAGE,  0,    15,   15,   4,    10,   10,    120,  15,   BROWN,      BLACK,        0,            FONT_ARIAL_10_B,     0,                       LBL_LED_BLUE,   SERVICE_FILTER_NORMAL,  GRAFX_OPTION_TOUCH_RECTANGLE | GRAFX_OPTION_BLEND_ALPHA)\
 X_BTN( BTN_TEST4,       SERV_ID_BDEF, 0,                     4,    200, BUTTON_MENU_NORMAL,  BUTTON_MENU_PRESSED, BUTTON_MENU_GRAY,  112,  9,    GLYPH_RANGE,        GLYPH_RANGE,        INVALID_IMAGE,  0,    20,   15,   4,    10,   10,    120,  15,   BROWN,      BLACK,        0,            FONT_ARIAL_10_B,     0,                       LBL_LED_YELLOW, SERVICE_FILTER_NORMAL,  GRAFX_OPTION_TOUCH_RECTANGLE | GRAFX_OPTION_BLEND_ALPHA)\
 X_BTN( BTN_TEST5,       SERV_ID_BDEF, 0,                     164,  50,  BUTTON_MENU_NORMAL,  BUTTON_MENU_PRESSED, BUTTON_MENU_GRAY,  113,  9,    GLYPH_REFERENCE,    GLYPH_REFERENCE,    INVALID_IMAGE,  16,   5,    15,   4,    10,   5,     120,  15,   BROWN,      BLACK,        0,            FONT_ARIAL_10_B,     0,                       INVALID_LABEL,  SERVICE_FILTER_NORMAL,  GRAFX_OPTION_TOUCH_RECTANGLE | GRAFX_OPTION_BLEND_ALPHA)\
 X_BTN( BTN_TEST6,       SERV_ID_BDEF, 0,                     164,  100, BUTTON_MENU_NORMAL,  BUTTON_MENU_PRESSED, BUTTON_MENU_GRAY,  113,  9,    GLYPH_WARNING,      GLYPH_WARNING,      INVALID_IMAGE,  16,   10,   15,   4,    10,   5,     120,  15,   BROWN,      BLACK,        0,            FONT_ARIAL_10_B,     0,                       INVALID_LABEL,  SERVICE_FILTER_NORMAL,  GRAFX_OPTION_TOUCH_RECTANGLE | GRAFX_OPTION_BLEND_ALPHA)\

//      Enum ID,          Service,      Sub, Px,   Py,   Sx,   Sy,   Icon 0,  		 Icon 1, 	    Icon 2,        Icon 3,        Option,
#define ICON_DEF(X_ICON) \
X_ICON( ICON_LED_GREEN,   SERV_ID_LEDS, 0,   300,  4,    0,    0,    LED_GREEN_OFF,  LED_GREEN_ON,  INVALID_IMAGE, INVALID_IMAGE,  GRAFX_OPTION_NONE  ) \
X_ICON( ICON_LED_RED,     SERV_ID_LEDS, 1,   198,  4,    0,    0,    LED_RED_OFF,    LED_RED_ON,    INVALID_IMAGE, INVALID_IMAGE,  GRAFX_OPTION_NONE  ) \
X_ICON( ICON_LED_YELLOW,  SERV_ID_LEDS, 2,   96,   4,    0,    0,    LED_YELLOW_OFF, LED_YELLOW_ON, INVALID_IMAGE, INVALID_IMAGE,  GRAFX_OPTION_NONE  ) \
X_ICON( ICON_LED_BLUE,    SERV_ID_LEDS, 3,   4,    4,    0,    0,    LED_BLUE_OFF,   LED_BLUE_ON,   INVALID_IMAGE, INVALID_IMAGE,  GRAFX_OPTION_NONE  ) \


//     Enum ID,              Service,      Sub, Px,   Py,   Sx,   Sy,   TC,      TAC,     TAC2,     Font ID,               Text Blend,   Text Label        Background Text Label,  Text Option         Option
#define LABEL_DEF(X_LBL) \
X_LBL( LABEL_TEST,           SERV_ID_TEST, 0,   200,  145,  119,  56,   GREEN,   GRAY_16, GRAY_16,  FONT_DS_DIGITAL_24_B,  ALPHA_BLEND,  LBL_5_DEC,        LBL_5_BACK,             _X_LEFT_Y_CENTER,   GRAFX_OPTION_NONE) \
X_LBL( LABEL_TIME,           SERV_ID_TIME, 0,   0,    7,    128,  20,   GRAY_16, GRAY_16, GRAY_16,  FONT_ARIAL_16_B,       ALPHA_BLEND,  LBL_TIME,         INVALID_LABEL,          _X_LEFT_Y_CENTER,   GRAFX_OPTION_NONE) \
X_LBL( LABEL_DATE,           SERV_ID_DATE, 0,   0,    67,   128,  20,   GRAY_16, GRAY_16, GRAY_16,  FONT_ARIAL_16_B,       ALPHA_BLEND,  LBL_DATE,         INVALID_LABEL,          _X_LEFT_Y_CENTER,   GRAFX_OPTION_NONE) \

//-------------------------------------------------------------------------------------------------








