################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Types/ArrayType.cpp \
../src/Types/BuiltinType.cpp \
../src/Types/EnumType.cpp \
../src/Types/FunctionType.cpp \
../src/Types/PointerType.cpp \
../src/Types/StructType.cpp \
../src/Types/Type.cpp \
../src/Types/TypedefType.cpp \
../src/Types/UnionType.cpp 

OBJS += \
./src/Types/ArrayType.o \
./src/Types/BuiltinType.o \
./src/Types/EnumType.o \
./src/Types/FunctionType.o \
./src/Types/PointerType.o \
./src/Types/StructType.o \
./src/Types/Type.o \
./src/Types/TypedefType.o \
./src/Types/UnionType.o 

CPP_DEPS += \
./src/Types/ArrayType.d \
./src/Types/BuiltinType.d \
./src/Types/EnumType.d \
./src/Types/FunctionType.d \
./src/Types/PointerType.d \
./src/Types/StructType.d \
./src/Types/Type.d \
./src/Types/TypedefType.d \
./src/Types/UnionType.d 


# Each subdirectory must supply rules for building sources it contributes
src/Types/%.o: ../src/Types/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++-4.7 -I"/home/njordan/workspace/mipsc/src/Compiler" -I"/home/njordan/workspace/mipsc/src/AST" -I"/home/njordan/workspace/mipsc/src/3AC" -I"/home/njordan/workspace/mipsc/src/ASM" -I"/home/njordan/workspace/mipsc/src/Types" -O0 -g3 -Wall -c -fmessage-length=0 -std=c++0x -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


