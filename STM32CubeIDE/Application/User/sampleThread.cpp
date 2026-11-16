/*
 * sampleThread.c
 *
 *  Created on: Aug 19, 2026
 *      Author: Celin
 */
#include <stdbool.h>

#include "sampleThread.hpp"
#include "errorThread.hpp"
#include "logThread.hpp"

#define SAMPLE_INVALID UINT32_MAX



extern osMutexId_t uartMutexHandle;
extern ADC_HandleTypeDef hadc1;

sampleThread::sampleThread(){
	firstSample = false;
	sample.vbatValue = 0U;
    sample.tempValue = 0U;
	sampleMutexHandle = nullptr;
}

sampleThread& sampleThread::getInstance() {
    static sampleThread instance;
    return instance;
}

void sampleThread::GetMutex(){
    osMutexAcquire(sampleMutexHandle, osWaitForever);
}

void sampleThread::ReleaseMutex(){
    osMutexRelease(sampleMutexHandle);
}

Sample_Data sampleThread::sampleGet(){

	Sample_Data returnSample;

	if(firstSample == false){
		returnSample.tempValue = SAMPLE_INVALID;
		returnSample.vbatValue = 0;
		return returnSample;
	}

	sampleThread::GetMutex();

    returnSample.tempValue = sample.tempValue;
    returnSample.vbatValue = sample.vbatValue;

    sampleThread::ReleaseMutex();

    return returnSample;
}

HAL_StatusTypeDef sampleThread::sampleRead(){
    HAL_StatusTypeDef status=HAL_OK;

    status = sampleTemperature();

    if(status!= HAL_OK)
    {
    	return status;
    }

    status=sampleVbat();

    return status;
}

HAL_StatusTypeDef sampleThread::sampleInit(){
	sample.vbatValue = 0U;
    sample.tempValue = 0U;
	sampleMutexHandle = osMutexNew(NULL);
	return HAL_OK;
}

HAL_StatusTypeDef sampleThread::sampleVbat() {

	HAL_StatusTypeDef status;

	sampleThread::GetMutex();

	  /* USER CODE BEGIN ADC1_Init 2 */
	ADC_ChannelConfTypeDef sConfig = {0};

	sConfig.Channel = ADC_CHANNEL_VBAT;
	sConfig.Rank = ADC_REGULAR_RANK_1;
	sConfig.SamplingTime = ADC_SAMPLETIME_391CYCLES_5;
	sConfig.SingleDiff = ADC_SINGLE_ENDED;
	sConfig.OffsetNumber = ADC_OFFSET_NONE;
	sConfig.Offset = 0;

	if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
	{
	  Error_Handler();
	}

	status = HAL_ADC_Start(&hadc1);
	if (status != HAL_OK)
	return status;

	status = HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);

	if (status == HAL_OK)
	{
		sample.vbatValue = HAL_ADC_GetValue(&hadc1);
	}

	HAL_ADC_Stop(&hadc1);

	sampleThread::ReleaseMutex();

	return status;
}

HAL_StatusTypeDef sampleThread::sampleTemperature(){

	HAL_StatusTypeDef status;

	sampleThread::GetMutex();

	  /* USER CODE BEGIN ADC1_Init 2 */
	ADC_ChannelConfTypeDef sConfig = {0};

	sConfig.Channel = ADC_CHANNEL_TEMPSENSOR; //ADC_CHANNEL_1
	sConfig.Rank = ADC_REGULAR_RANK_1;
	sConfig.SamplingTime = ADC_SAMPLETIME_391CYCLES_5;
	sConfig.SingleDiff = ADC_SINGLE_ENDED;
	sConfig.OffsetNumber = ADC_OFFSET_NONE;
	sConfig.Offset = 0;

	if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
	{
	  Error_Handler();
	}

	status = HAL_ADC_Start(&hadc1);
	if (status != HAL_OK)
	return status;

	status = HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);

	if (status == HAL_OK)
	{
		sample.tempValue = HAL_ADC_GetValue(&hadc1);
	}

	HAL_ADC_Stop(&hadc1);

	sampleThread::ReleaseMutex();

	return status;
}


void sampleThread::run(){
	sampleInit();

	  HAL_StatusTypeDef status = sampleRead();
	  if(status == HAL_OK)
	  {
		  firstSample = true;
	  }
	  else
	  {
		  //error msg
		  uint32_t errorSendValue = (uint32_t)status;
		  errorThread::getInstance().errorSend(&errorSendValue);
	  }
	  /* Infinite loop */
	  uint32_t count = 0;

	  for(;;)
	  {
		status = sampleRead();
		if(status!= HAL_OK){
			//error msg
		}

		count++;

		if(count>= 100)
		{
			count = 0;

			uint32_t val = SAMPLETHREAD; //priority 3 == sample

			//GetMutex();
			Log::getInstance().logWrite(&val);
			//ReleaseMutex();

			//send any error to error queue
			errorThread::getInstance().errorSend(&val);

			//osMutexAcquire(uartMutexHandle, osWaitForever);
			puttyprintf("sampleThread LogQUEUE PUT\n");
			//osMutexRelease(uartMutexHandle);
			//logQueue
		}

		osDelay(100);
	  }
}


void sampleThreadEntry(void *argument)
{
  /* USER CODE BEGIN sampleThread */
  sampleThread::getInstance().run();
  /* USER CODE END sampleThread */
}

