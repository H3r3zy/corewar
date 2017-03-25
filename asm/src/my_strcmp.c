/*
** my_strcmp.c for corewar in /home/desnosm/rendu/Progelem/CPE_2016_corewar/asm
**
** Made by maximilien desnos
** Login   <maximilien.desnos@epitech.eu>
**
** Started on  Sat Mar 25 18:56:17 2017 maximilien desnos
** Last update Sat Mar 25 18:56:19 2017 maximilien desnos
*/

#include	<stdlib.h>

int		my_strcmp(char *s1, char *s2)
{
  int		i;

  i = 0;
  if (s1 == NULL || s2 == NULL)
    return (-1);
  while (s1[i] != '\0' && s2[i] != '\0' && s2[i] == s1[i])
    i++;
  return (s1[i] - s2[i]);
}
