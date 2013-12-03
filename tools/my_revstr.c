/*
** my_revstr.c for tools in /home/keolas_s//test/prog_elem/new_korewar/tools
** 
** Made by souvisay keolasy
** Login   <keolas_s@epitech.net>
** 
** Started on  Sun Nov 17 12:08:01 2013 souvisay keolasy
** Last update Thu Nov 28 12:00:09 2013 souvisay keolasy
*/

#include "tools.h"

char	*my_revstr(char *str)
{
  int	i;
  int	len;
  int	temp;

  i = 0;
  len = my_strlen(str) - 1;
  if (!str)
    return (str);
  while (i < len - i)
    {
      temp = str[i];
      str[i] = str[len - i];
      str[len - i] = temp;
      i++;
    }
  return (str);
}

char	*my_revmem(char *str, int len)
{
  int	i;
  int	temp;

  i = 0;
  len--;
  if (!str)
    return (str);
  while (i < len - i)
    {
      temp = str[i];
      str[i] = str[len - i];
      str[len - i] = temp;
      i++;
    }
  return (str);
}
