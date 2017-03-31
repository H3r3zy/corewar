/*
** vm.h for corewar in /home/sahel/rendu/CPE/CPE_2016_corewar
** 
** Made by Sahel Lucas--Saoudi
** Login   <sahel.lucas-saoudi@epitech.eu>
** 
** Started on  Thu Mar 30 00:03:13 2017 Sahel Lucas--Saoudi
** Last update Fri Mar 31 00:24:59 2017 Sahel Lucas--Saoudi
*/

#ifndef VM_H_
# define VM_H_

# include "op.h"

typedef struct		s_action
{
  op_t			op;
  int			cycle;
  int			pos;
  int			pos_m;
  int			byte;
  int			*arg;
  struct s_action	*parra;
}			t_action;

typedef struct		s_player
{
  char		        p;
  char			is_dead;
  char			name[PROG_NAME_LENGTH + 1];
  char			comment[COMMENT_LENGTH + 1];
  int			magic;
  int			prog_size;
  int			carry;
  int			live;
  int			**champ;
  int			fd;
  struct s_player	*previous;
  struct s_player	*next;
  t_action		*action;
}			t_player;

typedef struct		s_reg
{
  int			value;
  struct s_reg		*next;
  struct s_reg		*previous;
}			t_reg;

typedef struct		s_game
{
  int			max_size;
  int			nb_live;
  int			actual_cycle;
  int			cycle_to_die;
  int			cycle_delta;
  char			*memory;
  t_player		*player;
  int			end;
  int			nb_j;
}			t_game;

t_player	*init_player(t_game *, char **);
t_action	*get_action(t_player *);
void		start_game(t_game *);

#endif /* !VM_H_ */
