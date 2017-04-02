/*
** ld_m.c for corewar in /home/desnos_m/rendu/Progelem/CPE_2016_corewar/corewar
**
** Made by maximilien desnos
** Login   <desnos_m@epitech.net>
**
** Started on  Sun Apr  2 10:45:49 2017 maximilien desnos
** Last update Sun Apr  2 12:19:01 2017 maximilien desnos
*/

#include	<sys/types.h>
#include	<unistd.h>
#include	"vm.h"

static void	verif_carry(t_player *player, int k)
{
  if (player->reg[k] == 0)
    {
      if (player->carry == 0)
	player->carry = 1;
      else if (player->carry == 1)
	player->carry = 0;
    }
}

void		ld_m(t_player *player, t_action *actual)
{
  char		i;
  int		j;
  int		k;

  lseek(player->fd, COMMENT_LENGTH + PROG_NAME_LENGTH + 16 + actual->pos + 2,
	SEEK_SET);
  if (actual->bytes[0] == 4)
    read(player->fd, &k, sizeof(k));
  else
    {
      read(player->fd, &k, sizeof(k));
    }
  read(player->fd, &i, sizeof(i));
  player->reg[(int)i] = player->reg[k];
  verif_carry(player, i);
}
