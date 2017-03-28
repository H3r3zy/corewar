/*
** check_type.c for  in /home/januar_m/delivery/CPE/CPE_2016_corewar/martin
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Sat Mar 25 15:03:26 2017 Martin Januario
** Last update Sun Mar 26 22:34:09 2017 Martin Januario
*/

#include	<stdlib.h>
#include	"my_string.h"
#include	"op.h"
#include	"parse.h"

int		check_type(char **arg, int i,
			   int idx, t_label *label)
{
  int		save;
  int		cpt;

  save = op_tab[i].type[idx];
  cpt = 0;
  if (save - 4 >= 0)
    {
      if (check_type_ind(arg[idx], 0) == 1)
	cpt++;
      save -= 4;
    }
  if (save - 2 >= 0)
    {
      if (check_type_dir(arg[idx], 0, label) == 1)
	cpt++;
      save -= 2;
    }
  if (save - 1 >= 0)
    if (check_type_reg(arg[idx], 0) == 1)
      cpt++;
  return ((cpt != 0) ? 1 : 0);
}
