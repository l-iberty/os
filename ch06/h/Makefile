.PHONY: buildimg clean cleanbin

CFLAGS = -I include/ -c -fno-stack-protector -m32 -w
ASMFLAGSK = -I include/ -f elf
ASMFLAGSB = -I boot/include/

######################################################################################

bin/kernel.bin: kernel/kernel.o kernel/start.o kernel/i8259.o kernel/global.o \
		kernel/protect.o lib/klib.o lib/kliba.o lib/string.o kernel/main.o \
		kernel/clock.o
	ld -melf_i386 -s -Ttext 0x30400 $^ -o $@

kernel/kernel.o: kernel/kernel.asm
	nasm $(ASMFLAGSK) $< -o $@

kernel/start.o: kernel/start.c
	gcc $(CFLAGS) $< -o $@

kernel/i8259.o: kernel/i8259.c
	gcc $(CFLAGS) $< -o $@

kernel/global.o: kernel/global.c
	gcc $(CFLAGS) $< -o $@

kernel/protect.o: kernel/protect.c
	gcc $(CFLAGS) $< -o $@

lib/klib.o: lib/klib.c
	gcc $(CFLAGS) $< -o $@

lib/kliba.o: lib/kliba.asm
	nasm $(ASMFLAGSK) $< -o $@

lib/string.o: lib/string.asm
	nasm $(ASMFLAGSK) $< -o $@

kernel/main.o: kernel/main.c
	gcc $(CFLAGS) $< -o $@

kernel/clock.o: kernel/clock.c
	gcc $(CFLAGS) $< -o $@

######################################################################################

buildimg:
	nasm $(ASMFLAGSB) boot/boot.asm -o bin/boot.bin
	nasm $(ASMFLAGSB) boot/loader.asm -o bin/loader.bin
	dd if=bin/boot.bin of=a.img bs=512 count=1 conv=notrunc
	sudo mount -o loop a.img /mnt/floppy
	sudo cp bin/loader.bin /mnt/floppy/
	sudo cp bin/kernel.bin /mnt/floppy/
	sudo umount /mnt/floppy

######################################################################################

clean:
	find . -name "*.o" | xargs rm

cleanbin:
	find . -name "*.bin" | xargs rm
