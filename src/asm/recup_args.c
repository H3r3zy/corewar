/*
** recup_args.c for corewar in /home/desnosm/rendu/Progelem/CPE_2016_corewar/asm
**
** Made by maximilien desnos
** Login   <maximilien.desnos@epitech.eu>
**
** Started on  Sat Mar 25 18:19:05 2017 maximilien desnos
** Last update Tue Mar 28 14:34:49 2017 Sahel Lucas--Saoudi
*/

#include	<stdlib.h>
#include	"my.h"
#include	"op.h"

static int	size_arg(char *fd, int i)
{
  int		j;

  j = 0;
  while (fd[i] != '\0')
    {
      i++;
      j++;
    }
  return (j);
}

static int	sin_space(char *fd, int i)
{
  while (fd[i] == ' ' || fd[i] == '\t')
    i++;
  return (i);
}

static int	verif_lb(char *fd, int i)
{
  while (fd[i] != ':' && fd[i] != '\0')
    i++;
  i++;
  return (i);
}

void		recup_args(char *fd, t_line *op, int ld)
{
  int		i;
  int		j;
  int		size;
  char		*arg;

  i = 0;
  j = 0;
  if (ld != -1)
    i = verif_lb(fd, i);
  i = sin_space(fd, i);
  while (fd[i] != ' ' && fd[i] != '\t' && fd[i] != '\0')
    i++;
  i = sin_space(fd, i);
  size = size_arg(fd, i);
  if ((arg = malloc(sizeof(char) * (size + 1))) == NULL)
    exit(84);
  while (fd[i] != '\0')
    {
      arg[j] = fd[i];
      j++;
      i++;
    }
  arg[j] = '\0';
  op->arg = my_str_to_arg(arg);
}
