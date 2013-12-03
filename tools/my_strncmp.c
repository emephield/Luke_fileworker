/*
** my_strcmp.c for tools.h in /home/keolas_s//test/prog_elem/magic21/tools
** 
** Made by souvisay keolasy
** Login   <keolas_s@epitech.net>
** 
** Started on  Wed Oct  9 16:17:05 2013 souvisay keolasy
** Last update Thu Oct 17 18:47:04 2013 souvisay keolasy
*/

int	my_strncmp(char *s1, char *s2, int size)
{
  if (!s1)
    return (-1);
  if (!s2)
    return (1);
  if (size == 0)
    return (0);
  else if ((*s1) != '\0' && (*s2) != '\0' && *s1 == *s2)
    return (my_strncmp(s1 + 1, s2 + 1, size - 1));
  return (*s1 - *s2);
}
