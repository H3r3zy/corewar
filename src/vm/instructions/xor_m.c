/*
** xor_m.c for corewar in /home/desnosm/rendu/Progelem/CPE_2016_corewar
**
** Made by maximilien desnos
** Login   <maximilien.desnos@epitech.eu>
**
** Started on  Sun Apr  2 04:13:09 2017 maximilien desnos
** Last update Sun Apr  2 06:30:32 2017 Martin Van Elslande
*/

static void	*recup_arg1(t_player *player, t_action *actual)
{
  int		j;

  if (actual->bytes[0] == 4)
    {
      read(player->fd, &j, sizeof(j));
      j = reverse_add(j);
    }
  else
    {
      (char)j;
      read(player->fd, &j, sizeof(j));
    }
  return (j);
}

static void	verif_carry(t_player *player, int k)
{
  if (player->reg[k] == 0)
    {
      if (player->carry == 0)
	player->carry = 1;
      else if (player->carry == 1)
	player->carry = 0;
    }
}

void		xor_m(t_player *player, t_action *actual)
{
  char		i;
  int		j;
  int		k;

  lseek(player->fd, COMMENT_LENGTH + PROG_NAME_LENGTH + 16 + actual->pos + 2,
	SEEK_SET);
  j = recup_arg1(player, actual);
  if (actual->bytes[0] != 4)
    (char)j;
  if (actual->bytes[1] == 4)
    {
      read(player->fd, &k, sizeof(k));
      k = reverse_add(k);
    }
  else
    {
      (char)i;
      read(player->fd, &k, sizeof(k));
    }
  read(player->fd, &i, sizeof(i));
  player->reg[i] = player->reg[j] ^ player->reg[k];
  verif_carry(player, i);
}