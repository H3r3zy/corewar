##
## Makefile for corewar in /home/sahel/rendu/CPE/CPE_2016_corewar
## 
## Made by Sahel Lucas--Saoudi
## Login   <sahel.lucas-saoudi@epitech.eu>
## 
## Started on  Fri Mar 31 14:22:41 2017 Sahel Lucas--Saoudi
## Last update Sun Apr  2 14:33:19 2017 Sahel Lucas--Saoudi
##

SRC	=	../src/vm/main.c			\
		../src/vm/player.c			\
		../src/vm/register.c			\
		../src/vm/game.c			\
		../src/vm/instructions/live.c		\
		../src/vm/instructions/zjmp.c		\
		../src/vm/instructions/fork.c		\
		../src/vm/instructions/sub_m.c		\
		../src/vm/instructions/st_m.c		\
		../src/vm/instructions/add_m.c		\
		../src/vm/instructions/and_m.c		\
		../src/vm/instructions/or_m.c		\
		../src/vm/instructions/xor_m.c		\
		../src/vm/instructions/ld_m.c		\
		../src/asm/my_power_rec.c		\
		../src/asm/reverse_add.c		\
		../src/asm/op.c				\
		../utils/my_putstr.c			\
		../utils/my_strdup.c			\
		../utils/my_strcpy.c			\
		../utils/my_putnbr.c			\
		../utils/my_putchar.c			\
		../utils/my_strncmp.c			\
		../graph_vm/src/ini_window.c		\
		../graph_vm/src/check_env.c		\
		../graph_vm/src/match.c			\
		../graph_vm/src/create_window.c		\
		../graph_vm/src/my_square_root.c	\
		../graph_vm/src/my_framebuffer_create.c	\
		../graph_vm/src/update_map.c		\
		../graph_vm/src/my_put_pixel.c		\
		../graph_vm/src/reset_frame.c		\
		../src/vm/bit.c

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
