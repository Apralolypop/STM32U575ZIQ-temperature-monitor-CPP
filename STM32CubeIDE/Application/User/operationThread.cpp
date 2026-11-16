/*
 * operationThread.c
 *
 *  Created on: Aug 19, 2026
 *      Author: Celin
 */

#include "operationThread.hpp"
#include "errorThread.hpp"
#include "logThread.hpp"
#include "sampleThread.hpp"

extern osMutexId_t uartMutexHandle;

operationThread& operationThread::getInstance(){
	static operationThread instance;
	return instance;
}

float operationThread::temperatureCal(uint32_t raw)
{
    float correctedRaw;

    // Assume VREF+ = 3.3 V
    // Calibration values were measured at 3.0 V
    correctedRaw = ((float)raw * 3300.0f) / 3000.0f;

    float cal1 = (float)(*TEMPSENSOR_CAL1_ADDR);
    float cal2 = (float)(*TEMPSENSOR_CAL2_ADDR);

    float temperature =
        ((correctedRaw - cal1) * 100.0f)
        / (cal2 - cal1)
        + 30.0f;

    return temperature;
}

void operationThread::run(){

  uint32_t count = 0;
  Sample_Data sample; //

  for(;;)
  {

	  sample = sampleThread::getInstance().sampleGet();
	  //printf("RAW VALUE 0x%lx\n", sample.tempValue);
	  float temperature = temperatureCal(sample.tempValue);

	  printf("The temperature is around %.2f C\r\n", temperature);
	  //printf("RAW VBAT VALUE 0x%lx\n", sample.vbatValue);
	  count++;

	  if(count>= 100){
		  count = 0;

		  uint32_t val = OPERATIONTHREAD; //priority 4 == operation

		  //GetMutex();
		  Log::getInstance().logWrite(&val);
		  //ReleaseMutex();

		  //send any error to error queue
		  errorThread::getInstance().errorSend(&val);

		  //osMutexAcquire(uartMutexHandle, osWaitForever);
		  puttyprintf("operationThread LogQUEUE PUT\n");
		  //osMutexRelease(uartMutexHandle);
		  //logQueue
	  }

	osDelay(100);
  }
}

void operationThreadEntry(void *argument)
{
  /* USER CODE BEGIN sampleThread */
  /* Infinite loop */
  operationThread::getInstance().run();

  /* USER CODE END sampleThread */
}

