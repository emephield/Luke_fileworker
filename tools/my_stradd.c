/*
** my_stradd.c for tools in /home/keolas_s//git/Luke_fileworker
** 
** Made by souvisay keolasy
** Login   <keolas_s@epitech.net>
** 
** Started on  Sun Dec  8 13:55:00 2013 souvisay keolasy
** Last update Sun Dec  8 13:55:12 2013 souvisay keolasy
*/

#include "tools.h"

char	*my_stradd(char *str1, char *str2)
{
  char	*ret;
  int	i;
  int	j;

  if (!(ret = my_malloc(my_strlen(str1) + my_strlen(str2) + 1)))
    return (ret);
  i = 0;
  while (str1 && str1[i] != '\0')
    {
      ret[i] = str1[i];
      i++;
    }
  j = 0;
  while (str2 && str2[j] != '\0')
    {
      ret[i + j] = str2[j];
      j++;
    }
  return (ret);
}
