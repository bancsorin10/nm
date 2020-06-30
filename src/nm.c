#include "../include/nm.h"

int main(int ac, char **av) {
    if (ac < 2) {
        ft_putendl("usage: nm {elf file}");
        return (0);
    }

    /* file name as argument */
    open_file(av[ac - 1]);

    return (0);
}
