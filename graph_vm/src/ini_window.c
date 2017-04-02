/*
** ini_window.c for  in /home/januar_m/delivery/PSU/PSU_2016_navy/bonus
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Wed Feb  1 22:13:46 2017 
** Last update Sun Apr  2 02:05:14 2017 Sahel Lucas--Saoudi
*/

#include		<stdlib.h>
#include		<math.h>
#include		"csfml.h"
#include		"op.h"
#include		"vm.h"

int			my_strlen(char *str)
{
  int			idx;

  idx = 0;
  if (str == NULL)
    return (0);
  while (str[idx] != '\0')
    idx++;
  return (idx);
}

int			my_tablen(char **map)
{
  int			idx;

  idx = 0;
  if (map == NULL)
    return (0);
  while (map[idx] != NULL)
    idx++;
  return (idx);
}

sfVector2i		size_win(sfVector2i size)
{
  sfVector2i		size_max;

  size_max.x = 1920 - size.x * 2;
  size_max.y = 1080 - size.y * 2;
  if (size_max.x % size.x != 0)
    size_max.x -= size_max.x % size.x;
  if (size_max.y % size.y != 0)
    size_max.y -= size_max.y % size.y;
  return (size_max);
}

int			ini_window(t_game *game, char *str)
{
  sfVector2i		size;
  t_core_window		needs;
  t_my_framebuffer	*buffer;
  int			tmp;
  sfEvent		event;

  size.x = sqrt(strlen(str));
  size.y = size.x;
  tmp = size.y;
  if (size.x == 0 || size.y == 0)
    return (0);
  size = size_win(size);
  if ((buffer = my_framebuffer_create(size.x, size.y)) == NULL ||
      (needs.window = create_window("VM Corewar", buffer->width,
				    buffer->height)) == NULL)
    return (84);
  size.x /= tmp;
  size.y /= tmp;
  sfRenderWindow_pollEvent(needs.window, &event);
  needs.sprite = sfSprite_create();
  needs.texture = sfTexture_create(buffer->width, buffer->height);
  sfSprite_setTexture(needs.sprite, needs.texture, sfTrue);
  start_game(game, buffer, &needs, size);
  return (0);
}
