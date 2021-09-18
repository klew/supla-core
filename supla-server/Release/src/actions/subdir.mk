################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/actions/abstract_channel_action_executor.cpp \
../src/actions/abstract_gate_state_getter.cpp \
../src/actions/action_gate_openclose.cpp \
../src/actions/action_gate_openclose_search_condition.cpp \
../src/actions/action_trigger.cpp \
../src/actions/action_trigger_config.cpp \
../src/actions/channel_action_executor.cpp \
../src/actions/gate_state_getter.cpp 

OBJS += \
./src/actions/abstract_channel_action_executor.o \
./src/actions/abstract_gate_state_getter.o \
./src/actions/action_gate_openclose.o \
./src/actions/action_gate_openclose_search_condition.o \
./src/actions/action_trigger.o \
./src/actions/action_trigger_config.o \
./src/actions/channel_action_executor.o \
./src/actions/gate_state_getter.o 

CPP_DEPS += \
./src/actions/abstract_channel_action_executor.d \
./src/actions/abstract_gate_state_getter.d \
./src/actions/action_gate_openclose.d \
./src/actions/action_gate_openclose_search_condition.d \
./src/actions/action_trigger.d \
./src/actions/action_trigger_config.d \
./src/actions/channel_action_executor.d \
./src/actions/gate_state_getter.d 


# Each subdirectory must supply rules for building sources it contributes
src/actions/%.o: ../src/actions/%.cpp src/actions/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -D__BCRYPT=1 -DSPROTO_WITHOUT_OUT_BUFFER -DSRPC_WITHOUT_OUT_QUEUE -DUSE_DEPRECATED_EMEV_V1 -D__OPENSSL_TOOLS=1 -I$(INCMYSQL) -I../src/mqtt -I../src/client -I../src/user -I../src/device -I../src -I$(SSLDIR)/include -O3 -Wall -fsigned-char -c -fmessage-length=0 -fstack-protector-all -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


