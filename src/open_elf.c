#include "../include/nm.h"

void open_elf(char *s) {
    int fd;

    if ((fd  = open(s, O_RDONLY)) < 1) {
        ft_putendl("I don't have acces to file");
        return ;
    }

    // check file stats first :)
    struct stat buffer;
    int         status;
    status = fstat(fd, &buffer);
    if (status == -1) {
        ft_putendl("fstat failed dude");
        return ;
    }

    void *addr = NULL;
    // PROT_NONE or PROT_READ
    // flags like MAP_SHARED check further info
    // buffer st size for file size and 0 for the offset 
    addr = mmap(NULL, buffer.st_size, PROT_READ, MAP_SHARED, fd, 0);
    if (addr == MAP_FAILED) {
        ft_putendl("dude map failed what are ya doing?");
        return ;
    }
    ft_putnbr(buffer.st_size);
    ft_putendl("below you have a map :)");
    int ls;
    ls = write(STDOUT_FILENO, addr, buffer.st_size); // STDOUT_FILENO is just 1 dude

    if (ls != buffer.st_size) {
        if (ls == -1)
            ft_putendl("guess i just cant write");
        else
            ft_putendl("idk dude i dont like to print stuff");
    }
}
