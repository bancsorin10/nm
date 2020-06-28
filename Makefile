SRCDIR = src
OBJDIR = obj
_SRC = nm.c open_file.c parse_elf_64.c
SRC = $(patsubst %,$(SRCDIR)/%,$(_SRC))
_OBJ = nm.o open_file.o parse_elf_64.o
OBJ = $(patsubst %,$(OBJDIR)/%,$(_OBJ))
CC = clang
FLAGS = -g -Wall -Wextra -Werror
LIBS = include/libft/libft.a
DEPS = include/nm.h

$(OBJDIR)/%.o: $(SRCDIR)/%.c 
	$(CC) -c $(FLAGS) $< -o $@

nm_make: $(OBJ) # libft but commented so i dont have to build it everytime
	$(CC) $(FLAGS) $(OBJ) -o nm $(LIBS)

libft:
	cd include/libft/ && make all

clean:
	rm -f $(OBJDIR)/*.o
	cd include/libft/ && make clean

fclean:
	cd include/libft/ && make fclean

re: fclean nm_make
