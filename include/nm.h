#ifndef NM_H
# define NM_H

# include <sys/stat.h>
# include <sys/mman.h>
# include <sys/types.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <stdint.h>
# include <elf.h>

void open_file(char *file_name);
void parse_elf_64(void *file);

#endif
