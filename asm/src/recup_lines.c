/*
** recup_lines.c for corewar in /home/desnosm/rendu/Progelem/CPE_2016_corewar/asm
**
** Made by maximilien desnos
** Login   <maximilien.desnos@epitech.eu>
**
** Started on  Sat Mar 25 15:07:35 2017 maximilien desnos
** Last update Sat Mar 25 15:40:49 2017 maximilien desnos
*/

#include	<stdlib.h>
#include	"my.h"

static void	add_op(t_line *op, t_line *op2)
{
  if (op->arg == NULL)
    {
      op = op2;
      op->next = NULL;
      op->previous = NULL;
    }
  else
    {
      while (op->next != NULL)
	op = op->next;
      op->next = op2;
      op2->previous = op;
      op2->next = NULL;
    }
}

void		find_info(char *fd, t_line *op)
{
  op->arg = my_strdup(fd);
  check_label(fd, op);
}

void		recup_lines(t_line *op, char **fd)
{
  t_line	*op2;
  int		i;

  i = 2;
  if ((op2 = malloc(sizeof(t_line))) == NULL)
    exit(84);
  while (fd[i] != NULL)
    {
      find_info(fd[i], op2);
      add_op(op, op2);
      i++;
    }
}
