/*
** main.c for corewar in /home/sahel/rendu/CPE/CPE_2016_corewar
** 
** Made by Sahel Lucas--Saoudi
** Login   <sahel.lucas-saoudi@epitech.eu>
** 
** Started on  Thu Mar 30 00:00:08 2017 Sahel Lucas--Saoudi
** Last update Fri Mar 31 00:30:02 2017 Sahel Lucas--Saoudi
*/

#include <stdlib.h>
#include "op.h"
#include "vm.h"

char		*create_memory_map()
{
  char		*str;
  int		i;

  str = malloc(MEM_SIZE + 2);
  if (!str)
    return (NULL);
  i = 0;
  while (i <= MEM_SIZE)
    {
      str[i] = '0';
      i++;
    }
  str[i] = '\0';
  return (str);
}

t_game		*init_game(char **av)
{
  t_game	*game;
  int		i;

  i = 0;
  while (av[i])
    i++;
  game = malloc(sizeof(t_game));
  if (!game)
    return (NULL);
  game->nb_live = 0;
  game->actual_cycle = 0;
  game->cycle_to_die = CYCLE_TO_DIE;
  game->cycle_delta = CYCLE_DELTA;
  game->max_size = MEM_SIZE / (i - 1);
  game->memory = create_memory_map();
  game->end = 0;
  if (!game->memory)
    return (NULL);
  game->player = NULL;
  return (game);
}

int		count_player(t_player *p)
{
  int		i;

  i = 0;
  while (p)
    {
      i++;
      p = p->next;
    }
  return (i);
}

int		main(int ac, char **av)
{
  t_game	*game;
  int		i;

  if (ac != 3)
    return (84);
  game = init_game(av);
  game->player = init_player(game, av);
  game->nb_j = count_player(game->player);
  start_game(game);
  return (0);
}
