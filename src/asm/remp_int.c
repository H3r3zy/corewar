/*
** remp_int.c for corewar in /home/desnosm/rendu/Progelem/CPE_2016_corewar/asm
**
** Made by maximilien desnos
** Login   <maximilien.desnos@epitech.eu>
**
** Started on  Sun Mar 26 18:18:57 2017 maximilien desnos
** Last update Wed Mar 29 16:05:34 2017 Sahel Lucas--Saoudi
*/

#include	<stdlib.h>
#include	"my.h"
#include	"op.h"

static void	change_overf(int i, unsigned int nb, t_line *op)
{
  unsigned int	tmp;

  if (op->byte[i] == 2)
    tmp = 65535;
  else
    tmp = 4294967295;
  if (nb > tmp)
    {
      while (nb > tmp)
	nb = nb + tmp;
      nb += 1;
    }
  op->ret[i] = nb;
}

static void	recup_reg(char *arg, t_line *op, int j)
{
  int		i;
  char		*tmp;

  i = 0;
  while (arg[i + 1] != '\0')
    i++;
  if ((tmp = malloc(sizeof(char) * (i + 1))) == NULL)
    exit(84);
  i = 1;
  while (arg[i] != '\0')
    {
      tmp[i - 1] = arg[i];
      i++;
    }
  tmp[i - 1] = '\0';
  op->ret[j] = my_getlongnbr(tmp);
}

static void	recup_dir(char *arg, t_line *op, int j)
{
  unsigned int	i;
  char		*tmp;

  i = 0;
  while (arg[i + 1] != '\0')
    i++;
  if ((tmp = malloc(sizeof(char) * (i + 1))) == NULL)
    exit(84);
  i = 1;
  while (arg[i] != '\0')
    {
      tmp[i - 1] = arg[i];
      i++;
    }
  tmp[i - 1] = '\0';
  i = my_getlongnbr(tmp);
  change_overf(j, i, op);
}

void		remp_int(t_line *op)
{
  int		i;
  unsigned int	tmp;

  i = 0;
  while (op->arg[i] != NULL)
    i++;
  if ((op->ret = malloc(sizeof(unsigned int) * i)) == NULL)
    exit(84);
  i = 0;
  while (op->arg[i] != NULL)
    {
      if (op->arg[i][0] == 'r')
	recup_reg(op->arg[i], op, i);
      else if (op->arg[i][0] == '%' && op->arg[i][1] == ':')
	op->ret[i] = 0;
      else if (op->arg[i][0] == '%' && op->arg[i][1] != ':')
	recup_dir(op->arg[i], op, i);
      else
	{
	  tmp = my_getlongnbr(op->arg[i]);
	  change_overf(i, tmp, op);
	}
      i++;
    }
}
