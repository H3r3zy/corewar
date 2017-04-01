/*
** my.h for  in /home/januar_m/delivery/CPE/CPE_2016_corewar/graph_vm
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Thu Mar 30 11:17:03 2017 Martin Januario
** Last update Fri Mar 31 18:15:02 2017 Sahel Lucas--Saoudi
*/

#ifndef CSFML_H_
# define CSFML_H_

# include	<SFML/Graphics/RenderWindow.h>
# include	<SFML/Graphics/Texture.h>
# include	<SFML/Graphics/Sprite.h>
# include	<SFML/Graphics/Color.h>
# include	<SFML/Audio.h>
# include	"framebuffer.h"
/*# include	"vm.h"*/

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
void			creator_loop(t_my_framebuffer *, t_core_window *, char *,
				     sfVector2i);
//int			ini_window(t_game *, char *);
int			update_map(t_my_framebuffer *, char *, sfVector2i);
sfColor			c_white(void);
sfColor			c_red(void);
sfColor			c_blue(void);
sfColor			c_green(void);
sfColor			c_yellow(void);
//	TMP
char	**create_map(char *);

#endif /* !CSFML_H_ */
