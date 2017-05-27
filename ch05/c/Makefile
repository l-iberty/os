kernel.bin: kernel.o
	ld -melf_i386 -s kernel.o -o kernel.bin

kernel.o: kernel.asm
	nasm -f elf kernel.asm -o kernel.o

clean:
	rm -f *.o
