# Day 2
## Finished bootloader
I successfully created a bootloader! (with Limine, so technically I didn't create
anything)

The approach is that the Makefile at the root of the repo would first build the 
kernel using the Makefile inside `kernel/`, then download the Limine binary,
extract, and build it inside `limine/build/`. Then, it would create an ISO
using the files built in `build/iso_root/` to build `larpos.iso`.