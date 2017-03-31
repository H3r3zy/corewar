/*
** main.c for  in /home/januar_m/delivery/PSU/PSU_2016_navy/bonus
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Wed Feb  1 21:01:24 2017 
** Last update Thu Mar 30 12:03:36 2017 Martin Januario
*/

#include	<stdlib.h>
#include	"my.h"

int		main(void)
{
  char		**map;

  if ((map = create_map()) == NULL)
    return (84);
  if (ini_window(map) == 84)
    return (84);
  //  free_tab(map);
  return (0);
}
