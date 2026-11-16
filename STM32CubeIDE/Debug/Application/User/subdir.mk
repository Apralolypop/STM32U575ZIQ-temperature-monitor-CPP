################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Application/User/errorThread.cpp \
../Application/User/logThread.cpp \
../Application/User/mainThread.cpp \
../Application/User/operationThread.cpp \
../Application/User/sampleThread.cpp \
../Application/User/singleton.cpp 

C_SRCS += \
C:/whf/STM32/Tony_STM32/Project/EEPROM/Src/app_freertos.c \
../Application/User/eeprom.c \
C:/whf/STM32/Tony_STM32/Project/EEPROM/Src/main.c \
C:/whf/STM32/Tony_STM32/Project/EEPROM/Src/stm32u5xx_hal_msp.c \
C:/whf/STM32/Tony_STM32/Project/EEPROM/Src/stm32u5xx_hal_timebase_tim.c \
C:/whf/STM32/Tony_STM32/Project/EEPROM/Src/stm32u5xx_it.c \
../Application/User/syscalls.c \
../Application/User/sysmem.c 

C_DEPS += \
./Application/User/app_freertos.d \
./Application/User/eeprom.d \
./Application/User/main.d \
./Application/User/stm32u5xx_hal_msp.d \
./Application/User/stm32u5xx_hal_timebase_tim.d \
./Application/User/stm32u5xx_it.d \
./Application/User/syscalls.d \
./Application/User/sysmem.d 

OBJS += \
./Application/User/app_freertos.o \
./Application/User/eeprom.o \
./Application/User/errorThread.o \
./Application/User/logThread.o \
./Application/User/main.o \
./Application/User/mainThread.o \
./Application/User/operationThread.o \
./Application/User/sampleThread.o \
./Application/User/singleton.o \
./Application/User/stm32u5xx_hal_msp.o \
./Application/User/stm32u5xx_hal_timebase_tim.o \
./Application/User/stm32u5xx_it.o \
./Application/User/syscalls.o \
./Application/User/sysmem.o 

CPP_DEPS += \
./Application/User/errorThread.d \
./Application/User/logThread.d \
./Application/User/mainThread.d \
./Application/User/operationThread.d \
./Application/User/sampleThread.d \
./Application/User/singleton.d 


# Each subdirectory must supply rules for building sources it contributes
Application/User/app_freertos.o: C:/whf/STM32/Tony_STM32/Project/EEPROM/Src/app_freertos.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32U575xx -c -I../../Inc -I"C:/whf/STM32/Tony_STM32/Project/EEPROM/STM32CubeIDE/Application/Include" -IC:/Users/Celin/STM32Cube/Repository/STM32Cube_FW_U5_V1.7.0/Drivers/STM32U5xx_HAL_Driver/Inc -IC:/Users/Celin/STM32Cube/Repository/STM32Cube_FW_U5_V1.7.0/Drivers/STM32U5xx_HAL_Driver/Inc/Legacy -IC:/Users/Celin/STM32Cube/Repository/STM32Cube_FW_U5_V1.7.0/Drivers/CMSIS/Device/ST/STM32U5xx/Include -IC:/Users/Celin/STM32Cube/Repository/STM32Cube_FW_U5_V1.7.0/Drivers/CMSIS/Include -IC:/Users/Celin/STM32Cube/Repository//Packs/STMicroelectronics/X-CUBE-FREERTOS/1.3.0/Middlewares/Third_Party/FreeRTOS/Source/include/ -IC:/Users/Celin/STM32Cube/Repository//Packs/STMicroelectronics/X-CUBE-FREERTOS/1.3.0/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM33_NTZ/non_secure/ -IC:/Users/Celin/STM32Cube/Repository//Packs/STMicroelectronics/X-CUBE-FREERTOS/1.3.0/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/ -IC:/Users/Celin/STM32Cube/Repository//Packs/STMicroelectronics/X-CUBE-FREERTOS/1.3.0/Drivers/CMSIS/RTOS2/Include/ -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/%.o Application/User/%.su Application/User/%.cyclo: ../Application/User/%.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32U575xx -c -I../../Inc -I"C:/whf/STM32/Tony_STM32/Project/EEPROM/STM32CubeIDE/Application/Include" -IC:/Users/Celin/STM32Cube/Repository/STM32Cube_FW_U5_V1.7.0/Drivers/STM32U5xx_HAL_Driver/Inc -IC:/Users/Celin/STM32Cube/Repository/STM32Cube_FW_U5_V1.7.0/Drivers/STM32U5xx_HAL_Driver/Inc/Legacy -IC:/Users/Celin/STM32Cube/Repository/STM32Cube_FW_U5_V1.7.0/Drivers/CMSIS/Device/ST/STM32U5xx/Include -IC:/Users/Celin/STM32Cube/Repository/STM32Cube_FW_U5_V1.7.0/Drivers/CMSIS/Include -IC:/Users/Celin/STM32Cube/Repository//Packs/STMicroelectronics/X-CUBE-FREERTOS/1.3.0/Middlewares/Third_Party/FreeRTOS/Source/include/ -IC:/Users/Celin/STM32Cube/Repository//Packs/STMicroelectronics/X-CUBE-FREERTOS/1.3.0/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM33_NTZ/non_secure/ -IC:/Users/Celin/STM32Cube/Repository//Packs/STMicroelectronics/X-CUBE-FREERTOS/1.3.0/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/ -IC:/Users/Celin/STM32Cube/Repository//Packs/STMicroelectronics/X-CUBE-FREERTOS/1.3.0/Drivers/CMSIS/RTOS2/Include/ -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/%.o Application/User/%.su Application/User/%.cyclo: ../Application/User/%.cpp Application/User/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m33 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32U575xx -c -I../../Inc -I"C:/whf/STM32/Tony_STM32/Project/EEPROM/STM32CubeIDE/Application/Include" -IC:/Users/Celin/STM32Cube/Repository/STM32Cube_FW_U5_V1.7.0/Drivers/STM32U5xx_HAL_Driver/Inc -IC:/Users/Celin/STM32Cube/Repository/STM32Cube_FW_U5_V1.7.0/Drivers/STM32U5xx_HAL_Driver/Inc/Legacy -IC:/Users/Celin/STM32Cube/Repository/STM32Cube_FW_U5_V1.7.0/Drivers/CMSIS/Device/ST/STM32U5xx/Include -IC:/Users/Celin/STM32Cube/Repository/STM32Cube_FW_U5_V1.7.0/Drivers/CMSIS/Include -IC:/Users/Celin/STM32Cube/Repository//Packs/STMicroelectronics/X-CUBE-FREERTOS/1.3.0/Middlewares/Third_Party/FreeRTOS/Source/include/ -IC:/Users/Celin/STM32Cube/Repository//Packs/STMicroelectronics/X-CUBE-FREERTOS/1.3.0/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM33_NTZ/non_secure/ -IC:/Users/Celin/STM32Cube/Repository//Packs/STMicroelectronics/X-CUBE-FREERTOS/1.3.0/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/ -IC:/Users/Celin/STM32Cube/Repository//Packs/STMicroelectronics/X-CUBE-FREERTOS/1.3.0/Drivers/CMSIS/RTOS2/Include/ -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/main.o: C:/whf/STM32/Tony_STM32/Project/EEPROM/Src/main.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32U575xx -c -I../../Inc -I"C:/whf/STM32/Tony_STM32/Project/EEPROM/STM32CubeIDE/Application/Include" -IC:/Users/Celin/STM32Cube/Repository/STM32Cube_FW_U5_V1.7.0/Drivers/STM32U5xx_HAL_Driver/Inc -IC:/Users/Celin/STM32Cube/Repository/STM32Cube_FW_U5_V1.7.0/Drivers/STM32U5xx_HAL_Driver/Inc/Legacy -IC:/Users/Celin/STM32Cube/Repository/STM32Cube_FW_U5_V1.7.0/Drivers/CMSIS/Device/ST/STM32U5xx/Include -IC:/Users/Celin/STM32Cube/Repository/STM32Cube_FW_U5_V1.7.0/Drivers/CMSIS/Include -IC:/Users/Celin/STM32Cube/Repository//Packs/STMicroelectronics/X-CUBE-FREERTOS/1.3.0/Middlewares/Third_Party/FreeRTOS/Source/include/ -IC:/Users/Celin/STM32Cube/Repository//Packs/STMicroelectronics/X-CUBE-FREERTOS/1.3.0/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM33_NTZ/non_secure/ -IC:/Users/Celin/STM32Cube/Repository//Packs/STMicroelectronics/X-CUBE-FREERTOS/1.3.0/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/ -IC:/Users/Celin/STM32Cube/Repository//Packs/STMicroelectronics/X-CUBE-FREERTOS/1.3.0/Drivers/CMSIS/RTOS2/Include/ -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/stm32u5xx_hal_msp.o: C:/whf/STM32/Tony_STM32/Project/EEPROM/Src/stm32u5xx_hal_msp.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32U575xx -c -I../../Inc -I"C:/whf/STM32/Tony_STM32/Project/EEPROM/STM32CubeIDE/Application/Include" -IC:/Users/Celin/STM32Cube/Repository/STM32Cube_FW_U5_V1.7.0/Drivers/STM32U5xx_HAL_Driver/Inc -IC:/Users/Celin/STM32Cube/Repository/STM32Cube_FW_U5_V1.7.0/Drivers/STM32U5xx_HAL_Driver/Inc/Legacy -IC:/Users/Celin/STM32Cube/Repository/STM32Cube_FW_U5_V1.7.0/Drivers/CMSIS/Device/ST/STM32U5xx/Include -IC:/Users/Celin/STM32Cube/Repository/STM32Cube_FW_U5_V1.7.0/Drivers/CMSIS/Include -IC:/Users/Celin/STM32Cube/Repository//Packs/STMicroelectronics/X-CUBE-FREERTOS/1.3.0/Middlewares/Third_Party/FreeRTOS/Source/include/ -IC:/Users/Celin/STM32Cube/Repository//Packs/STMicroelectronics/X-CUBE-FREERTOS/1.3.0/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM33_NTZ/non_secure/ -IC:/Users/Celin/STM32Cube/Repository//Packs/STMicroelectronics/X-CUBE-FREERTOS/1.3.0/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/ -IC:/Users/Celin/STM32Cube/Repository//Packs/STMicroelectronics/X-CUBE-FREERTOS/1.3.0/Drivers/CMSIS/RTOS2/Include/ -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/stm32u5xx_hal_timebase_tim.o: C:/whf/STM32/Tony_STM32/Project/EEPROM/Src/stm32u5xx_hal_timebase_tim.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32U575xx -c -I../../Inc -I"C:/whf/STM32/Tony_STM32/Project/EEPROM/STM32CubeIDE/Application/Include" -IC:/Users/Celin/STM32Cube/Repository/STM32Cube_FW_U5_V1.7.0/Drivers/STM32U5xx_HAL_Driver/Inc -IC:/Users/Celin/STM32Cube/Repository/STM32Cube_FW_U5_V1.7.0/Drivers/STM32U5xx_HAL_Driver/Inc/Legacy -IC:/Users/Celin/STM32Cube/Repository/STM32Cube_FW_U5_V1.7.0/Drivers/CMSIS/Device/ST/STM32U5xx/Include -IC:/Users/Celin/STM32Cube/Repository/STM32Cube_FW_U5_V1.7.0/Drivers/CMSIS/Include -IC:/Users/Celin/STM32Cube/Repository//Packs/STMicroelectronics/X-CUBE-FREERTOS/1.3.0/Middlewares/Third_Party/FreeRTOS/Source/include/ -IC:/Users/Celin/STM32Cube/Repository//Packs/STMicroelectronics/X-CUBE-FREERTOS/1.3.0/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM33_NTZ/non_secure/ -IC:/Users/Celin/STM32Cube/Repository//Packs/STMicroelectronics/X-CUBE-FREERTOS/1.3.0/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/ -IC:/Users/Celin/STM32Cube/Repository//Packs/STMicroelectronics/X-CUBE-FREERTOS/1.3.0/Drivers/CMSIS/RTOS2/Include/ -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/stm32u5xx_it.o: C:/whf/STM32/Tony_STM32/Project/EEPROM/Src/stm32u5xx_it.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32U575xx -c -I../../Inc -I"C:/whf/STM32/Tony_STM32/Project/EEPROM/STM32CubeIDE/Application/Include" -IC:/Users/Celin/STM32Cube/Repository/STM32Cube_FW_U5_V1.7.0/Drivers/STM32U5xx_HAL_Driver/Inc -IC:/Users/Celin/STM32Cube/Repository/STM32Cube_FW_U5_V1.7.0/Drivers/STM32U5xx_HAL_Driver/Inc/Legacy -IC:/Users/Celin/STM32Cube/Repository/STM32Cube_FW_U5_V1.7.0/Drivers/CMSIS/Device/ST/STM32U5xx/Include -IC:/Users/Celin/STM32Cube/Repository/STM32Cube_FW_U5_V1.7.0/Drivers/CMSIS/Include -IC:/Users/Celin/STM32Cube/Repository//Packs/STMicroelectronics/X-CUBE-FREERTOS/1.3.0/Middlewares/Third_Party/FreeRTOS/Source/include/ -IC:/Users/Celin/STM32Cube/Repository//Packs/STMicroelectronics/X-CUBE-FREERTOS/1.3.0/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM33_NTZ/non_secure/ -IC:/Users/Celin/STM32Cube/Repository//Packs/STMicroelectronics/X-CUBE-FREERTOS/1.3.0/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/ -IC:/Users/Celin/STM32Cube/Repository//Packs/STMicroelectronics/X-CUBE-FREERTOS/1.3.0/Drivers/CMSIS/RTOS2/Include/ -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-User

clean-Application-2f-User:
	-$(RM) ./Application/User/app_freertos.cyclo ./Application/User/app_freertos.d ./Application/User/app_freertos.o ./Application/User/app_freertos.su ./Application/User/eeprom.cyclo ./Application/User/eeprom.d ./Application/User/eeprom.o ./Application/User/eeprom.su ./Application/User/errorThread.cyclo ./Application/User/errorThread.d ./Application/User/errorThread.o ./Application/User/errorThread.su ./Application/User/logThread.cyclo ./Application/User/logThread.d ./Application/User/logThread.o ./Application/User/logThread.su ./Application/User/main.cyclo ./Application/User/main.d ./Application/User/main.o ./Application/User/main.su ./Application/User/mainThread.cyclo ./Application/User/mainThread.d ./Application/User/mainThread.o ./Application/User/mainThread.su ./Application/User/operationThread.cyclo ./Application/User/operationThread.d ./Application/User/operationThread.o ./Application/User/operationThread.su ./Application/User/sampleThread.cyclo ./Application/User/sampleThread.d ./Application/User/sampleThread.o ./Application/User/sampleThread.su ./Application/User/singleton.cyclo ./Application/User/singleton.d ./Application/User/singleton.o ./Application/User/singleton.su ./Application/User/stm32u5xx_hal_msp.cyclo ./Application/User/stm32u5xx_hal_msp.d ./Application/User/stm32u5xx_hal_msp.o ./Application/User/stm32u5xx_hal_msp.su ./Application/User/stm32u5xx_hal_timebase_tim.cyclo ./Application/User/stm32u5xx_hal_timebase_tim.d ./Application/User/stm32u5xx_hal_timebase_tim.o ./Application/User/stm32u5xx_hal_timebase_tim.su ./Application/User/stm32u5xx_it.cyclo ./Application/User/stm32u5xx_it.d ./Application/User/stm32u5xx_it.o ./Application/User/stm32u5xx_it.su ./Application/User/syscalls.cyclo ./Application/User/syscalls.d ./Application/User/syscalls.o ./Application/User/syscalls.su ./Application/User/sysmem.cyclo ./Application/User/sysmem.d ./Application/User/sysmem.o ./Application/User/sysmem.su

.PHONY: clean-Application-2f-User

