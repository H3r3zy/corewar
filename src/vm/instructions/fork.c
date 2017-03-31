/*
** fork.c for corewar in /home/desnosm/rendu/Progelem/CPE_2016_corewar
**
** Made by maximilien desnos
** Login   <maximilien.desnos@epitech.eu>
**
** Started on  Fri Mar 31 15:46:15 2017 maximilien desnos
** Last update Fri Mar 31 19:12:36 2017 maximilien desnos
*/

#include	<unistd.h>
#include	<sys/types.h>
#include	<stdlib.h>
#include	"op.h"
#include	"my.h"
#include	"vm.h"

void		fork_m(t_player *player, t_action *actual)
{
  t_action	*act2;
  short		byte;
  int		pos;
  int		tmp;

  if ((act2 = malloc(sizeof(t_action))) == NULL)
    exit(84);
  lseek(player->fd, COMMENT_LENGTH + PROG_NAME_LENGTH + 16 + actual->pos + 1, SEEK_SET);
  read(player->fd, &byte, sizeof(byte));
  byte = reverse_add2(byte);
  tmp = act2->pos_m;
  act2->pos_m = actual->pos_m + byte;
  pos = player->max_size * (player->p - 1) + act2->pos_m;
  if (pos > player->max_size * (player->p - 1) && pos < player->max_size * (player->p - 1) + player->prog_size)
    act2->pos = pos;
  else
    act2->pos = tmp;
}
