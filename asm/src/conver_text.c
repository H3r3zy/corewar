/*
** main.c for convert_text in /home/desnosm/rendu/Progelem/CPE_2016_corewar/asm/convert
**
** Made by Maximilien Desnos
** Login   <desnosm@epitech.net>
**
** Started on  Fri Mar 24 17:03:34 2017 Maximilien Desnos
** Last update Fri Mar 24 20:22:34 2017 Maximilien Desnos
*/

#include	<stdlib.h>
#include	<my.h>

static char	*convert_char(char c, char *conv)
{
  int		i;
  int		j;
  int		ret;
  int		k;
  char		*base;

  base = "0123456789abcdef";
  j = 1;
  k = 0;
  while (j <= c)
    j = j * 16;
  i = my_strlen(conv);
  j = j / 16;
  while (k != 2)
    {
      ret = c / j;
      conv[i] = base[ret];
      k++;
      i++;
      c = c - (ret * j);
      j = j / 16;
    }
  conv[i] = '\0';
  return (conv);
}

char		*convert_text(char *str)
{
  char		*conv;
  int		i;

  if ((conv = malloc(sizeof(char) * (my_strlen(str) * 2 + 1))) == NULL)
    return (NULL);
  conv[0] = '\0';
  i = 0;
  while (str[i] != '\0')
    {
      conv = convert_char(str[i], conv);
      i++;
    }
  return (conv);
}
