/*
** take_bit.c for corewar in /home/sahel/rendu/CPE/CPE_2016_corewar/asm
** 
** Made by Sahel Lucas--Saoudi
** Login   <sahel.lucas-saoudi@epitech.eu>
** 
** Started on  Sat Mar 25 14:16:23 2017 Sahel Lucas--Saoudi
** Last update Sun Mar 26 14:49:49 2017 Sahel Lucas--Saoudi
*/

#include <stdlib.h>
#include "op.h"
#include "my.h"

void	set_byte(t_line *line)
{
  int	i;
  int	is_idx;

  line->byte = 1;
  i = 0;
  is_idx = 0;
  if (match(line->op.mnemonique, "sti"))
    is_idx = 1;
  if (!match(line->op.mnemonique, "live") && !match(line->op.mnemonique, "zjmp") &&
      !match(line->op.mnemonique, "fork") && !match(line->op.mnemonique, "lfork"))
    line->byte += 1;
  while (line->arg[i])
    {
      if (line->arg[i][0] == 'r')
	line->byte += 1;
      else if (match(line->arg[i], "%*"))
	line->byte += (is_idx == 0) ? (IND_SIZE) : (2);
      else if ((line->arg[i][0] >= '0' && line->arg[i][0] <= '9')
	  || line->arg[i][0] == '-')
	line->byte += (is_idx == 0) ? (DIR_SIZE) : (2);
      i++;
    }
}

int	main()
{
  t_line	*l;

  l = malloc(sizeof(t_line));
  l->arg = malloc(sizeof(char *) * (4));
  l->arg[0] = "r1";
  l->arg[1] = "%:live";
  l->arg[2] = "%1";
  l->arg[3] = NULL;
  l->op = op_tab[10];
  set_byte(l);
  printf("%d\n", l->byte);
}
