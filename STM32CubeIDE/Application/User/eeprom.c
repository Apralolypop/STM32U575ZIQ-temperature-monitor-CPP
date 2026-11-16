/*
 * eeprom.c
 *
 *  Created on: Aug 17, 2026
 *      Author: Celin
 */


#include <eeprom.h>
#include "string.h"

extern I2C_HandleTypeDef hi2c2;

void eepromInit(void)
{
    HAL_I2C_IsDeviceReady(&hi2c2,
    					  I2C_EEPROM_ADDR,
                          3,
                          EEPROM_TIMEOUT);
}

HAL_StatusTypeDef eepromRead(uint16_t memAddr, uint8_t *pData, uint16_t dataLen)
{

	if ( (memAddr > EEPROM_MAX_ADDR) || (memAddr < EEPROM_MIN_ADDR) )
	{
		return HAL_ERROR;
	}

	if (pData == NULL)
	{
		return HAL_ERROR;
	}

    return HAL_I2C_Mem_Read(&hi2c2,
    						I2C_EEPROM_ADDR,
                            memAddr,
                            I2C_MEMADD_SIZE_16BIT,
                            pData,
                            dataLen,
                            EEPROM_TIMEOUT);
}


HAL_StatusTypeDef eepromWrite(uint16_t memAddr,
                              uint8_t *pData,
                              uint16_t dataLen)
{
    HAL_StatusTypeDef status;

	if ( (memAddr > EEPROM_MAX_ADDR) || (memAddr < EEPROM_MIN_ADDR) )
	{
		return HAL_ERROR;
	}

	if (pData == NULL)
	{
		return HAL_ERROR;
	}

    while (dataLen > 0)
    {
        uint16_t pageOffset = memAddr % EEPROM_PAGE_SIZE;
        uint16_t space = EEPROM_PAGE_SIZE - pageOffset;

        uint16_t writeLen;

        if (dataLen < space)
            writeLen = dataLen;
        else
            writeLen = space;

        status = HAL_I2C_Mem_Write(&hi2c2,
        						   I2C_EEPROM_ADDR,
                                   memAddr,
                                   I2C_MEMADD_SIZE_16BIT,
                                   pData,
                                   writeLen,
                                   EEPROM_TIMEOUT);

        if (status != HAL_OK)
            return status;

        status = HAL_I2C_IsDeviceReady(&hi2c2,
        		 	 	 	 	 	   I2C_EEPROM_ADDR,
                                       100,
                                       EEPROM_TIMEOUT);

        if (status != HAL_OK)
            return status;

        memAddr += writeLen;
        pData += writeLen;
        dataLen -= writeLen;
    }

    return HAL_OK;
}


HAL_StatusTypeDef eepromErase(uint16_t memAddr,
                              uint8_t numPages)
{
    uint8_t buffer[EEPROM_PAGE_SIZE];

	if ( (memAddr > EEPROM_MAX_ADDR) || (memAddr < EEPROM_MIN_ADDR) )
	{
		return HAL_ERROR;
	}

	if (numPages == 0)
	{
		return HAL_OK;
	}

    memset(buffer, 0xFF, EEPROM_PAGE_SIZE);

    for (uint8_t i = 0; i < numPages; i++)
    {
        if (eepromWrite(memAddr,
                        buffer,
                        EEPROM_PAGE_SIZE) != HAL_OK)
        {
            return HAL_ERROR;
        }

        memAddr += EEPROM_PAGE_SIZE;
    }

    return HAL_OK;
}



