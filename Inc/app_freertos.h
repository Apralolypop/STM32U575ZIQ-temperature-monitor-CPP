/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : app_freertos.h
  * Description        : FreeRTOS applicative header file
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __APP_FREERTOS_H__
#define __APP_FREERTOS_H__

#ifdef __cplusplus
extern "C" {
#endif
/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os2.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */


#include <stdio.h>
#include <stdbool.h>

#include <logThread.hpp>
#include <eeprom.h>

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Exported macro -------------------------------------------------------------*/
/* USER CODE BEGIN EM */
typedef enum{
	MAINTHREAD,
	LOGTHREAD,
	SAMPLETHREAD,
	OPERATIONTHREAD,
	ERRORTHREAD,
	USERBUTTONERRORPRESS = 100,
	ERROR201 = 201
} ThreadsType;

/* USER CODE END EM */
extern osThreadId_t mainThreadHandle;
extern osThreadId_t logThreadHandle;
extern osThreadId_t sampleThreadHandle;
extern osThreadId_t operationThreadHandle;
extern osThreadId_t errorHandleThreadHandle;
extern osMessageQueueId_t errorQueueHandle;
extern osMessageQueueId_t sampleQueueHandle;
extern osMessageQueueId_t logQueueHandle;

/* Exported function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

void puttyprintf(const char *s);


/* USER CODE END FunctionPrototypes */


void mainThreadEntry(void *argument);
void logThreadEntry(void *argument);
void sampleThreadEntry(void *argument);
void operationThreadEntry(void *argument);
void errorHandleThreadEntry(void *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

#ifdef __cplusplus
}
#endif
#endif /* __APP_FREERTOS_H__ */
