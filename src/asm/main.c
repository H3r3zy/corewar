/*
** main.c for corewar in /home/tsuna/Epitech/projects/corewar/error_handling
** 
** Made by Martin Van Elslande
** Login   <martin.van-elslande@epitech.eu>
** 
** Started on  Thu Mar 23 19:23:53 2017 Martin Van Elslande
** Last update Sun Apr  2 11:17:53 2017 Martin Van Elslande
*/

#include	<unistd.h>
#include	<fcntl.h>
#include	<stdlib.h>
#include	"parse.h"
#include	"my.h"
#include	"my_string.h"
#include	"op.h"
#include	"get_next_line.h"

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

char		**read_file(int fd, t_label *label, int *name_and_com)
{
  t_buffer	buffer;
  int		size;
  char		**champ;
  int		idx;

  ini_gnl(&buffer);
  idx = 0;
  if ((size = my_filelen(fd)) == 0)
    return (NULL);
  lseek(fd, 0, SEEK_SET);
  if ((champ = malloc(sizeof(char *) * (size + 1))) == NULL)
    return (NULL);
  while ((champ[idx] = get_next_line(fd, &buffer)) != NULL)
    {
      if (my_strlen(champ[idx]) && nb_space(champ[idx]) !=
	  my_strlen(champ[idx]) && !line_is_comment(champ[idx]))
	{
	  if (!convert_and_check(champ[idx], idx, label, name_and_com))
	    return (NULL);
	  idx++;
	  champ[idx] = NULL;
	}
    }
  champ[idx] = NULL;
  return (champ);
}

int		take_fd_cor(char *path)
{
  char		*name;
  int		i;
  int		fd;

  i = 0;
  name = my_strdup(path);
  while (sp_len(name, '/') != my_strlen(name))
    name = without_before_(name, '/');
  name[my_strlen(name) - 1] = '\0';
  name = my_realloc_gnl(name, "cor", &i);
  fd = open(name, O_CREAT | O_WRONLY | O_TRUNC, 0644);
  return (fd);
}

int		main_next(int fl, char **fd)
{
  t_line	*op;
  header_t	*hd;

  op = malloc(sizeof(t_line));
  hd = malloc(sizeof(header_t));
  if (!op || !hd || fl == -1)
    return (84);
  op = recup_lines(op, fd, 0);
  recup_header(fd, hd);
  write_asm(op, hd, fl);
  close(fl);
  return (0);
}

int		main(int ac, char **av)
{
  int		fl;
  char		**fd;
  int		*name_and_com;

  if ((name_and_com = malloc(sizeof(int) * 2)) == NULL)
    return (my_putstr(2, "Malloc error\n"));
  name_and_com[0] = 0;
  name_and_com[1] = 0;
  if (ac != 2 || my_strcmp(".s", &av[1][my_strlen(av[1]) - 2]))
    return (help(2, 84));
  else if (my_strcmp(av[1], "-h") == 0)
    return (help(1, 0));
  else if (REG_NUMBER > 255)
    return (my_putstr(2, "FAILED\nToo many registers\n"));
  else if (T_REG != 1 || T_DIR != 2 || T_IND != 4)
    return (my_putstr(2, "FAILED\nwrong args types\n"));
  else if ((fd = check_file(av[1], name_and_com)) == NULL)
    return (84);
  else if (name_and_com[0] != 1 || name_and_com[1] > 1)
    return (my_putstr(2, "Error with name or comment.\n"));
  fl = take_fd_cor(av[1]);
  if (main_next(fl, fd) == 84)
    return (84);
  return (my_putstr(1, "Compilation done [%s].\n", av[1]));
}
