/*
** zjmp.c for corewar in /home/sahel/rendu/CPE/CPE_2016_corewar
** 
** Made by Sahel Lucas--Saoudi
** Login   <sahel.lucas-saoudi@epitech.eu>
** 
** Started on  Fri Mar 31 11:30:56 2017 Sahel Lucas--Saoudi
** Last update Sun Apr  2 02:10:51 2017 Sahel Lucas--Saoudi
*/

#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "vm.h"

void	zjmp(t_player *player, t_action *actual)
{
  short	byte;

  lseek(player->fd, COMMENT_LENGTH + PROG_NAME_LENGTH + 16 +
	actual->pos + 1, SEEK_SET);
  read(player->fd, &byte, sizeof(byte));
  byte = reverse_add2(byte);
  if (player->carry == 1)
    actual->byte = byte;
  (void) player;
}
