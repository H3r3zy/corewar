/*
** main.c for corewar in /home/sahel/rendu/CPE/CPE_2016_corewar
** 
** Made by Sahel Lucas--Saoudi
** Login   <sahel.lucas-saoudi@epitech.eu>
** 
** Started on  Thu Mar 30 00:00:08 2017 Sahel Lucas--Saoudi
** Last update Thu Mar 30 00:29:45 2017 Sahel Lucas--Saoudi
*/

#include <stdlib.h>
#include "op.h"

char		*create_memory_map()
{
  char		*str;
  int		i;

  str = malloc(MEM_SIZE);
  if (!str)
    return (NULL);
  i = 0;
  while (i <= MEM_SIZE)
    str[i] = '0';
  return (str);
}

t_game		*init_game()
{
  t_game	*game;

  game = malloc(sizeof(t_game));
  if (!game)
    return (NULL);
  game->nb_live = 0;
  game->actual_cycle = 0;
  game->cycle_to_die = CYCLE_TO_DIE;
  game->cycle_delta = CYCLE_DELTA;
  game->memory = create_memory_map();
  if (!game->memory)
    return (NULL);
  game->player = NULL;
  return (game);
}

int		main(int ac, char **av)
{
  t_game	*game;
  
  if (ac != 3)
    return (84);
  game = init_game();
  init_player(game);
  return (0);
}
