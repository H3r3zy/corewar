/*
** check_label.c for corewar in /home/desnosm/rendu/Progelem/CPE_2016_corewar/asm
**
** Made by maximilien desnos
** Login   <maximilien.desnos@epitech.eu>
**
** Started on  Sat Mar 25 15:30:07 2017 maximilien desnos
** Last update Sat Mar 25 16:12:24 2017 maximilien desnos
*/

#include	<stdlib.h>
#include	"op.h"
#include	"my.h"

int		check_label(char *fd, t_line *op)
{
  int		i;
  int		j;

  j = 0;
  i = 0;
  while (fd[i] != '%' && fd[i] != ':' && fd[i] != '\0')
    i++;
  if (fd[i] != ':')
    {
      op->label = NULL;
      return (-1);
    }
  if ((op->label = malloc(sizeof(char) * (i + 1))) == NULL)
    exit(84);
  i = 0;
  while (fd[i] == ' ' || fd[i] == '\t')
    i++;
  while (fd[i] != '%' && fd[i] != ':' && fd[i] != '\0')
    {
      op->label[j] = fd[i];
      i++;
      j++;
    }
  op->label[i] = '\0';
  return (1);
}