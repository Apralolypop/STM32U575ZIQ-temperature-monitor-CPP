/*
 * sampleThread.h
 *
 *  Created on: Aug 19, 2026
 *      Author: Celin
 */

#ifndef APPLICATION_INCLUDE_SAMPLETHREAD_HPP_
#define APPLICATION_INCLUDE_SAMPLETHREAD_HPP_



#include "app_freertos.h"
#include "logThread.hpp"
#include <stdint.h>

typedef struct
{
	uint32_t vbatValue;
    uint32_t tempValue;
} Sample_Data;

#ifdef __cplusplus

class sampleThread{
	private:
		Sample_Data sample;

		bool firstSample;
		osMutexId_t sampleMutexHandle;

		HAL_StatusTypeDef sampleInit();
		HAL_StatusTypeDef sampleVbat();
		HAL_StatusTypeDef sampleTemperature();
		HAL_StatusTypeDef sampleRead();

		sampleThread();
		~sampleThread(){};

		void GetMutex();
		void ReleaseMutex();
	public:

		sampleThread(const sampleThread&) = delete;

		sampleThread& operator=(const sampleThread&) = delete;

		static sampleThread& getInstance();

		void run();

		Sample_Data sampleGet();

};

#endif

#ifdef __cplusplus
extern "C" {
#endif



#ifdef __cplusplus
}
#endif

#endif /* APPLICATION_INCLUDE_SAMPLETHREAD_H_ */
