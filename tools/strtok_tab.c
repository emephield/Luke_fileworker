/*
** strtok_tab.c for tools in /home/keolas_s//git/Luke_fileworker/tools
** 
** Made by souvisay keolasy
** Login   <keolas_s@epitech.net>
** 
** Started on  Thu Dec  5 15:02:22 2013 souvisay keolasy
** Last update Thu Dec  5 16:04:58 2013 souvisay keolasy
*/

#include <stdio.h>
#include "tools.h"
#include "boolean.h"

static char	**recurs_strtok(char *str, char *delim, int wcount)
{
  int		i;
  int		j;
  char		**ret;

  j = 0;
  while (str[j] != '\0' && my_is_in(str[j], delim) == TRUE)
    j++;
  i = j;
  while (str[i] != '\0' && my_is_in(str[i], delim) == FALSE)
    i++;
  if (str[i] != '\0')
    ret = recurs_strtok(str + i + 1, delim, wcount + 1);
  else
    ret = my_malloc((wcount + 1) * sizeof(*ret));
  if (ret == NULL)
    return (NULL);
  if ((ret[wcount - 1] = my_strndup(str + j, i - j)) == NULL)
    return (NULL);
  return (ret);
}

char	**strtok_tab(char *str, char *delim)
{
  return (recurs_strtok(str, delim, 1));
}
