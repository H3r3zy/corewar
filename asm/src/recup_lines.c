/*
** recup_lines.c for corewar in /home/desnosm/rendu/Progelem/CPE_2016_corewar/asm
**
** Made by maximilien desnos
** Login   <maximilien.desnos@epitech.eu>
**
** Started on  Sat Mar 25 15:07:35 2017 maximilien desnos
** Last update Mon Mar 27 15:21:23 2017 maximilien desnos
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
  int		lb;

  lb = check_label(fd, op);
  recup_args(fd, op, lb);
  recup_op(fd, op, lb);
  if (op->op.mnemonique)
    {
      set_byte(op);
      remp_int(op);
      /*printf(":%d:\n", op->op.code);
      write(1, &op->op.code, sizeof(char));
      if (op->have_cb == 1)
	write(1, &op->cb, sizeof(char));
      int i = 0;
      while (op->arg[i])
	{
	  //printf("new arg\n");
	  write(1, &op->ret[i], op->byte[i]);
	  i++;
	}
	//printf("bite\n");*/
    }
}

void		recup_lines(t_line *op, char **fd)
{
  t_line	*op2;
  int		i;
  int		j;
  int		m;

  i = 2;
  op->nb_bytes_tot = 0;
  if ((op2 = malloc(sizeof(t_line))) == NULL)
    exit(84);
  op->arg = NULL;
  while (fd[i] != NULL)
    {
      find_info(fd[i], op2);
      add_op(op, op2);
      op->nb_bytes_tot = op->nb_bytes_tot + bytes;
      i++;
    }
  /*  m = COREWAR_EXEC_MAGIC;
  j = 0;
  while (j < sizeof(int))
    {

      j++;
      }*/
}
