/*
 * Copyright 2022 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * @file fxls8974_drv_i2c.c
 * @brief The fxls8974_drv_i2c.c file implements the FXLS8964/67 sensor driver interfaces.
 */

//-----------------------------------------------------------------------
// ISSDK Includes
//-----------------------------------------------------------------------
#include "gpio_driver.h"
#include "fxls8974_drv_i2c.h"
#include "systick_utils.h"

//-----------------------------------------------------------------------
// Functions
//-----------------------------------------------------------------------
int32_t FXLS8974_I2C_Initialize(
    fxls8974_i2c_sensorhandle_t *pSensorHandle, ARM_DRIVER_I2C *pBus, uint8_t index, uint16_t sAddress, uint8_t *whoami)
{
    int32_t status;
    uint8_t reg = 0;

    /*! Check the input parameters. */
    if ((pSensorHandle == NULL) || (pBus == NULL))
    {
        return SENSOR_ERROR_INVALID_PARAM;
    }

    pSensorHandle->deviceInfo.deviceInstance = index;
    pSensorHandle->deviceInfo.functionParam = NULL;
    pSensorHandle->deviceInfo.idleFunction = NULL;

    /*!  Read and store the device's WHO_AM_I.*/
    status = Register_I2C_Read(pBus, &pSensorHandle->deviceInfo, sAddress, FXLS8974_WHO_AM_I, 1, &reg);
    //if ((ARM_DRIVER_OK != status) || (whoAmi != reg))
	(*whoami) = reg;
    if (ARM_DRIVER_OK != status)
    {
    	if ((FXLS8962_WHOAMI_VALUE != reg) || (FXLS8964_WHOAMI_VALUE != reg) || (FXLS8967_WHOAMI_VALUE != reg) || (FXLS8968_WHOAMI_VALUE != reg) || (FXLS8974_WHOAMI_VALUE != reg) || (FXLS8971_WHOAMI_VALUE != reg) || (FXLS8961_WHOAMI_VALUE != reg))
    	{
    		pSensorHandle->isInitialized = false;
    		return SENSOR_ERROR_BAD_ADDRESS;
    	}
        pSensorHandle->isInitialized = false;
        return SENSOR_ERROR_INIT;
    }

    /*! Initialize the sensor handle. */
    pSensorHandle->pCommDrv = pBus;
    pSensorHandle->slaveAddress = sAddress;
    pSensorHandle->isInitialized = true;
    return SENSOR_ERROR_NONE;
}

void FXLS8974_I2C_SetIdleTask(fxls8974_i2c_sensorhandle_t *pSensorHandle,
                              registeridlefunction_t idleTask,
                              void *userParam)
{
    pSensorHandle->deviceInfo.functionParam = userParam;
    pSensorHandle->deviceInfo.idleFunction = idleTask;
}

int32_t FXLS8974_I2C_Configure(fxls8974_i2c_sensorhandle_t *pSensorHandle, const registerwritelist_t *pRegWriteList)
{
    int32_t status;

    /*! Validate for the correct handle and register write list.*/
    if ((pSensorHandle == NULL) || (pRegWriteList == NULL))
    {
        return SENSOR_ERROR_INVALID_PARAM;
    }

    /*! Check whether sensor handle is initialized before applying configuration.*/
    if (pSensorHandle->isInitialized != true)
    {
        return SENSOR_ERROR_INIT;
    }

    /*! Put the device into standby mode so that configuration can be applied.*/
    status = Register_I2C_Write(pSensorHandle->pCommDrv, &pSensorHandle->deviceInfo, pSensorHandle->slaveAddress,
                                FXLS8974_SENS_CONFIG1, FXLS8974_SENS_CONFIG1_ACTIVE_STANDBY,
                                FXLS8974_SENS_CONFIG1_ACTIVE_MASK, false);
    if (ARM_DRIVER_OK != status)
    {
        return SENSOR_ERROR_WRITE;
    }

    /*! Apply the Sensor Configuration based on the Register Write List */
    status = Sensor_I2C_Write(pSensorHandle->pCommDrv, &pSensorHandle->deviceInfo, pSensorHandle->slaveAddress,
                              pRegWriteList);
    if (ARM_DRIVER_OK != status)
    {
        return SENSOR_ERROR_WRITE;
    }

    /*! Put the device into active mode and ready for reading data.*/
    status = Register_I2C_Write(pSensorHandle->pCommDrv, &pSensorHandle->deviceInfo, pSensorHandle->slaveAddress,
                                FXLS8974_SENS_CONFIG1, FXLS8974_SENS_CONFIG1_ACTIVE_ACTIVE,
                                FXLS8974_SENS_CONFIG1_ACTIVE_MASK, false);
    if (ARM_DRIVER_OK != status)
    {
        return SENSOR_ERROR_WRITE;
    }

    return SENSOR_ERROR_NONE;
}

int32_t FXLS8974_I2C_ReadData(fxls8974_i2c_sensorhandle_t *pSensorHandle,
                              const registerreadlist_t *pReadList,
                              uint8_t *pBuffer)
{
    int32_t status;

    /*! Validate for the correct handle and register read list.*/
    if ((pSensorHandle == NULL) || (pReadList == NULL) || (pBuffer == NULL))
    {
        return SENSOR_ERROR_INVALID_PARAM;
    }

    /*! Check whether sensor handle is initialized before reading sensor data.*/
    if (pSensorHandle->isInitialized != true)
    {
        return SENSOR_ERROR_INIT;
    }

    /*! Parse through the read list and read the data one by one. */
    status = Sensor_I2C_Read(pSensorHandle->pCommDrv, &pSensorHandle->deviceInfo, pSensorHandle->slaveAddress,
                             pReadList, pBuffer);
    if (ARM_DRIVER_OK != status)
    {
        return SENSOR_ERROR_READ;
    }

    return SENSOR_ERROR_NONE;
}

int32_t FXLS8974_I2C_DeInit(fxls8974_i2c_sensorhandle_t *pSensorHandle)
{
    int32_t status;

    if (pSensorHandle == NULL)
    {
        return SENSOR_ERROR_INVALID_PARAM;
    }

    /*! Check whether sensor handle is initialized before triggering sensor reset.*/
    if (pSensorHandle->isInitialized != true)
    {
        return SENSOR_ERROR_INIT;
    }

    /*! Trigger sensor device reset.*/
    status =
        Register_I2C_Write(pSensorHandle->pCommDrv, &pSensorHandle->deviceInfo, pSensorHandle->slaveAddress,
                           FXLS8974_SENS_CONFIG1, FXLS8974_SENS_CONFIG1_RST_RST, FXLS8974_SENS_CONFIG1_RST_MASK, false);
    if (ARM_DRIVER_OK != status)
    {
        return SENSOR_ERROR_WRITE;
    }
    else
    {
        /*! De-initialize sensor handle. */
        pSensorHandle->isInitialized = false;
    }

    /* Wait for MAX of TBOOT ms after soft reset command,
     * to allow enough time for FXLS8974AF to complete its internal boot sequence and be ready for communication. */
    BOARD_DELAY_ms(FXLS8974_TBOOT_MAX);

    return SENSOR_ERROR_NONE;
}
