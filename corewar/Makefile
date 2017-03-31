##
## Makefile for corewar in /home/sahel/rendu/CPE/CPE_2016_corewar
## 
## Made by Sahel Lucas--Saoudi
## Login   <sahel.lucas-saoudi@epitech.eu>
## 
## Started on  Fri Mar 31 14:22:41 2017 Sahel Lucas--Saoudi
## Last update Fri Mar 31 15:21:56 2017 Sahel Lucas--Saoudi
##

SRC	=	../src/vm/main.c		\
		../src/vm/player.c		\
		../src/vm/register.c		\
		../src/vm/game.c		\
		../src/vm/instructions/live.c	\
		../src/vm/instructions/zjmp.c	\
		../src/asm/my_power_rec.c	\
		../src/asm/reverse_add.c	\
		../src/asm/op.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Wextra -I../include

NAME	=	corewar

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

debug:	CFLAGS += -ggdb3

debug: fclean all

re:	fclean all
