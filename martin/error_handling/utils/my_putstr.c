/*
** my_putstr.c for  in /home/januar_m/delivery/CPE/CPE_2016_corewar/martin/error_handling/utils
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Fri Mar 24 19:34:31 2017 
** Last update Fri Mar 24 19:51:03 2017 Martin Januario
*/

#include	<unistd.h>
#include	"my_string.h"

int		my_putstr(int out, char *str)
{
  write(out, str, my_strlen(str));
  return ((out == 2) ? 84 : 0);
}
