/*
** my_strdup.c for my_strdup in /home/desnosm/rendu/SystUnix/PSU_2016_minishell1
**
** Made by Maximilien Desnos
** Login   <desnosm@epitech.net>
**
** Started on  Fri Jan  6 15:25:25 2017 Maximilien Desnos
** Last update Tue Jan 10 19:48:48 2017 Maximilien Desnos
*/

#include	<stdlib.h>
#include	"my.h"

char		*my_strdup(char *str)
{
  char		*tmp;
  int		i;

  i = my_strlen(str) + 1;
  if ((tmp = malloc(sizeof(char) * i)) == NULL)
    exit(84);
  i = 0;
  while (str != NULL && str[i] != '\0')
    {
      tmp[i] = str[i];
      i++;
    }
  tmp[i] = '\0';
  return (tmp);
}
