CC = cc
FLAGS = -Wall -wetra -Werror
SRC = main.c
OBJ = (SRC:.c=.o)


all = $(EXE)

$(EXE) : $(OBJ)
	cc 