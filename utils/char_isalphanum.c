/*
** char_isalphanum.c for corewar in /home/tsuna/Epitech/projects/corewar/corewar_repo/CPE_2016_corewar
** 
** Made by Martin Van Elslande
** Login   <martin.van-elslande@epitech.eu>
** 
** Started on  Sun Apr  2 06:32:07 2017 Martin Van Elslande
** Last update Sun Apr  2 08:53:22 2017 Martin Januario
*/

int	char_isalphanum(char c)
{
  if ((c >= 'a' && c <= 'z') ||
      (c >= 'A' && c <= 'Z') ||
      (c >= '0' && c <= '9'))
    return (1);
  return (0);
}
