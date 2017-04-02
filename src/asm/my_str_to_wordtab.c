/*
** my_str_to_wordtab.c for corewar in /home/desnosm/rendu/Progelem/CPE_2016_corewar/asm
**
** Made by maximilien desnos
** Login   <maximilien.desnos@epitech.eu>
**
** Started on  Sat Mar 25 16:00:10 2017 maximilien desnos
** Last update Sun Apr  2 07:31:27 2017 Martin Januario
*/

#include	<stdlib.h>
#include	"op.h"
#include	"my_string.h"

int		count_space(char *str)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  if (str != NULL)
    while (str[i] != '\0')
      {
	if (str[i] == SEPARATOR_CHAR || str[i] == ' ' || str[i] == '\t')
	  {
	    while (str[i] && (str[i] == SEPARATOR_CHAR  || str[i] == ' ' ||
			      str[i] == '\t'))
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
  while (str[i] == SEPARATOR_CHAR || str[i] == ' ' || str[i] == '\t')
    i++;
  return (i);
}

int		add_word_tab(int i, char *str, char **tab, int j)
{
  int		size;

  size = 0;
  i = sin_space(i, str);
  while (str[i + size] != '\0' && str[i + size] != SEPARATOR_CHAR)
    size++;
  if ((tab[j] = malloc(sizeof(char) * (size + 1))) == NULL)
    exit(84);
  size = 0;
  while (str[i] != '\0' && str[i] != SEPARATOR_CHAR && str[i] != ' ' &&
	 str[i] != '\t')
    {
      tab[j][size] = str[i];
      i = i + 1;
      size++;
    }
  tab[j][size] = '\0';
  i = sin_space(i, str);
  return (i);
}

char		**my_str_to_arg(char *str)
{
  char		**tab;
  int		size;
  int		i;
  int		j;

  j = 0;
  i = 0;
  size = count_space(str) + 2; // A revoir
  str[sp_len(str, COMMENT_CHAR)] = '\0';
  if ((tab = malloc(sizeof(char *) * (size + 1))) == NULL)
    exit(84);
  if (str != NULL)
    while (i < my_strlen(str) && str[i] != '\0')
      {
	i = add_word_tab(i, str, tab, j);
	j++;
      }
  tab[j] = NULL;
  return (tab);
}
