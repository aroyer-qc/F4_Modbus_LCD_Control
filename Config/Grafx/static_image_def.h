//-------------------------------------------------------------------------------------------------
//
//  File :  Static_image.h
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
//
//  Notes: X-macro Listing all the image resident in flash
//
//-------------------------------------------------------------------------------------------------

#pragma once

//-------------------------------------------------------------------------------------------------

//                  IMAGE_ID        Struct Info Image
#define STATIC_IMAGE_DEF(X_STATIC_IMAGE)  \
    X_STATIC_IMAGE( BOOT_SCREEN,        &SII_BootScreen          )\
    X_STATIC_IMAGE( PROGRESS_CURSOR,    &SII_ProgressCursor      )\
    X_STATIC_IMAGE( PROGRESS_BAR,       &SII_ProgressBar         )\
    X_STATIC_IMAGE( LED_BLUE_OFF,       &SII_LedBlueOff_16x16    )\
    X_STATIC_IMAGE( LED_BLUE_ON,        &SII_LedBlueOn_16x16     )\
    X_STATIC_IMAGE( LED_GRAY_OFF,       &SII_LedGrayOff_16x16    )\
    X_STATIC_IMAGE( LED_GREEN_OFF,      &SII_LedGreenOff_16x16   )\
    X_STATIC_IMAGE( LED_GREEN_ON,       &SII_LedGreenOn_16x16    )\
    X_STATIC_IMAGE( LED_RED_OFF,        &SII_LedRedOff_16x16     )\
    X_STATIC_IMAGE( LED_RED_ON,         &SII_LedRedOn_16x16      )\
    X_STATIC_IMAGE( LED_YELLOW_OFF,     &SII_LedYellowOff_16x16  )\
    X_STATIC_IMAGE( LED_YELLOW_ON,      &SII_LedYellowOn_16x16   )\

//-------------------------------------------------------------------------------------------------



