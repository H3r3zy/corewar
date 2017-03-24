/*
** verif_line.c for verif_line in /home/desnosm/rendu/Progelem/CPE_2016_corewar/asm/convert
**
** Made by Maximilien Desnos
** Login   <desnosm@epitech.net>
**
** Started on  Fri Mar 24 18:09:29 2017 Maximilien Desnos
** Last update Fri Mar 24 18:17:33 2017 Maximilien Desnos
*/

int		my_char_is_alphanum(char str)
{
  if ((str >= '0' && str <= '9') || (str >= 'a' && str <= 'z')
      || (str >= 'A' && str <= 'Z'))
    return (0);
  return (-1);
}

int		verif_line(char *str)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  if (str[0] == '#')
    return (-1);
  while (str[i] != '\0' )
    {
      if (my_char_is_alphanum(str[i]) == 0)
	j++;
      i++;
    }
  if (j == 0)
    return (-1);
  return (0);
}
