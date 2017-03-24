/*
** recup_file.c for recup_file in /home/desnosm/rendu/Progelem/CPE_2016_corewar/asm/convert
**
** Made by Maximilien Desnos
** Login   <desnosm@epitech.net>
**
** Started on  Fri Mar 24 17:20:31 2017 Maximilien Desnos
** Last update Fri Mar 24 18:23:00 2017 Maximilien Desnos
*/

#include	<unistd.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<stdlib.h>
#include	"get_next_line.h"
#include	"my.h"

int		count_line(char *av)
{
  int		fd;
  char		buf[2];
  int		i;

  if ((fd = open(av, O_RDONLY)) == -1)
    exit(84);
  i = 0;
  while (read(fd, buf, 1) > 0)
    {
      if (buf[0] == '\n')
	i++;
    }
  close(fd);
  return (i);
}

void		remp_tab(char *av, char **tab)
{
  int		i;
  int		fd;
  char		*str;

  i = 0;
  if ((fd = open(av, O_RDONLY)) == -1)
    exit(84);
  while ((str = get_next_line(fd)) != NULL)
    {
      if (verif_line(str) == 0)
	{
	  tab[i] = my_strdup(str);
	  i++;
	}
      free(str);
    }
  tab[i] = NULL;
}

char		**recup_file(char *av)
{
  int		size;
  char		**tab;

  size = count_line(av);
  if (size == 0 || (tab = malloc(sizeof(char *) * (size + 1))) == NULL)
    exit(84);
  remp_tab(av, tab);
  return (tab);
}
