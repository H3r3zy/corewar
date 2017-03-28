/*
** recup_file.c for recup_file in /home/desnosm/rendu/Progelem/CPE_2016_corewar/asm/convert
**
** Made by Maximilien Desnos
** Login   <desnosm@epitech.net>
**
** Started on  Fri Mar 24 17:20:31 2017 Maximilien Desnos
** Last update Tue Mar 28 13:17:58 2017 maximilien desnos
*/

#include	<unistd.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<stdlib.h>
#include	"get_next_line.h"
#include	"my.h"

static int	count_line(char *av)
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

static char	*verif_comment(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0' && str[i] != '/')
    {
      i++;
      if (str[i] == '/' && str[i + 1] != '/')
	i++;
    }
  str[i] = '\0';
  return (str);
}

static void	remp_tab(char *av, char **tab)
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
	  str = verif_comment(str);
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
