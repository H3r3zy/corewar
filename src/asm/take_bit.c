/*
** take_bit.c for corewar in /home/sahel/rendu/CPE/CPE_2016_corewar/asm
** 
** Made by Sahel Lucas--Saoudi
** Login   <sahel.lucas-saoudi@epitech.eu>
** 
** Started on  Sat Mar 25 14:16:23 2017 Sahel Lucas--Saoudi
** Last update Sun Apr  2 14:00:45 2017 Sahel Lucas--Saoudi
*/

#include <stdlib.h>
#include "op.h"
#include "my.h"

char	transfo(char coding_byte[MAX_ARGS_NUMBER * 2 + 1])
{
  char	i;
  char	dec;

  i = 0;
  dec = 0;
  while (i < MAX_ARGS_NUMBER * 2)
    {
      if (coding_byte[(int) i] == '1')
	dec += my_power_rec(2, MAX_ARGS_NUMBER * 2 - i - 1);
      i++;
    }
  return (dec);
}

int	tablen_(char **tab)
{
  int	len;

  len = 0;
  while (tab[len])
    len++;
  return (len);
}

void	set_byte_next(t_line *line, int *i, int *is_idx)
{
  line->bytes = 1;
  *i = 0;
  *is_idx = 0;
  line->have_cb = 0;
  if (line->op.code == 11 || line->op.code == 9 || line->op.code == 10 ||
      line->op.code == 12 || line->op.code == 15)
    *is_idx = 1;
  if (line->op.code != 1 && line->op.code != 9 && line->op.code != 12 &&
      line->op.code != 15)
    {
      line->bytes += 1;
      line->have_cb = 1;
    }
}

void	set_byte_next_next(t_line *line, char *coding_byte,
			   int i, int is_idx)
{
  if (i < tablen_(line->arg) && line->arg[i][0] == DIRECT_CHAR)
    {
      coding_byte[i * 2] = '1';
      coding_byte[i * 2 + 1] = '0';
      line->bytes += (is_idx == 0) ? (DIR_SIZE) : (2);
      line->byte[i] = (is_idx == 0) ? (DIR_SIZE) : (2);
    }
  else if (i < tablen_(line->arg))
    {
      coding_byte[i * 2] = '1';
      coding_byte[i * 2 + 1] = '1';
      line->bytes += (is_idx == 0) ? (IND_SIZE) : (2);
      line->byte[i] = (is_idx == 0) ? (IND_SIZE) : (2);
    }
  else
    {
      coding_byte[i * 2] = '0';
      coding_byte[i * 2 + 1] = '0';
      line->byte[i] = 0;
    }
}

void	set_byte(t_line *line)
{
  int	i;
  int	is_idx;
  char	*coding_byte;

  set_byte_next(line, &i, &is_idx);
  if ((coding_byte = malloc(MAX_ARGS_NUMBER * 2 + 1)) == NULL)
    exit(84);
  while (i < MAX_ARGS_NUMBER)
    {
      if (i < tablen_(line->arg) && line->arg[i][0] == 'r')
	{
	  coding_byte[i * 2] = '0';
	  coding_byte[i * 2 + 1] = '1';
	  line->bytes += 1;
	  line->byte[i] = 1;
	}
      else
	set_byte_next_next(line, coding_byte, i, is_idx);
      i++;
    }
  coding_byte[i * 2 - 1] = '\0';
  line->cb = transfo(coding_byte);
}
