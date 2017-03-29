/*
** without_before_.c for corewar in /home/sahel/rendu/CPE/CPE_2016_corewar
** 
** Made by Sahel Lucas--Saoudi
** Login   <sahel.lucas-saoudi@epitech.eu>
** 
** Started on  Wed Mar 29 13:24:36 2017 Sahel Lucas--Saoudi
** Last update Wed Mar 29 13:32:09 2017 Sahel Lucas--Saoudi
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "my_string.h"

char	*without_before_(char *str, char c)
{
  char	*new;
  int	str_i;
  int	new_i;

  str_i = 0;
  new_i = 0;
  new = malloc(my_strlen(str) + 1);
  if (!new)
    return (NULL);
  while (str[str_i] && str[str_i] != c)
    str_i++;
  str_i++;
  while (str[str_i])
    {
      new[new_i] = str[str_i];
      new_i++;
      str_i++;
    }
  new[new_i] = '\0';
  return (new);
}
