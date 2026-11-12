# larp-os
An operating system built to larp and flex.

**This OS does not contain any LLM-generated code. Some files though, are based off of templates online.**

## Requirements
* Make
* GCC
* Qemu to boot
* System must be x86-64

To build, run at project root
```
make
```

To run using qemu, run 
```
make run_bios
```

If your qemu executable goes under another name, change
```diff
.PHONY: run_bios
run_bios: iso
-  	qemu-system-x86_64 \
+	<your-qemu-executable> \
    	-M q35 \
		-m 256M \
		-cdrom $(ISO) \
		-boot order=d \
		-no-reboot \
		-no-shutdown
```