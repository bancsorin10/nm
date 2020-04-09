SRCDIR = src
OBJDIR = obj
_SRC = nm.c open_elf.c
SRC = $(patsubst %,$(SRCDIR)/%,$(_SRC))
_OBJ = nm.o open_elf.o
OBJ = $(patsubst %,$(OBJDIR)/%,$(_OBJ))
CC = gcc
FLAGS = -Wall -Wextra -Werror
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
