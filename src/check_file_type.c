#include "../include/nm.h"

void check_file_type(void *file)
{
    if (check_elf64(file))
        parse_elf_64(file);
}
