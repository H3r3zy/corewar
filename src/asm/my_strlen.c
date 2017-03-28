/*
** my_strlen.c for my_strlen in /home/desnosm/rendu/Progelem/CPE_2016_corewar/asm/convert
**
** Made by Maximilien Desnos
** Login   <desnosm@epitech.net>
**
** Started on  Fri Mar 24 15:57:54 2017 Maximilien Desnos
** Last update Fri Mar 24 15:58:15 2017 Maximilien Desnos
*/

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    {
      i++;
    }
  return (i);
}
