/*
 * logThread.c
 *
 *  Created on: Aug 19, 2026
 *      Author: Celin
 */

#include "logThread.hpp"
#include "errorThread.hpp"




extern osMutexId_t uartMutexHandle;

Log::Log(){
    logeeprom_addr = 0x0000; // Directly assign using the variable name
    logMutexHandle = nullptr;
    fLogInit = false;
}

// 3. The only public access point to get the instance
Log& Log::getInstance(){
	static Log instance;
	return instance;
}

HAL_StatusTypeDef Log::GetMutex(){
	if(	osMutexAcquire(logMutexHandle, osWaitForever) == osOK){
		return HAL_OK;
	}
	else{
		return HAL_BUSY;
	}

	return HAL_ERROR;
}

HAL_StatusTypeDef Log::ReleaseMutex(){
	if(	osMutexRelease(logMutexHandle) == osOK){
		return HAL_OK;
	}
	else{
		return HAL_BUSY;
	}

	return HAL_ERROR;
}

void Log::logInit(){
	logMutexHandle = osMutexNew(NULL);
	fLogInit = true;
}

void Log::logWrite(uint32_t *pData)
{
	if (fLogInit == false)
	{
		puttyprintf("log uninitialzed.\n");
		return;
	}

	//GetMutex();
	osMessageQueuePut(
			logQueueHandle,
			pData,
			0,
			osWaitForever
	);
	//putMutex();
}

void Log::logItrWrite(uint32_t *pData)
{
	if (fLogInit == false)
	{
		puttyprintf("log uninitialzed.\n");
		return;
	}

	//GetMutex();
	osMessageQueuePut(
			logQueueHandle,
			pData,
			0,
			0
	);
	//putMutex();
}

void Log::run()
{
	Log::logInit();
	uint32_t val = 0;

	for(;;)
	{

		while(osMessageQueueGet(
				logQueueHandle,
				&val,
				NULL,
				0) == osOK)
		{
			//osMutexAcquire(uartMutexHandle, osWaitForever);
			//uint8_t *writeData;

			//GetMutex();

			char writeData[50];
			memset(writeData, '\0', sizeof(writeData));

			switch(val){
			case MAINTHREAD:
				strcpy(writeData, "MAINTHREAD logged\n");
				puttyprintf("mainThread Log Solved\n");
				break;

			case LOGTHREAD:
				strcpy(writeData, "LOGTHREAD logged\n");
				puttyprintf("logThread Log Solved\n");
				break;

			case SAMPLETHREAD:
				strcpy(writeData, "SAMPLETHREAD logged\n");
				puttyprintf("mainThread Log Solved\n");
				break;

			case OPERATIONTHREAD:
				strcpy(writeData, "OPERATIONTHREAD logged\n");
				puttyprintf("operationThread Log Solved\n");
				break;

			case ERRORTHREAD:
				strcpy(writeData, "ERRORTHREAD logged\n");
				puttyprintf("errorThread Log Solved\n");
				break;

			case USERBUTTONERRORPRESS:
				strcpy(writeData, "BUTTON pressed initiating self-destruct\n");
				puttyprintf("HUGE error BUTTON pressed initiating self-destruct\n Solved\n");
				break;

			default:
				strcpy(writeData, "BIG ERROR logged\n");
				puttyprintf("Error thingy\n");
			}

			eepromWrite(logeeprom_addr,
						(uint8_t*)writeData,
						strlen(writeData) + 1);
			logeeprom_addr += strlen(writeData) + 1;

			osMutexAcquire(uartMutexHandle, osWaitForever);
			printf("Log received: %lu\r\n", (unsigned long)val);
			osMutexRelease(uartMutexHandle);
		}
		osDelay(100);
	}
}

void logThreadEntry(void *argument)
{
  /* USER CODE BEGIN logThread */


  /* Infinite loop */
	Log::getInstance().run();

  /* USER CODE END logThread */
}
