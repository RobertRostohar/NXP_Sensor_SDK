/*
 * Copyright 2023 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * @file fxls8971cf_poll.c
 * @brief The fxls8971cf_poll.c file implements the ISSDK FXLS8971 sensor driver
 *        example demonstration with polling mode.
 */

/*  SDK Includes */
#include "pin_mux.h"
#include "clock_config.h"
#include "board.h"
#include "fsl_debug_console.h"

/* CMSIS Includes */
#include "Driver_I2C.h"

/* ISSDK Includes */
#include "issdk_hal.h"
#include "fxls8971_drv.h"
#include "systick_utils.h"

/*******************************************************************************
 * Macros
 ******************************************************************************/
#define FXLS8971_DATA_SIZE 6

/*******************************************************************************
 * Constants
 ******************************************************************************/
/*! @brief Register settings for Normal (non buffered) mode. */
const registerwritelist_t cFxls8971ConfigNormal[] = {
    /* Set Full-scale range as 2G. */
    {FXLS8971_SENS_CONFIG1, FXLS8971_SENS_CONFIG1_FSR_2G, FXLS8971_SENS_CONFIG1_FSR_MASK},
    /* Set Wake Mode ODR Rate as 6.25Hz. */
    {FXLS8971_SENS_CONFIG3, FXLS8971_SENS_CONFIG3_WAKE_ODR_6_25HZ, FXLS8971_SENS_CONFIG3_WAKE_ODR_MASK},
    __END_WRITE_DATA__};

/*! @brief Address of DATA Ready Status Register. */
const registerreadlist_t cFxls8971DRDYEvent[] = {{.readFrom = FXLS8971_INT_STATUS, .numBytes = 1}, __END_READ_DATA__};

/*! @brief Address of Raw Accel Data in Normal Mode. */
const registerreadlist_t cFxls8971OutputNormal[] = {{.readFrom = FXLS8971_OUT_X_LSB, .numBytes = FXLS8971_DATA_SIZE},
                                                    __END_READ_DATA__};

/*******************************************************************************
 * Code
 ******************************************************************************/
/*!
 * @brief Main function
 */
int main(void)
{
    int32_t status;
    uint8_t whoami;
    uint8_t dataReady;
    uint8_t data[FXLS8971_DATA_SIZE];
    fxls8971_acceldata_t rawData;

    ARM_DRIVER_I2C *I2Cdrv = &I2C_S_DRIVER; // Now using the shield.h value!!!
    fxls8971_i2c_sensorhandle_t fxls8971Driver;

    /*! Initialize the MCU hardware. */
    BOARD_InitPins();
    BOARD_BootClockRUN();
    BOARD_SystickEnable();
    BOARD_InitDebugConsole();

    PRINTF("\r\n ISSDK FXLS8971 sensor driver example demonstration with poll mode\r\n");

    /*! Initialize the I2C driver. */
    status = I2Cdrv->Initialize(I2C_S_SIGNAL_EVENT);
    if (ARM_DRIVER_OK != status)
    {
        PRINTF("\r\n I2C Initialization Failed\r\n");
        return -1;
    }

    /*! Set the I2C Power mode. */
    status = I2Cdrv->PowerControl(ARM_POWER_FULL);
    if (ARM_DRIVER_OK != status)
    {
        PRINTF("\r\n I2C Power Mode setting Failed\r\n");
        return -1;
    }

    /*! Set the I2C bus speed. */
    status = I2Cdrv->Control(ARM_I2C_BUS_SPEED, ARM_I2C_BUS_SPEED_FAST);
    if (ARM_DRIVER_OK != status)
    {
        PRINTF("\r\n I2C Control Mode setting Failed\r\n");
        return -1;
    }

    /*! Initialize FXLS8971 sensor driver. */
    status = FXLS8971_I2C_Initialize(&fxls8971Driver, &I2C_S_DRIVER, I2C_S_DEVICE_INDEX, FXLS8971_I2C_ADDR,
                                     &whoami);
    if (ARM_DRIVER_OK != status)
    {
        PRINTF("\r\n Sensor Initialization Failed\r\n");
        return -1;
    }
    if ((FXLS8964_WHOAMI_VALUE == whoami) || (FXLS8967_WHOAMI_VALUE == whoami))
    {
    	PRINTF("\r\n Successfully Initialized Gemini with WHO_AM_I = 0x%X\r\n", whoami);
    }
    else if ((FXLS8974_WHOAMI_VALUE == whoami) || (FXLS8968_WHOAMI_VALUE == whoami))
    {
    	PRINTF("\r\n Successfully Initialized Timandra with WHO_AM_I = 0x%X\r\n", whoami);
    }
    else if ((FXLS8971_WHOAMI_VALUE == whoami) || (FXLS8961_WHOAMI_VALUE == whoami))
    {
    	PRINTF("\r\n Successfully Initialized Chiron with WHO_AM_I = 0x%X\r\n", whoami);
    }
    else if (FXLS8962_WHOAMI_VALUE == whoami)
    {
    	PRINTF("\r\n Successfully Initialized Newstein with WHO_AM_I = 0x%X\r\n", whoami);
    }
    else
    {
    	PRINTF("\r\n Bad WHO_AM_I = 0x%X\r\n", whoami);
        return -1;
    }

    /*!  Set the task to be executed while waiting for I2C transactions to complete. */
    FXLS8971_I2C_SetIdleTask(&fxls8971Driver, (registeridlefunction_t)SMC_SetPowerModeVlpr, SMC);

    /*! Configure the FXLS8971 sensor. */
    status = FXLS8971_I2C_Configure(&fxls8971Driver, cFxls8971ConfigNormal);
    if (ARM_DRIVER_OK != status)
    {
        PRINTF("\r\n FXLS8971 Sensor Configuration Failed, Err = %d\r\n", status);
        return -1;
    }
    PRINTF("\r\n Successfully Applied FXLS8971 Sensor Configuration\r\n");

    for (;;) /* Forever loop */
    {
        /*! Wait for data ready from the FXLS8971. */
        status = FXLS8971_I2C_ReadData(&fxls8971Driver, cFxls8971DRDYEvent, &dataReady);
        if (0 == (dataReady & FXLS8971_INT_STATUS_SRC_DRDY_MASK))
        {
            continue;
        }

        /*! Read new raw sensor data from the FXLS8971. */
        status = FXLS8971_I2C_ReadData(&fxls8971Driver, cFxls8971OutputNormal, data);
        if (ARM_DRIVER_OK != status)
        {
            PRINTF("\r\n Read Failed. \r\n");
            return -1;
        }

        /*! Convert the raw sensor data to signed 16-bit container for display to the debug port. */
        rawData.accel[0] = ((int16_t)data[1] << 8) | data[0];
        rawData.accel[1] = ((int16_t)data[3] << 8) | data[2];
        rawData.accel[2] = ((int16_t)data[5] << 8) | data[4];

        /* NOTE: PRINTF is relatively expensive in terms of CPU time, specially when used with-in execution loop. */
        PRINTF("\r\nX=%5d Y=%5d Z=%5d\r\n", rawData.accel[0], rawData.accel[1], rawData.accel[2]);
        ASK_USER_TO_RESUME(50); /* Ask for user input after processing 50 samples. */
    }
}
