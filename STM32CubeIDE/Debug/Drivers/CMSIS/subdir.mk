################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/whf/STM32/Tony_STM32/Project/EEPROM/Src/system_stm32u5xx.c 

C_DEPS += \
./Drivers/CMSIS/system_stm32u5xx.d 

OBJS += \
./Drivers/CMSIS/system_stm32u5xx.o 


# Each subdirectory must supply rules for building sources it contributes
Drivers/CMSIS/system_stm32u5xx.o: C:/whf/STM32/Tony_STM32/Project/EEPROM/Src/system_stm32u5xx.c Drivers/CMSIS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32U575xx -c -I../../Inc -I"C:/whf/STM32/Tony_STM32/Project/EEPROM/STM32CubeIDE/Application/Include" -IC:/Users/Celin/STM32Cube/Repository/STM32Cube_FW_U5_V1.7.0/Drivers/STM32U5xx_HAL_Driver/Inc -IC:/Users/Celin/STM32Cube/Repository/STM32Cube_FW_U5_V1.7.0/Drivers/STM32U5xx_HAL_Driver/Inc/Legacy -IC:/Users/Celin/STM32Cube/Repository/STM32Cube_FW_U5_V1.7.0/Drivers/CMSIS/Device/ST/STM32U5xx/Include -IC:/Users/Celin/STM32Cube/Repository/STM32Cube_FW_U5_V1.7.0/Drivers/CMSIS/Include -IC:/Users/Celin/STM32Cube/Repository//Packs/STMicroelectronics/X-CUBE-FREERTOS/1.3.0/Middlewares/Third_Party/FreeRTOS/Source/include/ -IC:/Users/Celin/STM32Cube/Repository//Packs/STMicroelectronics/X-CUBE-FREERTOS/1.3.0/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM33_NTZ/non_secure/ -IC:/Users/Celin/STM32Cube/Repository//Packs/STMicroelectronics/X-CUBE-FREERTOS/1.3.0/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/ -IC:/Users/Celin/STM32Cube/Repository//Packs/STMicroelectronics/X-CUBE-FREERTOS/1.3.0/Drivers/CMSIS/RTOS2/Include/ -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-CMSIS

clean-Drivers-2f-CMSIS:
	-$(RM) ./Drivers/CMSIS/system_stm32u5xx.cyclo ./Drivers/CMSIS/system_stm32u5xx.d ./Drivers/CMSIS/system_stm32u5xx.o ./Drivers/CMSIS/system_stm32u5xx.su

.PHONY: clean-Drivers-2f-CMSIS

