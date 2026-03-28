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
//      Enum ID,         Service,      Sub, Px, Py,   Sx,   Sy,   Icon 0,  		 Icon 1, 	    Icon 2,        Icon 3,        Option,
#define ICON_DEF(X_ICON) \
X_ICON( BACK_RCA,        SERV_ID_RFSH, 0,   0,  0,    0,    0,    BACK_RCA_IMG,  INVALID_IMAGE, INVALID_IMAGE, INVALID_IMAGE, GRAFX_OPTION_BLEND_CLEAR  ) \
X_ICON( ICON_STATUS,     SERV_ID_RFSH, 0,   5,  98,   0,    0,    INVALID_IMAGE, INVALID_IMAGE, INVALID_IMAGE, INVALID_IMAGE, GRAFX_OPTION_BLEND_CLEAR  ) \

//     Enum ID,              Service,      Sub, Px,   Py,   Sx,   Sy,   TC,      TAC,     TAC2,     Font ID,         Text Blend,   Text Label        Text Option         Option
#define LABEL_DEF(X_LBL) \
X_LBL( LABEL_TIME,           SERV_ID_TIME, 0,   0,    7,    128,  20,   GRAY_16, GRAY_16, GRAY_16,  SYS_FT_12,       CLEAR_BLEND,  LBL_TIME,         _X_LEFT_Y_CENTER,   GRAFX_OPTION_NONE) \
X_LBL( LABEL_DATE,           SERV_ID_DATE, 0,   0,    67,   128,  20,   GRAY_16, GRAY_16, GRAY_16,  SYS_FT_12,       CLEAR_BLEND,  LBL_DATE,         _X_LEFT_Y_CENTER,   GRAFX_OPTION_NONE) \

//-------------------------------------------------------------------------------------------------








