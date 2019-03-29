################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Utilities/Components/l3gd20/l3gd20.c 

OBJS += \
./Utilities/Components/l3gd20/l3gd20.o 

C_DEPS += \
./Utilities/Components/l3gd20/l3gd20.d 


# Each subdirectory must supply rules for building sources it contributes
Utilities/Components/l3gd20/%.o: ../Utilities/Components/l3gd20/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32 -DSTM32L4 -DSTM32L475VGTx -DB_L475E_IOT01A1 -DDEBUG -DSTM32L475xx -DUSE_HAL_DRIVER -I"C:/Users/atbecker22/workspace/Lab6/Utilities/Components/m24sr" -I"C:/Users/atbecker22/workspace/Lab6/Utilities/Components/cs43l22" -I"C:/Users/atbecker22/workspace/Lab6/Utilities/Components/mx25lm51245g" -I"C:/Users/atbecker22/workspace/Lab6/Utilities/Components/mfxstm32l152" -I"C:/Users/atbecker22/workspace/Lab6/CMSIS/device" -I"C:/Users/atbecker22/workspace/Lab6/Utilities/Components/cs42l51" -I"C:/Users/atbecker22/workspace/Lab6/Utilities/Components/n25q128a" -I"C:/Users/atbecker22/workspace/Lab6/Utilities/Components/st7735" -I"C:/Users/atbecker22/workspace/Lab6/Utilities/Components/ft3x67" -I"C:/Users/atbecker22/workspace/Lab6/Utilities/Components/rk043fn48h" -I"C:/Users/atbecker22/workspace/Lab6/Utilities/Components/hx8347g" -I"C:/Users/atbecker22/workspace/Lab6/HAL_Driver/Inc/Legacy" -I"C:/Users/atbecker22/workspace/Lab6/Utilities/Components/ov9655" -I"C:/Users/atbecker22/workspace/Lab6/Utilities/Components/stmpe1600" -I"C:/Users/atbecker22/workspace/Lab6/Utilities/Components/Common" -I"C:/Users/atbecker22/workspace/Lab6/Utilities/Components/l3gd20" -I"C:/Users/atbecker22/workspace/Lab6/Utilities/Components/lsm6dsl" -I"C:/Users/atbecker22/workspace/Lab6/HAL_Driver/Inc" -I"C:/Users/atbecker22/workspace/Lab6/Utilities/Components/stmpe811" -I"C:/Users/atbecker22/workspace/Lab6/Utilities/Components/wm8994" -I"C:/Users/atbecker22/workspace/Lab6/Utilities/B-L475E-IOT01" -I"C:/Users/atbecker22/workspace/Lab6/Utilities/Components/ft5336" -I"C:/Users/atbecker22/workspace/Lab6/Utilities/Components/n25q256a" -I"C:/Users/atbecker22/workspace/Lab6/inc" -I"C:/Users/atbecker22/workspace/Lab6/Utilities/Components/hts221" -I"C:/Users/atbecker22/workspace/Lab6/Utilities/Components/ls016b8uy" -I"C:/Users/atbecker22/workspace/Lab6/Utilities/Components/ft6x06" -I"C:/Users/atbecker22/workspace/Lab6/Utilities/Components/lis3mdl" -I"C:/Users/atbecker22/workspace/Lab6/Utilities/Components/lps22hb" -I"C:/Users/atbecker22/workspace/Lab6/Utilities/Components/st7789h2" -I"C:/Users/atbecker22/workspace/Lab6/Utilities/Components/lsm303c" -I"C:/Users/atbecker22/workspace/Lab6/Utilities/Components/iss66wvh8m8" -I"C:/Users/atbecker22/workspace/Lab6/Utilities/Components/lsm303dlhc" -I"C:/Users/atbecker22/workspace/Lab6/CMSIS/core" -I"C:/Users/atbecker22/workspace/Lab6/Utilities/Components/mx25r6435f" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


