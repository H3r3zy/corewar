/*
** player.c for corewar in /home/sahel/rendu/CPE/CPE_2016_corewar
** 
** Made by Sahel Lucas--Saoudi
** Login   <sahel.lucas-saoudi@epitech.eu>
** 
** Started on  Thu Mar 30 00:29:58 2017 Sahel Lucas--Saoudi
** Last update Thu Mar 30 21:31:10 2017 Sahel Lucas--Saoudi
*/

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
  char		is_idx;
  char		*cb_b;
  int		*arg[MAX_ARGS_NUMBER];
  
  cb = 0;
  is_idx = 0;
  action = malloc(sizeof(t_action));
  if (!player->action)
    lseek(player->fd, COMMENT_LENGTH + PROG_NAME_LENGTH + 16, SEEK_SET);
  else
    lseek(player->fd, COMMENT_LENGTH + PROG_NAME_LENGTH + 16 + player->action->pos + player->action->byte, SEEK_SET);
  read(player->fd, &ac, sizeof(char));
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
    {
      arg[i] = 0;
      i++;
    }
  i = 0;
  if (cb != 0)
    {
      cb_b = in_binary(cb);
      while (i < MAX_ARGS_NUMBER)
	{
	  if (cb_b[i * 2] == '0' && cb_b[i * 2 + 1] == '1')
	    {
	      read(player->fd, &arg[i], sizeof(char));
	      action->byte++;
	    }
	  else if (cb_b[i * 2] == '1' && cb_b[i * 2 + 1] == '0')
	    {
	      read(player->fd, &arg[i], (is_idx == 0) ? (DIR_SIZE) : (2));
	      action->byte += (is_idx == 0) ? (DIR_SIZE) : (2);
	    }
	  else if (cb_b[i * 2] == '1' && cb_b[i * 2 + 1] == '1')
	    {
	      read(player->fd, &arg[i], (is_idx == 0) ? (IND_SIZE) : (2));
	      action->byte += (is_idx == 0) ? (IND_SIZE) : (2);
	    }
	  i++;
	}
    }
  else if (ac == 1)
    {
      action->byte += DIR_SIZE;
      read(player->fd, &arg[0], DIR_SIZE);
    }
  else if (ac == 9)
    {
      action->byte += 2;
      read(player->fd, &arg[0], 2);
    }
  else if (ac == 12)
    {
      action->byte += 2;
      read(player->fd, &arg[0], 2);
    }
  else if (ac == 15)
    {
      action->byte += 2;
      read(player->fd, &arg[0], 2);
    }
  else if (ac == 16)
    {
      action->byte++;
      read(player->fd, &arg[0], 1);
    }
  if (player->action)
    {
      action->pos = player->action->pos + player->action->byte;
      action->pos_m = player->action->pos_m + player->action->byte; 
    }
  else
    {
      action->pos = 0;
      action->pos_m = 1024 * (player->p - 1);
    }
  action->parra = NULL;
  printf("Player %s\n|-> Action:\n", player->name);
  printf("\t|-> Pos C\t:%i\n", action->pos);
  printf("\t|-> Pos M\t:%i\n", action->pos_m);
  printf("\t|-> Cycle\t:%i\n", action->cycle);
  printf("\t|-> Byte\t:%u\n", action->byte);
  if (cb)
    printf("\t|-> Coding Byte\t:%i | %s\n", cb, cb_b);
  return (action);
}

t_player	*set_player(char **av, int i)
{
  t_player	*player;
  static int	p = 1;
  int		tmp;

  player = malloc(sizeof(t_player));
  player->fd = open(av[i], O_RDONLY);
  printf("Player : %s\n|-> fd : %i\n", av[i], player->fd);
  if (!player || player->fd == -1)
    return (NULL);
  read(player->fd, &player->magic, sizeof(int));
  read(player->fd, &player->name, PROG_NAME_LENGTH);
  read(player->fd, &tmp, sizeof(int));
  read(player->fd, &player->prog_size, sizeof(int));
  read(player->fd, &player->comment, COMMENT_LENGTH);
  read(player->fd, &tmp, sizeof(int));
  player->carry = 1;
  player->live = 0;
  player->p = p;
  p++;
  player->is_dead = 0;
  player->previous = NULL;
  player->next = NULL;
  player->action = NULL;
  player->action = get_action(player);
  return (player);
}

t_player	*init_player(char **av)
{
  t_player	*p1;
  int		i;

  p1 = set_player(av, 1);
  if (!p1)
    return (NULL);
  p1->next = NULL;
  p1->previous = NULL;
  i = 2;
  while (av[i])
    {
      p1->next = set_player(av, i);
      if (!p1->next)
	return (NULL);
      p1->next->previous = p1;
      i++;
      p1 = p1->next;
    }
  while (p1->previous)
    p1 = p1->previous;
  return (p1);
}
