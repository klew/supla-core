################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/push/abstract_access_token_provider.cpp \
../src/push/abstract_push_notification_gateway_client.cpp \
../src/push/access_token_providers.cpp \
../src/push/apns_client.cpp \
../src/push/fcm_access_token_provider.cpp \
../src/push/fcm_client.cpp \
../src/push/pn_dao.cpp \
../src/push/pn_delivery_task.cpp \
../src/push/pn_recipient.cpp \
../src/push/pn_recipients.cpp \
../src/push/pn_throttling.cpp \
../src/push/push_notification.cpp 

CPP_DEPS += \
./src/push/abstract_access_token_provider.d \
./src/push/abstract_push_notification_gateway_client.d \
./src/push/access_token_providers.d \
./src/push/apns_client.d \
./src/push/fcm_access_token_provider.d \
./src/push/fcm_client.d \
./src/push/pn_dao.d \
./src/push/pn_delivery_task.d \
./src/push/pn_recipient.d \
./src/push/pn_recipients.d \
./src/push/pn_throttling.d \
./src/push/push_notification.d 

OBJS += \
./src/push/abstract_access_token_provider.o \
./src/push/abstract_push_notification_gateway_client.o \
./src/push/access_token_providers.o \
./src/push/apns_client.o \
./src/push/fcm_access_token_provider.o \
./src/push/fcm_client.o \
./src/push/pn_dao.o \
./src/push/pn_delivery_task.o \
./src/push/pn_recipient.o \
./src/push/pn_recipients.o \
./src/push/pn_throttling.o \
./src/push/push_notification.o 


# Each subdirectory must supply rules for building sources it contributes
src/push/%.o: ../src/push/%.cpp src/push/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	$(CXX) -D__DEBUG=1 -D__SUPLA_SERVER=1 -DSPROTO_WITHOUT_OUT_BUFFER -DSRPC_WITHOUT_OUT_QUEUE -DUSE_DEPRECATED_EMEV_V1 -D__OPENSSL_TOOLS=1 -D__SSOCKET_WRITE_TO_FILE=$(SSOCKET_WRITE_TO_FILE) -D__BCRYPT=1 -I$(INCMYSQL) -I../src/mqtt -I../src/device -I../src/user -I../src -I$(SSLDIR)/include -I../src/client -O2 -g3 -Wall -fsigned-char -c -fmessage-length=0 -fstack-protector-all -D_FORTIFY_SOURCE=2 -std=c++11 -fPIE -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src-2f-push

clean-src-2f-push:
	-$(RM) ./src/push/abstract_access_token_provider.d ./src/push/abstract_access_token_provider.o ./src/push/abstract_push_notification_gateway_client.d ./src/push/abstract_push_notification_gateway_client.o ./src/push/access_token_providers.d ./src/push/access_token_providers.o ./src/push/apns_client.d ./src/push/apns_client.o ./src/push/fcm_access_token_provider.d ./src/push/fcm_access_token_provider.o ./src/push/fcm_client.d ./src/push/fcm_client.o ./src/push/pn_dao.d ./src/push/pn_dao.o ./src/push/pn_delivery_task.d ./src/push/pn_delivery_task.o ./src/push/pn_recipient.d ./src/push/pn_recipient.o ./src/push/pn_recipients.d ./src/push/pn_recipients.o ./src/push/pn_throttling.d ./src/push/pn_throttling.o ./src/push/push_notification.d ./src/push/push_notification.o

.PHONY: clean-src-2f-push

