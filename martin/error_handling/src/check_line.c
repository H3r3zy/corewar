/*
** check_line.c for  in /home/januar_m/delivery/CPE/CPE_2016_corewar/martin/error_handling
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Fri Mar 24 20:13:29 2017 Martin Januario
** Last update Fri Mar 24 20:31:29 2017 Martin Januario
*/

#include	<stdlib.h>
#include	"op.h"
#include	"parse.h"

int		name_comment(char *str, int idx)
{
  char		**tmp;

  if ((tmp = my_str_to_wordtab(str)) == NULL)
    return (0);
  if (idx == 1)
    {
      if (match(str, ".name"))
    }
  return (1);
}

int		check_line(char *line, int nb_line)
{
  if (nb_line <= 1)
    return (name_comment(line, nb_line));
  return (1);
}
