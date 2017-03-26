/*
** my_strcpy.c for  in /home/januar_m/delivery/PSU/PSU_2016_tetris
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Mon Feb 27 14:44:49 2017 
** Last update Fri Mar 24 20:41:30 2017 Martin Januario
*/

#include	"my_string.h"

char		*my_strcpy(char *dest, char *src)
{
  int		idx;

  idx = 0;
  while (src[idx] != '\0')
    {
      dest[idx] = src[idx];
      idx++;
    }
  dest[idx] = '\0';
  return (dest);
}
