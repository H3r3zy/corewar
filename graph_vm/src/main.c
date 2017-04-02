/*
** main.c for  in /home/januar_m/delivery/PSU/PSU_2016_navy/bonus
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Wed Feb  1 21:01:24 2017 
** Last update Sun Apr  2 02:07:29 2017 Sahel Lucas--Saoudi
*/

#include	<stdlib.h>
#include	"my.h"

int		main(int argc, char **argv)
{
  char		**map;

  if ((map = create_map(argv[1])) == NULL)
    return (84);
  if (ini_window(map) == 84)
    return (84);
  return (0);
}
