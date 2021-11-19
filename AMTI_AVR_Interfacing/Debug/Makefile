################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL := cmd.exe
RM := rm -rf

USER_OBJS :=

LIBS := 
PROJ := 

O_SRCS := 
C_SRCS := 
S_SRCS := 
S_UPPER_SRCS := 
OBJ_SRCS := 
ASM_SRCS := 
PREPROCESSING_SRCS := 
OBJS := 
OBJS_AS_ARGS := 
C_DEPS := 
C_DEPS_AS_ARGS := 
EXECUTABLES := 
OUTPUT_FILE_PATH :=
OUTPUT_FILE_PATH_AS_ARGS :=
AVR_APP_PATH :=$$$AVR_APP_PATH$$$
QUOTE := "
ADDITIONAL_DEPENDENCIES:=
OUTPUT_FILE_DEP:=
LIB_DEP:=
LINKER_SCRIPT_DEP:=

# Every subdirectory with source files must be described here
SUBDIRS := 


# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS +=  \
../ADC.c \
../Dio.c \
../I2C.c \
../ISRs.c \
../KeyPad.c \
../LCD.c \
../LED.c \
../main.c \
../PushButton.c \
../SevenSegement.c \
../SPI.c \
../StringHandler.c \
../Timer0.c \
../Timer1.c


PREPROCESSING_SRCS += 


ASM_SRCS += 


OBJS +=  \
ADC.o \
Dio.o \
I2C.o \
ISRs.o \
KeyPad.o \
LCD.o \
LED.o \
main.o \
PushButton.o \
SevenSegement.o \
SPI.o \
StringHandler.o \
Timer0.o \
Timer1.o

OBJS_AS_ARGS +=  \
ADC.o \
Dio.o \
I2C.o \
ISRs.o \
KeyPad.o \
LCD.o \
LED.o \
main.o \
PushButton.o \
SevenSegement.o \
SPI.o \
StringHandler.o \
Timer0.o \
Timer1.o

C_DEPS +=  \
ADC.d \
Dio.d \
I2C.d \
ISRs.d \
KeyPad.d \
LCD.d \
LED.d \
main.d \
PushButton.d \
SevenSegement.d \
SPI.d \
StringHandler.d \
Timer0.d \
Timer1.d

C_DEPS_AS_ARGS +=  \
ADC.d \
Dio.d \
I2C.d \
ISRs.d \
KeyPad.d \
LCD.d \
LED.d \
main.d \
PushButton.d \
SevenSegement.d \
SPI.d \
StringHandler.d \
Timer0.d \
Timer1.d

OUTPUT_FILE_PATH +=AMTI_AVR_Interfacing.elf

OUTPUT_FILE_PATH_AS_ARGS +=AMTI_AVR_Interfacing.elf

ADDITIONAL_DEPENDENCIES:=

OUTPUT_FILE_DEP:= ./makedep.mk

LIB_DEP+= 

LINKER_SCRIPT_DEP+= 


# AVR32/GNU C Compiler





























./%.o: .././%.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : 5.4.0
	$(QUOTE)C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -funsigned-char -funsigned-bitfields -DDEBUG  -I"C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.2.132\include"  -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega32 -B "C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.2.132\gcc\dev\atmega32" -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	



# AVR32/GNU Preprocessing Assembler



# AVR32/GNU Assembler




ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: $(OUTPUT_FILE_PATH) $(ADDITIONAL_DEPENDENCIES)

$(OUTPUT_FILE_PATH): $(OBJS) $(USER_OBJS) $(OUTPUT_FILE_DEP) $(LIB_DEP) $(LINKER_SCRIPT_DEP)
	@echo Building target: $@
	@echo Invoking: AVR/GNU Linker : 5.4.0
	$(QUOTE)C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE) -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS) -Wl,-Map="AMTI_AVR_Interfacing.map" -Wl,--start-group -Wl,-lm  -Wl,--end-group -Wl,--gc-sections -mmcu=atmega32 -B "C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.2.132\gcc\dev\atmega32"  
	@echo Finished building target: $@
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O ihex -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures  "AMTI_AVR_Interfacing.elf" "AMTI_AVR_Interfacing.hex"
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -j .eeprom  --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0  --no-change-warnings -O ihex "AMTI_AVR_Interfacing.elf" "AMTI_AVR_Interfacing.eep" || exit 0
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objdump.exe" -h -S "AMTI_AVR_Interfacing.elf" > "AMTI_AVR_Interfacing.lss"
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O srec -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures "AMTI_AVR_Interfacing.elf" "AMTI_AVR_Interfacing.srec"
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-size.exe" "AMTI_AVR_Interfacing.elf"
	
	





# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS) $(EXECUTABLES)  
	-$(RM) $(C_DEPS_AS_ARGS)   
	rm -rf "AMTI_AVR_Interfacing.elf" "AMTI_AVR_Interfacing.a" "AMTI_AVR_Interfacing.hex" "AMTI_AVR_Interfacing.lss" "AMTI_AVR_Interfacing.eep" "AMTI_AVR_Interfacing.map" "AMTI_AVR_Interfacing.srec" "AMTI_AVR_Interfacing.usersignatures"
	