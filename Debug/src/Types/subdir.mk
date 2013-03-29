################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Types/BuiltinType.cpp \
../src/Types/Type.cpp 

OBJS += \
./src/Types/BuiltinType.o \
./src/Types/Type.o 

CPP_DEPS += \
./src/Types/BuiltinType.d \
./src/Types/Type.d 


# Each subdirectory must supply rules for building sources it contributes
src/Types/%.o: ../src/Types/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++-4.7 -I"/home/yuta/workspace/MIPSc/src/Compiler" -I"/home/yuta/workspace/MIPSc/src/Types" -O0 -g3 -Wall -c -fmessage-length=0 -std=c++0x -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


