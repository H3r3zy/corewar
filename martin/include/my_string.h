/*
** my_string.h for corewar in /home/januar_m/delivery/CPE/CPE_2016_corewar/martin/error_handling
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Fri Mar 24 19:49:54 2017 Martin Januario
** Last update Sun Mar 26 22:39:09 2017 Martin Januario
*/

#ifndef		MY_STRING_H_
# define	MY_STRING_H_

# include	<stdio.h>

int		my_strlen(char *);
int		my_str_is_num(char *);
int		my_putstr(int, char *);
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
char		*my_strcpy(char *, char *);
int		my_str_is_alpha(char *);
char		**parse_(char *, char);

#endif		/* !MY_STRING_H_ */
