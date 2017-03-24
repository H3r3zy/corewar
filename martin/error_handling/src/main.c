/*
** main.c for corewar in /home/tsuna/Epitech/projects/corewar/error_handling
** 
** Made by Martin Van Elslande
** Login   <martin.van-elslande@epitech.eu>
** 
** Started on  Thu Mar 23 19:23:53 2017 Martin Van Elslande
** Last update Fri Mar 24 19:13:01 2017 Martin Van Elslande
*/

#include	<unistd.h>
#include	<fcntl.h>
#include	"utils.h"
#include	"parse.h"

int	help(int out, int ret)
{
  my_putstr(out, "USAGE\n");
  my_putstr(out, "\t./asm file_name[.s]\n\n");
  my_putstr(out, "DESCRIPTION\n");
  my_putstr(out, "\tfile_name\tfile in assembly language to be converted ");
  my_putstr(out, "into file_name.cor, an executable in the Virtual Machine).\n"
	    );
  return (ret);
}

int	check_line(char *line)
{
  int	i;

  i = 0;
  while (line[i] && line[i] != '#')
    {
      
    }
}

int	read_file(int fd)
{
  char	*line;

  while (line = get_next_line(fd))
    {
      if (!check_line(line))
	return (my_putstr(2, "MESSAGE A MODIFIER\n"));
      
    }
}

int	main(int ac, char **av)
{
  if (ac != 2)
    return (help(2, 84));
  else if (my_strcmp(av[1], "-h"))
    return (help(1, 0));
  else
    check_file(av[1]);
  return (0);
}
