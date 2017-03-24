/*
** main.c for corewar in /home/tsuna/Epitech/projects/corewar/error_handling
** 
** Made by Martin Van Elslande
** Login   <martin.van-elslande@epitech.eu>
** 
** Started on  Thu Mar 23 19:23:53 2017 Martin Van Elslande
** Last update Fri Mar 24 20:24:11 2017 Martin Januario
*/

#include	<unistd.h>
#include	<fcntl.h>
#include	"utils.h"
#include	"parse.h"
#include	"my_string.h"
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
  while ((str = get_nect_line(fd, &buffer)) != NULL)
    idx++;
  return (idx);
}

int		read_file(int fd)
{
  t_buffer	buffer;
  int		size;
  char		**champ;
  int		idx;

  ini_gnl(&buffer);
  idx = 0;
  if ((size = my_filelen(fd)) == 0)
    return (0);
  if ((champ = malloc(sizeof(char *) * (size + 1))) == NULL)
    return (1);
  while ((champ[idx] = get_next_line(fd, &buffer)) != NULL)
    {
      if (my_strlen(champ[idx]) != 0)
	{
	  if (!check_line(champ[idx], idx))
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
  if (ac != 2)
    return (help(2, 84));
  else if (my_strcmp(av[1], "-h"))
    return (help(1, 0));
  else
    check_file(av[1]);
  return (0);
}
