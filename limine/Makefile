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
# This is the Limine Makefile. Downloads Limine dependencies

LIMINE_VERSION 		:= 12.9.6
LIMINE_DIR 			:= .
BUILD_DIR			:= build
LIMINE_ARCHIVE		:= limine-binary.tar.gz
LIMINE_URL 			:= \
	https://github.com/limine-bootloader/limine/releases/download/v$(LIMINE_VERSION)/$(LIMINE_ARCHIVE)

.PHONY: limine
limine:
	mkdir -p $(BUILD_DIR)
	curl -fL $(LIMINE_URL) -o $(BUILD_DIR)/$(LIMINE_ARCHIVE)
	tar -xzf $(BUILD_DIR)/$(LIMINE_ARCHIVE) -C $(BUILD_DIR)
	make -C $(BUILD_DIR)/limine-binary