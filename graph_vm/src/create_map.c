/*
** create_map.c for  in /home/januar_m/delivery/CPE/CPE_2016_corewar/graph_vm
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Thu Mar 30 11:28:59 2017 Martin Januario
** Last update Thu Mar 30 22:43:34 2017 Martin Januario
*/

#include	<sys/stat.h>
#include	<fcntl.h>
#include	<unistd.h>
#include	<string.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	"get_next_line.h"
#include	"my.h"

char		**create_map(void)
{
  char		**map;
  char		*str;
  t_buffer	buffer;
  int		fd;
  int		idx;

  idx = 0;
  ini_gnl(&buffer);
  map = malloc(sizeof(char *) * 100);
  fd = open("./little_map.txt", O_RDONLY);
  while ((str = get_next_line(fd, &buffer)) != NULL)
    {
      map[idx] = strdup(str);
      free(str);
      idx++;
    }
  map[idx] = NULL;
  close(fd);
  return (map);
}
