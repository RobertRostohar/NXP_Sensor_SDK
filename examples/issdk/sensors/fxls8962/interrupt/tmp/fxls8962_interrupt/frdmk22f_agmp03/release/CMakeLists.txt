# CMSIS Build CMakeLists generated on 2023-01-19T08:37:31

cmake_minimum_required(VERSION 3.18)

# Target options

set(TARGET fxls8962_interrupt.release+frdmk22f_agmp03)
set(CPU Cortex-M4)
set(PRJ_DIR "C:/GIT/NXP_Sensor_SDK/examples/issdk/sensors/fxls8962/interrupt")
set(OUT_DIR "C:/GIT/NXP_Sensor_SDK/examples/issdk/sensors/fxls8962/interrupt/out/fxls8962_interrupt/frdmk22f_agmp03/release")
set(INT_DIR "C:/GIT/NXP_Sensor_SDK/examples/issdk/sensors/fxls8962/interrupt/tmp/fxls8962_interrupt/frdmk22f_agmp03/release")
set(FPU SP_FPU)
set(SECURE Non-secure)
set(BYTE_ORDER Little-endian)
set(CC_FLAGS_GLOBAL "-std=c99 -fno-builtin -fno-rtti -fshort-enums -fshort-wchar")
set(CXX_FLAGS_GLOBAL "-fno-builtin -fno-rtti -fshort-enums -fshort-wchar")
set(LD_FLAGS_GLOBAL "--entry=Reset_Handler --strict --info summarysizes --remove --keep=*(.crp) --keep=*(.FlashConfig) --diag_suppress 6314,6319")
set(LD_SCRIPT "C:/GIT/NXP_Sensor_SDK/boards/frdmk22f/RTE/Device/MK22FN512VLH12/MK22FN512xxx12_flash.scf")

set(DEFINES
  CPU_MK22FN512VLH12
  _RTE_
  MCUXPRESSO_SDK
  PRINTF_ADVANCED_ENABLE
  SERIAL_PORT_TYPE_UART=1
  BOARD_HEADER="frdm_k22f.h"
  SHIELD_HEADER="frdm_stbc_agmp03_shield.h"
  FRDM_K22F
  FREEDOM
  NDEBUG
)

set(INC_PATHS
  "C:/GIT/NXP_Sensor_SDK/examples/issdk/sensors/fxls8962/interrupt/RTE/Board_Support/MK22FN512VLH12"
  "C:/GIT/NXP_Sensor_SDK/examples/issdk/sensors/fxls8962/interrupt/RTE/Device/MK22FN512VLH12"
  "C:/GIT/NXP_Sensor_SDK/examples/issdk/sensors/fxls8962/interrupt/RTE/_fxls8962_interrupt.release_frdmk22f_agmp03"
  "C:/Temp/working-toolbox/packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include"
  "C:/Temp/working-toolbox/packs/ARM/CMSIS/5.9.0/CMSIS/Driver/Include"
  "C:/Temp/working-toolbox/packs/NXP/MK22F51212_DFP/15.0.0"
  "C:/Temp/working-toolbox/packs/NXP/MK22F51212_DFP/15.0.0/cmsis_drivers"
  "C:/Temp/working-toolbox/packs/NXP/MK22F51212_DFP/15.0.0/components/lists"
  "C:/Temp/working-toolbox/packs/NXP/MK22F51212_DFP/15.0.0/components/serial_manager"
  "C:/Temp/working-toolbox/packs/NXP/MK22F51212_DFP/15.0.0/components/uart"
  "C:/Temp/working-toolbox/packs/NXP/MK22F51212_DFP/15.0.0/drivers"
  "C:/Temp/working-toolbox/packs/NXP/MK22F51212_DFP/15.0.0/utilities/debug_console"
  "C:/Temp/working-toolbox/packs/NXP/MK22F51212_DFP/15.0.0/utilities/str"
  "C:/GIT/NXP_Sensor_SDK/middleware/issdk/hal"
  "C:/GIT/NXP_Sensor_SDK/middleware/issdk/drivers/systick"
  "C:/GIT/NXP_Sensor_SDK/middleware/issdk/sensors"
  "C:/GIT/NXP_Sensor_SDK/middleware/issdk/drivers/gpio/kinetis"
  "C:/GIT/NXP_Sensor_SDK/middleware/issdk/drivers/gpio"
  "C:/GIT/NXP_Sensor_SDK/boards/frdmk22f"
  "C:/GIT/NXP_Sensor_SDK/shields/agmp03"
)

set(ASM_SRC_FILES
  "C:/GIT/NXP_Sensor_SDK/examples/issdk/sensors/fxls8962/interrupt/RTE/Device/MK22FN512VLH12/startup_MK22F51212.S"
)

set(CC_SRC_FILES
  "C:/GIT/NXP_Sensor_SDK/boards/frdmk22f/frdm_k22f.c"
  "C:/GIT/NXP_Sensor_SDK/examples/issdk/sensors/fxls8962/interrupt/RTE/Board_Support/MK22FN512VLH12/board.c"
  "C:/GIT/NXP_Sensor_SDK/examples/issdk/sensors/fxls8962/interrupt/RTE/Board_Support/MK22FN512VLH12/clock_config.c"
  "C:/GIT/NXP_Sensor_SDK/examples/issdk/sensors/fxls8962/interrupt/RTE/Board_Support/MK22FN512VLH12/peripherals.c"
  "C:/GIT/NXP_Sensor_SDK/examples/issdk/sensors/fxls8962/interrupt/RTE/Board_Support/MK22FN512VLH12/pin_mux.c"
  "C:/GIT/NXP_Sensor_SDK/examples/issdk/sensors/fxls8962/interrupt/fxls8962_interrupt.c"
  "C:/GIT/NXP_Sensor_SDK/middleware/issdk/drivers/gpio/kinetis/gpio_driver.c"
  "C:/GIT/NXP_Sensor_SDK/middleware/issdk/drivers/gpio/kinetis/gpio_driver_irq.c"
  "C:/GIT/NXP_Sensor_SDK/middleware/issdk/drivers/systick/systick_utils.c"
  "C:/GIT/NXP_Sensor_SDK/middleware/issdk/sensors/fxls8962_drv.c"
  "C:/GIT/NXP_Sensor_SDK/middleware/issdk/sensors/register_io_i2c.c"
  "C:/GIT/NXP_Sensor_SDK/middleware/issdk/sensors/register_io_spi.c"
  "C:/GIT/NXP_Sensor_SDK/middleware/issdk/sensors/sensor_io_i2c.c"
  "C:/GIT/NXP_Sensor_SDK/middleware/issdk/sensors/sensor_io_spi.c"
  "C:/Temp/working-toolbox/packs/NXP/MK22F51212_DFP/15.0.0/cmsis_drivers/fsl_dspi_cmsis.c"
  "C:/Temp/working-toolbox/packs/NXP/MK22F51212_DFP/15.0.0/cmsis_drivers/fsl_i2c_cmsis.c"
  "C:/Temp/working-toolbox/packs/NXP/MK22F51212_DFP/15.0.0/cmsis_drivers/fsl_uart_cmsis.c"
  "C:/Temp/working-toolbox/packs/NXP/MK22F51212_DFP/15.0.0/components/lists/fsl_component_generic_list.c"
  "C:/Temp/working-toolbox/packs/NXP/MK22F51212_DFP/15.0.0/components/serial_manager/fsl_component_serial_manager.c"
  "C:/Temp/working-toolbox/packs/NXP/MK22F51212_DFP/15.0.0/components/serial_manager/fsl_component_serial_port_uart.c"
  "C:/Temp/working-toolbox/packs/NXP/MK22F51212_DFP/15.0.0/components/uart/fsl_adapter_uart.c"
  "C:/Temp/working-toolbox/packs/NXP/MK22F51212_DFP/15.0.0/drivers/fsl_adc16.c"
  "C:/Temp/working-toolbox/packs/NXP/MK22F51212_DFP/15.0.0/drivers/fsl_clock.c"
  "C:/Temp/working-toolbox/packs/NXP/MK22F51212_DFP/15.0.0/drivers/fsl_common.c"
  "C:/Temp/working-toolbox/packs/NXP/MK22F51212_DFP/15.0.0/drivers/fsl_common_arm.c"
  "C:/Temp/working-toolbox/packs/NXP/MK22F51212_DFP/15.0.0/drivers/fsl_dmamux.c"
  "C:/Temp/working-toolbox/packs/NXP/MK22F51212_DFP/15.0.0/drivers/fsl_dspi.c"
  "C:/Temp/working-toolbox/packs/NXP/MK22F51212_DFP/15.0.0/drivers/fsl_dspi_edma.c"
  "C:/Temp/working-toolbox/packs/NXP/MK22F51212_DFP/15.0.0/drivers/fsl_edma.c"
  "C:/Temp/working-toolbox/packs/NXP/MK22F51212_DFP/15.0.0/drivers/fsl_ftfx_cache.c"
  "C:/Temp/working-toolbox/packs/NXP/MK22F51212_DFP/15.0.0/drivers/fsl_ftfx_controller.c"
  "C:/Temp/working-toolbox/packs/NXP/MK22F51212_DFP/15.0.0/drivers/fsl_ftfx_flash.c"
  "C:/Temp/working-toolbox/packs/NXP/MK22F51212_DFP/15.0.0/drivers/fsl_ftfx_flexnvm.c"
  "C:/Temp/working-toolbox/packs/NXP/MK22F51212_DFP/15.0.0/drivers/fsl_gpio.c"
  "C:/Temp/working-toolbox/packs/NXP/MK22F51212_DFP/15.0.0/drivers/fsl_i2c.c"
  "C:/Temp/working-toolbox/packs/NXP/MK22F51212_DFP/15.0.0/drivers/fsl_i2c_edma.c"
  "C:/Temp/working-toolbox/packs/NXP/MK22F51212_DFP/15.0.0/drivers/fsl_lptmr.c"
  "C:/Temp/working-toolbox/packs/NXP/MK22F51212_DFP/15.0.0/drivers/fsl_lpuart.c"
  "C:/Temp/working-toolbox/packs/NXP/MK22F51212_DFP/15.0.0/drivers/fsl_rtc.c"
  "C:/Temp/working-toolbox/packs/NXP/MK22F51212_DFP/15.0.0/drivers/fsl_smc.c"
  "C:/Temp/working-toolbox/packs/NXP/MK22F51212_DFP/15.0.0/drivers/fsl_uart.c"
  "C:/Temp/working-toolbox/packs/NXP/MK22F51212_DFP/15.0.0/drivers/fsl_uart_edma.c"
  "C:/Temp/working-toolbox/packs/NXP/MK22F51212_DFP/15.0.0/system_MK22F51212.c"
  "C:/Temp/working-toolbox/packs/NXP/MK22F51212_DFP/15.0.0/utilities/debug_console/fsl_debug_console.c"
  "C:/Temp/working-toolbox/packs/NXP/MK22F51212_DFP/15.0.0/utilities/fsl_assert.c"
  "C:/Temp/working-toolbox/packs/NXP/MK22F51212_DFP/15.0.0/utilities/str/fsl_str.c"
)

# Toolchain config map

include ("C:/Temp/working-toolbox/cmsis-toolbox/etc/AC6.6.16.0.cmake")

# Setup project

project(${TARGET} LANGUAGES ASM C)

# Global Flags

set(CMAKE_ASM_FLAGS "${ASM_CPU} ${ASM_BYTE_ORDER} ${ASM_DEFINES} ${ASM_FLAGS}")
set(CMAKE_C_FLAGS "${CC_CPU} ${CC_BYTE_ORDER} ${CC_DEFINES} ${CC_SECURE} ${CC_FLAGS} ${CC_FLAGS_GLOBAL} ${CC_SYS_INC_PATHS}")
set(CMAKE_C_LINK_FLAGS "${LD_CPU} ${LD_SCRIPT} ${LD_SECURE} ${LD_FLAGS_GLOBAL} ${LD_FLAGS}")

# Compilation Database

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_custom_target(database COMMAND ${CMAKE_COMMAND} -E copy_if_different "${INT_DIR}/compile_commands.json" "${OUT_DIR}")

# Setup Target

add_executable(${TARGET} ${ASM_SRC_FILES} ${CC_SRC_FILES})
set(CMAKE_EXECUTABLE_SUFFIX ${EXE_SUFFIX})
set_target_properties(${TARGET} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${OUT_DIR})
target_include_directories(${TARGET} PUBLIC ${INC_PATHS})

# Bin and Hex Conversion

add_custom_command(TARGET ${TARGET} POST_BUILD COMMAND ${CMAKE_OBJCOPY} ${ELF2HEX})
add_custom_command(TARGET ${TARGET} POST_BUILD COMMAND ${CMAKE_OBJCOPY} ${ELF2BIN})
