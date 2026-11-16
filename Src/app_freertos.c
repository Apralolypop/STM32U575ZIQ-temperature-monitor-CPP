/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : app_freertos.c
  * Description        : FreeRTOS applicative file
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

/* Includes ------------------------------------------------------------------*/
#include "app_freertos.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
typedef StaticQueue_t osStaticMessageQDef_t;
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */


osMutexId_t uartMutexHandle; //printf

/* USER CODE END Variables */
/* Definitions for mainThread */
osThreadId_t mainThreadHandle;
const osThreadAttr_t mainThread_attributes = {
  .name = "mainThread",
  .priority = (osPriority_t) osPriorityLow,
  .stack_size = 1024 * 4
};
/* Definitions for logThread */
osThreadId_t logThreadHandle;
const osThreadAttr_t logThread_attributes = {
  .name = "logThread",
  .priority = (osPriority_t) osPriorityLow5,
  .stack_size = 2048 * 4
};
/* Definitions for sampleThread */
osThreadId_t sampleThreadHandle;
const osThreadAttr_t sampleThread_attributes = {
  .name = "sampleThread",
  .priority = (osPriority_t) osPriorityNormal,
  .stack_size = 2048 * 4
};
/* Definitions for operationThread */
osThreadId_t operationThreadHandle;
const osThreadAttr_t operationThread_attributes = {
  .name = "operationThread",
  .priority = (osPriority_t) osPriorityAboveNormal,
  .stack_size = 2048 * 4
};
/* Definitions for errorHandleThread */
osThreadId_t errorHandleThreadHandle;
const osThreadAttr_t errorHandleThread_attributes = {
  .name = "errorHandleThread",
  .priority = (osPriority_t) osPriorityLow,
  .stack_size = 2048 * 4
};
/* Definitions for errorQueue */
osMessageQueueId_t errorQueueHandle;
uint8_t errorQueueBuffer[ 32 * sizeof( uint32_t ) ];
osStaticMessageQDef_t errorQueueControlBlock;
const osMessageQueueAttr_t errorQueue_attributes = {
  .name = "errorQueue",
  .cb_mem = &errorQueueControlBlock,
  .cb_size = sizeof(errorQueueControlBlock),
  .mq_mem = &errorQueueBuffer,
  .mq_size = sizeof(errorQueueBuffer)
};
/* Definitions for sampleQueue */
osMessageQueueId_t sampleQueueHandle;
const osMessageQueueAttr_t sampleQueue_attributes = {
  .name = "sampleQueue"
};
/* Definitions for logQueue */
osMessageQueueId_t logQueueHandle;
uint8_t logQueueBuffer[ 32 * sizeof( uint32_t ) ];
osStaticMessageQDef_t logQueueControlBlock;
const osMessageQueueAttr_t logQueue_attributes = {
  .name = "logQueue",
  .cb_mem = &logQueueControlBlock,
  .cb_size = sizeof(logQueueControlBlock),
  .mq_mem = &logQueueBuffer,
  .mq_size = sizeof(logQueueBuffer)
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */
void puttyprintf(const char *s)
{
    osMutexAcquire(uartMutexHandle, osWaitForever);

    printf("%s", s);

    osMutexRelease(uartMutexHandle);
}
/* USER CODE END FunctionPrototypes */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */


  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */


  /* add mutexes, ... */
  uartMutexHandle = osMutexNew(NULL);


  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */
  /* creation of errorQueue */
  errorQueueHandle = osMessageQueueNew (32, sizeof(uint32_t), &errorQueue_attributes);
  /* creation of sampleQueue */
  sampleQueueHandle = osMessageQueueNew (32, sizeof(uint32_t), &sampleQueue_attributes);
  /* creation of logQueue */
  logQueueHandle = osMessageQueueNew (32, sizeof(uint32_t), &logQueue_attributes);

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */
  /* creation of mainThread */
  mainThreadHandle = osThreadNew(mainThreadEntry, NULL, &mainThread_attributes);

  /* creation of logThread */
  logThreadHandle = osThreadNew(logThreadEntry, NULL, &logThread_attributes);

  /* creation of sampleThread */
  sampleThreadHandle = osThreadNew(sampleThreadEntry, NULL, &sampleThread_attributes);

  /* creation of operationThread */
  operationThreadHandle = osThreadNew(operationThreadEntry, NULL, &operationThread_attributes);

  /* creation of errorHandleThread */
  errorHandleThreadHandle = osThreadNew(errorHandleThreadEntry, NULL, &errorHandleThread_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */



  printf("main   = %p\r\n", mainThreadHandle);
  printf("log    = %p\r\n", logThreadHandle);
  printf("sample = %p\r\n", sampleThreadHandle);
  printf("operation = %p\r\n", operationThreadHandle);
  printf("error  = %p\r\n", errorHandleThreadHandle);
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}
/* USER CODE BEGIN Header_mainThreadEntry */
/**
* @brief Function implementing the mainThread thread.
* @param argument: Not used
* @retval None
*/

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

