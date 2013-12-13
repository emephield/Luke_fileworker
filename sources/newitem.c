/*
** newitem.c for midnight in /home/keolas_s//test/systeme_unix/midnight/sources
** 
** Made by souvisay keolasy
** Login   <keolas_s@epitech.net>
** 
** Started on  Fri Nov 22 22:04:36 2013 souvisay keolasy
** Last update Thu Dec 12 18:11:10 2013 souvisay keolasy
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "midnight.h"
#include "my_menu.h"
#include "tools.h"

t_item		*newitem(char *name, char **src_path)
{
  t_item	*item;
  char		*temp;

  if ((item = my_malloc(sizeof(*item))) == NULL)
    return (NULL);
  if ((item->name = my_strdup(name)) == NULL)
    return (NULL);
  item->pwd = src_path;
  temp = creat_path(src_path);
  temp = my_stradd(temp, "/");
  temp = my_stradd(temp, name);
  if (stat(temp, &item->s_stat) == -1)
    {
      
    }
  free(temp);
  return (item);
}
