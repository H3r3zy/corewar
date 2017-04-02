/*
** update_map.c for  in /home/januar_m/delivery/CPE/CPE_2016_corewar/graph_vm
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Thu Mar 30 18:48:57 2017 Martin Januario
** Last update Sun Apr  2 11:11:33 2017 Martin Januario
*/

#include        <SFML/Graphics/RenderWindow.h>
#include        <SFML/Graphics/Texture.h>
#include        <SFML/Graphics/Sprite.h>
#include	<stdlib.h>
#include	"framebuffer.h"
#include	"csfml.h"
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

char		**my_str_to_wordmap(char *mem)
{
  char		**tab;
  int		nb;
  int		idx;
  int		tmp;

  idx = 0;
  tmp = 0;
  nb = my_square_root(my_strlen(mem));
  if ((tab = malloc(sizeof(char *) * (nb + 1))) == NULL)
    return (NULL);
  while (idx < nb)
    {
      tab[idx] = my_strndup(&mem[tmp], nb);
      tmp += nb;
      idx++;
    }
  tab[idx] = NULL;
  return (tab);
}

int		update_map(t_my_framebuffer *buffer, char *mem,
			   sfVector2i size)
{
  sfColor	color[5] = {sfWhite, sfRed, sfBlue, sfGreen, sfYellow};
  sfVector2i	idx;
  char		**map;
  sfVector2i	tmp;

  if ((map = my_str_to_wordmap(mem)) == NULL)
    return (84);
  idx.y = 0;
  tmp.y = 0;
  size.x--;
  size.y--;
  while (idx.y < 1080 && map[tmp.y] != NULL)
    {
      tmp.x = 0;
      idx.x = 0;
      while (idx.x < 1920 && map[tmp.y][tmp.x] != '\0')
	{
	  draw_square(buffer, idx, size, color[map[tmp.y][tmp.x] - '0']);
	  idx.x += size.x + 1;
	  tmp.x++;
	}
      tmp.y++;
      idx.y += size.y + 1;
    }
  return (0);
}
