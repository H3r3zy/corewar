/*
** check_line.c for  in /home/januar_m/delivery/CPE/CPE_2016_corewar/martin/error_handling
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Fri Mar 24 20:13:29 2017 Martin Januario
** Last update Sat Mar 25 11:19:50 2017 Martin Januario
*/

#include	<stdlib.h>
#include	"op.h"
#include	"parse.h"
#include	"my_string.h"

int		name_comment(char *str, int i)
{
  char		**tmp;

  if ((tmp = my_str_to_wordtab(str)) == NULL)
    return (0);
  if (my_tablen(tmp) != 2)
    return (free_tab(tmp));
  if (my_strcmp(tmp[0], (i == 0) ? NAME_CMD_STRING :
		COMMENT_CMD_STRING) != 0)
    return (free_tab(tmp));
  free_tab(tmp);
  return (1);
}

int		withdraw_comment(char *line)
{
  int		idx;

  idx = 0;
  while (line[idx] != '\0')
    {
      if (line[idx] == COMMENT_CHAR)
	{
	  line[idx] = '\0';
	  return (0);
	}
      idx++;
    }
  return (0);
}

int		check_line(char *line, int nb_line)
{
  withdraw_comment(line);
  if (nb_line <= 1)
    return (name_comment(line, nb_line));
  return (check_command(line, nb_line));
}
