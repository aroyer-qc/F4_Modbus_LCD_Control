//-------------------------------------------------------------------------------------------------
//
//  File : diskio_drv_cfg.h
//
//-------------------------------------------------------------------------------------------------
//
// Copyright(c) 2023 Alain Royer.
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
//
//  Add here any custom driver for the FatFS. 
//
//
//-------------------------------------------------------------------------------------------------

// #include "lib_class_fatfs_my_custom_driver.h"
// #include etc..

#define FAT_FS_DRIVE_DEF(X_DRIVE)\
/*                                                    ID of the FatFS drive,	Class object,         sub driver,     optional argument */\
    IF_USE( DIGINI_FATFS_USE_SPI_FLASH_CHIP, X_DRIVE( DISK_SPI_FLASH,           FatFS_SPI_FlashDisk,  SPI_ForFlash,   nullptr))           \

#if 0 // other example of drive
    IF_USE( DIGINI_FATFS_USE_SPI_SD_CARD,    X_DRIVE( SPI_SD_CARD,       		FatFS_SD_Card,        SPI_SD_Card,    nullptr  ))\
    IF_USE( DIGINI_FATFS_USE_SDIO_SD_CARD,   X_DRIVE( DISK_SDIO_SD_CARD, 		FatFS_SDIO,           SDIO_SD_Card,   nullptr  ))\
    IF_USE( DIGINI_FATFS_USE_USB_KEY,        X_DRIVE( DISK_USB_KEY,      		FatFS_USB,            USB_Key,        nullptr  ))\
    IF_USE( DIGINI_FATFS_USE_RAM_DISK,       X_DRIVE( DISK_RAM_DISK,     		FatFS_RAM_Disk,       RAM_Disk,       nullptr  ))\
	
#endif

//-------------------------------------------------------------------------------------------------
