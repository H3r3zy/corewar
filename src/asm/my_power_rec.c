/*
** my_power_rec.c for my_power_rec in /home/desnos_m/rendu/tempary_repo_Day05
** 
** Made by Maximilien Desnos
** Login   <desnos_m@epitech.net>
** 
** Started on  Fri Oct  7 11:07:04 2016 Maximilien Desnos
** Last update Mon Oct 10 21:35:44 2016 Maximilien Desnos
*/

int		my_power_rec(int nb, int p)
{
  int		i;
  long int	bv;

  i = 1;
  bv = 1;
  while (i <= p)
    {
      bv = bv * nb;
      i++;
    }
  if (bv <= -2147483648 || bv >= 2147483648)
    return (0);
  if (p > 0)
    return (nb * my_power_rec(nb, p - 1));
  else if (p == 0)
    return (1);
  else
    return (0);
  return (-1);
}
