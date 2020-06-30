#include "../include/nm.h"

static void print_value(int value);
static void print_type(int type);
static void print_name(char *name);

void print_syms_elf64(Elf64_Sym *symtab, int symbols, char *strtab)
{
    int i;
    char *name;
    /* TODO: something to print the value of */
    /* the symbol in 64 bit aka 16 hexa numbers */

    for (i = 0; i < symbols; i++)
    {
        name = strtab + symtab[i].st_name;

        /* some symbols don't have a name :( */
        if (ft_strlen(name))
        {
            print_value(symtab[i].st_value);
            print_type(symtab[i].st_info);
            print_name(name);
        }
    }
}

static void print_value(int value)
{
    char number[17] = "0000000000000000\0";
    char hexa[17] = "0123456789abcdef\0";
    int i;

    if (value == 0)
    {
        ft_putstr("                 ");
        return ;
    }

    i = 15;
    while (value > 0 && i >= 0)
    {
        number[i] = hexa[value % 16];
        value /= 16;
        --i;
    }

    ft_putstr(number);
    ft_putstr(" ");
}

static void print_type(int type)
{
    if (type == STT_NOTYPE)
        ft_putchar('U'); /* undefined symbol */
    else if (type == STT_OBJECT)
        ft_putchar('O'); /* object symbol */
    else if (type == STT_FUNC)
        ft_putchar('f'); /* symbol associated to a functio */
    else if (type == STT_SECTION)
        ft_putchar('S'); /* symbol associated to a section */
    else if (type == STT_FILE)
        ft_putchar('F'); /* symbol associated to a file */
    else if (type >= STT_LOPROC && type <= STT_HIPROC)
        ft_putchar('p'); /* processor specific semantics */
    else if (type == STB_LOCAL)
        ft_putchar('l'); /* local variable of the object file */
    else if (type == STB_GLOBAL)
        ft_putchar('G'); /* global symbol */
    else if (type == STB_WEAK)
        ft_putchar('g'); /* weak symbol(it resembels a global one) but have
                            lower definiton precedence) */
    else if (type >= STB_LOPROC && type <= STB_HIPROC)
        ft_putchar('p'); /* processor specific semantics */
    else
        ft_putchar('u'); /* undefined symbol? */

    ft_putstr(" ");
}

static void print_name(char *name)
{
    ft_putendl(name);
}
