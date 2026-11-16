################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/Celin/STM32Cube/Repository/Packs/STMicroelectronics/X-CUBE-FREERTOS/1.3.0/Middlewares/Third_Party/FreeRTOS/Source/portable/MemMang/heap_4.c 

C_DEPS += \
./Middlewares/RTOS2/CMSIS/RTOS2/Heap/Heap_4/heap_4.d 

OBJS += \
./Middlewares/RTOS2/CMSIS/RTOS2/Heap/Heap_4/heap_4.o 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/RTOS2/CMSIS/RTOS2/Heap/Heap_4/heap_4.o: C:/Users/Celin/STM32Cube/Repository/Packs/STMicroelectronics/X-CUBE-FREERTOS/1.3.0/Middlewares/Third_Party/FreeRTOS/Source/portable/MemMang/heap_4.c Middlewares/RTOS2/CMSIS/RTOS2/Heap/Heap_4/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32U575xx -c -I../../Inc -I"C:/whf/STM32/Tony_STM32/Project/EEPROM/STM32CubeIDE/Application/Include" -IC:/Users/Celin/STM32Cube/Repository/STM32Cube_FW_U5_V1.7.0/Drivers/STM32U5xx_HAL_Driver/Inc -IC:/Users/Celin/STM32Cube/Repository/STM32Cube_FW_U5_V1.7.0/Drivers/STM32U5xx_HAL_Driver/Inc/Legacy -IC:/Users/Celin/STM32Cube/Repository/STM32Cube_FW_U5_V1.7.0/Drivers/CMSIS/Device/ST/STM32U5xx/Include -IC:/Users/Celin/STM32Cube/Repository/STM32Cube_FW_U5_V1.7.0/Drivers/CMSIS/Include -IC:/Users/Celin/STM32Cube/Repository//Packs/STMicroelectronics/X-CUBE-FREERTOS/1.3.0/Middlewares/Third_Party/FreeRTOS/Source/include/ -IC:/Users/Celin/STM32Cube/Repository//Packs/STMicroelectronics/X-CUBE-FREERTOS/1.3.0/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM33_NTZ/non_secure/ -IC:/Users/Celin/STM32Cube/Repository//Packs/STMicroelectronics/X-CUBE-FREERTOS/1.3.0/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/ -IC:/Users/Celin/STM32Cube/Repository//Packs/STMicroelectronics/X-CUBE-FREERTOS/1.3.0/Drivers/CMSIS/RTOS2/Include/ -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-RTOS2-2f-CMSIS-2f-RTOS2-2f-Heap-2f-Heap_4

clean-Middlewares-2f-RTOS2-2f-CMSIS-2f-RTOS2-2f-Heap-2f-Heap_4:
	-$(RM) ./Middlewares/RTOS2/CMSIS/RTOS2/Heap/Heap_4/heap_4.cyclo ./Middlewares/RTOS2/CMSIS/RTOS2/Heap/Heap_4/heap_4.d ./Middlewares/RTOS2/CMSIS/RTOS2/Heap/Heap_4/heap_4.o ./Middlewares/RTOS2/CMSIS/RTOS2/Heap/Heap_4/heap_4.su

.PHONY: clean-Middlewares-2f-RTOS2-2f-CMSIS-2f-RTOS2-2f-Heap-2f-Heap_4

