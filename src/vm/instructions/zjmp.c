/*
** zjmp.c for corewar in /home/sahel/rendu/CPE/CPE_2016_corewar
** 
** Made by Sahel Lucas--Saoudi
** Login   <sahel.lucas-saoudi@epitech.eu>
** 
** Started on  Fri Mar 31 11:30:56 2017 Sahel Lucas--Saoudi
** Last update Fri Mar 31 12:07:30 2017 Sahel Lucas--Saoudi
*/

#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "vm.h"

void	zjmp(t_player *player, t_action *actual)
{
  short	byte;
  lseek(player->fd, COMMENT_LENGTH + PROG_NAME_LENGTH + 16 + actual->pos + 1, SEEK_SET);
  read(player->fd, &byte, sizeof(byte));
  printf("AVANT %i\n", byte);
  byte = reverse_add2(byte);
  printf("APRES %i\n", byte);
  actual->byte = byte;
  printf("ACTUAL BYTE %i\n", actual->byte);
  (void) player;
}
