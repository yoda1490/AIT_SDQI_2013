################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/LOCItems.cpp \
../src/LOCParts.cpp \
../src/PSP01.cpp 

OBJS += \
./src/LOCItems.o \
./src/LOCParts.o \
./src/PSP01.o 

CPP_DEPS += \
./src/LOCItems.d \
./src/LOCParts.d \
./src/PSP01.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


