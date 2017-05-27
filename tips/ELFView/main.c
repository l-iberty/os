//#define _DEBUG_

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "elf.h"

#define ELF_HDRLEN 0x0034
#define BUF_SIZE 0x1000


#ifdef _DEBUG_
char *testfile = "/home/l-iberty/os/ch05/e/kernel.bin";
#endif

void dispEHdr(Elf32_Ehdr *elf_ehdr);
void dispPHdr(Elf32_Phdr *elf_phdr, int phnum);
void printBytes(void *buf, int len);


int main(int argc, char **argv) {
#ifndef _DEBUG_
    if (argc != 2) {
        printf("usage: %s <elf_file>\n", argv[0]);
        return 1;
    }
#endif

    Elf32_Ehdr *elf_ehdr;
    Elf32_Phdr *elf_phdr;
    char buf[BUF_SIZE];
    int fd;
    ssize_t nr;

#ifndef _DEBUG_
    fd = open(argv[1], O_RDONLY);
#else
    fd = open(testfile, O_RDONLY);
#endif
    if (fd == -1) {
        perror("open");
        return 1;
    }

    nr = read(fd, buf, BUF_SIZE);
    if (nr == -1) {
        perror("read");
        return 1;
    }

    printf("\n-------- ELF Header --------\n");
    elf_ehdr = (Elf32_Ehdr *) buf;
    dispEHdr(elf_ehdr);

    printf("\n-------- Program Header --------\n");
    elf_phdr = (Elf32_Phdr *) (buf + elf_ehdr->e_phoff);
    dispPHdr(elf_phdr, elf_ehdr->e_phnum);

    return 0;
}

void dispEHdr(Elf32_Ehdr *elf_ehdr) {
    printBytes(elf_ehdr, sizeof(Elf32_Ehdr));

    printf("type: 0x%.4x\n", elf_ehdr->e_type);
    printf("machine: 0x%.4x\n", elf_ehdr->e_machine);
    printf("version: 0x%.8x\n", elf_ehdr->e_version);
    printf("entry: 0x%.8x\n", elf_ehdr->e_entry);
    printf("phoff: 0x%.8x\n", elf_ehdr->e_phoff);
    printf("shoff: 0x%.8x\n", elf_ehdr->e_shoff);
    printf("flags： 0x%.8x\n", elf_ehdr->e_flags);
    printf("ehsize: 0x%.4x\n", elf_ehdr->e_ehsize);
    printf("phtsize: 0x%.4x\n", elf_ehdr->e_phentsize);
    printf("phnum: 0x%.4x\n", elf_ehdr->e_phnum);
    printf("shtsize: 0x%.4x\n", elf_ehdr->e_shentsize);
    printf("shnum: 0x%.4x\n", elf_ehdr->e_shnum);
    printf("shstrndx: 0x%.4x\n", elf_ehdr->e_shstrndx);
}

void dispPHdr(Elf32_Phdr *elf_phdr, int phnum) {
    for (int i = 0; i < phnum; i++, elf_phdr++) {
        printf("\n++++ %d ++++\n", i + 1);
        printBytes(elf_phdr, sizeof(Elf32_Phdr));

        printf("type: 0x%.8x\n", elf_phdr->p_type);
        printf("offset: 0x%.8x\n", elf_phdr->p_offset);
        printf("vaddr: 0x%.8x\n", elf_phdr->p_vaddr);
        printf("paddr: 0x%.8x\n", elf_phdr->p_paddr);
        printf("filesz: 0x%.8x\n", elf_phdr->p_filesz);
        printf("memsz: 0x%.8x\n", elf_phdr->p_memsz);
        printf("flags: 0x%.8x\n", elf_phdr->p_flags);
        printf("align: 0x%.8x\n", elf_phdr->p_algin);
    }
}

void printBytes(void *buf, int len) {
    printf("=================================================\n");
    unsigned char *p = (unsigned char *) buf;
    for (int i = 0; i < len; i++) {
        printf("%.2x ", p[i]);
        if ((i + 1) % 16 == 0) printf("\n");
    }
    printf("\n=================================================\n");
}
