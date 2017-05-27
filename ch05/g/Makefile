.PHONY: buildimg clean

CFLAGS = -c -fno-stack-protector -m32		
ASMFLAGS = -f elf

######################################################################################

kernel.bin: kernel.o start.o i8259.o global.o protect.o klib.o kliba.o string.o
	ld -melf_i386 -s -Ttext 0x30400 $^ -o $@

kernel.o: kernel.asm
	nasm $(ASMFLAGS) kernel.asm -o kernel.o

start.o: start.c
	gcc $(CFLAGS) start.c -o start.o

i8259.o: i8259.c
	gcc $(CFLAGS) i8259.c -o i8259.o

global.o: global.c
	gcc $(CFLAGS) global.c -o global.o

protect.o: protect.c
	gcc $(CFLAGS) protect.c -o protect.o

klib.o: klib.c
	gcc $(CFLAGS) klib.c -o klib.o

kliba.o: kliba.asm
	nasm $(ASMFLAGS) kliba.asm -o kliba.o

string.o: string.asm
	nasm $(ASMFLAGS) string.asm -o string.o

######################################################################################

buildimg:
	nasm boot.asm -o boot.bin
	nasm loader.asm -o loader.bin
	dd if=boot.bin of=a.img bs=512 count=1 conv=notrunc
	sudo mount -o loop a.img /mnt/floppy
	sudo cp loader.bin /mnt/floppy/
	sudo cp kernel.bin /mnt/floppy/
	sudo umount /mnt/floppy

######################################################################################

clean:
	rm -f *.o
