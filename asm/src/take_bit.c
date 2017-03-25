/*
** take_bit.c for corewar in /home/sahel/rendu/CPE/CPE_2016_corewar/asm
** 
** Made by Sahel Lucas--Saoudi
** Login   <sahel.lucas-saoudi@epitech.eu>
** 
** Started on  Sat Mar 25 14:16:23 2017 Sahel Lucas--Saoudi
** Last update Sat Mar 25 15:12:28 2017 Sahel Lucas--Saoudi
*/

#include <stdlib.h>
#include "op.h"
#include "my.h"

void	set_byte(t_line *line)
{
  int	i;

  line->byte = 1;
  i = 0;
  while (line->arg[i])
    {
      if (line->arg[i][0] == 'r')
	line->byte += REG_SIZE;
      else if (match(line->arg[i], "%*"))
	line->byte += IND_SIZE;
      else if ((line->arg[i][0] >= '0' && line->arg[i][0] <= '9')
	  || line->arg[i][0] == '-')
	line->byte += DIR_SIZE;
      i++;
    }
}

int	main()
{
  t_line	*l;

  l = malloc(sizeof(t_line));
  l->arg = malloc(sizeof(char *) * (4));
  //l->arg[0] = "r1";
  l->arg[0] = "%:live";
  //l->arg[2] = "%1";
  l->arg[1] = NULL;
  l->op = op_tab[9];
  set_byte(l);
  printf("%d\n", l->byte);
}
