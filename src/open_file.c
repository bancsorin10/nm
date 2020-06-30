#include "../include/nm.h"

static void check_file_type(void *file);

void open_file(char *s)
{
    struct stat buffer;
    int         status;
    int fd;
    void *addr = NULL;

    if ((fd  = open(s, O_RDONLY)) < 1)
    {
        ft_putendl("I don't have acces to file");
        return ;
    }

    /* check file stats */
    status = fstat(fd, &buffer);
    if (status == -1)
    {
        ft_putendl("fstat failed");
        return ;
    }

    addr = mmap(NULL, buffer.st_size, PROT_READ|PROT_EXEC, MAP_PRIVATE, fd, 0);
    close(fd);

    if (addr == MAP_FAILED)
    {
        ft_putendl("couldn't map region");
        return ;
    }

    check_file_type(addr); /* check if the file is an elf file and parse further */

    munmap(addr, buffer.st_size);
}

static void check_file_type(void *file)
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
    {
        /* if the file is not elf just return */
        return ;
    }

    /* planning in introducing also the elf 32 and maybe some other filetypes */

    if (((char *)file)[4] == ELFCLASS64)
        parse_elf_64(file);
}
