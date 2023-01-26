# CMSIS Build CMakeLists generated on 2023-01-26T14:27:29

cmake_minimum_required(VERSION 3.18)

# Target options

set(TARGET fxls8974cf_poll.release+lpcxpresso54114_a8974)
set(CPU Cortex-M4)
set(PRJ_DIR "C:/GIT/NXP_Sensor_SDK/examples/issdk/sensors/fxls8974cf/poll")
set(OUT_DIR "C:/GIT/NXP_Sensor_SDK/examples/issdk/sensors/fxls8974cf/poll/out/fxls8974cf_poll/lpcxpresso54114_a8974/release")
set(INT_DIR "C:/GIT/NXP_Sensor_SDK/examples/issdk/sensors/fxls8974cf/poll/tmp/fxls8974cf_poll/lpcxpresso54114_a8974/release")
set(FPU SP_FPU)
set(SECURE Non-secure)
set(BYTE_ORDER Little-endian)
set(OPTIMIZE size)
set(DEBUG off)
set(CC_FLAGS_GLOBAL "-std=c99 -fno-builtin -fno-rtti -fshort-enums -fshort-wchar")
set(CXX_FLAGS_GLOBAL "-fno-builtin -fno-rtti -fshort-enums -fshort-wchar")
set(LD_FLAGS_GLOBAL "--entry=Reset_Handler --strict --info summarysizes --remove --keep=*(.crp) --keep=*(.FlashConfig) --diag_suppress 6314,6319")
set(LD_SCRIPT "C:/GIT/NXP_Sensor_SDK/boards/lpcxpresso54114/RTE/Device/LPC54114J256BD64_cm4/LPC54114J256_cm4.scf")

set(DEFINES
  CPU_LPC54114J256BD64_cm4
  _RTE_
  SERIAL_PORT_TYPE_UART=1
  BOARD_HEADER="lpc54114.h"
  SHIELD_HEADER="frdm_stbi_a8974_shield.h"
  NDEBUG
)

set(INC_PATHS
  "C:/GIT/NXP_Sensor_SDK/boards/lpcxpresso54114/RTE/Board_Support/LPC54114J256BD64_cm4"
  "C:/GIT/NXP_Sensor_SDK/boards/lpcxpresso54114/RTE/Device/LPC54114J256BD64_cm4"
  "C:/GIT/NXP_Sensor_SDK/examples/issdk/sensors/fxls8974cf/poll/RTE/_fxls8974cf_poll.release_lpcxpresso54114_a8974"
  "C:/Users/nxf81111/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include"
  "C:/Users/nxf81111/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Driver/Include"
  "C:/Users/nxf81111/AppData/Local/Arm/Packs/NXP/LPC54114_DFP/13.0.0"
  "C:/Users/nxf81111/AppData/Local/Arm/Packs/NXP/LPC54114_DFP/13.0.0/cmsis_drivers"
  "C:/Users/nxf81111/AppData/Local/Arm/Packs/NXP/LPC54114_DFP/13.0.0/components/lists"
  "C:/Users/nxf81111/AppData/Local/Arm/Packs/NXP/LPC54114_DFP/13.0.0/components/serial_manager"
  "C:/Users/nxf81111/AppData/Local/Arm/Packs/NXP/LPC54114_DFP/13.0.0/components/uart"
  "C:/Users/nxf81111/AppData/Local/Arm/Packs/NXP/LPC54114_DFP/13.0.0/drivers"
  "C:/Users/nxf81111/AppData/Local/Arm/Packs/NXP/LPC54114_DFP/13.0.0/utilities/debug_console"
  "C:/Users/nxf81111/AppData/Local/Arm/Packs/NXP/LPC54114_DFP/13.0.0/utilities/str"
  "C:/GIT/NXP_Sensor_SDK/middleware/issdk/hal"
  "C:/GIT/NXP_Sensor_SDK/middleware/issdk/drivers/systick"
  "C:/GIT/NXP_Sensor_SDK/middleware/issdk/sensors"
  "C:/GIT/NXP_Sensor_SDK/middleware/issdk/drivers/gpio/lpc"
  "C:/GIT/NXP_Sensor_SDK/middleware/issdk/drivers/gpio"
  "C:/GIT/NXP_Sensor_SDK/boards/lpcxpresso54114"
  "C:/GIT/NXP_Sensor_SDK/shields/a8974"
)

set(ASM_SRC_FILES
  "C:/Users/nxf81111/AppData/Local/Arm/Packs/NXP/LPC54114_DFP/13.0.0/arm/startup_LPC54114_cm4.S"
)

set(CC_SRC_FILES
  "C:/GIT/NXP_Sensor_SDK/boards/lpcxpresso54114/RTE/Board_Support/LPC54114J256BD64_cm4/board.c"
  "C:/GIT/NXP_Sensor_SDK/boards/lpcxpresso54114/RTE/Board_Support/LPC54114J256BD64_cm4/clock_config.c"
  "C:/GIT/NXP_Sensor_SDK/boards/lpcxpresso54114/RTE/Board_Support/LPC54114J256BD64_cm4/peripherals.c"
  "C:/GIT/NXP_Sensor_SDK/boards/lpcxpresso54114/RTE/Board_Support/LPC54114J256BD64_cm4/pin_mux.c"
  "C:/GIT/NXP_Sensor_SDK/boards/lpcxpresso54114/lpc54114.c"
  "C:/GIT/NXP_Sensor_SDK/examples/issdk/sensors/fxls8974cf/poll/fxls8974cf_poll.c"
  "C:/GIT/NXP_Sensor_SDK/middleware/issdk/drivers/gpio/lpc/gpio_driver.c"
  "C:/GIT/NXP_Sensor_SDK/middleware/issdk/drivers/gpio/lpc/gpio_driver_irq.c"
  "C:/GIT/NXP_Sensor_SDK/middleware/issdk/drivers/systick/systick_utils.c"
  "C:/GIT/NXP_Sensor_SDK/middleware/issdk/sensors/fxls8974_drv.c"
  "C:/GIT/NXP_Sensor_SDK/middleware/issdk/sensors/register_io_i2c.c"
  "C:/GIT/NXP_Sensor_SDK/middleware/issdk/sensors/register_io_spi.c"
  "C:/GIT/NXP_Sensor_SDK/middleware/issdk/sensors/sensor_io_i2c.c"
  "C:/GIT/NXP_Sensor_SDK/middleware/issdk/sensors/sensor_io_spi.c"
  "C:/Users/nxf81111/AppData/Local/Arm/Packs/NXP/LPC54114_DFP/13.0.0/cmsis_drivers/fsl_i2c_cmsis.c"
  "C:/Users/nxf81111/AppData/Local/Arm/Packs/NXP/LPC54114_DFP/13.0.0/cmsis_drivers/fsl_spi_cmsis.c"
  "C:/Users/nxf81111/AppData/Local/Arm/Packs/NXP/LPC54114_DFP/13.0.0/cmsis_drivers/fsl_usart_cmsis.c"
  "C:/Users/nxf81111/AppData/Local/Arm/Packs/NXP/LPC54114_DFP/13.0.0/components/lists/fsl_component_generic_list.c"
  "C:/Users/nxf81111/AppData/Local/Arm/Packs/NXP/LPC54114_DFP/13.0.0/components/serial_manager/fsl_component_serial_manager.c"
  "C:/Users/nxf81111/AppData/Local/Arm/Packs/NXP/LPC54114_DFP/13.0.0/components/serial_manager/fsl_component_serial_port_uart.c"
  "C:/Users/nxf81111/AppData/Local/Arm/Packs/NXP/LPC54114_DFP/13.0.0/components/uart/fsl_adapter_usart.c"
  "C:/Users/nxf81111/AppData/Local/Arm/Packs/NXP/LPC54114_DFP/13.0.0/drivers/fsl_clock.c"
  "C:/Users/nxf81111/AppData/Local/Arm/Packs/NXP/LPC54114_DFP/13.0.0/drivers/fsl_common.c"
  "C:/Users/nxf81111/AppData/Local/Arm/Packs/NXP/LPC54114_DFP/13.0.0/drivers/fsl_dma.c"
  "C:/Users/nxf81111/AppData/Local/Arm/Packs/NXP/LPC54114_DFP/13.0.0/drivers/fsl_flexcomm.c"
  "C:/Users/nxf81111/AppData/Local/Arm/Packs/NXP/LPC54114_DFP/13.0.0/drivers/fsl_gint.c"
  "C:/Users/nxf81111/AppData/Local/Arm/Packs/NXP/LPC54114_DFP/13.0.0/drivers/fsl_gpio.c"
  "C:/Users/nxf81111/AppData/Local/Arm/Packs/NXP/LPC54114_DFP/13.0.0/drivers/fsl_i2c.c"
  "C:/Users/nxf81111/AppData/Local/Arm/Packs/NXP/LPC54114_DFP/13.0.0/drivers/fsl_i2c_dma.c"
  "C:/Users/nxf81111/AppData/Local/Arm/Packs/NXP/LPC54114_DFP/13.0.0/drivers/fsl_inputmux.c"
  "C:/Users/nxf81111/AppData/Local/Arm/Packs/NXP/LPC54114_DFP/13.0.0/drivers/fsl_power.c"
  "C:/Users/nxf81111/AppData/Local/Arm/Packs/NXP/LPC54114_DFP/13.0.0/drivers/fsl_reset.c"
  "C:/Users/nxf81111/AppData/Local/Arm/Packs/NXP/LPC54114_DFP/13.0.0/drivers/fsl_spi.c"
  "C:/Users/nxf81111/AppData/Local/Arm/Packs/NXP/LPC54114_DFP/13.0.0/drivers/fsl_spi_dma.c"
  "C:/Users/nxf81111/AppData/Local/Arm/Packs/NXP/LPC54114_DFP/13.0.0/drivers/fsl_usart.c"
  "C:/Users/nxf81111/AppData/Local/Arm/Packs/NXP/LPC54114_DFP/13.0.0/drivers/fsl_usart_dma.c"
  "C:/Users/nxf81111/AppData/Local/Arm/Packs/NXP/LPC54114_DFP/13.0.0/system_LPC54114_cm4.c"
  "C:/Users/nxf81111/AppData/Local/Arm/Packs/NXP/LPC54114_DFP/13.0.0/utilities/debug_console/fsl_debug_console.c"
  "C:/Users/nxf81111/AppData/Local/Arm/Packs/NXP/LPC54114_DFP/13.0.0/utilities/fsl_assert.c"
  "C:/Users/nxf81111/AppData/Local/Arm/Packs/NXP/LPC54114_DFP/13.0.0/utilities/str/fsl_str.c"
)

set(LIB_FILES
  "C:/Users/nxf81111/AppData/Local/Arm/Packs/NXP/LPC54114_DFP/13.0.0/arm/keil_lib_power.lib"
)

# Toolchain config map

include ("C:/Ctools/cmsis-toolbox-windows64/etc/AC6.6.18.0.cmake")

# Setup project

project(${TARGET} LANGUAGES ASM C)

# Global Flags

set(CMAKE_ASM_FLAGS "${ASM_CPU} ${ASM_BYTE_ORDER} ${ASM_DEFINES} ${ASM_OPTIONS_FLAGS} ${ASM_FLAGS}")
set(CMAKE_C_FLAGS "${CC_CPU} ${CC_BYTE_ORDER} ${CC_DEFINES} ${CC_SECURE} ${CC_OPTIONS_FLAGS} ${CC_FLAGS} ${CC_FLAGS_GLOBAL} ${CC_SYS_INC_PATHS}")
set(CMAKE_C_LINK_FLAGS "${LD_CPU} ${_LS}\"${LD_SCRIPT}\" ${LD_SECURE} ${LD_FLAGS_GLOBAL} ${LD_OPTIONS_FLAGS} ${LD_FLAGS}")

# Compilation Database

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_custom_target(database COMMAND ${CMAKE_COMMAND} -E copy_if_different "${INT_DIR}/compile_commands.json" "${OUT_DIR}")

# Setup Target

add_executable(${TARGET} ${ASM_SRC_FILES} ${CC_SRC_FILES})
set(CMAKE_EXECUTABLE_SUFFIX ${EXE_SUFFIX})
set_target_properties(${TARGET} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${OUT_DIR} LINK_DEPENDS ${LD_SCRIPT})
target_include_directories(${TARGET} PUBLIC ${INC_PATHS})
target_link_libraries(${TARGET} ${LIB_FILES})

# Bin and Hex Conversion

add_custom_command(TARGET ${TARGET} POST_BUILD COMMAND ${CMAKE_OBJCOPY} ${ELF2HEX})
add_custom_command(TARGET ${TARGET} POST_BUILD COMMAND ${CMAKE_OBJCOPY} ${ELF2BIN})
