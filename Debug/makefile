################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/MTIMER0/subdir.mk
-include MCAL/MEEPROM/subdir.mk
-include MCAL/MDIO/subdir.mk
-include MCAL/MADC/subdir.mk
-include HAL/HMOTOR/subdir.mk
-include HAL/HLM35/subdir.mk
-include HAL/HLCD/subdir.mk
-include APP/subdir.mk
-include .metadata/.plugins/org.eclipse.cdt.make.core/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
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

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Smart_AC_team.lss \

FLASH_IMAGE += \
Smart_AC_team.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Smart_AC_team.elf secondary-outputs

# Tool invocations
Smart_AC_team.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Smart_AC_team.map -mmcu=atmega32 -o "Smart_AC_team.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Smart_AC_team.lss: Smart_AC_team.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Smart_AC_team.elf  >"Smart_AC_team.lss"
	@echo 'Finished building: $@'
	@echo ' '

Smart_AC_team.hex: Smart_AC_team.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Smart_AC_team.elf  "Smart_AC_team.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Smart_AC_team.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Smart_AC_team.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Smart_AC_team.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
