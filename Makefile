##
## Makefile for corewar in /home/sahel/rendu/CPE/CPE_2016_corewar
## 
## Made by Sahel Lucas--Saoudi
## Login   <sahel.lucas-saoudi@epitech.eu>
## 
## Started on  Wed Mar 29 13:32:44 2017 Sahel Lucas--Saoudi
## Last update Sun Apr  2 08:21:37 2017 Martin Januario
##

SRC	=	src/asm/main.c			\
		src/asm/check_line.c		\
		src/asm/check_command.c		\
		src/asm/check_type.c		\
		src/asm/check_label_error.c	\
		src/asm/type_all.c		\
		src/asm/add_label.c		\
		src/asm/op.c			\
		src/asm/get_next_line.c		\
		src/asm/check_label.c		\
		src/asm/count_size_header_str.c	\
		src/asm/help.c			\
		src/asm/my_nbr_to_str.c		\
		src/asm/my_power_rec.c		\
		src/asm/my_str_to_wordtab.c	\
		src/asm/recup_args.c		\
		src/asm/recup_file.c		\
		src/asm/recup_header.c		\
		src/asm/recup_lines.c		\
		src/asm/recup_op.c		\
		src/asm/remp_int.c		\
		src/asm/reverse_add.c		\
		src/asm/set_label.c		\
		src/asm/take_bit.c		\
		src/asm/verif_line.c		\
		src/asm/errors.c		\
		src/asm/without_before_.c

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
		utils/my_getlongnbr.c		\
		utils/my_str_to_wordtab.c	\
		utils/free_tab.c		\
		utils/my_free.c			\
		utils/my_str_is_alpha.c		\
		utils/my_strncmp.c		\
		utils/my_putnbr.c		\
		utils/my_putchar.c		\
		utils/char_isalphanum.c		\
		utils/my_strcmp.c

GNL	=	gnl/get_next_line.c		\
		gnl/ini_gnl.c

OBJ	=	$(BASICS:.c=.o)			\
		$(GNL:.c=.o)			\
		$(SRC:.c=.o)

CFLAGS	=	-Wall -Wextra -I include/

NAME	=	asm/asm

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
