/*
** file.c for corewar in /home/tsuna/Epitech/projects/corewar/error_handling
** 
** Made by Martin Van Elslande
** Login   <martin.van-elslande@epitech.eu>
** 
** Started on  Fri Mar 24 19:06:59 2017 Martin Van Elslande
** Last update Sun Mar 26 22:02:55 2017 Martin Januario
*/

#include	<fcntl.h>
#include	<unistd.h>
#include	"utils.h"
#include	"parse.h"
#include	"my_string.h"

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
  int		nb;
  t_label       *label;

  nb = 0;
  if (NULL == (label = malloc(sizeof(t_label) * 1)))
    return (84);
  label->name =	NULL;
  label->here = 0;
  if (!check_folder(file))
    return (84);
  fd = open(file, O_RDONLY);
  if (fd == -1)
    return (my_putstr(2, "Error while opening the file.\n"));
  nb = read_file(fd, label);
  while (label->next != NULL)
    {
      if (label->here == 0 && label->name != NULL)
	return (84);
      label = label->next;
    }
  if (!nb)
    return (84);
  return (0);
}
