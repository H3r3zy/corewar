/*
** check_command.c for  in /home/januar_m/delivery/CPE/CPE_2016_corewar/martin
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Sat Mar 25 11:05:25 2017 Martin Januario
** Last update Sun Mar 26 22:38:45 2017 Martin Januario
*/

#include	<stdlib.h>
#include	"my_string.h"
#include	"parse.h"
#include	"op.h"

int		my_len_space(char *str)
{
  int		idx;
  int		result;

  idx = 0;
  result = 0;
    while (str[idx] != '\0')
      {
	if (str[idx] != ' ' && str[idx] != '\t')
	  result++;
	idx++;
      }
  return (result);
}

char		*epur_command(char *str)
{
  char		*new;
  int		idx;
  int		idx2;

  idx = 0;
  idx2 = 0;
  if ((new = malloc(my_len_space(str) + 1)) == NULL)
    return (NULL);
  while (str[idx] != '\0')
    {
      if (str[idx] != ' ' && str[idx] != '\t')
	{
	  new[idx2] = str[idx];
	  idx2++;
	}
      idx++;
    }
  new[idx2] = '\0';
  return (new);
}

int		id_command(char *str, int nb_line, int i, t_label *label)
{
  char		**arg;
  char		*new;
  int		idx;

  idx = 0;
  (void) nb_line;
  if ((new = epur_command(str)) == NULL)
    return (0);
  if ((arg = parse_(new, SEPARATOR_CHAR)) == NULL)
    return (0);
  if (my_tablen(arg) != op_tab[i].nbr_args)
    return (0);
  while (arg[idx] != NULL && idx < op_tab[i].nbr_args)
    {
      if (op_tab[i].type[idx] == 0)
	return (0);
      if (check_type(arg, i, idx, label) == 0)
	return (0);
      idx++;
    } 
  return (1);
}

int		nb_space(char *str)
{
  int		idx;

  idx = 0;
  while (str[idx] != '\0')
    {
      if (str[idx] != ' ' && str[idx] != '\t')
	return (idx);
      idx++;
    }
  return (idx);
}

int		check_command(char *str, int nb_line,
			      t_label *label)
{
  char		**tmp;
  char		*new;
  int		idx;

  idx = 0;
  if ((tmp = my_str_to_wordtab(str)) == NULL ||
      my_tablen(tmp) == 0)
    return (0);
  while (op_tab[idx].mnemonique != NULL)
    {
      if (my_strcmp(tmp[0], op_tab[idx].mnemonique) == 0)
	return (id_command(&str[my_strlen(tmp[0]) + nb_space(str)], nb_line, idx, label));
      idx++;
    }
  if ((new = epur_command(str)) == NULL)
    return (0);
  if (new[my_strlen(new) - 1] == LABEL_CHAR)
    return (add_label(label, new));
  free_tab(tmp);
  return (0);
}
