/*
** take_bit.c for corewar in /home/sahel/rendu/CPE/CPE_2016_corewar/asm
** 
** Made by Sahel Lucas--Saoudi
** Login   <sahel.lucas-saoudi@epitech.eu>
** 
** Started on  Sat Mar 25 14:16:23 2017 Sahel Lucas--Saoudi
** Last update Wed Mar 29 17:46:50 2017 Sahel Lucas--Saoudi
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

void	set_byte(t_line *line)
{
  int	i;
  int	is_idx;
  char	coding_byte[MAX_ARGS_NUMBER + 1];

  line->bytes = 1;
  i = 0;
  is_idx = 0;
  line->have_cb = 0;
  if (match(line->op.mnemonique, "sti") || match(line->op.mnemonique, "zjmp") ||
      match(line->op.mnemonique, "ldi") || match(line->op.mnemonique, "fork") ||
      match(line->op.mnemonique, "lldi") || match(line->op.mnemonique, "lfork"))
    is_idx = 1;
  if (!match(line->op.mnemonique, "live") && !match(line->op.mnemonique, "zjmp") &&
      !match(line->op.mnemonique, "fork") && !match(line->op.mnemonique, "lfork"))
    {
      line->bytes += 1;
      line->have_cb = 1;
    }
  while (i < MAX_ARGS_NUMBER)
    {
      if (i < tablen_(line->arg) && line->arg[i][0] == 'r') // Registre
	{
	  coding_byte[i * 2] = '0';
	  coding_byte[i * 2 + 1] = '1';
	  line->bytes += 1;
	  line->byte[i] = 1;
	}
      else if (i < tablen_(line->arg) && line->arg[i][0] == DIRECT_CHAR) // Direct
	{
	  coding_byte[i * 2] = '1';
	  coding_byte[i * 2 + 1] = '0';
	  line->bytes += (is_idx == 0) ? (DIR_SIZE) : (2);
	  line->byte[i] = (is_idx == 0) ? (DIR_SIZE) : (2);
	}
      else if (i < tablen_(line->arg)) // indirect
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
      i++;
    }
  
  coding_byte[i * 2 - 1] = '\0';
  line->cb = transfo(coding_byte);
}
