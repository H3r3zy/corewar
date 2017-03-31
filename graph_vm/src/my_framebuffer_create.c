/*
** my_framebuffer_create.c for  in /home/januar_m/delivery/PSU/PSU_2016_navy/bonus
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Wed Feb  1 21:07:26 2017 
** Last update Wed Feb  1 21:07:27 2017 
*/

#include	<SFML/Graphics/RenderWindow.h>
#include	<SFML/Graphics/Texture.h>
#include	<SFML/Graphics/Sprite.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	"framefuffer.h"

t_my_framebuffer	*my_framebuffer_create(int width, int height)
{
  t_my_framebuffer	*frame_buf;
  int			idx;

  idx = 0;
  if ((frame_buf = malloc(sizeof(t_my_framebuffer))) == NULL)
    return (NULL);
  frame_buf->width = width;
  frame_buf->height = height;
  if ((frame_buf->pixels =
       malloc(width * height * 4 * sizeof(frame_buf->pixels))) == NULL)
    return (NULL);
  while (idx < width * height * 4)
    {
      frame_buf->pixels[idx] = 0;
      idx++;
    }
  return (frame_buf);
}
