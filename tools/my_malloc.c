/*
** my_malloc.c for magic21 in /home/keolas_s//test/prog_elem/magic21
** 
** Made by souvisay keolasy
** Login   <keolas_s@epitech.net>
** 
** Started on  Tue Sep 24 13:09:40 2013 souvisay keolasy
** Last update Wed Oct 16 13:05:12 2013 souvisay keolasy
*/

#include <stdlib.h>
#include "my_errno.h"

void	*my_malloc(int size)
{
  void	*temp;
  char	*ret;
  int	i;

  temp = malloc(size);
  if (temp == NULL)
    {
      print_errno(ENOMEM);
      return (NULL);
    }
  ret = (char *) temp;
  i = 0;
  while (i < size)
    {
      ret[i] = '\0';
      i++;
    }
  return ((void *) ret);
}
