/*
** my_bzero.c for magic21 in /home/keolas_s//test/prog_elem/magic21
** 
** Made by souvisay keolasy
** Login   <keolas_s@epitech.net>
** 
** Started on  Tue Sep 24 11:07:00 2013 souvisay keolasy
** Last update Wed Sep 25 09:03:23 2013 souvisay keolasy
*/

#include <stdio.h>

void	my_bzero(void *ptr, const int len)
{
  int	i;
  char	*temp;

  i = 0;
  temp = ptr;
  while (ptr != NULL && len > 0 && i < len)
    {
      temp[i] = '\0';
      i++;
    }
}
