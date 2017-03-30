/*
** totab.c for corewar in /home/sahel/rendu/CPE/CPE_2016_corewar
** 
** Made by Sahel Lucas--Saoudi
** Login   <sahel.lucas-saoudi@epitech.eu>
** 
** Started on  Thu Mar 30 14:35:55 2017 Sahel Lucas--Saoudi
** Last update Thu Mar 30 14:44:24 2017 Sahel Lucas--Saoudi
*/

#include <stdlib.h>

char	**to_tab(char *str)
{
  char	**tab;
  int	tab_i;
  int	tab_i_i;
  int	str_i;

  tab_i = 0;
  str_i = 0;
  tab = malloc(sizeof(char *) * (strlen(str)));
  while (str[str_i])
    {
      tab_i_i = 0;
      tab[tab_i] = malloc(strlen(str));
      while (str[str_i] && (str[str_i] == ' ' || str[str_i] == '\t'))
	str_i++;
      if (str[str_i] == '\"')
	{
	  str_i++;
	  while (str[str_i] && str[str_i] != '\"')
	    tab[tab_i][tab_i_i++] = str[str_i++];
	  str_i++;
	}
      else
	while (str[str_i] && str[str_i] != ' ' && str[str_i] != '\t' && str[str_i] != '\"')
	  tab[tab_i][tab_i_i++] = str[str_i++];
      tab[tab_i][tab_i_i] = '\0';
      tab_i++;
    }
  tab[tab_i] = NULL;
  return (tab);
}
