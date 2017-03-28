/*
** set_label.c for  in /home/sahel/rendu/CPE/CPE_2016_corewar/asm
** 
** Made by Sahel Lucas--Saoudi
** Login   <sahel.lucas-saoudi@epitech.eu>
** 
** Started on  Sun Mar 26 20:30:08 2017 Sahel Lucas--Saoudi
** Last update Tue Mar 28 11:18:46 2017 Sahel Lucas--Saoudi
*/

#include <unistd.h>
#include "op.h"
#include "my.h"

static void	set_label_bytes(t_line *actual, t_line *first, int arg)
{
  int		byte;
  int		label_line;
  int		i;

  byte = 0;
  while (first)
    {
      if (first->label && match(first->label, &actual->arg[arg][2]))
	{
	  label_line = first->line;
	  while (first->line != actual->line)
	    {
	      if (first->line < actual->line)
		{
		  if (first->exist)
		    byte -= first->bytes;
		  first = first->next;
		}
	      else
		{
		  if (first->exist)
		    byte += first->bytes;
		  first = first->previous;
		}
	    }
	  if (label_line <= actual->line)
	    {
	      i = 0;
	      byte -= (actual->have_cb) ? (1) : (0);
	      while (i < arg)
		{
		  byte -= actual->byte[i];
		  i++;
		}
	    }
	  else
	    {
	      i = arg + 1;
	      while (actual->arg[i])
		{
		  byte += actual->byte[i];
		  i++;
		}
	    }
	  actual->ret[arg] = byte;
	  return ;
	}
      first = first->next;
    }
}

static void	need_label(t_line *first, t_line *line)
{
  int		arg_i;

  arg_i = 0;
  if (line->exist)
    while (line->arg[arg_i])
      {
	if (line->arg[arg_i][0] == '%' && line->arg[arg_i][1] == ':')
	  set_label_bytes(line, first, arg_i);
	arg_i++;
      }
}

void		set_label(t_line *line)
{
  t_line	*tmp;

  tmp = line;
  while (tmp)
    {
      if (tmp->exist)
	need_label(line, tmp);
      tmp = tmp->next;
    }
}