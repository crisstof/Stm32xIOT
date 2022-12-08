################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/gpio.c \
../Src/main.c \
../Src/stm32l0xx_hal_msp.c \
../Src/stm32l0xx_it.c \
../Src/syscalls.c \
../Src/sysmem.c \
../Src/system_stm32l0xx.c \
../Src/usart.c 

OBJS += \
./Src/gpio.o \
./Src/main.o \
./Src/stm32l0xx_hal_msp.o \
./Src/stm32l0xx_it.o \
./Src/syscalls.o \
./Src/sysmem.o \
./Src/system_stm32l0xx.o \
./Src/usart.o 

C_DEPS += \
./Src/gpio.d \
./Src/main.d \
./Src/stm32l0xx_hal_msp.d \
./Src/stm32l0xx_it.d \
./Src/syscalls.d \
./Src/sysmem.d \
./Src/system_stm32l0xx.d \
./Src/usart.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L073xx -c -I../Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/gpio.d ./Src/gpio.o ./Src/main.d ./Src/main.o ./Src/stm32l0xx_hal_msp.d ./Src/stm32l0xx_hal_msp.o ./Src/stm32l0xx_it.d ./Src/stm32l0xx_it.o ./Src/syscalls.d ./Src/syscalls.o ./Src/sysmem.d ./Src/sysmem.o ./Src/system_stm32l0xx.d ./Src/system_stm32l0xx.o ./Src/usart.d ./Src/usart.o

.PHONY: clean-Src

