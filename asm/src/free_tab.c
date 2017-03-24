/*
** free_tab.c for free_tab in /home/desnosm/rendu/SystUnix/PSU_2016_minishell1
**
** Made by Maximilien Desnos
** Login   <desnosm@epitech.net>
**
** Started on  Wed Jan  4 20:28:51 2017 Maximilien Desnos
** Last update Sat Jan  7 21:30:27 2017 Maximilien Desnos
*/

#include	<stdlib.h>

void		free_tab(char **tab)
{
  int		i;

  i = 0;
  while (tab[i] != NULL)
    {
      free(tab[i]);
      i++;
    }
  free(tab);
}
