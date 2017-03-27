/*
** check_label.c for  in /home/januar_m/delivery/CPE/tmp/CPE_2016_corewar/martin
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Sun Mar 26 15:27:14 2017 Martin Januario
** Last update Mon Mar 27 18:47:59 2017 Martin Januario
*/

#include	<stdlib.h>
#include	"op.h"
#include	"my_string.h"
#include	"parse.h"

int		check_label(char *str, t_label *label)
{
  t_label	*tmp;
  int		idx;

  tmp = NULL;
  idx = 0;
  while (str[idx] != 0)
    {
      if (found_char(LABEL_CHARS, str[idx]) == 0)
	return (0);
      idx++;
    }
  while (label->next != NULL && my_strcmp(str, label->name) != 0)
    label = label->next;
  if (my_strcmp(str, label->name) == 0)
    return (1);
  if (NULL == (tmp = malloc(sizeof(t_label) * 1)))
    return (0);
  tmp->name = my_strdup(str);
  if (tmp->name == NULL)
    return (0);
  tmp->here = 0;
  return (1);
}
