/*
** my_str_to_wordtab.c for corewar in /home/tsuna/Epitech/projects/corewar/CPE_2016_corewar
** 
** Made by Martin Van Elslande
** Login   <martin.van-elslande@epitech.eu>
** 
** Started on  Sun Apr  2 04:32:10 2017 Martin Van Elslande
** Last update Sun Apr  2 05:39:18 2017 Martin Van Elslande
*/

#include	<stdlib.h>

int	char_isalphanum(char c)
{
  if ((c >= 'a' && c <= 'z') ||
      (c >= 'A' && c <= 'Z') ||
      (c >= '0' && c <= '9'))
    return (1);
  return (0);
}

int	count_words(char *str)
{
  int	i;
  int	nb_words;

  i = 0;
  nb_words = 0;
  while (str[i])
    {
      if (str[i] == '\"')
	{
	  i++;
	  while (str[i] && str[i] != '\"')
	    i++;
	  if (!str[i] || str[i + 1] > 32)
	    return (0);
	  nb_words++;
	}
      else if (str[i] > 32 && str[i + 1] <= 32)
	nb_words++;
      i++;
    }
  return (nb_words);
}

int	get_word_length(char *str)
{
  int	i;

  i = 0;
  if (str[i] == '\"')
    {
      i++;
      while (str[i] != '\"')
	i++;
      i--;
    }
  else
    while (str[i] > 32)
      i++;
  return (i);
}

void	my_strcpy_word(char *str, char *cpy)
{
  int	i;

  i = 0;
  if (str[i] == '\"')
    {
      i++;
      while (str[i] && str[i] != '\"')
	{
	  cpy[i - 1] = str[i];
	  i++;
	}
      cpy[i - 1] = 0;
    }
  else
    {
      while (str[i] && str[i] > 32)
	{
	  cpy[i] = str[i];
	  i++;
	}
      cpy[i] = 0;
    }
}

int	set_line(char *str, char **tab, int i, int j)
{
  int	wordlen;

  wordlen = get_word_length(&str[i]);
  tab[j] = malloc(sizeof(char) * (wordlen + 1));
  my_strcpy_word(&str[i], tab[j]);
  if (str[i] != '\"')
    i += wordlen + 1;
  else
    i += wordlen + 2;
  return (i);
}

char	**my_str_to_wordtab(char *str)
{
  int	i;
  int	j;
  int	nb_words;
  char	**tab;

  nb_words = count_words(str);
  if (nb_words == 0)
    return (NULL);
  tab = malloc(sizeof(char *) * (count_words(str) + 1));
  i = 0;
  j = 0;
  while (str[i])
    {
      while (str[i] && str[i] <= 32 && str[i] != '\"')
	i++;
      if (str[i])
	{
	  i = set_line(str, tab, i, j);
	  j++;
	}
    }
  tab[j] = NULL;
  return (tab);
}
