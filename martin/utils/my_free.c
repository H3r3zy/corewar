/*
** my_free.c for  in /home/januar_m/delivery/CPE/CPE_2016_corewar/martin/error_handling
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Fri Mar 24 20:29:50 2017 Martin Januario
** Last update Fri Mar 24 20:30:20 2017 Martin Januario
*/

#include	<stdlib.h>

void		my_free(char *str)
{
  if (str != NULL)
    free(str);
}
