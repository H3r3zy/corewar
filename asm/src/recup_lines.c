/*
** recup_lines.c for corewar in /home/desnosm/rendu/Progelem/CPE_2016_corewar/asm
**
** Made by maximilien desnos
** Login   <maximilien.desnos@epitech.eu>
**
** Started on  Sat Mar 25 15:07:35 2017 maximilien desnos
** Last update Tue Mar 28 11:19:35 2017 Sahel Lucas--Saoudi
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"my.h"

static void	add_op(t_line *op, t_line *op2)
{
  while (op->next)
    op = op->next;
  op->next = op2;
  op2->previous = op;
  op2->next = NULL;
}

static t_line	*find_info(char *fd)
{
  int		lb;
  static int	nb_line = 0;
  t_line	*op;

  op = malloc(sizeof(t_line));
  op->exist = 1;
  lb = check_label(fd, op);
  recup_args(fd, op, lb);
  recup_op(fd, op, lb);
  op->line = nb_line;
  nb_line++;
  if (op->exist)
    {
      set_byte(op);
      remp_int(op);
    }
  return (op);
}

void		write_asm(t_line *op)
{
  int		i;

  while (op)
    {
      if (op->exist)
	{
	  write(1, &op->op.code, sizeof(char));
	  if (op->have_cb == 1)
	    write(1, &op->cb, sizeof(char));
	  i = 0;
	  while (op->arg[i])
	    {
	      if (op->byte[i] == 2)
		op->ret[i] = reverse_add2(op->ret[i]);
	      else if (op->byte[i] == 4)
		op->ret[i] = reverse_add(op->ret[i]);
	      write(1, &op->ret[i], op->byte[i]);
	      i++;
	    }
	}
      op = op->next;
    }
}

t_line		*recup_lines(t_line *op, char **fd)
{
  t_line	*op2;
  int		i;

  i = 2;
  op->nb_bytes_tot = 0;
  if ((op2 = malloc(sizeof(t_line))) == NULL)
    exit(84);
  op->arg = NULL;
  op->previous = NULL;
  op = find_info(fd[i]);
  op->next = NULL;
  op->previous = NULL;
  while (fd[i] != NULL)
    {
      op2 = find_info(fd[i]);
      add_op(op, op2);
      op->nb_bytes_tot = op->nb_bytes_tot + op->bytes;
      i++;
    }
  set_label(op);
  return (op);
}
