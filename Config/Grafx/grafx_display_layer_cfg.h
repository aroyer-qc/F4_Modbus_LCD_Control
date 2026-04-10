//-------------------------------------------------------------------------------------------------
//
//  File :  grafx_display_layer_cfg.h
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

// Because of the nature of the LCD 8080 FMC mode, and the lack of external memory:
//	- There is no construction layer
//	- Coarse touch layer (10 pixels x 10 Pixels) Array 768 Bytes  number of touch zone == 256

//-------------------------------------------------------------------------------------------------
//           Name of the layer              Initial layer      Pixel Format            Size X                    Size Y
#define LAYER_DEF(X_LAYER) \
    X_LAYER( BACKGROUND_DISPLAY_LAYER_0,    LAYER_DUMMY,       PIXEL_FORMAT_RGB565,    0,                        0)\
    X_LAYER( FOREGROUND_DISPLAY_LAYER_0,    LAYER_DUMMY,       PIXEL_FORMAT_RGB565,    0,                        0)\
    X_LAYER( TOUCH_SENSE_LAYER,             LAYER_VIRTUAL,     PIXEL_FORMAT_A8,        GRAFX_DRIVER_SIZE_X / 10, GRAFX_DRIVER_SIZE_Y / 10)\

//-------------------------------------------------------------------------------------------------

// Unused define layer
// CONSTRUCTION_BACKGROUND_LAYER,
// CONSTRUCTION_FOREGROUND_LAYER,
// FOREGROUND_SLIDING_LAYER,



