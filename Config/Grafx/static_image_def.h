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
    X_STATIC_IMAGE( BACKGROUND,         	&SII_DiamondPlate        )\
    X_STATIC_IMAGE( LED_BLUE_OFF,       	&SII_LedBlueOff_16x16    )\
    X_STATIC_IMAGE( LED_BLUE_ON,        	&SII_LedBlueOn_16x16     )\
    X_STATIC_IMAGE( LED_GRAY_OFF,       	&SII_LedGrayOff_16x16    )\
    X_STATIC_IMAGE( LED_GREEN_OFF,      	&SII_LedGreenOff_16x16   )\
    X_STATIC_IMAGE( LED_GREEN_ON,       	&SII_LedGreenOn_16x16    )\
    X_STATIC_IMAGE( LED_RED_OFF,        	&SII_LedRedOff_16x16     )\
    X_STATIC_IMAGE( LED_RED_ON,         	&SII_LedRedOn_16x16      )\
    X_STATIC_IMAGE( LED_YELLOW_OFF,     	&SII_LedYellowOff_16x16  )\
    X_STATIC_IMAGE( LED_YELLOW_ON,      	&SII_LedYellowOn_16x16   )\
    X_STATIC_IMAGE( BUTTON_MENU_GRAY,   	&SII_BtMenuGray          )\
    X_STATIC_IMAGE( BUTTON_MENU_NORMAL, 	&SII_BtMenuNormal        )\
    X_STATIC_IMAGE( BUTTON_MENU_PRESSED, 	&SII_BtMenuPressed       )\
    X_STATIC_IMAGE( BUTTON_SPHERE_NORMAL, 	&SII_Sphere              )\
    X_STATIC_IMAGE( BUTTON_SPHERE_PRESSED, 	&SII_SpherePressed       )\
    X_STATIC_IMAGE( GLYPH_DIAGNOSTIC, 	    &SII_Diagnostic          )\
    X_STATIC_IMAGE( GLYPH_INFO,         	&SII_Info                )\
    X_STATIC_IMAGE( GLYPH_MEASURE, 	        &SII_Measure             )\
    X_STATIC_IMAGE( GLYPH_RANGE,         	&SII_Range               )\
    X_STATIC_IMAGE( GLYPH_REFERENCE,        &SII_Reference           )\
    X_STATIC_IMAGE( GLYPH_WARNING,      	&SII_Warning             )\
    X_STATIC_IMAGE( GLYPH_OK,           	&SII_Ok                  )\

//-------------------------------------------------------------------------------------------------



