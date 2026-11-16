/*
 * eeprom.h
 *
 *  Created on: Aug 17, 2026
 *      Author: Celin
 */
#ifndef APPLICATION_USER_EEPROM_HPP_
#define APPLICATION_USER_EEPROM_HPP_

#ifdef __cplusplus
extern "C" {
#endif


#include "main.h"

#define I2C_EEPROM_ADDR (0x50U<<1U)
#define EEPROM_PAGE_SIZE      128
#define EEPROM_TIMEOUT        500
#define EEPROM_MAX_ADDR       0x80000U
#define EEPROM_MIN_ADDR       0x0U

void eepromInit(void);


HAL_StatusTypeDef eepromRead(uint16_t memAddr,
                             uint8_t *pData,
                             uint16_t dataLen);

HAL_StatusTypeDef eepromWrite(uint16_t memAddr,
                              uint8_t *pData,
                              uint16_t dataLen);

HAL_StatusTypeDef eepromErase(uint16_t memAddr,
                              uint8_t numPages);

#ifdef __cplusplus
}
#endif

#endif /* APPLICATION_USER_EEPROM_H_ */

