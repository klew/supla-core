################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/converter/value_to_action_converter.cpp 

CPP_DEPS += \
./src/converter/value_to_action_converter.d 

OBJS += \
./src/converter/value_to_action_converter.o 


# Each subdirectory must supply rules for building sources it contributes
src/converter/%.o: ../src/converter/%.cpp src/converter/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -D__BCRYPT=1 -DSPROTO_WITHOUT_OUT_BUFFER -DSRPC_WITHOUT_OUT_QUEUE -DUSE_DEPRECATED_EMEV_V1 -D__OPENSSL_TOOLS=1 -I$(INCMYSQL) -I../src/mqtt -I../src/client -I../src/user -I../src/device -I../src -I$(SSLDIR)/include -O3 -Wall -fsigned-char -c -fmessage-length=0 -fstack-protector-all -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src-2f-converter

clean-src-2f-converter:
	-$(RM) ./src/converter/value_to_action_converter.d ./src/converter/value_to_action_converter.o

.PHONY: clean-src-2f-converter
