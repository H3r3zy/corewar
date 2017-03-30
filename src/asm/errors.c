/*
** errors.c for corewar in /home/tsuna/Epitech/projects/corewar/corewar_repo/CPE_2016_corewar
** 
** Made by Martin Van Elslande
** Login   <martin.van-elslande@epitech.eu>
** 
** Started on  Wed Mar 29 18:19:06 2017 Martin Van Elslande
** Last update Thu Mar 30 12:54:21 2017 Martin Van Elslande
*/

#include	"my_string.h"
#include	"op.h"

int		error_messages(int nb_err, int nb_line)
{
  if (nb_err == 0)
    my_putstr(2, "FAILED\nMalloc error.\n");
  else if (nb_err == 1)
    my_putstr(2, "FAILED\nA function in op_tab doesn't accept arguments.\n");
  else if (nb_err == 2)
    my_putstr(2, "line %d, Incorrect type in parameters.\n", nb_line);
  else if (nb_err == 3)
    my_putstr(2, "line %d, Too few arguments.\n", nb_line);
  else if (nb_err == 4)
    my_putstr(2, "line %d, Unknown keyword.\n", nb_line);
  else if (nb_err == 5)
    my_putstr(2, "line %d, Name is over the max size (%d).\n", nb_line,
	      PROG_NAME_LENGTH);
  else if (nb_err == 6)
    my_putstr(2, "line %d, Comment is over the max size (%d).\n", nb_line,
	      COMMENT_LENGTH);
  return (0);
}
