#include "../include/nm.h"

int check_elf64(void *file)
{
    char *magic_number;

    magic_number = (char *)malloc(5);
    /* hard coding the magic number because i don't seem to be able to write */
    /* the string as a constant \x7fELF */
    
    magic_number[0] = '\x7f';
    magic_number[1] = 'E';
    magic_number[2] = 'L';
    magic_number[3] = 'F';
    magic_number[4] = '\0';

    if (ft_strncmp((char *)file, magic_number, 4))
        return (0);

    if (((char *)file)[4] == ELFCLASS64)
        return (1);
    
    return (0);
}
