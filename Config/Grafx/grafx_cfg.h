//-------------------------------------------------------------------------------------------------
//
//  File :  grafx_cfg.h
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
// Notes: if GRAFX_USE_A_SKIN is define
//
//      lib_compression make use of the display memory for:
//          - Loading of the compressed image
//          - to hold temporary data use during decompression
//          - to hold decompressed data before storage in to the database
//
//-------------------------------------------------------------------------------------------------

#pragma once

//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
// Define(s)
//-------------------------------------------------------------------------------------------------

#define GRAFX_USE_LOAD_SKIN                             DEF_DISABLED
#define GRAFX_USE_POINTING_DEVICE                       DEF_DISABLED // DEF_ENABLED
#define GRAFX_USE_PDI_MULTI_EVENT                       DEF_DISABLED    // Enable support for Multi-touch
#define GRAFX_PDI_INTERRUPT_IO                          DEF_DISABLED    // Pointing device IRQ (touch)
#define GRAFX_USE_RAM_DATABASE                          DEF_DISABLED    // Not used as all graphic/font etc, are static
#define GRAFX_USE_HARD_DATABASE                         DEF_ENABLED     // Use graphic/font etc from flash memory
#define GRAFX_USE_GRAFX_CUSTOM_COLOR                    DEF_DISABLED    // Will not try to load color_cfg.h

#define GRAFX_USE_DISPLAY_RAM                           DEF_ENABLED
#define GRAFX_USE_RAM_DATA                              DEF_DISABLED     // if ram memory was reserved in loading script for layer
#define GRAFX_USE_ROM_DATA                              DEF_DISABLED


// Special section use in this project
#define GRAFX_USE_MULTI_LINE                            DEF_DISABLED

#define GRAFX_USE_SLIDING_PAGE                          DEF_DISABLED
#define GRAFX_SLIDING_PAGE_GRANULARITY                  16              // Each step is 10 Pixel wide
#define GRAFX_TICK_WAIT_BETWEEN_SLIDE_IN_LOOP           16

#define GRAFX_DEBUG_GUI                                 DEF_DISABLED	// This option can not be set if no layer exist
#define GRAFX_PAINT_BOX_DEBUG                           DEF_DISABLED
#define GRAFX_PAINT_BOX_DEBUG_COLOR                     RED

#define DIGINI_USE_QUAD_SPI_FOR_GRAFX_DATABASE      	DEF_DISABLED

#if (GRAFX_USE_POINTING_DEVICE == DEF_ENABLED)
  #define GRAFX_PDI_SWAP_XY                             DEF_ENABLED
  #define GRAFX_PDI_INVERT_X                            DEF_DISABLED    // Not existent on this setup
  #define GRAFX_PDI_INVERT_Y                            DEF_DISABLED    // Not existent on this setup
#endif

#define GRAFX_USE_FONT_SIZE_8                           DEF_DISABLED    // Must not used when GRAFX_USE_RAM_DATABASE is DEF_DISABLED
#define GRAFX_USE_FONT_SIZE_12                          DEF_DISABLED
#define GRAFX_USE_FONT_SIZE_16                          DEF_DISABLED

///------------------------------------------------------------------------------------------------
/// Color supported mode in this project
#define GRAFX_COLOR_ARGB8888                            DEF_ENABLED     // Needed to merge graphic using DMA2D
#define GRAFX_COLOR_RGB888                              DEF_DISABLED
#define GRAFX_COLOR_RGB565                              DEF_ENABLED
#define GRAFX_COLOR_ARGB1555                            DEF_DISABLED
#define GRAFX_COLOR_ARGB4444                            DEF_DISABLED
#define GRAFX_COLOR_L8                                  DEF_DISABLED
#define GRAFX_COLOR_AL44                                DEF_DISABLED
#define GRAFX_COLOR_AL88                                DEF_DISABLED
#define GRAFX_COLOR_L4                                  DEF_DISABLED
#define GRAFX_COLOR_A8                                  DEF_ENABLED     // Needed for the FONT and also for the touch sensing layer
#define GRAFX_COLOR_A4                                  DEF_DISABLED
#define GRAFX_COLOR_RGB332                              DEF_DISABLED
#define GRAFX_COLOR_RGB444                              DEF_DISABLED

#define DIGINI_MAX_PRINT_NUMBER_OF_LINE                 8               // This is the maximum number of line in the same string

// Default service available in Grafx
#define USE_SERV_DATE                                   DEF_DISABLED    // Service to provide the date
#define USE_SERV_INPD                                   DEF_DISABLED    // Service to input a decimal value
#define USE_SERV_INPF                                   DEF_DISABLED    // Service to input a float value
#define USE_SERV_INPH                                   DEF_DISABLED    // Service to input a Hexa value
#define USE_SERV_INPS                                   DEF_DISABLED    // Service to input a string
#define USE_SERV_TIME                                   DEF_DISABLED    // Service to provide time
#define USE_SERV_XCHG                                   DEF_DISABLED    // Special service to exchange data.

// Define for GRAFX Driver
#define GRAFX_LCD_BASE                                  FMC_BANK1_1             // NE1 region
#define GRAFX_LCD_REGISTER_SELECT_BIT                   16                      // A16

#define GRAFX_TICK_WAIT_BETWEEN_REFRESH_LOOP            8

//-------------------------------------------------------------------------------------------------
// Layer support configuration (other than TOUCH_SENSE_LAYER, we won't use full frame RAM for construction)

#define GRAFX_USE_BACKGROUND_LAYER                      DEF_DISABLED	// We don't have access to display memory and don't have multi layer capability here
#define GRAFX_USE_CONSTRUCTION_BACKGROUND_LAYER         DEF_DISABLED	// We don't have access to display memory and don't have multi layer capability here
#define GRAFX_USE_FOREGROUND_LAYER           			DEF_DISABLED    // We don't access display memory via layer
#define GRAFX_USE_CONSTRUCTION_FOREGROUND_LAYER         DEF_DISABLED
#define GRAFX_DEBUG_GUI                                 DEF_DISABLED	// This option can not be set if no layer exist

//-------------------------------------------------------------------------------------------------
