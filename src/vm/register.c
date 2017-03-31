/*
** register.c for corewar in /home/sahel/rendu/CPE/CPE_2016_corewar
** 
** Made by Sahel Lucas--Saoudi
** Login   <sahel.lucas-saoudi@epitech.eu>
** 
** Started on  Fri Mar 31 13:29:02 2017 Sahel Lucas--Saoudi
** Last update Fri Mar 31 13:37:42 2017 Sahel Lucas--Saoudi
*/

#include "vm.h"
#include "op.h"

int	*init_register(t_player *player)
{
  int	*reg;
  int	i;

  reg = malloc(sizeof(int) * (REG_NUMBER));
  if (!reg)
    return (NULL);
  i = 1;
  reg[0] = player->p;
  while (i < REG_NUMBER)
    {
      reg[i] = 0;
      i++;
    }
  return (reg);
}
