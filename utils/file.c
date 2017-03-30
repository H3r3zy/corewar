/*
** file.c for corewar in /home/tsuna/Epitech/projects/corewar/error_handling
** 
** Made by Martin Van Elslande
** Login   <martin.van-elslande@epitech.eu>
** 
** Started on  Fri Mar 24 19:06:59 2017 Martin Van Elslande
** Last update Thu Mar 30 15:35:51 2017 Sahel Lucas--Saoudi
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
  close(fd);
  return (1);
}

char		**check_file(char *file, int *name_and_com)
{
  char		**tmp;
  int		fd;
  t_label       *label;

  if (NULL == (label = malloc(sizeof(t_label) * 1)))
    return (NULL);
  label->name =	NULL;
  label->next = NULL;
  label->here = 0;
  if (!check_folder(file))
    return (NULL);
  fd = open(file, O_RDONLY);
  if (fd == -1)
    {
      my_putstr(2, "Error while opening the file.\n");
      return (NULL);
    }
  if ((tmp = read_file(fd, label, name_and_com)) == NULL)
    {
      close(fd);
      return (NULL);
    }
  while (label->next != NULL)
    {
      if (label->here == 0 && label->name != NULL)
	{
	  close(fd);
	  return (NULL);
	}
      label = label->next;
    }
  if ((label->here == 0 && label->name != NULL))
    {
      close(fd);
      return (NULL);
    }
  close(fd);
  return (tmp);
}
