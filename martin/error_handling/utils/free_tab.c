/*
** free_tab.c for  in /home/januar_m/delivery/CPE/CPE_2016_corewar/martin/error_handling
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Fri Mar 24 20:27:32 2017 Martin Januario
** Last update Fri Mar 24 20:28:44 2017 Martin Januario
*/

#include	<stdlib.h>

int		free_tab(char **tab)
{
  int		idx;

  idx = 0;
  if (tab == NULL)
    return (0);
  while (tab[idx] != NULL)
    {
      my_free(tab[idx]);
      idx++;
    }
  free(tab);
  return (0);
}
