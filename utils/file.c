/*
** file.c for corewar in /home/tsuna/Epitech/projects/corewar/error_handling
** 
** Made by Martin Van Elslande
** Login   <martin.van-elslande@epitech.eu>
** 
** Started on  Fri Mar 24 19:06:59 2017 Martin Van Elslande
** Last update Thu Mar 30 12:01:08 2017 Martin Van Elslande
*/

#include	<fcntl.h>
#include	<stdlib.h>
#include	<unistd.h>
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

int		check_file(char *file, int *name_and_com)
{
  int		fd;
  int		nb;
  t_label       *label;

  nb = 0;
  if (NULL == (label = malloc(sizeof(t_label) * 1)))
    return (84);
  label->name =	NULL;
  label->next = NULL;
  label->here = 0;
  if (!check_folder(file))
    return (84);
  fd = open(file, O_RDONLY);
  if (fd == -1)
    return (my_putstr(2, "Error while opening the file.\n"));
  nb = read_file(fd, label, name_and_com);
  if (!nb)
    return (84);
  while (label->next != NULL)
    {
      if (label->here == 0 && label->name != NULL)
	return (84);
      label = label->next;
    }
  if (!nb || (label->here == 0 && label->name != NULL))
    return (84);
  return (0);
}
