/*
** check_env.c for  in /home/januar_m/delivery/graphical/wolf3d/bonus
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Sun Jan  1 12:47:08 2017 
** Last update Sun Apr  2 10:26:05 2017 Martin Januario
*/

#include	<stdlib.h>
#include	"my.h"

int		check_name_next(char *str)
{
  if (match(str, "LSCOLORS=*") == 1)
    return (1);
  else if (match(str, "LS_COLORS=*") == 1)
    return (1);
  else if (match(str, "XDG_RUNTIME_DIR=*") == 1)
    return (1);
  return (0);
}

int		check_name(char *str)
{
  if (match(str, "DISPLAY=*") == 1 && str[8] != '\0')
    return (1);
  else if (match(str, "LIBRARY_PATH=*") == 1)
    return (1);
  else if (match(str, "LD_LIBRARY_PATH=*") == 1)
    return (1);
  else if (match(str, "CPATH=*") == 1)
    return (1);
  else if (check_name_next(str) == 1)
    return (1);
  return (0);
}

int		check_env(char **tab)
{
  int		idx;
  int		cpt;

  idx = 0;
  cpt = 0;
  while (tab[idx] != NULL)
    {
      if (check_name(tab[idx]) == 1)
	cpt++;
      idx++;
    }
  if (cpt != 7)
    return (1);
  return (0);
}
