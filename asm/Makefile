##
## Makefile for corewar in /home/desnosm/rendu/Progelem/CPE_2016_corewar/asm
## 
## Made by maximilien desnos
## Login   <maximilien.desnos@epitech.eu>
## 
## Started on  Sat Mar 25 15:40:03 2017 maximilien desnos
## Last update Sun Mar 26 18:50:17 2017 maximilien desnos
##

SRC	=	src/main.c		\
		src/conver_text.c	\
		src/op.c		\
		src/recup_lines.c	\
		src/check_label.c	\
		src/my_getnbr.c		\
		src/remp_int.c		\
		src/recup_op.c		\
		src/my_strcmp.c		\
		src/recup_args.c	\
		src/convert_base.c	\
		src/my_str_to_wordtab.c	\
		src/my_nbr_to_str.c	\
		src/recup_file.c	\
		src/my_strlen.c		\
		src/get_next_line.c	\
		src/count_size_header_str.c\
		src/put.c		\
		src/recup_header.c	\
		src/free_tab.c		\
		src/verif_line.c	\
		src/my_power_rec.c	\
		src/aff_tab.c		\
		src/my_strdup.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wextra -Wall -I include -g

NAME	=	asm

all: $(NAME)

$(NAME) :	$(OBJ)
	gcc -g -ggdb3 -o $(NAME) $(OBJ) $(CFLAGS)

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(OBJ)

re: fclean all

.PHONY:	all, fclean, clean, re
