/*
** parse_.c for  in /home/sahel/rendu/PSU/PSU_2016_minishell2
** 
** Made by Sahel
** Login   <sahel.lucas-saoudi@epitech.eu@epitech.net>
** 
** Started on  Mon Mar 13 14:22:34 2017 Sahel
** Last update Mon Mar 13 18:40:42 2017 Sahel
*/

#include <stdlib.h>
#include <unistd.h>
#include "main.h"
#include "basic.h"

static int	nb_word(char *str, char c)
{
  int		str_i;
  int		nb;

  str_i = 0;
  nb = 0;
  while (str[str_i])
    {
      nb++;
      while (str[str_i] && str[str_i] == c)
	str_i++;
      while (str[str_i] && str[str_i] != c)
	str_i++;
    }
  return (nb);
}

static char	*manage_str(char *str, int *str_i, char c)
{
  char		*new;
  int		new_i;

  new_i = 0;
  if (!(new = malloc(strlen_(str) + 1)))
    return (NULL);
  while (str[*str_i] && str[*str_i] == c)
    (*str_i)++;
  if (str[*str_i] && str[*str_i] == '\"')
    {
      (*str_i)++;
      while (str[*str_i] && str[*str_i] != '\"')
	new[new_i++] = str[(*str_i)++];
      (*str_i)++;
    }
  else
    while (str[*str_i] && str[*str_i] != c)
      new[new_i++] = str[(*str_i)++];
  new[new_i] = '\0';
  return (new);
}

char	**parse_(char *str, char c)
{
  char	**tab;
  int	tab_i;
  int	str_i;

  if (!str || !*str || !(tab = malloc(sizeof(char *) * (nb_word(str, c) + 10))))
    return (NULL);
  tab_i = 0;
  str_i = 0;
  while (str[str_i])
    {
      
      tab[tab_i] = manage_str(str, &str_i, c);
      if (!tab || !tab[tab_i] || !*tab[tab_i]);
      else
	tab_i++;
    }
  tab[tab_i] = NULL;
  return (tab);
}
