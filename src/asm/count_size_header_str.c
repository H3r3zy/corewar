/*
** count_size_header_str.c for count_size_header_str in /home/desnosm/rendu/Progelem/CPE_2016_corewar/asm
**
** Made by Maximilien Desnos
** Login   <desnosm@epitech.net>
**
** Started on  Fri Mar 24 20:01:18 2017 Maximilien Desnos
** Last update Sun Apr  2 02:23:36 2017 Sahel Lucas--Saoudi
*/

#include	<stdlib.h>
#include	"op.h"

int		recup_pos_name(char **tab, int z, int j, char *tmp)
{
  int		i;

  i = 0;
  while (tmp[j] != '\0' && tab[z] != NULL)
    {
      j = 0;
      while (tab[z] && tab[z][i] != '\0' && tab[z][i] != tmp[0])
	{
	  while (tab[z][i] != tmp[0] && tab[z][i] != '\0')
	    i++;
	  if (tab[z][i] == '\0' && tab[z + 1])
	    {
	      i = 0;
	      z++;
	    }
	}
      while (tab[z][i] == tmp[j])
	{
	  i++;
	  j++;
	}
      if (tmp[j] != '\0')
	{
	  i = 0;
	  z++;
	}
    }
  return (z);
}

int		recup_pos_comment(char **tab)
{
  int		i;
  int		j;
  char		*tmp;

  i = 0;
  j = 0;
  tmp = COMMENT_CMD_STRING;
  while (tab[1][i] != '.')
    i++;
  while (tab[1][i] == tmp[j])
    {
      i++;
      j++;
    }
  if (tmp[j] == '\0')
    return (0);
  return (1);
}

int		count_size_header_str(char *str)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (str[i] != '"')
    i++;
  i++;
  while (str[i] != '\0')
    {
      i++;
      j++;
    }
  return (j);
}
