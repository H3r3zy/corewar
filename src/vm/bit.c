/*
** bit.c for corewar in /home/sahel/rendu/CPE/CPE_2016_corewar
** 
** Made by Sahel Lucas--Saoudi
** Login   <sahel.lucas-saoudi@epitech.eu>
** 
** Started on  Sun Apr  2 14:18:02 2017 Sahel Lucas--Saoudi
** Last update Sun Apr  2 14:44:17 2017 Sahel Lucas--Saoudi
*/

#include "vm.h"

t_action	*set_pos_action(t_action *action, t_player *player)
{
  if (player->action)
    {
      action->pos = (player->action->pos + player->action->byte) %
	player->prog_size;
      action->pos_m = (player->action->pos_m + player->action->byte) %
	MEM_SIZE;
    }
  else
    {
      action->pos = 0;
      action->pos_m = player->max_size * (player->p - 1);
    }
  action->parra = NULL;
  return (action);
}

void	set_byte_action(t_action *action, char cb, int is_idx, int ac)
{
  int	i;
  int	size;
  char	*cb_b;

  i = 0;
  if (cb != 0)
    {
      cb_b = in_binary(cb);
      while (i < MAX_ARGS_NUMBER)
	{
	  size = 0;
	  if (cb_b[i * 2] == '0' && cb_b[i * 2 + 1] == '1')
	    size = 1;
	  else if (cb_b[i * 2] == '1' && cb_b[i * 2 + 1] == '0')
	    size = (is_idx == 0) ? (DIR_SIZE) : (2);
	  else if (cb_b[i * 2] == '1' && cb_b[i * 2 + 1] == '1')
	    size = (is_idx == 0) ? (IND_SIZE) : (2);
	  action->bytes[i++] = size;
	  action->byte += size;
	}
    }
  else if (ac == 9 || ac == 12 || ac == 15)
    action->byte += 2;
  else
    action->byte += (ac == 16) ? (1) : (DIR_SIZE);
}
