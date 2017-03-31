/*
** my_put_pixel.c for  in /home/januar_m/delivery/PSU/PSU_2016_navy/bonus
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Wed Feb  1 21:07:03 2017 
** Last update Wed Feb  1 21:07:04 2017 
*/

#include	<SFML/Graphics/RenderWindow.h>
#include	<SFML/Graphics/Texture.h>
#include	<SFML/Graphics/Sprite.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	"framefuffer.h"
#include	"my.h"

void	my_put_pixel(t_my_framebuffer *frame_buffer, int x, int y,
		     sfColor color)
{
  if (x >= 0 && y >= 0 && x < frame_buffer->width && y < frame_buffer->height)
    {
      frame_buffer->pixels[(frame_buffer->width * y + x) * 4] = color.r;
      frame_buffer->pixels[(frame_buffer->width * y + x) * 4 + 1] = color.g;
      frame_buffer->pixels[(frame_buffer->width * y + x) * 4 + 2] = color.b;
      frame_buffer->pixels[(frame_buffer->width * y + x) * 4 + 3] = color.a;
    }
}
