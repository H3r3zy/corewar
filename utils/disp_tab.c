/*
** disp_tab.c for  in /home/januar_m/delivery/PSU/PSU_2016_minishell2
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Tue Mar 14 13:25:27 2017 
** Last update Fri Mar 24 19:53:10 2017 Martin Januario
*/

#include	<stdlib.h>
#include	"my_string.h"

void		disp_tab(char **tab)
{
  int		idx;

  idx = 0;
  while (tab != NULL && tab[idx] != NULL)
    {
      my_putstr(1, tab[idx]);
      my_putstr(1, "\n");
      idx++;
    }
}
