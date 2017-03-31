/*
** my.h for  in /home/januar_m/delivery/CPE/CPE_2016_corewar/graph_vm
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Thu Mar 30 11:17:03 2017 Martin Januario
** Last update Thu Mar 30 21:04:57 2017 Martin Januario
*/

#ifndef MY_H_
# define MY_H_

# include	<SFML/Graphics/RenderWindow.h>
# include	<SFML/Graphics/Texture.h>
# include	<SFML/Graphics/Sprite.h>
# include	<SFML/Graphics/Color.h>
# include	<SFML/Audio.h>
# include	"framefuffer.h"

typedef struct		s_core_window
{
  sfRenderWindow	*window;
  sfTexture		*texture;
  sfSprite		*sprite;
}			t_core_window;

t_my_framebuffer	*my_framebuffer_create(int, int);
sfRenderWindow		*create_window(char *, int, int);
sfMusic			*start_music(char *);
int			destroy_music(sfMusic *);
void			creator_loop(t_my_framebuffer *, t_core_window *, char **,
				     sfVector2i);
int			ini_window(char **);
int			update_map(t_my_framebuffer *, char **, sfVector2i);
sfColor			c_white(void);
sfColor			c_red(void);
sfColor			c_blue(void);
sfColor			c_green(void);
sfColor			c_yellow(void);
//	TMP
char	**create_map(void);

#endif /* !MY_H_ */
