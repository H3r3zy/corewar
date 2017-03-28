/*
** my_putchar.c for corewar in /home/tsuna/Epitech/projects/corewar/CPE_2016_corewar/martin
** 
** Made by Martin Van Elslande
** Login   <martin.van-elslande@epitech.eu>
** 
** Started on  Fri Mar 24 21:47:03 2017 Martin Van Elslande
** Last update Fri Mar 24 21:47:20 2017 Martin Van Elslande
*/

#include	<unistd.h>

void		my_putchar(char c)
{
  write(1, &c, 1);
}
