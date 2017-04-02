/*
** player.c for corewar in /home/sahel/rendu/CPE/CPE_2016_corewar
** 
** Made by Sahel Lucas--Saoudi
** Login   <sahel.lucas-saoudi@epitech.eu>
** 
** Started on  Thu Mar 30 00:29:58 2017 Sahel Lucas--Saoudi
** Last update Sun Apr  2 02:13:11 2017 Sahel Lucas--Saoudi
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "op.h"
#include "vm.h"
#include "my.h"

char	*in_binary(unsigned char cb)
{
  char	*cb_b;
  int	i;

  i = 0;
  cb_b = malloc(MAX_ARGS_NUMBER * 2 + 1);
  if (!cb_b)
    return (NULL);
  while (i < MAX_ARGS_NUMBER * 2)
    cb_b[i++] = '0';
  cb_b[i] = '\0';
  i = 0;
  while (i < MAX_ARGS_NUMBER * 2)
    {
      if (cb - my_power_rec(2, MAX_ARGS_NUMBER * 2 - i - 1) >= 0)
	{
	  cb_b[i] = '1';
	  cb -= my_power_rec(2, MAX_ARGS_NUMBER * 2 - i - 1);
	}
      else
	cb_b[i] = '0';
      i++;
    }
  return (cb_b);
}

t_action	*get_action(t_player *player)
{
  t_action	*action;
  char		ac;
  char		cb;
  int		i;
  int		size;
  char		is_idx;
  char		*cb_b;
  int		arg[MAX_ARGS_NUMBER];

  cb = 0;
  is_idx = 0;
  size = COMMENT_LENGTH + PROG_NAME_LENGTH + 16;
  action = malloc(sizeof(t_action));
  lseek(player->fd, (!player->action) ? (size) :
	(size + player->action->pos + player->action->byte), SEEK_SET);
  size = read(player->fd, &ac, sizeof(char));
  if (size == 0)
    return (NULL);
  action->op = op_tab[ac - 1];
  action->cycle = action->op.nbr_cycles;
  action->byte = 1;
  if (ac != 1 && ac != 9 && ac != 12 && ac != 15)
    {
      read(player->fd, &cb, sizeof(char));
      action->byte++;
    }
  if (ac == 11 || ac == 9 || ac == 10 || ac == 12 || ac == 15)
    is_idx = 1;
  cb_b = NULL;
  i = 0;
  while (i < MAX_ARGS_NUMBER)
    arg[i++] = 0;
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
	  action->bytes[i] = size;
	  action->byte += size;
	  i++;
	}
    }
  else if (ac == 1)
    action->byte += DIR_SIZE;
  else if (ac == 9 || ac == 12 || ac == 15)
    action->byte += 2;
  else if (ac == 16)
    action->byte++;
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
  action->arg = arg;
  action->parra = NULL;
  return (action);
}

t_player	*set_player(t_game *game, char **av, int i)
{
  t_player	*player;
  static int	p = 1;
  int		tmp;

  player = malloc(sizeof(t_player));
  player->fd = open(av[i], O_RDONLY);
  if (!player || player->fd == -1)
    return (NULL);
  read(player->fd, &player->magic, sizeof(int));
  read(player->fd, &player->name, PROG_NAME_LENGTH);
  read(player->fd, &tmp, sizeof(int));
  read(player->fd, &player->prog_size, sizeof(int));
  read(player->fd, &player->comment, COMMENT_LENGTH);
  read(player->fd, &tmp, sizeof(int));
  player->magic = reverse_add(player->magic);
  player->prog_size = reverse_add(player->prog_size);
  player->carry = 1;
  player->live = 0;
  player->p = p;
  player->max_size = game->max_size;
  player->reg = init_register(player);
  if (!player->reg)
    return (NULL);
  p++;
  player->is_dead = 0;
  player->previous = NULL;
  player->next = NULL;
  player->action = NULL;
  player->action = get_action(player);
  return (player);
}

t_player	*init_player(t_game *game, char **av)
{
  t_player	*p1;
  int		i;
  int		prog_size;

  p1 = set_player(game, av, 1);
  if (!p1)
    return (NULL);
  prog_size = p1->prog_size;
  while (prog_size > 0)
    {
      printf("%i\n", game->max_size * (p1->p - 1) + prog_size);
      game->memory[game->max_size * (p1->p - 1) + prog_size] = p1->p + 48;
      prog_size--;
    }
  p1->next = NULL;
  p1->previous = NULL;
  i = 2;
  while (av[i])
    {
      p1->next = set_player(game, av, i);
      if (!p1->next)
	return (NULL);
      prog_size = p1->next->prog_size;
      while (prog_size > 0)
	{
	  game->memory[game->max_size * (p1->next->p - 1) + prog_size] = p1->next->p + 48;
	  prog_size--;
	}
      p1->next->previous = p1;
      i++;
      p1 = p1->next;
    }
  while (p1->previous)
    p1 = p1->previous;
  return (p1);
}
