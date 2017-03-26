/*
** my_string.h for corewar in /home/januar_m/delivery/CPE/CPE_2016_corewar/martin/error_handling
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Fri Mar 24 19:49:54 2017 Martin Januario
** Last update Sat Mar 25 14:42:32 2017 Martin Januario
*/

#ifndef		MY_STRING_H_
# define	MY_STRING_H_

int		my_strlen(char *);
int		my_str_is_num(char *);
int		my_putstr(int, char *);
int		my_strcmp(char *, char *);
void		disp_tab(char **);
int		match(char *, char *);
int		my_tablen(char **);
char		**my_str_to_wordtab(char *);
int		free_tab(char **);
void		my_free(char *);
char		*my_strdup(char *);
char		*my_strcpy(char *, char *);
int		my_str_is_alpha(char *);
int		check_command(char *, int);
char		**parse_(char *, char);

#endif		/* !MY_STRING_H_ */
