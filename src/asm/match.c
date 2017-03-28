/*
** match.c for Match nMatch in /home/H3r3zy/rendu/CPool_match-nmatch
** 
** Made by Lucas Sahel
** Login   <H3r3zy@epitech.net>
** 
** Started on  Sun Oct 16 17:16:31 2016 Lucas Sahel
** Last update Tue Jan 17 21:21:55 2017 Sahel
*/

int	match(char *s1, char *s2)
{
  if (*s2 == '*')
    return ((*s1 == '\0') ? (match(s1, s2 + 1)) :
	    (match(s1 + 1, s2) || match(s1, s2 + 1)));
  if (*s1 == *s2)
    return ((*s1 == '\0') ? (1) : (match(s1 + 1, s2 + 1)));
  return (0);
}
