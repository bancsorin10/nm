#include "../include/nm.h"

int main(int ac, char **av) {
    if (ac < 2) {
        ft_putendl("usage: nm {elf file}");
        return (0);
    }
    // probably check for extra options here

    open_elf(av[ac - 1]); // suppose file name is always in last argument

    return (0);
}
