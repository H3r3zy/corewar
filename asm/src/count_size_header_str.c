/*
** count_size_header_str.c for count_size_header_str in /home/desnosm/rendu/Progelem/CPE_2016_corewar/asm
**
** Made by Maximilien Desnos
** Login   <desnosm@epitech.net>
**
** Started on  Fri Mar 24 20:01:18 2017 Maximilien Desnos
** Last update Tue Mar 28 15:51:14 2017 maximilien desnos
*/

#include	"op.h"

int		recup_pos_name(char **tab)
{
  int                   i;
  int                   j;
  char                  *tmp;

  i = 0;
  j = 0;
  tmp = NAME_CMD_STRING;
  while (tab[0][i] != '.')
    i++;
  while (tab[0][i] == tmp[j])
    {
      i++;
      j++;
    }
  if (tmp[j] == '\0')
    return (0);
  return (1);
}

int		recup_pos_comment(char **tab)
{
  int                   i;
  int                   j;
  char                  *tmp;

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
