cmake_minimum_required(VERSION 3.18)

project(F4_Modbus_LCD_Control C CXX ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")

set(CPU_FLAGS "-mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=hard")

set(COMMON_C_FLAGS "-fno-strict-aliasing -ffunction-sections -fdata-sections ")
set(COMMON_CXX_FLAGS "-fno-strict-aliasing -ffunction-sections -fdata-sections -fno-use-cxa-atexit")

set(LINKER_SCRIPT "${CMAKE_CURRENT_LIST_DIR}/stm32f437vg_flash.ld")

set(CMAKE_C_FLAGS_DEBUG   "-O0 -g3 ${CPU_FLAGS} ${COMMON_C_FLAGS} -DDEBUG")
set(CMAKE_C_FLAGS_RELEASE "-O2 -g2 ${CPU_FLAGS} ${COMMON_C_FLAGS}")

set(CMAKE_CXX_FLAGS_DEBUG   "-O0 -g3 ${CPU_FLAGS} ${COMMON_CXX_FLAGS} -DDEBUG -Wno-psabi -Wno-literal-suffix -fpermissive -fschedule-insns -Wno-register")
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -g2 ${CPU_FLAGS} ${COMMON_CXX_FLAGS} -fschedule-insns -Wno-register")

set(CMAKE_ASM_FLAGS "${CPU_FLAGS} -Wa,--gdwarf-2 -save-temps -fdata-sections -ffunction-sections")

set(CMAKE_EXE_LINKER_FLAGS "${CPU_FLAGS} --specs=nosys.specs -Wl,--warn-common=no -Wl,--no-warn-rwx-segments -Wl,--no-warn-mismatch -Wl,--gc-sections -Wl,--no-warn-rwx-segments -lm -T${LINKER_SCRIPT}")

# ---------------------------------------------------------------------------
# Generate syscalls.c automatically in the build directory
# ---------------------------------------------------------------------------
set(SYSCALLS_FILE "${CMAKE_BINARY_DIR}/syscalls.c")

file(WRITE ${SYSCALLS_FILE} "
#include <sys/stat.h>
#include <errno.h>
#include <stdint.h>

extern uint32_t _end;
static uint8_t *heap_end = 0;

caddr_t _sbrk(int incr)
{
    if (heap_end == 0) {
        heap_end = (uint8_t *)&_end;
    }

    uint8_t *prev = heap_end;
    heap_end += incr;
    return (caddr_t)prev;
}

int _write(int file, char *ptr, int len)
{
    return len;
}

int _read(int file, char *ptr, int len)
{
    errno = EINVAL;
    return -1;
}

int _close(int file)
{
    return -1;
}

int _lseek(int file, int ptr, int dir)
{
    return 0;
}

int _fstat(int file, struct stat *st)
{
    st->st_mode = S_IFCHR;
    return 0;
}

int _isatty(int file)
{
    return 1;
}
int _kill(int pid, int sig)
{
    errno = EINVAL;
    return -1;
}

int _getpid(void)
{
    return 1;
}

void _exit(int status)
{
    while (1) {}
}

void _abort(void)
{
    while (1) {}
}
")


set(SOURCES
    ${SYSCALLS_FILE}
    ./App/ressource/src/BtMenuGray.cpp
    ./App/ressource/src/BtMenuNormal.cpp
    ./App/ressource/src/BtMenuPressed.cpp
    ./App/ressource/src/Diagnostic.cpp
    ./App/ressource/src/DiamondPlate.cpp
    ./App/ressource/src/Info.cpp
    ./App/ressource/src/LedBlueOff_16x16.cpp
    ./App/ressource/src/LedBlueOn_16x16.cpp
    ./App/ressource/src/LedGrayOff_16x16.cpp
    ./App/ressource/src/LedGreenOff_16x16.cpp
    ./App/ressource/src/LedGreenOn_16x16.cpp
    ./App/ressource/src/LedRedOff_16x16.cpp
    ./App/ressource/src/LedRedOn_16x16.cpp
    ./App/ressource/src/LedYellowOff_16x16.cpp
    ./App/ressource/src/LedYellowOn_16x16.cpp
    ./App/ressource/src/Measure.cpp
    ./App/ressource/src/Ok.cpp
    ./App/ressource/src/Range.cpp
    ./App/ressource/src/Reference.cpp
    ./App/ressource/src/Sphere.cpp
    ./App/ressource/src/SpherePressed.cpp
    ./App/ressource/src/StaticFont.cpp
    ./App/ressource/src/Warning.cpp

    ./App/src/bsp.cpp
    ./App/src/irq.cpp
    ./App/src/main.cpp
    ./App/src/service.cpp
    ./App/src/task_main.cpp
    ./App/src/taskIdle.cpp
    ./App/src/vt100_user_callback.cpp
    ./App/src/modbus_callback.cpp

    ./App/startup_stm32f4xx.S

    #./ebmon.c

    ./Module/Digini/Comm/CmdLine/src/lib_cli.cpp
    ./Module/Digini/Comm/CmdLine/src/lib_cli_command.cpp
    ./Module/Digini/Comm/Comm/src/lib_comm.cpp
    ./Module/Digini/Comm/Console/src/lib_console.cpp
    ./Module/Digini/Comm/VT100/src/lib_vt100.cpp
    ./Module/Digini/Comm/VT100/src/lib_vt100_callback.cpp
    ./Module/Digini/Comm/Modbus/src/lib_class_modbus_serial.cpp

    ./Module/Digini/Database/src/lib_class_database.cpp
    ./Module/Digini/Database/src/lib_class_hard_dbase.cpp
    ./Module/Digini/Database/src/lib_class_rom_dbase.cpp
    ./Module/Digini/Database/src/lib_database_wrapper.cpp
    ./Module/Digini/Database/src/port/STM32F4xx/lib_class_STM32F4_bkpreg_dbase.cpp

    ./Module/Digini/Digini/src/digini.cpp
    ./Module/Digini/Digini/src/lib_label.cpp
    ./Module/Digini/Grafx/src/basic/lib_basic_alpha.cpp
    ./Module/Digini/Grafx/src/basic/lib_basic_box.cpp
    ./Module/Digini/Grafx/src/basic/lib_basic_polygon.cpp
    ./Module/Digini/Grafx/src/basic/lib_basic_printf.cpp

    ./Module/Digini/Grafx/src/color/lib_grafx_color.cpp

    ./Module/Digini/Grafx/src/driver/generic/lib_GenericDriver.cpp
    "./Module/Digini/Grafx/src/driver/STM32/lib_STM32_fmc_lcd_320x240 - UMSH_8252MD_T - SSD2119.cpp"
    ./Module/Digini/Grafx/src/driver/STM32/lib_STM32xxx_dma2d_GenericDriver.cpp

    ./Module/Digini/Grafx/src/font/lib_class_font.cpp

    ./Module/Digini/Grafx/src/layer/lib_class_layer.cpp

    ./Module/Digini/Grafx/src/lib_grafx.cpp
    ./Module/Digini/Grafx/src/lib_tools.cpp

    ./Module/Digini/Grafx/src/service/lib_service.cpp

    ./Module/Digini/Grafx/src/skin/lib_grafx_printf.cpp

    ./Module/Digini/Grafx/src/task/lib_gui_task.cpp
    ./Module/Digini/Grafx/src/task/lib_pdi_task.cpp

    ./Module/Digini/Grafx/src/widget/lib_widget_background.cpp
    ./Module/Digini/Grafx/src/widget/lib_widget_basic_box.cpp
    ./Module/Digini/Grafx/src/widget/lib_widget_basic_button.cpp
    ./Module/Digini/Grafx/src/widget/lib_widget_basic_rectangle.cpp
    ./Module/Digini/Grafx/src/widget/lib_widget_basic_shape.cpp
    ./Module/Digini/Grafx/src/widget/lib_widget_button.cpp
    ./Module/Digini/Grafx/src/widget/lib_widget_icon.cpp
    ./Module/Digini/Grafx/src/widget/lib_widget_label.cpp
    ./Module/Digini/Grafx/src/widget/lib_widget_label_list.cpp
    ./Module/Digini/Grafx/src/widget/lib_widget_variable.cpp

    ./Module/Digini/Memory/src/lib_memory.cpp

	./Module/Digini/Modbus/src/lib_class_modbus.cpp
	./Module/Digini/Modbus/src/lib_class_modbus_app.cpp

    ./Module/Digini/Peripheral/src/device/lib_class_resistive_touch_discrete.cpp
    ./Module/Digini/Peripheral/src/device/lib_class_spi_serial_flash.cpp

    ./Module/Digini/Peripheral/src/port/STM32F4xx/lib_class_STM32F4_adc.cpp
    ./Module/Digini/Peripheral/src/port/STM32F4xx/lib_class_STM32F4_crc.cpp
    ./Module/Digini/Peripheral/src/port/STM32F4xx/lib_class_STM32F4_dac.cpp
    ./Module/Digini/Peripheral/src/port/STM32F4xx/lib_class_STM32F4_dma.cpp
    ./Module/Digini/Peripheral/src/port/STM32F4xx/lib_class_STM32F4_pwm.cpp
    ./Module/Digini/Peripheral/src/port/STM32F4xx/lib_class_STM32F4_rtc.cpp
    ./Module/Digini/Peripheral/src/port/STM32F4xx/lib_class_STM32F4_spi.cpp
    ./Module/Digini/Peripheral/src/port/STM32F4xx/lib_class_STM32F4_tim.cpp
    ./Module/Digini/Peripheral/src/port/STM32F4xx/lib_class_STM32F4_uart.cpp
    ./Module/Digini/Peripheral/src/port/STM32F4xx/lib_STM32F4_fmc_lcd.cpp
    ./Module/Digini/Peripheral/src/port/STM32F4xx/lib_STM32F4_io.cpp
    ./Module/Digini/Peripheral/src/port/STM32F4xx/lib_STM32F4_isr.cpp
    ./Module/Digini/Peripheral/src/port/STM32F4xx/lib_STM32F4_rng.cpp
    ./Module/Digini/Peripheral/src/port/STM32F4xx/lib_STM32F4_system_clock.c

    ./Module/Digini/RTOS_Wrapper/src/nOS/lib_nOS_Tick.c

    ./Module/Digini/String/src/lib_string.cpp

    ./Module/Digini/Utility/src/lib_1aschex.cpp
    ./Module/Digini/Utility/src/lib_2aschex.cpp
    ./Module/Digini/Utility/src/lib_2bcddec.cpp
    ./Module/Digini/Utility/src/lib_2decbcd.cpp
    ./Module/Digini/Utility/src/lib_4aschex.cpp
    ./Module/Digini/Utility/src/lib_4bcddec.cpp
    ./Module/Digini/Utility/src/lib_4decbcd.cpp
    ./Module/Digini/Utility/src/lib_6aschex.cpp
    ./Module/Digini/Utility/src/lib_bit_reversal.cpp
    ./Module/Digini/Utility/src/lib_class_crc.cpp
    ./Module/Digini/Utility/src/lib_fifo.cpp
    ./Module/Digini/Utility/src/lib_stacktistic.cpp
    ./Module/Digini/Utility/src/lib_time_and_delay.cpp
    ./Module/Digini/Utility/src/port/STM32F4xx/lib_stacktistic_STM32F4.cpp

    ./Module/nOS/src/nOSAlarm.c
    ./Module/nOS/src/nOSBarrier.c
    ./Module/nOS/src/nOSEvent.c
    ./Module/nOS/src/nOSFlag.c
    ./Module/nOS/src/nOSList.c
    ./Module/nOS/src/nOSMem.c
    ./Module/nOS/src/nOSMutex.c
    ./Module/nOS/src/nOSQueue.c
    ./Module/nOS/src/nOSSched.c
    ./Module/nOS/src/nOSSem.c
    ./Module/nOS/src/nOSSignal.c
    ./Module/nOS/src/nOSThread.c
    ./Module/nOS/src/nOSTime.c
    ./Module/nOS/src/nOSTimer.c
    ./Module/nOS/src/port/GCC/ARM_Cortex_M4/nOSPort.c
)

add_executable(F4_Modbus_LCD_Control.elf ${SOURCES})

target_link_options(F4_Modbus_LCD_Control.elf  PRIVATE
    -Wl,--defsym=__HEAP_SIZE=0x00002000
    -Wl,--defsym=__STACK_SIZE=0x00000300
)

target_compile_definitions(F4_Modbus_LCD_Control.elf PRIVATE
    STM32F4xx
    STM32F437xx
    STM32F427_437xx
    ARM_MATH_CM4
    USE_USB_FS
)

target_include_directories(F4_Modbus_LCD_Control.elf PRIVATE
    ./App/inc
    ./App/ressource/inc
    ./Config
    ./Config/Grafx
    ./Module
    ./Module/Digini
    ./Module/Digini/Comm
    ./Module/Digini/Comm/VT100/inc
    ./Module/Digini/Comm/Console/inc
    ./Module/Digini/Comm/CmdLine/inc
    ./Module/Digini/Comm/Modbus/inc
    ./Module/Digini/Database/inc
    ./Module/Digini/Database/inc/port/STM32F4xx
    ./Module/Digini/Digini/inc
    ./Module/Digini/Grafx/inc
    ./Module/Digini/Grafx/inc/color
    ./Module/Digini/Grafx/inc/driver
    ./Module/Digini/Grafx/inc/driver/STM32
    ./Module/Digini/Grafx/inc/font
    ./Module/Digini/Grafx/inc/layer
    ./Module/Digini/Grafx/inc/service
    ./Module/Digini/Grafx/inc/task
    ./Module/Digini/Grafx/inc/widget
    ./Module/Digini/Memory/inc
    ./Module/Digini/Peripheral/inc
    ./Module/Digini/Peripheral/inc/device
    ./Module/Digini/Peripheral/inc/device/core
    ./Module/Digini/Peripheral/inc/device/port/STM32F4xx
    ./Module/Digini/Peripheral/inc/interface
    ./Module/Digini/Peripheral/inc/port/STM32F4xx
    ./Module/Digini/RTOS_Wrapper/src/nOS
    ./Module/Digini/String/inc
    ./Module/Digini/Utility/inc
    ./Module/nOS/inc
    ./Module/nOS/inc/port/GCC/ARM_Cortex_M4
)

set_target_properties(F4_Modbus_LCD_Control.elf PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY_DEBUG   "${CMAKE_CURRENT_LIST_DIR}/bin/Debug"
    RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_LIST_DIR}/bin/Release"
    ARCHIVE_OUTPUT_DIRECTORY_DEBUG   "${CMAKE_CURRENT_LIST_DIR}/obj/Debug"
    ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_LIST_DIR}/obj/Release"
    LIBRARY_OUTPUT_DIRECTORY_DEBUG   "${CMAKE_CURRENT_LIST_DIR}/obj/Debug"
    LIBRARY_OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_LIST_DIR}/obj/Release"
)

add_custom_command(TARGET F4_Modbus_LCD_Control.elf POST_BUILD
    COMMAND arm-none-eabi-objcopy -O ihex $<TARGET_FILE:F4_Modbus_LCD_Control.elf> ${CMAKE_CURRENT_LIST_DIR}/bin/$<CONFIG>/F4_Modbus_LCD_Control.hex
    COMMAND arm-none-eabi-objcopy -O binary $<TARGET_FILE:F4_Modbus_LCD_Control.elf> ${CMAKE_CURRENT_LIST_DIR}/bin/$<CONFIG>/F4_Modbus_LCD_Control.bin
)
