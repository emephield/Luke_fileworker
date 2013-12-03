/*
** my_strcmp.c for tools.h in /home/keolas_s//test/prog_elem/magic21/tools
** 
** Made by souvisay keolasy
** Login   <keolas_s@epitech.net>
** 
** Started on  Wed Oct  9 16:17:05 2013 souvisay keolasy
** Last update Wed Oct 16 23:36:00 2013 souvisay keolasy
*/

int	my_strcmp(char *s1, char *s2)
{
  if (!s1)
    return (-1);
  if (!s2)
    return (1);
  if ((*s1) != '\0' && (*s2) != '\0' && *s1 == *s2)
    return (my_strcmp(s1 + 1, s2 + 1));
  return (*s1 - *s2);
}
