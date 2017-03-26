/*
** my_getnbr.c for corewar in /home/desnosm/rendu/Progelem/CPE_2016_corewar/asm
**
** Made by maximilien desnos
** Login   <maximilien.desnos@epitech.eu>
**
** Started on  Sun Mar 26 18:31:10 2017 maximilien desnos
** Last update Sun Mar 26 18:31:42 2017 maximilien desnos
*/

#include	<stdlib.h>

static int	my_str_to_len(char *str)
{
  int		size;
  int		i;

  i = 0;
  size = 0;
  while ((str[size] != '\0' && str[size] <= '9' && str[size] >= '0')
	 || str[size] == '-' || str[size] == '+')
    size++;
  while (str[i] == '+' || str[i] == '-')
    i++;
  size = size - i;
  return (size);
}

static int	my_power(int i)
{
  int		j;
  int		nb;

  nb = 1;
  j = 0;
  while (j != i)
    {
      nb = nb * 10;
      j++;
    }
  return (nb);
}

static int	minus(char *str, int *size, int nb)
{
  int		j;
  int		m;

  j = 0;
  m = 0;
  while (str[j] == '+' || str[j] == '-')
    {
      if (str[j] == '-')
	m++;
      *size = *size + 1;
      j++;
    }
  if ((m % 2) != 0)
    nb = nb * -1;
  return (nb);
}

int		my_getnbr(char *str)
{
  int		i;
  int		nb;
  int		size;
  int		power;

  size = 0;
  nb = 0;
  i = my_str_to_len(str);
  i--;
  while (i >= 0)
    {
      if (str[size] == '-' || str[size] == '+')
	minus(str, &size, 0);
      power = my_power(i);
      nb = nb + (power * (str[size] - '0'));
      size++;
      i--;
    }
  if (str[0] == '-' || str[0] == '+')
    nb = minus(str, &size, nb);
  if ((i = my_str_to_len(str)) > 10 || nb <= -2147483647 || nb >= 2147483647)
    return (0);
  return (nb);
}
