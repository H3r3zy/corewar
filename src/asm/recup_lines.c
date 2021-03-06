/*
** recup_lines.c for corewar in /home/desnosm/rendu/Progelem/CPE_2016_corewar/asm
**
** Made by maximilien desnos
** Login   <maximilien.desnos@epitech.eu>
**
** Started on  Sat Mar 25 15:07:35 2017 maximilien desnos
** Last update Sun Apr  2 10:39:03 2017 Martin Januario
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"my.h"
#include	"op.h"
#include	"my_string.h"

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

  if ((op = malloc(sizeof(t_line))) == NULL)
    exit(84);
  op->exist = 1;
  op->bytes = 0;
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

void		write_asm(t_line *op, header_t *hd, int fd)
{
  int		i;

  remp_fd(hd, fd, op);
  while (op)
    {
      if (op->exist)
	{
	  write(fd, &op->op.code, sizeof(char));
	  if (op->have_cb == 1)
	    write(fd, &op->cb, sizeof(char));
	  i = 0;
	  while (op->arg[i])
	    {
	      if (op->byte[i] == 2)
		op->ret[i] = (unsigned short) reverse_add2(op->ret[i]);
	      else if (op->byte[i] == 4)
		op->ret[i] = (unsigned int) reverse_add(op->ret[i]);
	      write(fd, &op->ret[i], op->byte[i]);
	      i++;
	    }
	}
      op = op->next;
    }
}

t_line		*recup_lines(t_line *op, char **fd, int i)
{
  t_line	*op2;

  op->nb_bytes_tot = 0;
  if ((op2 = malloc(sizeof(t_line))) == NULL)
    exit(84);
  op->arg = NULL;
  op->previous = NULL;
  op = find_info(fd[i]);
  i++;
  op->nb_bytes_tot = op->bytes;
  op->next = NULL;
  op->previous = NULL;
  while (i < my_tablen(fd))
    {
      op2 = find_info(fd[i]);
      add_op(op, op2);
      op->nb_bytes_tot = op->nb_bytes_tot + op2->bytes;
      i++;
    }
  set_label(op);
  return (op);
}
