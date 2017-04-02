/*
** creator_loop.c for  in /home/januar_m/delivery/PSU/PSU_2016_navy/bonus
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Thu Feb  2 12:40:43 2017 
** Last update Thu Mar 30 18:52:54 2017 Martin Januario
*/

#include	<SFML/Graphics/RenderWindow.h>
#include	<SFML/Graphics/Texture.h>
#include	<SFML/Graphics/Sprite.h>
#include	"framefuffer.h"
#include	"my.h"

void		creator_loop(t_my_framebuffer *buffer,
			     t_core_window *ns, char **map,
			     sfVector2i size)
{
  sfEvent	event;

  update_map(buffer, map, size);
  sfTexture_updateFromPixels(ns->texture, buffer->pixels,
			     buffer->width, buffer->height, 0, 0);
  while (sfRenderWindow_isOpen(ns->window))
    {
      sfRenderWindow_clear(ns->window, sfBlack);
      while (sfRenderWindow_pollEvent(ns->window, &event))
	{
	  if (event.type == sfEvtClosed ||
	      sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
	    sfRenderWindow_close(ns->window);
	}
      sfRenderWindow_drawSprite(ns->window, ns->sprite, NULL);
      sfRenderWindow_display(ns->window);
    }
  sfRenderWindow_destroy(ns->window);
}
