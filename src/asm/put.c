/*
** put.c for put in /home/desnosm/rendu/SystUnix/PSU_2016_minishell1
**
** Made by Maximilien Desnos
** Login   <desnosm@epitech.net>
**
** Started on  Wed Jan  4 14:38:20 2017 Maximilien Desnos
** Last update Fri Mar 24 18:47:33 2017 Sahel Lucas--Saoudi
*/

#include	<unistd.h>
#include	"my.h"

void		my_putchar(char c, int i)
{
  write(i, &c, 1);
}

void		my_putstr(char *str, int j)
{
  write(j, str, my_strlen(str));
}
