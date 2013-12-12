/*
** my_is_in.c for tools in /home/keolas_s//git/Luke_fileworker/tools
** 
** Made by souvisay keolasy
** Login   <keolas_s@epitech.net>
** 
** Started on  Thu Dec  5 14:57:29 2013 souvisay keolasy
** Last update Thu Dec  5 15:01:49 2013 souvisay keolasy
*/

#include "boolean.h"

t_bool	my_is_in(const char c, const char *delim)
{
  int	i;

  i = 0;
  while (delim && delim[i] != '\0')
    {
      if (c == delim[i])
	return (TRUE);
      i++;
    }
  return (FALSE);
}
