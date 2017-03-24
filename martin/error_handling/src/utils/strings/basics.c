/*
** basics.c for corewar in /home/tsuna/Epitech/projects/corewar/error_handling
** 
** Made by Martin Van Elslande
** Login   <martin.van-elslande@epitech.eu>
** 
** Started on  Fri Mar 24 19:03:49 2017 Martin Van Elslande
** Last update Fri Mar 24 19:06:27 2017 Martin Van Elslande
*/

#include	<unistd.h>

int		my_strlen(char *str)
{
  int		i;

  if (!str)
    return (0);
  i = 0;
  while (str[i])
    i++;
  return (i);
}

int		my_putstr(int out, char *str)
{
  write(out, str, my_strlen(str));
  if (out == 2)
    return (84);
  return (0);
}

int     my_strcmp(char *cmp1, char *cmp2)
{
  int   i;

  if (my_strlen(cmp1) != my_strlen(cmp2))
    return (0);
  i = 0;
  while (cmp1[i] && cmp2[i])
    {
      if (cmp1[i] != cmp2[i])
        return (0);
      i++;
    }
  return (1);
}
