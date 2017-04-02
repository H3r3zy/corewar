/*
** my_putstr.c for  in /home/januar_m/delivery/CPE/CPE_2016_corewar/martin/error_handling/utils
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Fri Mar 24 19:34:31 2017 Martin Januario
** Last update Sat Mar 25 12:48:30 2017 Martin Van Elslande
*/

#include	<unistd.h>
#include	<stdarg.h>
#include	"my_string.h"

int		my_putstr(int out, char *str, ...)
{
  va_list	ap;
  int		i;
  char		*arg;

  va_start(ap, str);
  i = 0;
  while (str[i])
    {
      if (my_strncmp("%d", &str[i], 2))
	{
	  my_putnbr(va_arg(ap, int));
	  i++;
	}
      else if (my_strncmp("%s", &str[i], 2))
	{
	  arg = va_arg(ap, char *);
	  write(out, arg, my_strlen(arg));
	  i++;
	}
      else
	write(out, &str[i], 1);
      i++;
    }
  return ((out == 2) ? 84 : 0);
}
