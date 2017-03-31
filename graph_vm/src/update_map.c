/*
** update_map.c for  in /home/januar_m/delivery/CPE/CPE_2016_corewar/graph_vm
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Thu Mar 30 18:48:57 2017 Martin Januario
** Last update Fri Mar 31 10:49:49 2017 Martin Januario
*/

#include        <SFML/Graphics/RenderWindow.h>
#include        <SFML/Graphics/Texture.h>
#include        <SFML/Graphics/Sprite.h>
#include	<stdlib.h>
#include	"framefuffer.h"
#include	"my.h"

void		draw_square(t_my_framebuffer *buffer, sfVector2i from,
			    sfVector2i to, sfColor color)
{
  sfVector2i	save;

  save.y = from.y;
  while (save.y < to.y + from.y)
    {
      save.x = from.x;
      while (save.x < from.x + to.x)
	{
	  my_put_pixel(buffer, save.x, save.y, color);
	  save.x++;
	}
      save.y++;
    }  
}

int		update_map(t_my_framebuffer *buffer, char **map,
			   sfVector2i size)
{
  sfColor	(*color[5])(void) = {c_white, c_red, c_blue, c_green, c_yellow};
  sfVector2i	idx;
  sfVector2i	tmp;

  idx.y = 0;
  tmp.y = 0;
  size.x--;
  size.y--;
  printf("size:\nx: %d\ny: %d\n", size.x, size.y);
  while (idx.y < 1080 && map[tmp.y] != NULL)
    {
      tmp.x = 0;
      idx.x = 0;
      while (idx.x < 1920 && map[tmp.y][tmp.x] != '\0')
	{
	  draw_square(buffer, idx, size, color[map[tmp.y][tmp.x] - '0']());
	  idx.x += size.x + 1;
	  tmp.x++;
	}
      printf("width: %d\n", tmp.x);
      tmp.y++;
      idx.y += size.y + 1;
    }
  return (0);
}
