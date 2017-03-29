/*
** my_getnbr.c for  in /home/januar_m/delivery/CPE/tmp/CPE_2016_corewar/getnbr
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Wed Mar 29 12:58:17 2017 Martin Januario
** Last update Wed Mar 29 13:16:31 2017 Martin Januario
*/

#include	<stdio.h>

long long int	my_getlongnbr(char *str)
{
  long long int	nb;
  int		neg;
  int		idx;

  nb = 0;
  idx = 0;
  neg = 1;
  while (str[idx] != '\0' && (str[idx] == '-' || str[idx] == '+'))
    {
      if (str[idx] == '-')
	neg *= -1;
      idx++;
    }
  if (str[idx] == '\0')
    return (0);
  while (str[idx] != '\0' && str[idx] >= '0' && str[idx] <= '9')
    {
      nb *= 10;
      nb += (str[idx] - '0');
      idx++;
    }
  return (nb * neg);
}
