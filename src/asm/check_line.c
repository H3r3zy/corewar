/*
** check_line.c for  in /home/januar_m/delivery/CPE/CPE_2016_corewar/martin/error_handling
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Fri Mar 24 20:13:29 2017 Martin Januario
** Last update Thu Mar 30 13:33:59 2017 Martin Van Elslande
*/

#include	<stdlib.h>
#include	"op.h"
#include	"parse.h"
#include	"my_string.h"

int		name_comment(char *str, int nb_line, int *name_and_com)
{
  char		**tmp;

  if ((tmp = my_str_to_wordtab(str)) == NULL)
    return (0);
  if (my_tablen(tmp) != 2)
    return (free_tab(tmp));
  if (my_strcmp(tmp[0], NAME_CMD_STRING) &&
      my_strcmp(tmp[0], COMMENT_CMD_STRING))
    return (error_messages(4, nb_line));
  if (!my_strcmp(tmp[0], NAME_CMD_STRING))
    {
      if (my_strlen(tmp[1]) > PROG_NAME_LENGTH)
	return (error_messages(5, nb_line));
      name_and_com[0]++;
    }
  if (!my_strcmp(tmp[0], COMMENT_CMD_STRING))
    {
      if (my_strlen(tmp[1]) > COMMENT_LENGTH)
	return (error_messages(6, nb_line));
      name_and_com[1]++;
    }
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

int		check_line(char *line, int nb_line, t_label *label,
			   int *name_and_com)
{
  int		namelen;
  int		comlen;
  int		i;

  namelen = my_strlen(NAME_CMD_STRING);
  comlen = my_strlen(COMMENT_CMD_STRING);
  withdraw_comment(line);
  i = 0;
  while (line[i] && (line[i] == ' ' || line[i] == '\t'))
    i++;
  if (!line[i])
    return (1);
  if (my_strncmp(&line[i], NAME_CMD_STRING, namelen) ||
      my_strncmp(&line[i], COMMENT_CMD_STRING, comlen))
    return (name_comment(&line[i], nb_line, name_and_com));
  return (check_command(&line[i], nb_line, label));
}

int		convert_and_check(char *line, int nb_line, t_label *label,
				  int *name_and_com)
{
  char		**tab;
  int		i;

  i = 0;
  while (line[i] && (line[i] == ' ' || line[i] == '\t'))
    i++;
  while (line[i] && line[i] != ' ' && line[i] != '\t')
    i++;
  if (line[i - 1] && line[i - 1] == LABEL_CHAR)
    {
      if (!(tab = malloc(sizeof(char *) * 3)))
	return (0);
      tab[2] = 0;
      if (!(tab[0] = my_strndup(line, i)))
	return (0);
      while (line[i] && (line[i] == ' ' || line[i] == '\t'))
	i++;
      if (!(tab[1] = my_strdup(&line[i])))
	return (0);
      if (!check_line(tab[0], nb_line, label, name_and_com) ||
	  !check_line(tab[1], nb_line, label, name_and_com))
	return (0);
      return (1);
    }
  return (check_line(line, nb_line, label, name_and_com));
}
