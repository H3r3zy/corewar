/*
** my_strlen.c for corewar in /home/sahel/rendu/CPE/CPE_2016_corewar
** 
** Made by Sahel Lucas--Saoudi
** Login   <sahel.lucas-saoudi@epitech.eu>
** 
** Started on  Wed Mar 29 13:24:10 2017 Sahel Lucas--Saoudi
** Last update Wed Mar 29 13:46:15 2017 Sahel Lucas--Saoudi
*/

#include	<stdlib.h>

int		sp_len(char *str, char c)
{
  int		l;

  l = 0;
  while (str && str[l] && str[l] != c)
    l++;
  return (l);
}

int		my_strlen(char *str)
{
  int		idx;

  idx = 0;
  if (str == NULL)
    return (0);
  while (str[idx] != '\0')
    idx++;
  return (idx);
}
