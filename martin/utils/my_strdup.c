/*
** my_strdup.c for corewar in /home/tsuna/Epitech/projects/corewar/CPE_2016_corewar/martin
** 
** Made by Martin Van Elslande
** Login   <martin.van-elslande@epitech.eu>
** 
** Started on  Sun Mar 26 14:26:15 2017 Martin Van Elslande
** Last update Sun Mar 26 14:29:23 2017 Martin Van Elslande
*/

#include	<stdlib.h>
#include	"my_string.h"

char	*my_strndup(char *src, int n)
{
  int	i;
  char	*str;

  if (!src)
    return (NULL);
  if (my_strlen(src) < n)
    n = my_strlen(src);
  str = malloc(sizeof(char) * (n + 1));
  if (!str)
    return (NULL);
  i = 0;
  while (src[i] && i < n)
    {
      str[i] = src[i];
      i++;
    }
  return (str);
}

char	*my_strdup(char *src)
{
  char	*str;

  if (src == NULL)
    return (NULL);
  if ((str = malloc(sizeof(char) * my_strlen(src) + 1)) == 0)
    return (NULL);
  my_strcpy(str, src);
  return (str);
}
