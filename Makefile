# Target name of final executable
TARGET = bare_metal

# DEBUG
DEBUG = 1

# Build Directory
BUILD_DIR = build
SRC_DIR  = .
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRC_FILES))
$(info SRC_FILES is $(SRC_FILES))
$(info OBJ_FILES is $(OBJ_FILES))

# Tools to use
CROSS_COMPILE = arm-none-eabi-
CC = $(CROSS_COMPILE)gcc
LD = $(CROSS_COMPILE)gcc
CP = $(CROSS_COMPILE)objcopy


# GCC FLAGS
CPU = -mcpu=cortex-m4
FPU = -mfpu=fpv4-sp-d16
FLOAT-ABI = -mfloat-abi=hard
MCU = $(CPU) -mthumb $(FPU) $(FLOAT-ABI)
GCC_STANDARD = -std=c90
DEPENDECY = -MMD

# Additional DEBUG Flag
OPT = -O3
DEBUG_FLAG = -Wall -Wno-unused -Wextra -pedantic

# -H print the recursive searh path
# -M prints which headerfiles was included
ifeq ($(DEBUG), 1)
OPT = -O0
DEBUG_FLAG += -H -g3 -gdwarf-2
endif

# Compiler Flags
#CFLAGS += -ffreestanding
CFLAGS += $(MCU) $(DEBUG_FLAG) $(OPT) $(GCC_STANDARD) $(DEPENDECY)\
					-ffreestanding -ffunction-sections -nostdlib \
					-fdata-sections


# Linker Script
LSCRIPT=mem.ld

# Libs for Linker
# gonna use -nostdlib and pick and choose desired libs
# -lc has malloc but need to implement _sbrk
LIBS = -lc
# Linker Flags
LDFLAGS = -T$(LSCRIPT)  $(MCU) -nostdlib $(LIBS) -Wl,-Map=map.map -Wl,--cref -Wl,--gc-sections

# Objs
#OBJ = startup.o

all: $(TARGET).bin

$(TARGET).bin: $(TARGET).elf | $(BUILD_DIR)
	$(CP) -O binary $< $@

$(TARGET).elf: $(OBJ_FILES) | $(BUILD_DIR)
	$(LD)  $(LDFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS)  -c -o $@ $<

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)
#startup.o: startup.c
	#$(CC) $(CFLAGS) -c startup.c

#vector_table.o: vector_table.c
	#$(CC) $(CFLAGS) -c vector_table.c

#dynamic_memory.o: dynamic_memory.c
#	$(CC) $(CFLAGS) -c dynamic_memory.c

#main.o: main.c
#	$(CC) $(CFLAGS) -c main.c


.PHONY: clean nuke
-include $(OBJ_FILES:.o=.d)

make nuke:
	-rm -rf *.o *.d *.elf *.bin *.hex *.map $(BUILD_DIR)
