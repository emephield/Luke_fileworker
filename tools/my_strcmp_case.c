/*
** my_strcmp.c for tools.h in /home/keolas_s//test/prog_elem/magic21/tools
** 
** Made by souvisay keolasy
** Login   <keolas_s@epitech.net>
** 
** Started on  Wed Oct  9 16:17:05 2013 souvisay keolasy
** Last update Sat Nov 23 01:20:35 2013 souvisay keolasy
*/

int	my_strcmp_case(char *s1, char *s2)
{
  char	c1;
  char	c2;

  if (!s1)
    return (-1);
  if (!s2)
    return (1);
  if ((c1 = *s1) >= 'a' && c1 <= 'z')
    c1 -= 'a' - 'A';
  if ((c2 = *s2) >= 'a' && c2 <= 'z')
    c2 -= 'a' - 'A';
  if (c1 != '\0' && c2 != '\0' && c1 == c2)
    return (my_strcmp_case(s1 + 1, s2 + 1));
  return (c1 - c2);
}
