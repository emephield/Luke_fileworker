/*
** get_file.c for midnight in /home/keolas_s//test/systeme_unix/midnight/sources
** 
** Made by souvisay keolasy
** Login   <keolas_s@epitech.net>
** 
** Started on  Tue Nov 26 00:49:27 2013 souvisay keolasy
** Last update Fri Dec 13 07:59:05 2013 souvisay keolasy
*/

#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include "boolean.h"
#include "my_menu.h"
#include "tools.h"
#include "midnight.h"

t_item		**rec_fill_item(DIR *directory, char **src_path)
{
  static int	count = 0;
  struct dirent *file;
  t_item	**ret;
  t_item	*item;

  if ((file = readdir(directory)) != NULL)
    {
      count++;
      if ((ret = rec_fill_item(directory, src_path)) == NULL)
	return (NULL);
      if ((item = newitem(file->d_name, src_path)) == NULL)
	return (NULL);
      --count;
      ret[count] = item;
    }
  else
    {
      if ((ret = my_malloc((count + 1) * sizeof(*ret))) == NULL)
	return (NULL);
    }
  return (ret);
}

char		*creat_path(char **path)
{
  char		*ret;
  char		*temp;
  char		*temp2;
  int		i;

  i = 0;
  ret = NULL;
  while (path[i] != NULL)
    {
      if ((temp = my_stradd("/", path[i])) == NULL)
	return (NULL);
      if ((temp2 = my_stradd(ret, temp)) == NULL)
	return (NULL);
      free(temp);
      i++;
      if (ret != NULL)
	free(ret);
      ret = temp2;
    }
  if (i == 0)
    return ("/");
  return (ret);
}

t_item		**get_file(char **src_path)
{
  DIR		*directory;
  t_item	**ret;
  char		*path;

  if ((path = creat_path(src_path)) == NULL)
    return (FALSE);
  if (access(path, X_OK) != FALSE)
    return (NULL);
  if ((directory = opendir(path)) == NULL)
    return (NULL);
  if ((ret = rec_fill_item(directory, src_path)) == NULL)
    return (NULL);
  sort_item(ret);
  return (ret);
}
