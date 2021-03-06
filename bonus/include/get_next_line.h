/*
** get_next_line.h for  in /home/januar_m/delivery/CPE/CPE_2016_matchstick
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Mon Feb 13 15:01:20 2017 
** Last update Fri Mar 24 19:59:53 2017 Martin Januario
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

# define	READ_SIZE (42)

typedef struct	s_buffer
{
  char		buffer[READ_SIZE + 1];
  int		idx;
  int		size;
}		t_buffer;

char		*get_next_line(int, t_buffer *);
void		ini_gnl(t_buffer *);

#endif /* !GET_NEXT_LINE_H_ */
