/*
** my.h for my in /home/desnosm/rendu/Progelem/CPE_2016_corewar/asm/convert
**
** Made by Maximilien Desnos
** Login   <desnosm@epitech.net>
**
** Started on  Fri Mar 24 17:13:56 2017 Maximilien Desnos
** Last update Fri Mar 24 18:35:06 2017 Sahel Lucas--Saoudi
*/

#ifndef MY_H_
# define MY_H_

# include "op.h"

char		**recup_file(char *);
char		*conver_text(char *);
char		*my_nbr_to_str(int);
char		*convert_base(char *, char *, char *);
char		*get_next_line(int);
char		*my_strdup(char *);
int		verif_line(char *);
int		my_strlen(char *);
int		my_power_rec(int, int);
void		my_putchar(char, int);
void		my_putstr(char *, int);
void		recup_header(char **, header_t *);
void		aff_tab(char **);

#endif /* MY_H_ */
