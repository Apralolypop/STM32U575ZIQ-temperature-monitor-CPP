/*
 * mainThread.c
 *
 *  Created on: Aug 19, 2026
 *      Author: Celin
 */
#include "errorThread.hpp"
#include "logThread.hpp"
#include "mainThread.hpp"


extern IWDG_HandleTypeDef hiwdg;

extern osMutexId_t uartMutexHandle;

mainThread& mainThread::getInstance()
{
	static mainThread instance;
	return instance;
}

void mainThread::run()
{
	uint16_t count = 0;

	for(;;)
	{
		count++;

		if(count>= 100){
			count = 0;

		uint32_t val = MAINTHREAD; //priority 1 == main

		//GetMutex();
		Log::getInstance().logWrite(&val);
		//ReleaseMutex();

		//send any error to error queue
		errorThread::getInstance().errorSend(&val);

		//osMutexAcquire(uartMutexHandle, osWaitForever);
		puttyprintf("MainThread LogQUEUE PUT\n");
		//osMutexRelease(uartMutexHandle);
		//logQueue
	}


	//Feeddog here.
	//osMutexAcquire(uartMutexHandle, osWaitForever);
	//printf("MainThread running\n");
	//osMutexRelease(uartMutexHandle);

	HAL_IWDG_Refresh(&hiwdg);

	osDelay(100);
	}
}

void mainThreadEntry(void *argument)
{
  /* USER CODE BEGIN mainThread */
  /* Infinite loop */
  mainThread::getInstance().run();
  /* USER CODE END mainThread */
}
