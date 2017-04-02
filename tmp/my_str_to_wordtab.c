/*
** my_str_to_wordtab.c for  in /home/januar_m/delivery/CPE/CPE_2016_corewar/tmp
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Thu Mar 30 13:45:43 2017 Martin Januario
** Last update Sun Apr  2 02:03:29 2017 Sahel Lucas--Saoudi
*/

#include	<stdio.h>
#include	<string.h>
#include	<stdlib.h>

void		nb_words_next(char *str, int *idx, int *res)
{
  if (str[*idx] == ' ' || str[*idx] == '\t')
    {
      (*res)++;
      (*idx)++;
    }
  else
    (*idx)++;
}

int		nb_words(char *str)
{
  int		qt[2];
  int		idx;
  int		res;

  idx = 0;
  res = 0;
  qt[0] = 0;
  qt[1] = 0;
  while (str[idx] != '\0')
    {
      if (qt[0] == 0 && qt[1] == 0 && (str[idx] == ' ' || str[idx] == '\t'))
	while (str[idx] != '\0' && (str[idx] == ' ' || str[idx] == '\t'))
	  idx++;
      else if ((qt[1] == 0 && str[*idx] == '\"') || (qt[0] == 0 && str[*idx] == '\''))
	{
	  qt[(str[idx] == '\'') ? 1 : 0] =
	    (qt[(str[idx] == '\'') ? 1 : 0] + 1) % 2;
	  idx++;
	}
      else
	nb_words_next(str, &idx, &res);
    }
  return (res);
}

char		*give_me_word(char *str, int *idx)
{
  char		*res;
  int		cpt;
  int		qt[2];

  qt[0] = 0;
  qt[1] = 0;
  cpt = 0;
  if ((res = malloc(strlen(&str[*idx]) + 1)) == NULL)
    return (NULL);
  while (str[*idx] != '\0')
    {
      if (qt[0] == 0 && qt[1] == 0 && (str[*idx] == ' ' || str[*idx] == '\t'))
	{
	  while (str[*idx] != '\0' && (str[*idx] == ' ' || str[*idx] == '\t'))
	    (*idx)++;
	  res[cpt] = '\0';
	  return (res);
	}
      else if ((qt[1] == 0 && str[*idx] == '\"') || (qt[0] == 0 &&
						     str[*idx] == '\''))
	{
	  qt[(str[*idx] == '\'') ? 1 : 0] =
	    (qt[(str[*idx] == '\'') ? 1 : 0] + 1) % 2;
	  (*idx)++;
	}
      else
	res[cpt++] = str[(*idx)++];
    }
  res[cpt] = '\0';
  return (res);
}

char		**my_str_to_wordtab(char *str)
{
  char		**tab;
  int		nb;
  int		idx;
  int		idx2;

  tab = NULL;
  idx = 0;
  idx2 = 0;
  nb = nb_words(str);
  if ((tab = malloc(sizeof(char *) * (nb + 1))) == NULL)
    return (NULL);
  while (idx < nb)
    {
      if ((tab[idx] = give_me_word(str, &idx2)) == NULL)
	return (NULL);
      idx++;
    }
  tab[idx] = NULL;
  return (tab);
}
