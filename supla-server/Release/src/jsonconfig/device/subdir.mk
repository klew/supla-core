################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/jsonconfig/device/device_json_config.cpp 

CPP_DEPS += \
./src/jsonconfig/device/device_json_config.d 

OBJS += \
./src/jsonconfig/device/device_json_config.o 


# Each subdirectory must supply rules for building sources it contributes
src/jsonconfig/device/%.o: ../src/jsonconfig/device/%.cpp src/jsonconfig/device/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -D__BCRYPT=1 -DUSE_OS_TZDB=1 -D__SUPLA_SERVER=1 -DSPROTO_WITHOUT_OUT_BUFFER -DSRPC_WITHOUT_OUT_QUEUE -DUSE_DEPRECATED_EMEV_V1 -DUSE_DEPRECATED_EMEV_V2 -D__OPENSSL_TOOLS=1 -I$(INCMYSQL) -I../src/mqtt -I../src/client -I../src/user -I../src/device -I../src -I$(SSLDIR)/include -O2 -Wall -fsigned-char -c -fmessage-length=0 -fstack-protector-all -std=c++11 -fPIE -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src-2f-jsonconfig-2f-device

clean-src-2f-jsonconfig-2f-device:
	-$(RM) ./src/jsonconfig/device/device_json_config.d ./src/jsonconfig/device/device_json_config.o

.PHONY: clean-src-2f-jsonconfig-2f-device

