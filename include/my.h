/*
** my.h for my in /home/desnosm/rendu/Progelem/CPE_2016_corewar/asm/convert
**
** Made by Maximilien Desnos
** Login   <desnosm@epitech.net>
**
** Started on  Fri Mar 24 17:13:56 2017 Maximilien Desnos
** Last update Thu Mar 30 13:36:58 2017 maximilien desnos
*/

#ifndef MY_H_
# define MY_H_

# include "op.h"

typedef struct	s_line
{
  op_t		op;
  char		**arg;
  char		*label;
  char		*write;
  char		cb;
  char		have_cb;
  int		nb_bytes_tot;
  int		line;
  int		bytes;
  int		byte[MAX_ARGS_NUMBER];
  int		exist;
  unsigned int	*ret;
  struct s_line	*previous;
  struct s_line	*next;
}		t_line;

long long int	my_getlongnbr(char *);
unsigned int	reverse_add(unsigned int);
unsigned int	reverse_add2(unsigned int);
int		recup_pos_comment(char **);
int		my_getnbr(char *);
int		check_label(char *, t_line *);
int		recup_pos_name(char **, int, int, char *);
int		count_size_header_str(char *);
int		match(char *, char *);
int		verif_line(char *);
int		my_strlen(char *);
int		my_power_rec(int, int);
void		recup_header(char **, header_t *);
int		my_strcmp(char *, char *);
char		*my_strdup(char *);
char		**recup_file(char *);
char		**my_str_to_arg(char *);
char		*conver_text(char *);
char		*my_nbr_to_str(int);
char		*convert_base(char *, char *, char *);
char		*get_next_line_fd(int);
char		*my_strdup(char *);
char		*my_realloc_gnl(char *, char *, int *);
char		*without_before_(char *, char);
void		remp_int(t_line *);
void		set_byte(t_line *);
void		set_label(t_line *);
void		aff_tab(char **);
void		recup_op(char *, t_line *, int);
void		recup_args(char *, t_line *, int);
void		write_asm(t_line *, header_t *, int);
void		remp_fd(header_t *, int, t_line *);
t_line		*recup_lines(t_line *, char **);

#endif /* MY_H_ */
