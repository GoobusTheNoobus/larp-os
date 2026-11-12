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
# This is the root Makefile. It is reponsible for building the bootable
# ISO, not building the kernel. 

# Build directory
BUILD_DIR 		:= build

# Emulated root
ISO_ROOT 		:= $(BUILD_DIR)/iso_root

KERNEL := kernel/kernel.elf
ISO := $(BUILD_DIR)/larpos.iso

LIMINE_DIR := limine/build/limine-binary

.PHONY: all
all: iso

# Build the kernel using kernel/Makefile

.PHONY: kernel
kernel:
	$(MAKE) -C kernel

# Prepare and create the ISO

.PHONY: iso
iso: kernel limine
	rm -rf $(ISO_ROOT)
	mkdir -p $(ISO_ROOT)/boot/limine
	mkdir -p $(ISO_ROOT)/EFI/BOOT

	cp $(KERNEL) $(ISO_ROOT)/boot/
	cp $(LIMINE_DIR)/limine-bios.sys $(ISO_ROOT)/boot/limine/
	cp $(LIMINE_DIR)/limine-bios-cd.bin $(ISO_ROOT)/boot/limine/
	cp $(LIMINE_DIR)/limine-uefi-cd.bin $(ISO_ROOT)/boot/limine/
	cp $(LIMINE_DIR)/BOOTX64.EFI $(ISO_ROOT)/EFI/BOOT/
	cp limine.conf $(ISO_ROOT)/boot/limine/

# Long ass command that I understand about 3% of
	xorriso -as mkisofs \
		-R -r -J \
		-b boot/limine/limine-bios-cd.bin \
		-no-emul-boot \
		-boot-load-size 4 \
		-boot-info-table \
		-hfsplus \
		-apm-block-size 2048 \
		--efi-boot boot/limine/limine-uefi-cd.bin \
		--efi-boot-part \
		--efi-boot-image \
		--protective-msdos-label \
		$(ISO_ROOT) \
		-o $(ISO)

	$(LIMINE_DIR)/limine bios-install $(ISO)

# Launch QEMU

.PHONY: run_bios
run_bios: iso
	qemu-system-x86_64 \
		-M q35 \
		-m 256M \
		-cdrom $(ISO) \
		-boot order=d \
		-no-reboot \
		-no-shutdown


# Download dependencies
.PHONY: limine
limine:
	$(MAKE) -C limine

# Remove build outputs

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)
	$(MAKE) -C kernel clean


# Remove build outputs and downloaded dependencies
.PHONY: nuke
nuke: clean
	rm -rf $(LIMINE_DIR)