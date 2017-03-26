/*
** my_strdup.c for  in /home/januar_m/delivery/PSU/PSU_2016_tetris
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Mon Feb 27 14:44:41 2017 
** Last update Fri Mar 24 20:40:43 2017 Martin Januario
*/

#include	<stdlib.h>
#include	"my_string.h"

char	*my_strdup(char *src)
{
  char	*str;

  if (src == NULL)
    return (NULL);
  if ((str = malloc(sizeof(char) * my_strlen(src) + 1)) == 0)
    return (NULL);
  my_strcpy(str, src);
  return (str);
}
