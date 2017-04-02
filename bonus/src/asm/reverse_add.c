/*
** reverse_add.c for corewar in /home/desnosm/rendu/Progelem/CPE_2016_corewar/asm
**
** Made by maximilien desnos
** Login   <maximilien.desnos@epitech.eu>
**
** Started on  Tue Mar 28 12:01:16 2017 maximilien desnos
** Last update Tue Mar 28 13:10:15 2017 maximilien desnos
*/

unsigned int		reverse_add2(unsigned int i)
{
  unsigned short	tmp;
  char			*in;
  char			*out;
  int			j;

  in = (char *)&i;
  out = (char *)(&tmp + 1) - 1;
  j = sizeof(int);
  while (j > 0)
    {
      *out-- = *in++;
      j--;
    }
  return (tmp);
}

unsigned int		reverse_add(unsigned int i)
{
  unsigned int		tmp;
  char			*in;
  char			*out;
  int			j;

  in = (char *)&i;
  out = (char *)(&tmp + 1) - 1;
  j = sizeof(tmp);
  while (j > 0)
    {
      *out-- = *in++;
      j--;
    }
  return (tmp);
}
