/*
** help.c for  in /home/januar_m/delivery/CPE/CPE_2016_corewar
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Sun Apr  2 08:17:45 2017 Martin Januario
** Last update Sun Apr  2 08:29:28 2017 Martin Januario
*/

#include	<stdlib.h>
#include	"my_string.h"
#include	"get_next_line.h"
#include	"my.h"

int		help(int out, int ret)
{
  my_putstr(out, "USAGE\n");
  my_putstr(out, "\t./asm file_name[.s]\n\n");
  my_putstr(out, "DESCRIPTION\n");
  my_putstr(out, "\tfile_name\tfile in assembly language to be converted ");
  my_putstr(out, "into file_name.cor, an executable in the Virtual Machine)");
  my_putstr(out, ".\n");
  return (ret);
}

int		my_filelen(int fd)
{
  char		*str;
  int		idx;

  idx = 1;
  while ((str = get_next_line_fd(fd)) != NULL)
    {
      free(str);
      idx++;
    }
  return (idx);
}
