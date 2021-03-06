/*
** my_nbr_to_str.c for corewar in /home/desnosm/rendu/Progelem/CPE_2016_corewar/asm
**
** Made by maximilien desnos
** Login   <maximilien.desnos@epitech.eu>
**
** Started on  Sat Mar 25 18:31:25 2017 maximilien desnos
** Last update Sat Mar 25 18:31:27 2017 maximilien desnos
*/

#include	<stdlib.h>
#include	"my.h"

char		*minus(char *str, int *k)
{
  str[*k] = '-';
  *k = *k + 1;
  return (str);
}

char		*ini_this(long int *i, int *j, int *k, int *nb)
{
  char		*str;
  int		m;

  m = 0;
  if (*nb < 0)
    {
      *nb = *nb * -1;
      m = 1;
    }
  *i = 1;
  *k = 0;
  *j = 0;
  while (*i <= *nb)
    {
      *i *= 10;
      *j += 1;
    }
  if ((str = malloc(sizeof(char) * (*j + 2))) == NULL)
    return (NULL);
  if (m == 1)
    str = minus(str, &*k);
  return (str);
}

char 		*my_nbr_to_str(int nb)
{
  long int	i;
  int		ret;
  int		j;
  char		*str;
  int		k;

  str = ini_this(&i, &j, &k, &nb);
  if (i == 1)
    {
      str[0] = (nb + '0');
      str[1] = '\0';
      return (str);
    }
  i = i / 10;
  while (i != 0)
    {
      ret = nb / i;
      str[k++] = (ret + '0');
      nb = nb - (ret * i);
      i = i / 10;
    }
  str[k] = '\0';
  return (str);
}
