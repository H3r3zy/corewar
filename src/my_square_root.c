/*
** my_square_root.c for my_square_rout in /home/desnos_m/rendu/CPool_Day05
** 
** Made by Maximilien Desnos
** Login   <desnos_m@epitech.net>
** 
** Started on  Fri Oct  7 12:54:21 2016 Maximilien Desnos
** Last update Mon Oct 10 21:36:10 2016 Maximilien Desnos
*/

int		my_square_root(int nb)
{
  int		square;

  square = 1;
  if (nb == 1)
    return (1);
  while (square < nb)
    {
      if ((nb % square) == 0 && (square * square) == nb)
	return (square);
      square++;
    }
  return (0);
}
