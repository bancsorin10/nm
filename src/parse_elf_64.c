#include "../include/nm.h"

void parse_elf_64(void *file)
{
    Elf64_Ehdr *hdr;
    Elf64_Shdr *shdr;
    Elf64_Sym *symtab;
    char *strtab;
    int symbols;
    int sections;
    int i;

    symtab = NULL;

    /* after verifying the data type we can just cast it to obtain all */
    /* the information needed to our program */
    hdr = (Elf64_Ehdr *)file;

    /* obtain the section header that contains all the sections */
    shdr = (Elf64_Shdr *)((char *)file + hdr->e_shoff);
    sections = hdr->e_shnum; /* the number of sections */
    
    for (i = 0; i < sections; i++)
    {
        if (shdr[i].sh_type == SHT_SYMTAB)
        {
            symtab = (Elf64_Sym *)((char *)file + shdr[i].sh_offset);
            symbols = shdr[i].sh_size / shdr[i].sh_entsize;
            break ;
        }
    }
    
    /* the section header provides in sh_link the index to the */
    /* string table with the name of the symbols used */
    strtab = (char *)file + shdr[shdr[i].sh_link].sh_offset;

    if (symtab == NULL)
    {
        ft_putendl("there are no symbols the file might be stripped");
        return ;
    }

    print_syms_elf64(symtab, symbols, strtab);
}
