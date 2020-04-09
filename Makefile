SRCDIR = src
OBJDIR = obj
SRC = $(SRCDIR)/nm.c
_OBJ = nm.o
OBJ = $(patsubst %,$(OBJDIR)/%,$(_OBJ))
CC = gcc
FLAGS = -Wall -Wextra -Werror
LIBS = include/libft/libft.a
DEPS = include/nm.h

$(OBJDIR)/%.o: $(SRCDIR)/%.c 
	$(CC) -c $(SRC) -o $@ $(FLAGS)

nm_make: $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o nm $(LIBS)

libft:
	cd include/libft/ && make all

clean:
	rm -f $(OBJDIR)/*.o
	cd include/libft/ && make clean

fclean:
	cd include/libft/ && make fclean



