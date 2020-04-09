#include "../include/nm.h"

int main(int ac, char **av, char **env) {
    
    printf("%s %s\n", av[ac-1], env[0]);

    return (0);
}
