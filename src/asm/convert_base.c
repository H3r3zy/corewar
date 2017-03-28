/*
** convert_base.c for convert_base in /home/desnos_m/rendu/Piscine/CPool_Day08/task05
**
** Made by Maximilien Desnos
** Login   <desnos_m@epitech.net>
**
** Started on  Wed Oct 12 22:26:31 2016 Maximilien Desnos
** Last update Fri Mar 24 18:38:53 2017 Sahel Lucas--Saoudi
*/

#include	<stdlib.h>
#include	"my.h"

static int	my_pos(char *str, char c)
{
  int		i;

  i = 0;
  while (str[i] != c)
    i++;
  return (i);
}

static int	count_size_base(unsigned int nbr, char *base, int size)
{
  long int	i;
  int		ret;

  i = 1;
  while (i <= nbr)
    i = i * my_strlen(base);
  if (i == 1)
    {
      size++;
      return (0);
    }
  i = i / my_strlen(base);
  while (i != 0)
    {
      ret = nbr / i;
      size++;
      nbr = nbr - (ret * i);
      i = i / my_strlen(base);
    }
  return (size);
}

static char	*ret_nbr_base(unsigned int nbr,
			      char *base, char *nbr_base, int end)
{
  long int	i;
  unsigned int	ret;

  i = 1;
  while (i <= nbr)
    i = i * my_strlen(base);
  if (i == 1)
    {
      nbr_base[end] = nbr + '0';
      end++;
      nbr_base[end] = '\0';
      return (nbr_base);
    }
  i = i / my_strlen(base);
  while (i != 0)
    {
      ret = nbr / i;
      nbr_base[end] = base[ret];
      end++;
      nbr = nbr - (ret * i);
      i = i / my_strlen(base);
    }
  nbr_base[end] = '\0';
  return (nbr_base);
}

static unsigned int	my_getnbr_base(char *str, char *base)
{
  int			i;
  int			end;
  unsigned int		nb;
  int			ba;

  nb = 0;
  ba = my_strlen(base) - 1;
  ba++;
  end = 0;
  i = my_strlen(str) - 1;
  while (str[end] != '\0')
    {
      nb = nb + (my_pos(base, str[end]) * my_power_rec(ba, i));
      i--;
      end++;
    }
  return (nb);
}

char	*convert_base(char *nbr, char *base_from, char *base_to)
{
  unsigned int	nbr_int;
  int		size;
  char		*nbr_base;
  int		end;

  if ((my_strlen(base_to) <= 1) || my_strlen(base_from) <= 1)
    return (0);
  end = 0;
  size = 0;
  nbr_int = my_getnbr_base(nbr, base_from);
  size = count_size_base(nbr_int, base_to, size);
  if ((nbr_base = malloc(sizeof(char) * (size + 1))) == NULL)
    return (NULL);
  nbr_base = ret_nbr_base(nbr_int, base_to, nbr_base, end);
  return (nbr_base);
}
