################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Compiler/Scope.cpp \
../src/Compiler/Symbol.cpp \
../src/Compiler/SymbolTable.cpp \
../src/Compiler/SymbolTableInfo.cpp 

CC_SRCS += \
../src/Compiler/lex.cc \
../src/Compiler/main.cc \
../src/Compiler/parse.cc 

OBJS += \
./src/Compiler/Scope.o \
./src/Compiler/Symbol.o \
./src/Compiler/SymbolTable.o \
./src/Compiler/SymbolTableInfo.o \
./src/Compiler/lex.o \
./src/Compiler/main.o \
./src/Compiler/parse.o 

CC_DEPS += \
./src/Compiler/lex.d \
./src/Compiler/main.d \
./src/Compiler/parse.d 

CPP_DEPS += \
./src/Compiler/Scope.d \
./src/Compiler/Symbol.d \
./src/Compiler/SymbolTable.d \
./src/Compiler/SymbolTableInfo.d 


# Each subdirectory must supply rules for building sources it contributes
src/Compiler/%.o: ../src/Compiler/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++-4.7 -O0 -g3 -Wall -c -fmessage-length=0 -std=c++0x -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/Compiler/%.o: ../src/Compiler/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++-4.7 -O0 -g3 -Wall -c -fmessage-length=0 -std=c++0x -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


