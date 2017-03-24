/*
** gnl.c for gnl in /home/desnosm/rendu/Progelem/CPE_2016_getnextline
**
** Made by Maximilien Desnos
** Login   <desnosm@epitech.net>
**
** Started on  Tue Jan 17 12:01:16 2017 Maximilien Desnos
** Last update Tue Feb 14 15:34:35 2017 maximilien desnos
*/

#include        <unistd.h>
#include        <stdlib.h>
#include        <sys/types.h>
#include        <sys/stat.h>
#include        <fcntl.h>
#include        "get_next_line.h"

int		my_strleng(char *str, int b)
{
  int		i;

  i = 0;
  if (b == 0)
    return (0);
  while (str[i] != '\0')
    i++;
  return (i);
}

int		my_strcpy(char *d, char *str, int i)
{
  while (str[i] != '\0' && str[i] != '\n')
    {
      d[i] = str[i];
      i++;
    }
  return (i);
}

char		*my_realoc(char *str, char *ad, int *a, int *b)
{
  int		i;
  int		j;
  char		*d;

  i = my_strleng(str, *b);
  *b = *b + 1;
  if ((d = malloc(sizeof(char) * (my_strleng(ad, *b) + i + 2))) == NULL)
    return (NULL);
  *b = *b - 1;
  i = 0;
  j = 0;
  if (*b != 0)
    i = my_strcpy(d, str, i);
  while (ad != NULL && ad[j + *a] != '\0' && ad[j + *a] != '\n')
    {
      d[i + j] = ad[j + *a];
      j++;
    }
  *a = *a + j;
  free(str);
  d[i + j] = '\0';
  return (d);
}

char		*princ(char *str, int size, int fd, int *b)
{
  static char	buf[READ_SIZE + 1];
  static int	a = 0;

  if (a == 0 || buf[a] == '\0')
    {
      a = 0;
      if ((size = read(fd, buf, READ_SIZE)) <= 0)
	return (NULL);
      buf[size] = '\0';
    }
  while (buf[a] != '\n')
    {
      if (buf[a] == '\0')
	{
	  a = 0;
	  if ((size = read(fd, buf, READ_SIZE)) <= 0)
	    return (str);
	  buf[size] = '\0';
	}
      if (a > 0 || size > 0)
	str = my_realoc(str, buf, &a, &*b);
      *b = *b + 1;
    }
  a = a + 1;
  return (str);
}

char		*get_next_line(int fd)
{
  char		*str;
  int		size;
  static int	b;

  b = 0;
  if (fd < 0)
    {
      return (NULL);
    }
  size = 0;
  str = NULL;
  if ((str = malloc(sizeof(char) * (READ_SIZE + 1))) == NULL)
    return (NULL);
  str[0] = '\0';
  str = princ(str, size, fd, &b);
  return (str);
}
