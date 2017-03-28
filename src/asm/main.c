/*
** main.c for corewar in /home/tsuna/Epitech/projects/corewar/error_handling
** 
** Made by Martin Van Elslande
** Login   <martin.van-elslande@epitech.eu>
** 
** Started on  Thu Mar 23 19:23:53 2017 Martin Van Elslande
** Last update Tue Mar 28 15:36:40 2017 Sahel Lucas--Saoudi
*/

#include	<unistd.h>
#include	<fcntl.h>
#include	<stdlib.h>
#include	"utils.h"
#include	"parse.h"
#include	"my.h"
#include	"my_string.h"
#include	"op.h"
#include	"get_next_line.h"

int		help(int out, int ret)
{
  my_putstr(out, "USAGE\n");
  my_putstr(out, "\t./asm file_name[.s]\n\n");
  my_putstr(out, "DESCRIPTION\n");
  my_putstr(out, "\tfile_name\tfile in assembly language to be converted ");
  my_putstr(out, "into file_name.cor, an executable in the Virtual Machine).\n"
	    );
  return (ret);
}

int		my_filelen(int fd)
{
  t_buffer	buffer;
  char		*str;
  int		idx;

  idx = 0;
  ini_gnl(&buffer);
  while ((str = get_next_line(fd, &buffer)) != NULL)
    idx++;
  return (idx);
}

int		line_is_comment(char *str)
{
  int		idx;

  idx = 0;
  while (str[idx] != '\0' &&
	 str[idx] == '\t' && str[idx] == ' ')
    idx++;
  if (str[idx] == COMMENT_CHAR)
    return (1);
  return (0);
}

int		read_file(int fd, t_label *label)
{
  t_buffer	buffer;
  int		size;
  char		**champ;
  int		idx;

  ini_gnl(&buffer);
  idx = 0;
  if ((size = my_filelen(fd)) == 0)
    return (0);
  lseek(fd, 0, SEEK_SET);
  if ((champ = malloc(sizeof(char *) * (size + 1))) == NULL)
    return (1);
  while ((champ[idx] = get_next_line(fd, &buffer)) != NULL)
    {
      if (my_strlen(champ[idx]) && nb_space(champ[idx]) != my_strlen(champ[idx])
	  && !line_is_comment(champ[idx]))
	{
	  if (!convert_and_check(champ[idx], idx, label))
	    return (0);
	  idx++;
	  champ[idx] = NULL;
	}
    }
  champ[idx] = NULL;
  return (1);
}

int		main(int ac, char **av)
{
  int		fl;
  char		**fd;
  t_line	*op;
  header_t	*hd;
  
  if (ac != 2)
    return (help(2, 84));
  else if (my_strcmp(av[1], "-h") == 0)
    return (help(1, 0));
  else if (T_REG != 1 || T_DIR != 2 || T_IND != 4)
    return (my_putstr(2, "AHAHAHAHAHAHAHAHAHAH\n"));
  else if (check_file(av[1]) == 84)
    return (my_putstr(2, "ERROR IN CHAMPIONS.\n"));
  fd = recup_file(av[1]);
  op = malloc(sizeof(t_line));
  hd = malloc(sizeof(header_t));
  if (!op || !hd)
    return (84);
  op = recup_lines(op, fd);
  fl = recup_header(fd, hd);
  write_asm(op, hd, fl);
  return (0);
}
