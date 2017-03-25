/*
** my.h for my in /home/desnosm/rendu/Progelem/CPE_2016_corewar/asm/convert
**
** Made by Maximilien Desnos
** Login   <desnosm@epitech.net>
**
** Started on  Fri Mar 24 17:13:56 2017 Maximilien Desnos
** Last update Sat Mar 25 18:15:26 2017 maximilien desnos
*/

#ifndef MY_H_
# define MY_H_

# include "op.h"

typedef struct	s_line
{
  op_t		op;
  char		**arg;
  char		*label;
  int		byte;
  struct s_line	*previous;
  struct s_line	*next;
}		t_line;

void		recup_lines(t_line *, char **);
char		*my_strdup(char *);
int		check_label(char *, t_line *);
int		recup_pos_name(char **);
int		count_size_header_str(char *);
int		match(char *, char *);
int		recup_header(char **, header_t *);
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
void		aff_tab(char **);

#endif /* MY_H_ */
