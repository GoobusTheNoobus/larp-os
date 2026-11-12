# ====================================================
# 		 _                      _____ _____ 
# 		| |                    |  _  /  ___|
# 		| |     __ _ _ __ _ __ | | | \ `--. 
# 		| |    / _` | '__| '_ \| | | |`--. \ 
# 		| |___| (_| | |  | |_) \ \_/ /\__/ /
# 		\_____/\__,_|_|  | .__/ \___/\____/ 
#                 | |                
#                 |_|                
#
# ====================================================
# 
# LarpOS is licensed under the MIT license
# Copyright (c) 2026 David H.
#
# ====================================================
#
# This is the kernel Makefile. Builds the kernel into an ELF 
# executable.

CC := gcc
LD := ld

BUILD_DIR := build
SOURCE_DIR := .

TARGET := kernel.elf

CFLAGS := \
	-std=c2x \
	-ffreestanding \
	-fno-stack-protector \
	-fno-pic \
	-m64 \
	-mno-red-zone \
	-mcmodel=kernel \
	-Wall \
	-Wextra \
	-MMD -MP

LDFLAGS := \
	-nostdlib \
	-static \
	-z max-page-size=0x1000 \
	-T linker.ld

SOURCES := $(wildcard $(SOURCE_DIR)/*.c)
OBJECTS := $(patsubst $(SOURCE_DIR)/%.c,$(BUILD_DIR)/%.o,$(SOURCES))

DEPS := $(OBJECTS:.o=.d)

-include $(DEPS)

.PHONY: all clean

all: $(TARGET)

# Compile sources
$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.c
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Link objects
$(TARGET): $(OBJECTS) linker.ld
	$(LD) $(LDFLAGS) $(OBJECTS) -o $@

clean:
	rm -rf $(BUILD_DIR) $(TARGET)