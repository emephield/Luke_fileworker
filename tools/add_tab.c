/*
** add_tab.c for tools in /home/keolas_s//git/Luke_fileworker/tools
** 
** Made by souvisay keolasy
** Login   <keolas_s@epitech.net>
** 
** Started on  Thu Dec 12 13:22:21 2013 souvisay keolasy
** Last update Thu Dec 12 13:55:46 2013 souvisay keolasy
*/

#include	<stdio.h>
#include	"tools.h"

char	**add_tab(char *str, char **tab)
{
  char	**new_array;
  int	line;
  int	i;

  i = 0;
  line = 0;
  if (tab == NULL)
    return (NULL);
  while (tab[line] != NULL)
    line++;
  if ((new_array = my_malloc(sizeof(*new_array) * (line + 2))) == NULL)
    return (NULL);
  while (tab[i])
    {
      new_array[i] = my_strdup(tab[i]);
      i++;
    }
  new_array[i] = my_strdup(str);
  new_array[i + 1] = NULL;
  return (new_array);
}
