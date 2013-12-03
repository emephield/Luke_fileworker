/*
** get_file.c for midnight in /home/keolas_s//test/systeme_unix/midnight/sources
** 
** Made by souvisay keolasy
** Login   <keolas_s@epitech.net>
** 
** Started on  Tue Nov 26 00:49:27 2013 souvisay keolasy
** Last update Tue Nov 26 11:48:14 2013 souvisay keolasy
*/

#include <sys/types.h>
#include <dirent.h>
#include "boolean.h"
#include "my_menu.h"
#include "tools.h"
#include "midnight.h"

t_item		**rec_fill_item(DIR *directory)
{
  static int	count = 0;
  struct dirent *file;
  t_item	**ret;
  t_item	*item;

  if ((file = readdir(directory)) != NULL)
    {
      count++;
      if ((ret = rec_fill_item(directory)) == NULL)
	return (NULL);
      if ((item = newitem(file->d_name)) == NULL)
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

t_item		**get_file()
{
  DIR		*directory;
  t_item	**ret;

  if ((directory = opendir(".")) == NULL)
    return (NULL);
  if ((ret = rec_fill_item(directory)) == NULL)
    return (NULL);
  sort_item(ret);

  /* affichage */
  /* while (*ret != NULL) */
  /*   { */
  /*     printf("%s\n", (*ret)->name); */
  /*     ret++; */
  /*   } */
  /* affichage */

  return (ret);
}
