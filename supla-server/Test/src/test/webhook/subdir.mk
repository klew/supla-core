################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/test/webhook/StateWebhookClientTest.cpp \
../src/test/webhook/StateWebhookCredentialsTest.cpp \
../src/test/webhook/StateWebhookRequestTest.cpp \
../src/test/webhook/StateWebhookTokenRefreshTest.cpp 

CPP_DEPS += \
./src/test/webhook/StateWebhookClientTest.d \
./src/test/webhook/StateWebhookCredentialsTest.d \
./src/test/webhook/StateWebhookRequestTest.d \
./src/test/webhook/StateWebhookTokenRefreshTest.d 

OBJS += \
./src/test/webhook/StateWebhookClientTest.o \
./src/test/webhook/StateWebhookCredentialsTest.o \
./src/test/webhook/StateWebhookRequestTest.o \
./src/test/webhook/StateWebhookTokenRefreshTest.o 


# Each subdirectory must supply rules for building sources it contributes
src/test/webhook/%.o: ../src/test/webhook/%.cpp src/test/webhook/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -D__DEBUG=1 -D__SUPLA_SERVER=1 -DUSE_DEPRECATED_EMEV_V1 -D__TEST=1 -D__OPENSSL_TOOLS=1 -D__BCRYPT=1 -I../src -I../src/asynctask -I../src/mqtt -I$(INCMYSQL) -I../src/user -I../src/device -I../src/client -I$(SSLDIR)/include -I../src/test -O2 -g3 -Wall -fsigned-char -c -fmessage-length=0 -fstack-protector-all -D_FORTIFY_SOURCE=2 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src-2f-test-2f-webhook

clean-src-2f-test-2f-webhook:
	-$(RM) ./src/test/webhook/StateWebhookClientTest.d ./src/test/webhook/StateWebhookClientTest.o ./src/test/webhook/StateWebhookCredentialsTest.d ./src/test/webhook/StateWebhookCredentialsTest.o ./src/test/webhook/StateWebhookRequestTest.d ./src/test/webhook/StateWebhookRequestTest.o ./src/test/webhook/StateWebhookTokenRefreshTest.d ./src/test/webhook/StateWebhookTokenRefreshTest.o

.PHONY: clean-src-2f-test-2f-webhook

