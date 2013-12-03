/*
** my_memset.c for tools in /home/keolas_s//test/prog_elem/magic21/tools
** 
** Made by souvisay keolasy
** Login   <keolas_s@epitech.net>
** 
** Started on  Sat Sep 28 15:57:55 2013 souvisay keolasy
** Last update Sat Sep 28 16:03:42 2013 souvisay keolasy
*/

#include <stdio.h>

void	*my_memset(void *s, char c, int n)
{
  int	i;
  char	*temp;

  i = 0;
  if (n <= 0 || !s)
    return (NULL);
  temp = s;
  while (i < n)
    {
      temp[i] = c;
      i++;
    }
  return (s);
}
