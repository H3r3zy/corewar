/*
** type_all.c for  in /home/januar_m/delivery/CPE/tmp/CPE_2016_corewar/martin
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Sun Mar 26 15:04:37 2017 Martin Januario
** Last update Mon Mar 27 18:47:27 2017 Martin Januario
*/

#include	<stdlib.h>
#include	"op.h"
#include	"my_string.h"
#include	"parse.h"

int		check_type_ind(char *str, int nb_line)
{
  (void) nb_line;
  if (my_str_is_num(str) == 84)
    return (0);
  return (1);
}

int		check_type_dir(char *str, int nb_line, t_label *label)
{
  (void) nb_line;
  if (my_strlen(str) <= 1 || str[0] != '%')
    return (0);
  if (str[1] == LABEL_CHAR)
    return (check_label(&str[2], label));
  if (my_str_is_num(&str[1]) == 84)
    return (0);
  return (1);
}

int		check_type_reg(char *str, int nb_line)
{
  int		nb;

  nb = 0;
  (void) nb_line;
  if (my_strlen(str) <= 1 || str[0] != 'r')
    return (0);
  if (my_str_is_num(&str[1]) == 84)
    return (0);
  if ((nb = my_getnbr(&str[1])) <= 0)
    return (0);
  if (nb > REG_NUMBER)
    return (0);
  return (1);
}
