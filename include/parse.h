/*
** parse.h for corewar in /home/tsuna/Epitech/projects/corewar/error_handling
** 
** Made by Martin Van Elslande
** Login   <martin.van-elslande@epitech.eu>
** 
** Started on  Fri Mar 24 19:10:44 2017 Martin Van Elslande
** Last update Sun Apr  2 08:19:26 2017 Martin Januario
*/

#ifndef		PARSE_H_
# define	PARSE_H_

typedef struct		s_label
{
  struct s_label	*next;
  char			*name;
  int			here;
}			t_label;

int		help(int, int);
int		my_filelen(int);
char		**read_file(int, t_label *, int *);
char		**check_file(char *, int *);
int		check_line(char *, int, t_label *, int *);
int		check_type(char **, int, int, t_label *);
int		check_type_ind(char *, int);
int		check_type_reg(char *, int);
int		check_type_dir(char *, int, t_label *);
int		check_label_error(char *, t_label *);
int		check_command(char *, int, t_label *);
int		convert_and_check(char *, int, t_label *, int *);
int		error_messages(int, int);
int		add_label(t_label *, char *);

#endif		/* !PARSE_H_ */
