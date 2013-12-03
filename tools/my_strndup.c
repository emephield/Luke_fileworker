/*
** my_strndup.c for tool in /home/keolas_s//test/systeme_unix/explora/tools
** 
** Made by souvisay keolasy
** Login   <keolas_s@epitech.net>
** 
** Started on  Wed Oct 16 12:59:26 2013 souvisay keolasy
** Last update Wed Oct 16 13:06:45 2013 souvisay keolasy
*/

#include <stdio.h>
#include "tools.h"

char	*my_strndup(char *str, int len)
{
  char	*ret;
  int	i;

  if (!str)
    return (str);
  i = 0;
  if ((ret = my_malloc(sizeof(*ret) * (my_strlen(str) + 1))) == NULL)
    return (NULL);
  while (str[i] != '\0' && i < len)
    {
      ret[i] = str[i];
      i++;
    }
  return (ret);
}
