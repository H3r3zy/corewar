/*
** file.c for corewar in /home/tsuna/Epitech/projects/corewar/error_handling
** 
** Made by Martin Van Elslande
** Login   <martin.van-elslande@epitech.eu>
** 
** Started on  Fri Mar 24 19:06:59 2017 Martin Van Elslande
** Last update Fri Mar 24 19:11:40 2017 Martin Van Elslande
*/

#include	<fcntl.h>
#include	<unistd.h>
#include	"utils.h"
#include	"parse.h"

int		check_folder(char *file)
{
  int		fd;

  fd = open(file, O_DIRECTORY);
  if (fd != -1)
    {
      my_putstr(2, "You tried to compile a directory !\n");
      close(fd);
      return (0);
    }
  return (1);
}

int		check_file(char *file)
{
  int		fd;

  if (!check_folder(file))
    return (84);
  fd = open(file, O_RDONLY);
  if (fd == -1)
    return (my_putstr(2, "Error while opening the file.\n"));
  if (!read_file(fd))
    return (84);
  return (0);
}
