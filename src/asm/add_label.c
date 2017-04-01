/*
** add_label.c for  in /home/januar_m/delivery/CPE/tmp/CPE_2016_corewar/martin
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Sun Mar 26 18:23:02 2017 Martin Januario
** Last update Sun Apr  2 00:15:20 2017 Martin Januario
*/

#include	<stdlib.h>
#include	"parse.h"
#include	"my_string.h"
#include	"op.h"

int		add_label(t_label *label, char *str)
{
  t_label	*new;
  char		*tmp;
  int		idx;

  new = NULL;
  idx = 0;
  while (idx < my_strlen(str) - 1)
    {
      if (found_char(LABEL_CHARS, str[idx]) == 0)
	return (0);
      idx++;
    }
  tmp = malloc(sizeof(char) * (my_strlen(str)));
  if (tmp == NULL)
    return (0);
  my_strncpy(tmp, str, my_strlen(str) - 1);
  while (label->next != NULL && my_strcmp(label->name, tmp) != 0)
    label = label->next;
  if (my_strcmp(label->name, tmp) == 0)
    {
      if (label->here == 1)
	return (0);
      label->here = 1;
      return (1);
    }
  while (label->next != NULL)
    label = label->next;
  if (NULL == (new = malloc(sizeof(t_label) * 1)))
    return (0);
  new->name = &tmp[0];
  new->here = 1;
  new->next = NULL;
  label->next = new;
  return (1);
}
