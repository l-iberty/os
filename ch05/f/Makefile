kernel.bin: kernel.o string.o start.o kliba.o
	ld -melf_i386 -s -Ttext 0x30400 kernel.o string.o start.o kliba.o -o kernel.bin

kernel.o: kernel.asm
	nasm -f elf kernel.asm -o kernel.o

string.o: string.asm
	nasm -f elf string.asm -o string.o

start.o: start.c
	gcc -c start.c -o start.o -m32

kliba.o: kliba.asm
	nasm -f elf kliba.asm -o kliba.o

clean:
	rm -f *.o 
