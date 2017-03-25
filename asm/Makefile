##
## Makefile for Makefile in /home/desnos_m/rendu/Progelem/CPE_2016_matchstick
## 
## Made by maximilien desnos
## Login   <desnos_m@epitech.net>
## 
## Started on  Mon Feb 13 15:09:13 2017 maximilien desnos
## Last update Fri Mar 24 22:01:03 2017 Maximilien Desnos
##

SRC	=	src/main.c		\
		src/conver_text.c	\
		src/convert_base.c	\
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
