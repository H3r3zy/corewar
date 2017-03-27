/*
** my_strncmp.c for corewar in /home/tsuna/Epitech/projects/corewar/CPE_2016_corewar/martin
** 
** Made by Martin Van Elslande
** Login   <martin.van-elslande@epitech.eu>
** 
** Started on  Fri Mar 24 21:02:43 2017 Martin Van Elslande
** Last update Fri Mar 24 21:44:05 2017 Martin Van Elslande
*/

#include	"my_string.h"

int		my_strncmp(char *cmp1, char *cmp2, int n)
{
  int		i;

  if (my_strlen(cmp1) < n || my_strlen(cmp2) < n)
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
