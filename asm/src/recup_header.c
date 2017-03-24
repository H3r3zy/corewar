/*
** recup_header.c for recup_header in /home/desnosm/rendu/Progelem/CPE_2016_corewar/asm/convert
**
** Made by Maximilien Desnos
** Login   <desnosm@epitech.net>
**
** Started on  Fri Mar 24 18:29:45 2017 Maximilien Desnos
** Last update Fri Mar 24 19:27:53 2017 Maximilien Desnos
*/

#include	"op.h"
#include	"my.h"



void		recup_header(char **tab, header_t *hd)
{
  char		*tmp;
  char		*magic;

  aff_tab(tab);
  tmp = my_nbr_to_str(COREWAR_EXEC_MAGIC);
  magic = convert_base(tmp, "0123456789", "0123456789ABCDEF");
  free(tmp);
}
