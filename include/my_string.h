/*
** my_string.h for corewar in /home/januar_m/delivery/CPE/CPE_2016_corewar/martin/error_handling
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Fri Mar 24 19:49:54 2017 Martin Januario
** Last update Wed Mar 29 13:36:16 2017 Sahel Lucas--Saoudi
*/

#ifndef		MY_STRING_H_
# define	MY_STRING_H_

# include	<stdio.h>

int		my_strlen(char *);
int		sp_len(char *, char);
int		my_str_is_num(char *);
int		my_putstr(int, char *, ...);
int		my_strcmp(char *, char *);
void		disp_tab(char **);
int		match(char *, char *);
int		nb_space(char *);
int		my_getnbr(char *);
int		my_tablen(char **);
int		found_char(char *, char);
char		*my_strncpy(char *, char *, int);
char		**my_str_to_wordtab(char *);
int		free_tab(char **);
void		my_free(char *);
char		*my_strdup(char *);
char		*my_strndup(char *, int);
char		*my_strcpy(char *, char *);
int		my_strncmp(char *, char *, int);
int		my_str_is_alpha(char *);
void		my_putchar(char);
char		**parse_(char *, char);
int		my_putnbr(int);
long long int	my_getlongnbr(char *);

#endif		/* !MY_STRING_H_ */
