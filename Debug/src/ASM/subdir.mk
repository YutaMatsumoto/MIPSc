################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/ASM/MIPSGenerator.cpp 

OBJS += \
./src/ASM/MIPSGenerator.o 

CPP_DEPS += \
./src/ASM/MIPSGenerator.d 


# Each subdirectory must supply rules for building sources it contributes
src/ASM/%.o: ../src/ASM/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++-4.7 -I"/home/njordan/workspace/mipsc/src/Compiler" -I"/home/njordan/workspace/mipsc/src/AST" -I"/home/njordan/workspace/mipsc/src/3AC" -I"/home/njordan/workspace/mipsc/src/ASM" -I"/home/njordan/workspace/mipsc/src/Types" -O0 -g3 -Wall -c -fmessage-length=0 -std=c++0x -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


