################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/Burak/Desktop/calismalarim/freeRTOS/RTOS_workspace/common/Third_Party/SEGGER/SEGGER/SEGGER_RTT.c \
C:/Users/Burak/Desktop/calismalarim/freeRTOS/RTOS_workspace/common/Third_Party/SEGGER/SEGGER/SEGGER_RTT_printf.c \
C:/Users/Burak/Desktop/calismalarim/freeRTOS/RTOS_workspace/common/Third_Party/SEGGER/SEGGER/SEGGER_SYSVIEW.c 

S_UPPER_SRCS += \
C:/Users/Burak/Desktop/calismalarim/freeRTOS/RTOS_workspace/common/Third_Party/SEGGER/SEGGER/SEGGER_RTT_ASM_ARMv7M.S 

OBJS += \
./common/Third_Party/SEGGER/SEGGER/SEGGER_RTT.o \
./common/Third_Party/SEGGER/SEGGER/SEGGER_RTT_ASM_ARMv7M.o \
./common/Third_Party/SEGGER/SEGGER/SEGGER_RTT_printf.o \
./common/Third_Party/SEGGER/SEGGER/SEGGER_SYSVIEW.o 

S_UPPER_DEPS += \
./common/Third_Party/SEGGER/SEGGER/SEGGER_RTT_ASM_ARMv7M.d 

C_DEPS += \
./common/Third_Party/SEGGER/SEGGER/SEGGER_RTT.d \
./common/Third_Party/SEGGER/SEGGER/SEGGER_RTT_printf.d \
./common/Third_Party/SEGGER/SEGGER/SEGGER_SYSVIEW.d 


# Each subdirectory must supply rules for building sources it contributes
common/Third_Party/SEGGER/SEGGER/SEGGER_RTT.o: C:/Users/Burak/Desktop/calismalarim/freeRTOS/RTOS_workspace/common/Third_Party/SEGGER/SEGGER/SEGGER_RTT.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Burak/Desktop/calismalarim/freeRTOS/RTOS_workspace/common/Third_Party/FreeRTOS/include" -I"C:/Users/Burak/Desktop/calismalarim/freeRTOS/RTOS_workspace/common/Third_Party/SEGGER/SEGGER" -I"C:/Users/Burak/Desktop/calismalarim/freeRTOS/RTOS_workspace/common/Third_Party/SEGGER/Config" -I"C:/Users/Burak/Desktop/calismalarim/freeRTOS/RTOS_workspace/common/Third_Party/SEGGER/OS" -I"C:/Users/Burak/Desktop/calismalarim/freeRTOS/RTOS_workspace/common/Third_Party/FreeRTOS/portable/GCC/ARM_CM4F" -I../Task -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"common/Third_Party/SEGGER/SEGGER/SEGGER_RTT.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
common/Third_Party/SEGGER/SEGGER/SEGGER_RTT_ASM_ARMv7M.o: C:/Users/Burak/Desktop/calismalarim/freeRTOS/RTOS_workspace/common/Third_Party/SEGGER/SEGGER/SEGGER_RTT_ASM_ARMv7M.S
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -c -I"C:/Users/Burak/Desktop/calismalarim/freeRTOS/RTOS_workspace/common/Third_Party/SEGGER/Config" -I"C:/Users/Burak/Desktop/calismalarim/freeRTOS/RTOS_workspace/common/Third_Party/SEGGER/SEGGER" -I../Task -x assembler-with-cpp -MMD -MP -MF"common/Third_Party/SEGGER/SEGGER/SEGGER_RTT_ASM_ARMv7M.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"
common/Third_Party/SEGGER/SEGGER/SEGGER_RTT_printf.o: C:/Users/Burak/Desktop/calismalarim/freeRTOS/RTOS_workspace/common/Third_Party/SEGGER/SEGGER/SEGGER_RTT_printf.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Burak/Desktop/calismalarim/freeRTOS/RTOS_workspace/common/Third_Party/FreeRTOS/include" -I"C:/Users/Burak/Desktop/calismalarim/freeRTOS/RTOS_workspace/common/Third_Party/SEGGER/SEGGER" -I"C:/Users/Burak/Desktop/calismalarim/freeRTOS/RTOS_workspace/common/Third_Party/SEGGER/Config" -I"C:/Users/Burak/Desktop/calismalarim/freeRTOS/RTOS_workspace/common/Third_Party/SEGGER/OS" -I"C:/Users/Burak/Desktop/calismalarim/freeRTOS/RTOS_workspace/common/Third_Party/FreeRTOS/portable/GCC/ARM_CM4F" -I../Task -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"common/Third_Party/SEGGER/SEGGER/SEGGER_RTT_printf.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
common/Third_Party/SEGGER/SEGGER/SEGGER_SYSVIEW.o: C:/Users/Burak/Desktop/calismalarim/freeRTOS/RTOS_workspace/common/Third_Party/SEGGER/SEGGER/SEGGER_SYSVIEW.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Burak/Desktop/calismalarim/freeRTOS/RTOS_workspace/common/Third_Party/FreeRTOS/include" -I"C:/Users/Burak/Desktop/calismalarim/freeRTOS/RTOS_workspace/common/Third_Party/SEGGER/SEGGER" -I"C:/Users/Burak/Desktop/calismalarim/freeRTOS/RTOS_workspace/common/Third_Party/SEGGER/Config" -I"C:/Users/Burak/Desktop/calismalarim/freeRTOS/RTOS_workspace/common/Third_Party/SEGGER/OS" -I"C:/Users/Burak/Desktop/calismalarim/freeRTOS/RTOS_workspace/common/Third_Party/FreeRTOS/portable/GCC/ARM_CM4F" -I../Task -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"common/Third_Party/SEGGER/SEGGER/SEGGER_SYSVIEW.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

