/*
** my_putnbr.c for corewar in /home/tsuna/Epitech/projects/corewar/CPE_2016_corewar
** 
** Made by Martin Van Elslande
** Login   <martin.van-elslande@epitech.eu>
** 
** Started on  Mon Mar 27 18:03:48 2017 Martin Van Elslande
** Last update Mon Mar 27 18:08:08 2017 Martin Van Elslande
*/

#include	<unistd.h>
#include	"my_string.h"

int	digits(int nb)
{
  if (nb > 9)
    {
      digits(nb / 10);
      my_putchar(nb % 10 + 48);
    }
  else
    my_putchar(nb + 48);
  return (0);
}

int	my_putnbr(int nb)
{
  if (nb < 0)
    {
      my_putchar(45);
      nb = nb * (-1);
    }
  digits(nb);
  return (0);
}
