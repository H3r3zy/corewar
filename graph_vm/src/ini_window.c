/*
** ini_window.c for  in /home/januar_m/delivery/PSU/PSU_2016_navy/bonus
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Wed Feb  1 22:13:46 2017 
** Last update Thu Mar 30 21:41:04 2017 Martin Januario
*/

#include		<stdlib.h>
#include		"my.h"

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

  size_max.x = 1920 - size.x;
  size_max.y = 1080 - size.y;
  if (size_max.x % size.x != 0)
    size_max.x -= size_max.x % size.x;
  if (size_max.y % size.y != 0)
    size_max.y -= size_max.y % size.y;
  return (size_max);
}

int			ini_window(char **map)
{
  sfVector2i		size;
  t_core_window		needs;
  t_my_framebuffer	*buffer;
  sfEvent		event;

  size.x = my_strlen(map[0]);
  size.y = my_tablen(map);
  if (size.x == 0 || size.y == 0)
    return (0);
  size = size_win(size);
  printf("x: %d\ny: %d\n", size.x, size.y);
  if ((buffer = my_framebuffer_create(1920, 1080)) == NULL ||
      (needs.window = create_window("VM Corewar", buffer->width,
				    buffer->height)) == NULL)
    return (84);
  size.x /=  my_strlen(map[0]);
  size.y /= my_tablen(map);
  sfRenderWindow_pollEvent(needs.window, &event);
  needs.sprite = sfSprite_create();
  needs.texture = sfTexture_create(buffer->width, buffer->height);
  sfSprite_setTexture(needs.sprite, needs.texture, sfTrue);
  creator_loop(buffer, &needs, map, size);
  return (0);
}
