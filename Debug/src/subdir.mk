################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/controlTest.cpp \
../src/main.cpp \
../src/staticFunction.cpp \
../src/threadControl.cpp 

C_SRCS += \
../src/mongoose.c 

OBJS += \
./src/controlTest.o \
./src/main.o \
./src/mongoose.o \
./src/staticFunction.o \
./src/threadControl.o 

CPP_DEPS += \
./src/controlTest.d \
./src/main.d \
./src/staticFunction.d \
./src/threadControl.d 

C_DEPS += \
./src/mongoose.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


