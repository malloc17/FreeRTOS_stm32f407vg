################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Esp8266/esp8266_driver.c 

OBJS += \
./Esp8266/esp8266_driver.o 

C_DEPS += \
./Esp8266/esp8266_driver.d 


# Each subdirectory must supply rules for building sources it contributes
Esp8266/esp8266_driver.o: ../Esp8266/esp8266_driver.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Burak/Desktop/calismalarim/freeRTOS/RTOS_workspace/common/Third_Party/FreeRTOS/include" -I"C:/Users/Burak/Desktop/calismalarim/freeRTOS/RTOS_workspace/common/Third_Party/SEGGER/SEGGER" -I"C:/Users/Burak/Desktop/calismalarim/freeRTOS/RTOS_workspace/common/Third_Party/SEGGER/Config" -I"C:/Users/Burak/Desktop/calismalarim/freeRTOS/RTOS_workspace/common/Third_Party/SEGGER/OS" -I"C:/Users/Burak/Desktop/calismalarim/freeRTOS/RTOS_workspace/common/Third_Party/FreeRTOS/portable/GCC/ARM_CM4F" -I../Task -I../Esp8266 -I../Handler -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Esp8266/esp8266_driver.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

