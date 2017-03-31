/*
** live.c for corewar in /home/sahel/rendu/CPE/CPE_2016_corewar
** 
** Made by Sahel Lucas--Saoudi
** Login   <sahel.lucas-saoudi@epitech.eu>
** 
** Started on  Fri Mar 31 11:15:53 2017 Sahel Lucas--Saoudi
** Last update Fri Mar 31 11:22:46 2017 Sahel Lucas--Saoudi
*/

#include "vm.h"

void	live(t_player *player, t_action *actual)
{
  (void) actual;
  player->live++;
}
