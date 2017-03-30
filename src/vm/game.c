/*
** game.c for corewar in /home/sahel/rendu/CPE/CPE_2016_corewar
** 
** Made by Sahel Lucas--Saoudi
** Login   <sahel.lucas-saoudi@epitech.eu>
** 
** Started on  Thu Mar 30 20:43:07 2017 Sahel Lucas--Saoudi
** Last update Thu Mar 30 21:34:45 2017 Sahel Lucas--Saoudi
*/

#include "vm.h"
#include "op.h"

void		change_action(t_player *player, int i)
{
  while (i > 0)
    {
      player->action = player->action->parra;
      i--;
    }
  player->action = get_action(player);
}

void		action_loop(t_player *player)
{
  t_action	*tmp;
  int		i;

  printf("\nTour joueur %i : %s\n", player->p, player->name);
  tmp = player->action;
  i = 0;
  while (tmp)
    {
      if (tmp->cycle == 0)
	{
	  //exec_action(player, i);
	  change_action(player, i);
	}
      else
	tmp->cycle--;
      printf("Action %i:\n\t|-> Function\t:%s\n\t|-> Cycle\t:%i\n", i, tmp->op.mnemonique, tmp->cycle);
      printf("\t|-> Byte\t:%i\n", tmp->byte);
      tmp = tmp->parra;
      i++;
    }
}

int	player_loop(t_player *player)
{
  int	dead;

  dead = 0;
  while (player)
    {
      if (player->is_dead)
	dead++;
      else
	{
	  action_loop(player);
	  
	}
      player = player->next;
    }
  return (dead);
}

void	start_game(t_game *game)
{
  while (game->end != game->nb_j - 1)
    {
      printf("\n####~~\n\tNEW CYCLE\n####~~\n");
      game->end = player_loop(game->player);
      
      usleep(50000);
    }
}
