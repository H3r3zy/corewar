/*
** music.c for  in /home/januar_m/delivery/PSU/PSU_2016_navy/bonus
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Sat Feb  4 02:40:46 2017 
** Last update Thu Mar 30 12:01:35 2017 Martin Januario
*/

#include	<SFML/System.h>
#include	<SFML/Audio.h>
#include	<unistd.h>
#include	"my.h"

sfMusic		*start_music(char *str)
{
  sfMusic	*music;

  music = sfMusic_createFromFile(str);
  if (!music)
    return (NULL);
  sfMusic_play(music);
  sfMusic_setLoop(music, sfTrue);
  return (music);
}

int		destroy_music(sfMusic *music)
{
  if (!music)
    return (1);
  sfMusic_destroy(music);
  return (1);
}
