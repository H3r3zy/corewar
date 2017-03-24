/*
** my.h for my in /home/desnosm/rendu/Progelem/CPE_2016_corewar/asm/convert
**
** Made by Maximilien Desnos
** Login   <desnosm@epitech.net>
**
** Started on  Fri Mar 24 17:13:56 2017 Maximilien Desnos
** Last update Fri Mar 24 18:23:48 2017 Maximilien Desnos
*/

#ifndef MY_H_
# define MY_H_

char		**recup_file(char *);
char		*conver_text(char *);
char		*get_next_line(int);
char		*my_strdup(char *);
int		verif_line(char *);
int		my_strlen(char *);
int		my_power_rec(int, int);
void		my_putchar(char, int);
void		my_putstr(char *, int);

#endif /* MY_H_ */
