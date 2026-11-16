/*
 * errorThread.c
 *
 *  Created on: Aug 19, 2026
 *      Author: Celin
 */

#include "errorThread.hpp"
#include "logThread.hpp"

extern osMutexId_t uartMutexHandle;

errorThread& errorThread::getInstance(){
	static errorThread instance;
	return instance;
}

void errorItrCSend(uint32_t * pData){
	errorThread::getInstance().errorItrSend(pData);
}

void errorThread::errorSend(uint32_t *pData)
{
	osMessageQueuePut(
			errorQueueHandle,
			pData,
			0,
			osWaitForever
	);
}

void errorThread::errorItrSend(uint32_t *pData){
	osMessageQueuePut(
			errorQueueHandle,
			pData,
			0,
			0
	);
}

void errorThread::run(){
  uint32_t count = 0;
  for(;;)
  {
		count++;
		uint32_t val = 0;
		while(osMessageQueueGet(
					errorQueueHandle,
					&val,
					NULL,
					0) == osOK)
		{
			Log::getInstance().logWrite(&val);
		}

		 if(count>= 100){
			count = 0;

			uint32_t val = ERRORTHREAD; //priority 5 == error

			//GetMutex();
			Log::getInstance().logWrite(&val);
			//ReleaseMutex();

			//osMutexAcquire(uartMutexHandle, osWaitForever);
			puttyprintf("errorThread LogQUEUE PUT\n");
			//osMutexRelease(uartMutexHandle);
			//logQueue
		}

	osDelay(100);
  }
}

void errorHandleThreadEntry(void *argument)
{
  /* USER CODE BEGIN sampleThread */
  /* Infinite loop */
  errorThread::getInstance().run();
  /* USER CODE END sampleThread */
}
