/*
** recup_op.c for corewar in /home/desnosm/rendu/Progelem/CPE_2016_corewar/asm
**
** Made by maximilien desnos
** Login   <maximilien.desnos@epitech.eu>
**
** Started on  Sat Mar 25 18:43:31 2017 maximilien desnos
** Last update Wed Mar 29 18:14:31 2017 Sahel Lucas--Saoudi
*/

#include	<stdlib.h>
#include	"my.h"
#include	"op.h"

static int	count_size_fct(char *fd, int i)
{
  int		size;

  size = 0;
  while (fd[i] != ' ' && fd[i] != '\t' && fd[i] != '\0')
    {
      size++;
      i++;
    }
  return (size);
}

static int	sin_space(char *fd, int i)
{
  while (fd[i] == ' ' || fd[i] == '\t')
    i++;
  return (i);
}

void		remp_op(char *fct, t_line *op)
{
  int		i;
  int		j;

  j = 0;
  i = 0;
  while (op_tab[i].mnemonique != NULL)
    {
      if (my_strcmp(fct, op_tab[i].mnemonique) == 0 ||
	  my_strcmp(fct, op_tab[i].comment) == 0)
	{
	  op->op = op_tab[i];
	  j = 1;
	}
      i++;
    }
  if (j == 0)
    op->exist = 0;
}

static int	verif_lb(char *fd, int i)
{
  while (fd[i] != LABEL_CHAR)
    i++;
  i++;
  return (i);
}

void		recup_op(char *fd, t_line *op, int lb)
{
  int		i;
  int		j;
  int		size;
  char		*fct;

  i = 0;
  j = 0;
  if (lb != -1)
    i = verif_lb(fd, i);
  i = sin_space(fd, i);
  size = count_size_fct(fd, i);
  if ((fct = malloc(sizeof(char) * (size + 1))) == NULL)
    exit(84);
  while (fd[i] != ' ' && fd[i] != '\t' && fd[i] != '\0')
    {
      fct[j] = fd[i];
      j++;
      i++;
    }
  fct[j] = '\0';
  if (j > 0)
    remp_op(fct, op);
  else
    op->exist = 0;
}
