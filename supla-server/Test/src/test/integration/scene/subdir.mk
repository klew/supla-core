################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/test/integration/scene/SceneOperationsDaoTest.cpp 

CPP_DEPS += \
./src/test/integration/scene/SceneOperationsDaoTest.d 

OBJS += \
./src/test/integration/scene/SceneOperationsDaoTest.o 


# Each subdirectory must supply rules for building sources it contributes
src/test/integration/scene/%.o: ../src/test/integration/scene/%.cpp src/test/integration/scene/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -D__DEBUG=1 -DUSE_DEPRECATED_EMEV_V1 -D__TEST=1 -D__OPENSSL_TOOLS=1 -D__BCRYPT=1 -I../src -I../src/asynctask -I../src/mqtt -I$(INCMYSQL) -I../src/user -I../src/device -I../src/client -I$(SSLDIR)/include -I../src/test -O2 -g3 -Wall -fsigned-char -c -fmessage-length=0 -fstack-protector-all -D_FORTIFY_SOURCE=2 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src-2f-test-2f-integration-2f-scene

clean-src-2f-test-2f-integration-2f-scene:
	-$(RM) ./src/test/integration/scene/SceneOperationsDaoTest.d ./src/test/integration/scene/SceneOperationsDaoTest.o

.PHONY: clean-src-2f-test-2f-integration-2f-scene
