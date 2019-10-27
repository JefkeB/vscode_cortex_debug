## keep this name in sync with the 1 used in
## launch.json
## "executable": ".\\build\\${workspaceFolderBasename}.elf",
PROJ_NAME=SAMD21
VERBOSE = @

SOURCE_SUB_DIR = Source

PROCESSOR_MODEL = __SAMD21G18A__


####
DEFINES_ = \
	-DEF_RGB56FL_MAGWEG \
	-DUSE_I2C_2V8


LINKER_SCRIPT = $(SOURCE_SUB_DIR)/ASF/sam0/utils/linker_scripts/samd21/gcc/samd21j18a_flash.ld

## Source files
SRCS_ = \
	main.c 

## Include files
INCLUDE_DIRS_ = \
	. \
	config 
	

## ASF source files
ASF_SRCS_ = \
	ASF/common2/boards/user_board/init.c \
	ASF/common2/services/delay/sam0/systick_counter.c \
	ASF/common/utils/interrupt/interrupt_sam_nvic.c \
	ASF/sam0/drivers/adc/adc_sam_d_r/adc.c \
	ASF/sam0/drivers/eeprom/emulator/main_array/eeprom.c \
	ASF/sam0/drivers/extint/extint_callback.c \
	ASF/sam0/drivers/extint/extint_sam_d_r/extint.c \
	ASF/sam0/drivers/port/port.c \
	ASF/sam0/drivers/sercom/sercom.c \
	ASF/sam0/drivers/sercom/sercom_interrupt.c \
	ASF/sam0/drivers/sercom/i2c_master.c \
	ASF/sam0/drivers/sercom/spi/spi.c \
	ASF/sam0/drivers/sercom/spi/spi_interrupt.c \
	ASF/sam0/drivers/sercom/usart/usart.c \
	ASF/sam0/drivers/system/interrupt/system_interrupt.c \
	ASF/sam0/drivers/system/pinmux/pinmux.c \
	ASF/sam0/drivers/system/system.c \
	ASF/sam0/drivers/tc/tc_interrupt.c \
	ASF/sam0/drivers/tc/tc_sam_d_r/tc.c \
	ASF/sam0/services/nvm/nvm.c \
	ASF/sam0/utils/syscalls/gcc/syscalls.c \
	ASF/sam0/drivers/system/clock/clock_samd21_r21_da_ha1/clock.c \
	ASF/sam0/drivers/system/clock/clock_samd21_r21_da_ha1/gclk.c \
	ASF/sam0/utils/cmsis/samd21/source/system_samd21.c \
	ASF_MOD/startup_samd21.c
	

#	ASF/sam0/drivers/sercom/i2c/i2c_samd20/i2c_master.c \	
	 
## ASF Include files	
ASF_INCLUDE_DIRS_ = \
	ASF\common\utils \
	ASF\common\boards \
	ASF\common2\boards\user_board \
	ASF\common2\services\delay \
	ASF\sam0\drivers\adc \
	ASF\sam0\drivers\adc\adc_sam_d_r \
	ASF\sam0\drivers\eeprom\emulator\main_array \
	ASF\sam0\drivers\extint \
	ASF\sam0\drivers\port \
	ASF\sam0\drivers\sercom \
	ASF\sam0\drivers\sercom\i2c \
	ASF\sam0\drivers\sercom\spi \
	ASF\sam0\drivers\sercom\usart \
	ASF\sam0\drivers\system \
	ASF\sam0\drivers\system\clock \
	ASF\sam0\drivers\system\clock\clock_samd21_r21_da_ha1 \
	ASF\sam0\drivers\system\interrupt \
	ASF\sam0\drivers\system\interrupt\system_interrupt_samd21 \
	ASF\sam0\drivers\system\pinmux \
	ASF\sam0\drivers\system\power\power_sam_d_r \
	ASF\sam0\drivers\system\reset\reset_sam_d_r \
	ASF\sam0\drivers\tc \
	ASF\sam0\services\nvm \
	ASF\sam0\utils \
	ASF\sam0\utils\cmsis\samd21\include \
	ASF\sam0\utils\cmsis\samd21\source \
	ASF\sam0\utils\header_files \
	ASF\sam0\utils\preprocessor \
	ASF\thirdparty\CMSIS\include 
	
# all source file	
SRCS := $(addprefix $(SOURCE_SUB_DIR)/,$(SRCS_)) $(addprefix $(SOURCE_SUB_DIR)/,$(ASF_SRCS_))
	
# make -I"src/INCLUDEFILEPATH" from each line in the includes collection	
INCLUDE_DIRS := $(addprefix -I"$(SOURCE_SUB_DIR)/,$(addsuffix ", $(INCLUDE_DIRS_))) $(addprefix -I"$(SOURCE_SUB_DIR)/,$(addsuffix ", $(ASF_INCLUDE_DIRS_)))	
	
####	   
CC=arm-none-eabi-gcc
CPP=arm-none-eabi-g++
OBJCOPY=arm-none-eabi-objcopy
OBJSIZE=arm-none-eabi-size

####
OBJDIR = build


ASF_DEFINES = \
	-D$(PROCESSOR_MODEL) \
	-DDEBUG \
	-DBOARD=USER_BOARD \
	-DARM_MATH_CM0PLUS=true \
	-DSPI_CALLBACK_MODE=true \
	-DSYSTICK_MODE \
	-DEXTINT_CALLBACK_MODE=true \
	-DUSART_CALLBACK_MODE=false \
	-DI2C_MASTER_CALLBACK_MODE=false \
	-DTC_ASYNC=true \
	$(OPTIONZ)
	
DEFINES = $(DEFINES_) $(ASF_DEFINES)	

####
CFLAGS = \
	-mthumb \
	-Os \
	-ffunction-sections \
	-mlong-calls \
	-g3 \
	-Wall \
	-mcpu=cortex-m0plus \
	-c \
	-std=gnu99 

####	
CPPFLAGS = \
	-mthumb \
	-Os \
	-ffunction-sections \
	-fno-rtti \
	-fno-exceptions \
	-mlong-calls \
	-g3 \
	-Wall \
	-mcpu=cortex-m0plus \
	-c 

####	
LDFLAGS =\
	-mthumb \
	-Wl,-Map="$(PROJ_NAME).map" \
	--specs=nano.specs \
	-Wl,--start-group \
	-lm  \
	-Wl,--end-group \
	-L"source/ASF/thirdparty/CMSIS/Lib/GCC"  \
	-Wl,--gc-sections \
	-mcpu=cortex-m0plus \
	-Wl,--entry=Reset_Handler \
	-Wl,--cref \
	-mthumb \
	-T$(LINKER_SCRIPT) \
	-Wl,--defsym,STACK_SIZE=0x0400 \
##	-Xlinker --section-start=.text_nietInGebruik=0x8100 \
##	-Xlinker --section-start=.device_information_nietInGebruik=0x008000  

####
CFLAGS += $(INCLUDE_DIRS) $(DEFINES)
CPPFLAGS += $(INCLUDE_DIRS) $(DEFINES)

####
OBJS := $(SRCS:.c=.o)
OBJS := $(OBJS:.cpp=.o)
OBJS := $(OBJS:.s=.o)
OBJS := $(addprefix $(OBJDIR)/,$(OBJS))

all: $(OBJDIR)/$(PROJ_NAME).elf $(OBJDIR)/$(PROJ_NAME).hex $(OBJDIR)/$(PROJ_NAME).bin

$(OBJDIR)/%.elf: $(OBJS)
	@echo Linking ...
	$(VERBOSE)$(CPP) -o $@ $^ $(LDFLAGS)	
##	$(CPP) $(CFLAGS) -o $@ $^ $(LDFLAGS)

%.hex: %.elf
	$(VERBOSE)$(OBJCOPY) -O ihex $^ $@

%.bin: %.elf
	$(VERBOSE)$(OBJCOPY) -O binary $^ $@
	$(VERBOSE)$(OBJSIZE) $^ 
		

$(OBJDIR)/%.o: %.c
	@echo Building file: $<
	$(VERBOSE)mkdir -p $(dir $@)
	$(VERBOSE)$(CC) -c $(CFLAGS) -o $@ $^
	
$(OBJDIR)/%.o: %.cpp
	@echo Building file: $<
	$(VERBOSE)mkdir -p $(dir $@)
	$(VERBOSE)$(CPP) -c $(CPPFLAGS) -o $@ $^

$(OBJDIR)/%.o: %.s
	$(CC) -c $(CFLAGS) -o $@ $^

$(OBJDIR):
	mkdir -p $@

clean:
	rm -f $(OBJDIR)/$(PROJ_NAME).elf
	rm -f $(OBJDIR)/$(PROJ_NAME).hex
	rm -f $(OBJDIR)/$(PROJ_NAME).bin
	rm -f $(OBJDIR)/$(PROJ_NAME).map
	find $(OBJDIR) -type f -name '*.o' -print0 | xargs -0 -r rm


program: $(OBJDIR)/$(PROJ_NAME).elf
	openocd-0.6.1 -f program.cfg


# Dependdencies
$(OBJDIR)/$(PROJ_NAME).elf: $(OBJS) | $(OBJDIR)