/*
** recup_header.c for recup_header in /home/desnosm/rendu/Progelem/CPE_2016_corewar/asm/convert
**
** Made by Maximilien Desnos
** Login   <desnosm@epitech.net>
**
** Started on  Fri Mar 24 18:29:45 2017 Maximilien Desnos
** Last update Wed Mar 29 13:20:40 2017 Sahel Lucas--Saoudi
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
  while (tab[i] != '.')
    i++;
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
  recup_str_header(tab[0], hd->prog_name);
  i = recup_pos_comment(tab);
  recup_str_header(tab[1], hd->comment);
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

void			remp_fd(header_t *hd, int fd, t_line *op)
{
  int			i;
  int			j;
  int			tmp;

  tmp = reverse_add(COREWAR_EXEC_MAGIC);
  i = my_strlen(hd->prog_name);
  write(fd, &tmp, sizeof(tmp));
  write(fd, hd->prog_name, i);
  while (i < 132)
    {
      write(fd, "\0", 1);
      i++;
    }
  j = my_strlen(hd->comment);
  tmp = reverse_add(op->nb_bytes_tot);
  write(fd, &tmp, sizeof(tmp));
  write(fd, hd->comment, j);
  while (j < 2052)
    {
      write(fd, "\0", 1);
      j++;
    }
}

void			recup_header(char **tab, header_t *hd)
{
  recup_name(tab, hd);
  name_file(hd->prog_name);
}
