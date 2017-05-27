/**
 * 定义ELF文件各部分数据结构
 */
#ifndef ELF_ELF_HEADER_H
#define ELF_ELF_HEADER_H

#define EI_NIDEND       16

typedef unsigned int Elf32_Addr;
typedef unsigned short Elf32_Half;
typedef unsigned int Elf32_Off;
typedef unsigned int Elf32_Sword;
typedef unsigned int Elf32_Word;

/**
 * ELF文件由4部分组成, 分别是 ELF Header, Program Header Table, Sections,
 * 和 Section Header Table.
 */

// ELF Header
typedef struct {
    unsigned char       e_ident[EI_NIDEND]; // 标识以及其他信息
    Elf32_Half          e_type;             // 文件类型 (0x002表示一个可执行文件)
    Elf32_Half          e_machine;          // 运行该程序需要的体系结构 (0x003表明是Intel 80386)
    Elf32_Word          e_version;          // 文件版本号
    Elf32_Addr          e_entry;            // 程序入口地址
    Elf32_Off           e_phoff;            // Program Header Table 的文件偏移量
    Elf32_Off           e_shoff;            // Section Header Table 的文件偏移量
    Elf32_Word          e_flags;            // 对IA32而言, 此项为0
    Elf32_Half          e_ehsize;           // ELF Header 的大小 (0x0034)
    Elf32_Half          e_phentsize;        // Program Header Table 中每个条目 (一个 Program Header) 的大小
    Elf32_Half          e_phnum;            // Program Header Table 中的条目个数
    Elf32_Half          e_shentsize;        // Section Header Table 中每个条目 (一个 Section Header) 的大小
    Elf32_Half          e_shnum;            // Section Header Table 中的条目个数
    Elf32_Half          e_shstrndx;         // 包含节名称的字符串表是第几个字节(从0开始数), 即第几个节包含节名称
} Elf32_Ehdr;

// Program Header
// 描述系统准备程序运行所需的一个段(segment)的信息
// 注意到段(segment)和节(section)的区别：一个段(segment)包含若干个节(sections)
typedef struct {
    Elf32_Word          p_type;             // 当前 Program Header 所在描述符的段的类型
    Elf32_Off           p_offset;           // 段的第一字节的文件偏移量
    Elf32_Addr          p_vaddr;            // 段的第一字节在内存中的虚拟地址
    Elf32_Addr          p_paddr;            // 在物理地址定位相关的系统中, 此项是物理地址保留
    Elf32_Word          p_filesz;           // 段在文件中的长度
    Elf32_Word          p_memsz;            // 段在内存中的长度
    Elf32_Word          p_flags;            // 与段相关的标志
    Elf32_Word          p_algin;            // 段在文件及内存中按照改值进行对齐
} Elf32_Phdr;

#endif //ELF_ELF_HEADER_H
