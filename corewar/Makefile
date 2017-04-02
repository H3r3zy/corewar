##
## Makefile for corewar in /home/sahel/rendu/CPE/CPE_2016_corewar
## 
## Made by Sahel Lucas--Saoudi
## Login   <sahel.lucas-saoudi@epitech.eu>
## 
## Started on  Fri Mar 31 14:22:41 2017 Sahel Lucas--Saoudi
## Last update Sun Apr  2 02:58:35 2017 maximilien desnos
##

SRC	=	../src/vm/main.c		\
		../src/vm/player.c		\
		../src/vm/register.c		\
		../src/vm/game.c		\
		../src/vm/instructions/live.c	\
		../src/vm/instructions/zjmp.c	\
		../src/vm/instructions/fork.c	\
		../src/vm/instructions/sub_m.c	\
		../src/vm/instructions/add_m.c	\
		../src/vm/instructions/and_m.c	\
		../src/vm/instructions/or_m.c	\
		../src/vm/instructions/xor_m.c	\
		../src/asm/my_power_rec.c	\
		../src/asm/reverse_add.c	\
		../src/asm/op.c			\
		../graph_vm/src/ini_window.c	\
		../graph_vm/src/create_window.c	\
		../graph_vm/src/my_framebuffer_create.c	\
		../graph_vm/src/update_map.c		\
		../graph_vm/src/my_put_pixel.c		\
		../graph_vm/src/reset_frame.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Wextra -I../include 

NAME	=	corewar

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) -lm -lc_graph_prog

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

debug:	CFLAGS += -ggdb3

debug: fclean all

re:	fclean all
