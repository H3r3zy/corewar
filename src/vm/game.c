/*
** game.c for corewar in /home/sahel/rendu/CPE/CPE_2016_corewar
** 
** Made by Sahel Lucas--Saoudi
** Login   <sahel.lucas-saoudi@epitech.eu>
** 
** Started on  Thu Mar 30 20:43:07 2017 Sahel Lucas--Saoudi
** Last update Fri Mar 31 11:53:58 2017 Sahel Lucas--Saoudi
*/

#include <stdio.h>
#include "vm.h"
#include "op.h"

void		exec_action(t_player *player, int i)
{
  while (i > 0)
    {
      player->action = player->action->parra;
      i--;
    }
  if (player->action->op.code == 1)
    live(player, player->action);
  if (player->action->op.code == 9)
    zjmp(player, player->action);
}

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
	  exec_action(player, i);
	  change_action(player, i);
	  if (!player->action)
	    player->is_dead = 1;
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
      if (player->is_dead || !player->action)
	dead++;
      else
	action_loop(player);
      player = player->next;
    }
  return (dead);
}

void	start_game(t_game *game)
{
  int	cycle;

  cycle = 0;
  while (game->end < game->nb_j - 1)
    {
      printf("\n####~~\n\tNEW CYCLE\n####~~\n");
      game->end = player_loop(game->player);
      cycle++;
      /*update_map(buffer, game->memory, (sfVector2i) {79,79});
      sfTexture_updateFormPixels(ns->texture, buffer->pixels, buffer->width, buffer->height, 0, 0);
      sfRenderWindow_clear(ns->window, sfBlack);
      sfRenderWindow_drawSprite(ns->window, ns->sprite, NULL);
      sfRenderWindow_display(ns->window);*/
      //      usleep(50000);
    }
  //sfRednerWindow_destroy(ns->window);
  while (game->player && game->player->is_dead != 0)
    {
      game->player = game->player->next;
    }
  printf("%s\n", game->memory);
  if (!game->player)
    printf("EGALITE\n");
  else
    printf("## %i Cycles ##\nThe winner is the player %i:\n%s\nWith %i lives\n\"%s\"\n", cycle, game->player->p, game->player->name, game->player->live, game->player->comment);
}
