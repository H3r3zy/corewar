/*
** main.c for main in /home/desnosm/rendu/Progelem/CPE_2016_corewar/asm/convert
**
** Made by Maximilien Desnos
** Login   <desnosm@epitech.net>
**
** Started on  Fri Mar 24 17:11:31 2017 Maximilien Desnos
** Last update Fri Mar 24 19:23:01 2017 Maximilien Desnos
*/

#include	<stdlib.h>
#include	"my.h"
#include	"op.h"

int		main(int ac, char **av)
{
  char		**fd;
  header_t	*hd;

  if (ac > 1)
    fd = recup_file(av[1]);
  else
    exit(84);
  if ((hd = malloc(sizeof(header_t))) == NULL)
    exit(84);
  recup_header(fd, hd);
  return (0);
}