/*
 * logThread.h
 *
 *  Created on: Aug 19, 2026
 *      Author: Celin
 */

#ifndef APPLICATION_INCLUDE_LOGTHREAD_HPP_
#define APPLICATION_INCLUDE_LOGTHREAD_HPP_


#include <eeprom.h>
#include <stdio.h>
#include "string.h"

#include "app_freertos.h"


#ifdef __cplusplus
class Log {
	public:
		// 1. Delete copy constructor to prevent cloning
		Log(const Log&) = delete;

		// 2. Delete assignment operator to prevent overwriting
		Log& operator=(const Log&) = delete;

		// 3. The only public access point to get the instance
		static Log& getInstance();

		void logWrite(uint32_t *pData);
		void logItrWrite(uint32_t *pData);

		void run();

		uint16_t logeeprom_addr;

	private:
		Log();

		~Log() = default;

		osMutexId_t logMutexHandle;

		bool fLogInit;

		HAL_StatusTypeDef GetMutex();

		HAL_StatusTypeDef ReleaseMutex();

		void logInit(void);

};

#endif

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif

#endif /* APPLICATION_INCLUDE_LOGTHREAD_H_ */
