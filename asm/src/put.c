/*
** put.c for put in /home/desnosm/rendu/SystUnix/PSU_2016_minishell1
**
** Made by Maximilien Desnos
** Login   <desnosm@epitech.net>
**
** Started on  Wed Jan  4 14:38:20 2017 Maximilien Desnos
** Last update Thu Jan 19 18:27:46 2017 Maximilien Desnos
*/

#include	<unistd.h>

void		my_putchar(char c, int i)
{
  write(i, &c, 1);
}

void		my_putstr(char *str, int j)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i], j);
      i++;
    }
}
