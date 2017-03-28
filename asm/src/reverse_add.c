/*
** reverse_add.c for corewar in /home/desnosm/rendu/Progelem/CPE_2016_corewar/asm
**
** Made by maximilien desnos
** Login   <maximilien.desnos@epitech.eu>
**
** Started on  Tue Mar 28 12:01:16 2017 maximilien desnos
** Last update Tue Mar 28 12:16:49 2017 maximilien desnos
*/

int		reverse_add(int i)
{
  int		tmp;
  char		*in;
  char		*out;
  int		j;

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
