#include "../include/nm.h"

static void print_syms(Elf64_Sym *symtab, int symbols);

void parse_elf_64(void *file)
{
    Elf64_Ehdr *hdr;
    Elf64_Shdr *shdr;
    Elf64_Sym *symtab;
    int symbols;
    int sections;
    int i;

    symtab = NULL;

    /* well after verifying the data type we can just cast it to obtain all */
    /* the information needed to our program */
    hdr = (Elf64_Ehdr *)file;

    /* take the section header offset from the file header and search for */
    /* the section with the symbol table */
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

    if (symtab == NULL)
    {
        ft_putendl("there are no symbols the file might be stripped");
        return ;
    }

    /* ------------------------------------------------------------------- */
    /* there might be multiple string tables and so the formula doesn't hold */
    int strtab_offset= hdr->e_shoff + hdr->e_shstrndx * hdr->e_shentsize;
    /* this is the address that holds the string table */
    /* the enttries are not fixed size */
    Elf64_Shdr *strtab = file + strtab_offset;
    if (strtab->sh_type == SHT_STRTAB)
        ft_putendl("string table indeed");
    int strtab_size = strtab->sh_size;
    int ii = 0;
    char *string_table = (char *)file + strtab_offset;
    for (i = 0; i < strtab_size; i++)
    {
        if (string_table[i] == '\0')
        {
            ft_putendl("");
            ft_putnbr(ii);
            ft_putstr(" ----- ");
            ii++;
        }
        else
            ft_putchar(string_table[i]);
    }
    /* ------------------------------------------------------------------- */

    print_syms(symtab, symbols);
}

static void print_syms(Elf64_Sym *symtab, int symbols)
{
    int i;

    for (i = 0; i < symbols; i++)
    {
        /* ft_putendl(symtab[i].st_name); */
    }
    ft_putnbr(symtab[0].st_name);
    ft_putendl("");
    ft_putnbr(symbols);
}
