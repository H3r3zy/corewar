/*
** create_map.c for  in /home/januar_m/delivery/CPE/CPE_2016_corewar/graph_vm
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Thu Mar 30 11:28:59 2017 Martin Januario
** Last update Fri Mar 31 12:29:47 2017 Martin Januario
*/

#include	<sys/stat.h>
#include	<fcntl.h>
#include	<unistd.h>
#include	<string.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	"get_next_line.h"
#include	"my.h"

char		**create_map(char *tmp)
{
  char		**map;
  char		*str;
  t_buffer	buffer;
  int		fd;
  int		idx;

  idx = 0;
  ini_gnl(&buffer);
  map = malloc(sizeof(char *) * 1000);
  fd = open(tmp, O_RDONLY);
  while ((str = get_next_line(fd, &buffer)) != NULL)
    {
      map[idx] = strdup(str);
      if (map[idx] == NULL)
	return (84);
      free(str);
      idx++;
    }
  map[idx] = NULL;
  close(fd);
  return (map);
}
