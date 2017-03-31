##
## Makefile for  in /home/januar_m/delivery/CPE/CPE_2016_corewar/graph_vm
## 
## Made by Martin Januario
## Login   <martin.januario@epitech.eu>
## 
## Started on  Thu Mar 30 11:17:40 2017 Martin Januario
## Last update Thu Mar 30 20:58:04 2017 Martin Januario
##

SRC	=	src/create_window.c		\
		src/creator_loop.c		\
		src/ini_window.c		\
		src/main.c			\
		src/my_framebuffer_create.c	\
		src/color.c			\
		src/update_map.c		\
		src/my_put_pixel.c		\
		src/create_map.c		\
		src/music.c			\
		src/reset_frame.c

GNL	=	gnl/ini_gnl.c			\
		gnl/get_next_line.c

OBJ	=	$(SRC:.c=.o)			\
		$(GNL:.c=.o)

CFLAGS	=	-g -Wall -Wextra -I include/

NAME	=	vm_graph

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) -lc_graph_prog

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
