hello: hello.o
	ld -melf_i386 -s hello.o -o hello

hello.o: hello.asm
	nasm -f elf hello.asm -o hello.o

clean:
	rm -f *.o
