#include "../include/nm.h"

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

    check_file_type(addr);

    munmap(addr, buffer.st_size);
}
