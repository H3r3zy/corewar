/*
** recup_header.c for recup_header in /home/desnosm/rendu/Progelem/CPE_2016_corewar/asm/convert
**
** Made by Maximilien Desnos
** Login   <desnosm@epitech.net>
**
** Started on  Fri Mar 24 18:29:45 2017 Maximilien Desnos
** Last update Tue Mar 28 12:20:49 2017 maximilien desnos
*/

#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<stdio.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	"op.h"
#include	"my.h"

static void		recup_str_header(char *tab, char *name)
{
  int			i;
  int			j;

  i = 0;
  j = 0;
  while (tab[i] != '"')
    i++;
  i++;
  while (tab[i] != '"')
    {
      name[j] = tab[i];
      j++;
      i++;
    }
  name[j] = '\0';
}

static int     		recup_name(char **tab, header_t *hd)
{
  int			i;

  i = recup_pos_name(tab);
  recup_str_header(tab[i], hd->prog_name);
  return (i);
}

static char		*name_file(char *name)
{
  char			*nm_fl;
  int			i;
  int			j;
  char			*tmp;

  tmp = ".cor";
  i = 0;
  j = 0;
  if ((nm_fl = malloc(sizeof(char) * (my_strlen(name) + 5))) == NULL)
    exit(84);
  while (name[i] != '\0')
    {
      nm_fl[i] = name[i];
      i++;
    }
  while (tmp[j] != '\0')
    {
      nm_fl[i] = tmp[j];
      j++;
      i++;
    }
  nm_fl[i] = '\0';
  return (nm_fl);
}

static void		remp_fd(header_t *hd, int fd)
{
  int			i;
  int			j;

  i = my_strlen(hd->prog_name);
  write(fd, hd->prog_name, i);
  while (i < 128)
    {
      write(fd, "\0", 1);
      i++;
    }
  j = my_strlen(hd->comment);
  write(fd, hd->comment, j);
  while (j < 2048)
    {
      write(fd, "\0", 1);
      j++;
    }
}

int			recup_header(char **tab, header_t *hd)
{
  int		fd;
  char		*name;
  int		i;

  recup_name(tab, hd);
  i = COREWAR_EXEC_MAGIC;
  recup_str_header(tab[1], hd->comment);
  name = name_file(hd->prog_name);
  if ((fd = open(name, O_WRONLY| O_CREAT , 0644)) == -1)
    exit(84);
  write(fd, &i, sizeof(i));
  remp_fd(hd, fd);
  return (fd);
}
