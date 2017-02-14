################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/mail2.c 

OBJS += \
./src/mail2.o 

C_DEPS += \
./src/mail2.d 


# Each subdirectory must supply rules for building sources it contributes
src/mail2.o: ../src/mail2.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"src/mail2.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


