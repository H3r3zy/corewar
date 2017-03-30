/*
** player.c for corewar in /home/sahel/rendu/CPE/CPE_2016_corewar
** 
** Made by Sahel Lucas--Saoudi
** Login   <sahel.lucas-saoudi@epitech.eu>
** 
** Started on  Thu Mar 30 00:29:58 2017 Sahel Lucas--Saoudi
** Last update Thu Mar 30 00:48:29 2017 Sahel Lucas--Saoudi
*/

#include <stdlib.h>
#include "op.h"
#include "vm.h"

int		**get_champ(int fd)
{
  (void) fd; // recup le champ ici
}

t_player	set_player(char **av, int i)
{
  t_player	*player;
  static int	p = 1;
  int		fd;
  int		tmp;

  fd = open(av[i]);
  player = malloc(sizeof(t_player));
  if (!player || fd == -1)
    return (NULL);
  read(fd, &player->magic, sizeof(int));
  read(fd, &player->name, PROG_NAME_LENGTH);
  read(fd, &tmp, sizeof(int));
  read(fd, &player->prog_size, sizeof(int));
  read(fd, &player->comment, COMMENT_LENGTH);
  read(fd, &tmp, sizeof(int));
  player->carry = 1;
  player->live = 0;
  player->p = p;
  p++;
  player->is_dead = 0;
  player->champ = get_champ(fd);
  player->previous = NULL;
  player->next = NULL;
  player->a1 = NULL;
}

t_player	init_player(char **av)
{
  t_player	*p1;

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
      p1->next = NULL;
    }
  while (p1->previous)
    p1 = p1->previous;
  return (p1);
}
