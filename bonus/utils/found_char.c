/*
** found_char.c for  in /home/januar_m/delivery/CPE/tmp/CPE_2016_corewar/martin
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Sun Mar 26 15:19:12 2017 Martin Januario
** Last update Sun Mar 26 15:20:22 2017 Martin Januario
*/

int		found_char(char *str, char car)
{
  int		idx;

  idx = 0;
  while (str[idx] != '\0')
    {
      if (str[idx] == car)
	return (1);
      idx++;
    }
  return (0);
}
