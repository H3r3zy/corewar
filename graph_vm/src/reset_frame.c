/*
** reset_frame.c for  in /home/januar_m/delivery/PSU/PSU_2016_navy/bonus
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Wed Feb  1 21:07:41 2017 
** Last update Wed Feb  1 21:07:47 2017 
*/

#include	<SFML/Graphics/RenderWindow.h>
#include	"framefuffer.h"
#include	"my.h"

void		reset_frame(t_my_framebuffer *pixel_buffer)
{
  int		idx;

  idx = 0;
  while (idx < pixel_buffer->height * pixel_buffer->width * 4)
    {
      pixel_buffer->pixels[idx] = 0;
      idx++;
    }
}
