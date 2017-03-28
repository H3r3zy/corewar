/*
** main.c for main in /home/desnosm/rendu/Progelem/CPE_2016_corewar/asm/convert
**
** Made by Maximilien Desnos
** Login   <desnosm@epitech.net>
**
** Started on  Fri Mar 24 17:11:31 2017 Maximilien Desnos
** Last update Tue Mar 28 12:49:43 2017 maximilien desnos
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include	<stdlib.h>
#include	"my.h"
#include	"op.h"

int		main(int ac, char **av)
{
  char		**fd;
  header_t	*hd;
  t_line	*op;

  if (ac > 1)
    fd = recup_file(av[1]);
  else
    exit(84);
  if ((op = malloc(sizeof(t_line))) == NULL)
    exit(84);
  if ((hd = malloc(sizeof(header_t))) == NULL)
    exit(84);
  recup_lines(op, fd);
  recup_header(fd, hd);
  printf("%i", op->exist);
  /*  write_asm(op);*/
  return (0);
}
