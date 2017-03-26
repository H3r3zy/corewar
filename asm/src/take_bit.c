/*
** take_bit.c for corewar in /home/sahel/rendu/CPE/CPE_2016_corewar/asm
** 
** Made by Sahel Lucas--Saoudi
** Login   <sahel.lucas-saoudi@epitech.eu>
** 
** Started on  Sat Mar 25 14:16:23 2017 Sahel Lucas--Saoudi
** Last update Sun Mar 26 18:19:20 2017 Sahel Lucas--Saoudi
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
      if (coding_byte[i] == 1)
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
      match(line->op.mnemonique, "lldi"))
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
	  coding_byte[i * 2] = 0;
	  coding_byte[i * 2 + 1] = 1;
	  line->bytes += 1;
	  line->byte[i] = 1;
	}
      else if (i < tablen_(line->arg) && match(line->arg[i], "%*")) // Direct
	{
	  coding_byte[i * 2] = 1;
	  coding_byte[i * 2 + 1] = 0;
	  line->bytes += (is_idx == 0) ? (DIR_SIZE) : (2);
	  line->byte[i] = (is_idx == 0) ? (DIR_SIZE) : (2);
	}
      else if (i < tablen_(line->arg) && ((line->arg[i][0] >= '0' && line->arg[i][0] <= '9')
				|| line->arg[i][0] == '-')) // indirect
	{
	  coding_byte[i * 2] = 1;
	  coding_byte[i * 2 + 1] = 1;
	  line->bytes += (is_idx == 0) ? (IND_SIZE) : (2);
	  line->byte[i] = (is_idx == 0) ? (IND_SIZE) : (2);
	}
      else
	{
	  coding_byte[i * 2] = 0;
	  coding_byte[i * 2 + 1] = 0;
	  line->byte[i] = 0;
	}
      //printf("%i\n", line->byte[i]);
      i++;
    }
  
  coding_byte[i * 2 - 1] = '\0';
  line->cb = transfo(coding_byte);
}
/*
int	main()
{
  t_line	*l;

  l = malloc(sizeof(t_line));
  l->arg = malloc(sizeof(char *) * (4));
  l->arg[0] = "r1";
  l->arg[1] = "%0";
  l->arg[2] = "r1";
  l->arg[3] = NULL;
  l->op = op_tab[5];
  set_byte(l);
  //printf("%d\n", l->byte);
  write(1, &l->op.code, sizeof(char));
  //write(1, "A", 1);
  if (l->have_cb == 1)
    write(1, &l->cb, sizeof(char));
}
*/
