/*
** add_m.c for corewar in /home/desnosm/rendu/Progelem/CPE_2016_corewar
**
** Made by maximilien desnos
** Login   <maximilien.desnos@epitech.eu>
**
** Started on  Fri Mar 31 19:59:16 2017 maximilien desnos
** Last update Sun Apr  2 02:53:38 2017 maximilien desnos
*/

#include	<sys/types.h>
#include	<unistd.h>
#include	"vm.h"

void		add_m(t_player *player, t_action *actual)
{
  char		i;
  char		j;
  char		k;

  (void)actual;
  lseek(player->fd, COMMENT_LENGTH + PROG_NAME_LENGTH + 16 +
	actual->pos + 1, SEEK_SET);
  read(player->fd, &i, sizeof(i));
  read(player->fd, &j, sizeof(j));
  read(player->fd, &k, sizeof(k));
  player->reg[(int)k] = player->reg[(int)j] + player->reg[(int)i];
  if (player->reg[(int)k] == 0)
    {
      if (player->carry == 0)
	player->carry = 1;
      else if (player->carry == 1)
	player->carry = 0;
    }
}
