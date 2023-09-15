################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include common/Third_Party/SEGGER/SEGGER/Syscalls/subdir.mk
-include common/Third_Party/SEGGER/SEGGER/subdir.mk
-include common/Third_Party/SEGGER/OS/subdir.mk
-include common/Third_Party/SEGGER/Config/subdir.mk
-include common/Third_Party/FreeRTOS/portable/MemMang/subdir.mk
-include common/Third_Party/FreeRTOS/portable/GCC/ARM_CM4F/subdir.mk
-include common/Third_Party/FreeRTOS/subdir.mk
-include Uif/subdir.mk
-include Task/subdir.mk
-include Logs/subdir.mk
-include Drivers/STM32F4xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

BUILD_ARTIFACT_NAME := 9_FreeRTOS_count_semaphore
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX := 
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME).$(BUILD_ARTIFACT_EXTENSION)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
9_FreeRTOS_count_semaphore.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
9_FreeRTOS_count_semaphore.list \

OBJCOPY_BIN += \
9_FreeRTOS_count_semaphore.bin \


# All Target
all: main-build

# Main-build Target
main-build: 9_FreeRTOS_count_semaphore.elf secondary-outputs

# Tool invocations
9_FreeRTOS_count_semaphore.elf: $(OBJS) $(USER_OBJS) C:\Users\Burak\Desktop\calismalarim\freeRTOS\RTOS_workspace\9_FreeRTOS_count_semaphore\STM32F407VGTX_FLASH.ld
	arm-none-eabi-gcc -o "9_FreeRTOS_count_semaphore.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\Users\Burak\Desktop\calismalarim\freeRTOS\RTOS_workspace\9_FreeRTOS_count_semaphore\STM32F407VGTX_FLASH.ld" --specs=nosys.specs -Wl,-Map="9_FreeRTOS_count_semaphore.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

9_FreeRTOS_count_semaphore.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "9_FreeRTOS_count_semaphore.list"
	@echo 'Finished building: $@'
	@echo ' '

9_FreeRTOS_count_semaphore.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "9_FreeRTOS_count_semaphore.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents fail-specified-linker-script-missing warn-no-linker-script-specified
.SECONDARY:

-include ../makefile.targets
