/*
** my_str_to_wordtab.c for corewar in /home/desnosm/rendu/Progelem/CPE_2016_corewar/asm
**
** Made by maximilien desnos
** Login   <maximilien.desnos@epitech.eu>
**
** Started on  Sat Mar 25 16:00:10 2017 maximilien desnos
** Last update Sat Mar 25 16:02:17 2017 maximilien desnos
*/

#include	<stdlib.h>

int		count_space(char *str)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  if (str != NULL)
    while (str[i] != '\0')
      {
	if (str[i] == ',')
	  {
	    while (str[i] == ',')
	      i++;
	    j++;
	  }
	else
	  i++;
      }
  return (j);
}

int		sin_space(int i, char *str)
{
  while (str[i] == ',')
    i++;
  return (i);
}

int		add_word_tab(int i, char *str, char **tab, int j)
{
  int		size;

  size = 0;
  i = sin_space(i, str);
  while (str[i + size] != '\0' && str[i + size] != ',')
    size++;
  if ((tab[j] = malloc(sizeof(char) * (size + 1))) == NULL)
    exit(84);
  size = 0;
  while (str[i] != '\0' && str[i] != ',')
    {
      tab[j][size] = str[i];
      i = i + 1;
      size++;
    }
  tab[j][size] = '\0';
  i = sin_space(i, str);
  return (i);
}

char		**my_str_to_wordtab(char *str)
{
  char		**tab;
  int		size;
  int		i;
  int		j;

  j = 0;
  i = 0;
  size = count_space(str) + 2;
  if ((tab = malloc(sizeof(char *) * (size + 1))) == NULL)
    exit(84);
  if (str != NULL)
    while (str[i] != '\0')
      {
	i = add_word_tab(i, str, tab, j);
	j++;
      }
  tab[j] = NULL;
  return (tab);
}
