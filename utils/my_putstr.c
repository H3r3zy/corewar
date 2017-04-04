/*
** my_putstr.c for corewar in /home/tsuna/Epitech/projects/minishell2/tests/PSU_2016_minishell1
** 
** Made by Martin Van Elslande
** Login   <martin.van-elslande@epitech.eu>
** 
** Started on  Tue Apr  4 21:09:19 2017 Martin Van Elslande
** Last update Tue Apr  4 21:09:21 2017 Martin Van Elslande
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
