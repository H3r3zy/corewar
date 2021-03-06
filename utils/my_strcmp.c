/*
** my_strcmp.c for  in /home/januar_m/delivery/PSU/PSU_2016_tetris
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Wed Mar  1 14:44:40 2017 
** Last update Sat Mar 25 12:39:31 2017 Martin Januario
*/

#include	"my_string.h"

int		my_strcmp(char *s1, char *s2)
{
  int		idx;
  int		len1;
  int		len2;

  idx = 0;
  len1 = my_strlen(s1);
  len2 = my_strlen(s2);
  if (len1 == 0 || len2 == 0)
    return (1);
  while (idx <= len1 && idx <= len2 && s1[idx] != '\0' && s2[idx] != '\0')
    {
      if (s1[idx] > s2[idx])
	return (1);
      if (s1[idx] < s2[idx])
	return (-1);
      idx++;
    }
  if (len1 > len2)
    return (1);
  if (len1 < len2)
    return (-1);
  return (0);
}
