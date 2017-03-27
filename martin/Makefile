##
## Makefile for  in /home/januar_m/delivery/CPE/CPE_2016_corewar/martin/error_handling
## 
## Made by Martin Januario
## Login   <martin.januario@epitech.eu>
## 
## Started on  Fri Mar 24 19:22:19 2017 
## Last update Mon Mar 27 18:02:53 2017 Martin Van Elslande
##

SRC	=	src/main.c			\
		src/check_line.c		\
		src/check_command.c		\
		src/check_type.c		\
		src/check_label.c		\
		src/type_all.c			\
		src/add_label.c			\
		src/op.c

BASICS	=	utils/my_strlen.c		\
		utils/my_putstr.c		\
		utils/match.c			\
		utils/my_strncpy.c		\
		utils/disp_tab.c		\
		utils/parse_.c			\
		utils/found_char.c		\
		utils/my_getnbr.c		\
		utils/my_strcpy.c		\
		utils/my_tablen.c		\
		utils/my_str_is_num.c		\
		utils/my_strdup.c		\
		utils/file.c			\
		utils/my_str_to_wordtab.c	\
		utils/free_tab.c		\
		utils/my_free.c			\
		utils/my_str_is_alpha.c		\
		utils/my_strncmp.c		\
		utils/my_putnbr.c		\
		utils/my_putchar.c		\
		utils/my_strcmp.c

GNL	=	gnl/get_next_line.c		\
		gnl/ini_gnl.c

OBJ	=	$(BASICS:.c=.o)			\
		$(GNL:.c=.o)			\
		$(SRC:.c=.o)

CFLAGS	=	-Wall -Wextra -I include/

NAME	=	pars_me

all:		$(NAME)

debug:		CFLAGS += -ggdb3

debug:		fclean all

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all

.PHONY:		all debug clean fclean re
