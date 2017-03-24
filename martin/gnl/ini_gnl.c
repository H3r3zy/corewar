/*
** ini_gnl.c for  in /home/januar_m/delivery/PSU/PSU_2016_minishell2
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Tue Mar 14 12:54:02 2017 
** Last update Fri Mar 24 19:58:07 2017 Martin Januario
*/

#include	"get_next_line.h"
#include	"my_string.h"

void		ini_gnl(t_buffer *news)
{
  news->buffer[0] = '\0';
  news->idx = 0;
  news->size = 0;
}
