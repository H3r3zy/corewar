/*
** vm.h for corewar in /home/sahel/rendu/CPE/CPE_2016_corewar
** 
** Made by Sahel Lucas--Saoudi
** Login   <sahel.lucas-saoudi@epitech.eu>
** 
** Started on  Thu Mar 30 00:03:13 2017 Sahel Lucas--Saoudi
** Last update Sun Apr  2 10:06:06 2017 Martin Januario
*/

#ifndef VM_H_
# define VM_H_

# include <SFML/Graphics.h>
# include "op.h"
# include "csfml.h"

typedef struct		s_action
{
  struct s_action	*parra;
  op_t			op;
  int			cycle;
  int			pos;
  int			pos_m;
  int			byte;
  int			bytes[MAX_ARGS_NUMBER];
  int			*arg;
}			t_action;

typedef struct		s_player
{
  struct s_player	*previous;
  struct s_player	*next;
  char		        p;
  char			is_dead;
  char			name[PROG_NAME_LENGTH + 1];
  char			comment[COMMENT_LENGTH + 1];
  int			max_size;
  int			magic;
  int			prog_size;
  int			carry;
  int			live;
  int			fd;
  int			*reg;
  t_action		*action;
}			t_player;

typedef struct		s_reg
{
  struct s_reg		*next;
  struct s_reg		*previous;
  int			value;
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

int		ini_window(t_game *, char *);
t_player	*init_player(t_game *, char **);
t_action	*get_action(t_player *);
int		*init_register(t_player *);
unsigned int	reverse_add2(unsigned int);
unsigned int	reverse_add(unsigned int);
void		start_game(t_game *, t_my_framebuffer *,
			   t_core_window *, sfVector2i);
void		live(t_player *, t_action *);
void		zjmp(t_player *, t_action *);

#endif /* !VM_H_ */
