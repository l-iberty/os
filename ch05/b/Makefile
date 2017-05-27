foobar: foo.o bar.o
	ld -melf_i386 -s foo.o bar.o -o foobar

foo.o: foo.asm
	nasm -f elf foo.asm -o foo.o

bar.o: bar.c
	gcc -c bar.c -o bar.o -m32

clean:
	rm -f *.o
