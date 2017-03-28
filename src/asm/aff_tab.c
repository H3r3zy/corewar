/*
** aff_tab.c for aff_tab.c in /home/desnosm/rendu/SystUnix/PSU_2016_minishell1
**
** Made by Maximilien Desnos
** Login   <desnosm@epitech.net>
**
** Started on  Fri Jan  6 20:05:09 2017 Maximilien Desnos
** Last update Thu Jan 19 18:20:05 2017 Maximilien Desnos
*/

#include	<stdlib.h>
#include	"my.h"

void		aff_tab(char **tab)
{
  int		i;

  i = 0;
  while (tab[i] != NULL)
    {
      my_putstr(tab[i], 0);
      my_putchar('\n', 0);
      i++;
    }
}
