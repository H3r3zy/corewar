/*
** st_m.c for corewar in /home/desnos_m/rendu/Progelem/CPE_2016_corewar
**
** Made by maximilien desnos
** Login   <desnos_m@epitech.net>
**
** Started on  Sun Apr  2 12:18:27 2017 maximilien desnos
** Last update Sun Apr  2 14:34:09 2017 Sahel Lucas--Saoudi
*/

#include	<sys/types.h>
#include	<unistd.h>
#include	"vm.h"

void		st_m(t_player *player, t_action *actual)
{
  char		i;
  int		k;

  lseek(player->fd, COMMENT_LENGTH + PROG_NAME_LENGTH + 16 + actual->pos + 2,
	SEEK_SET);
  read(player->fd, &i, sizeof(i));
  if (actual->bytes[0] == 4)
    read(player->fd, &k, sizeof(k));
  else
    {
      read(player->fd, &k, sizeof(k));
    }
  player->reg[(int)k] = player->reg[(int)i];
}
