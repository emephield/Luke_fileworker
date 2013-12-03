/*
** newitem.c for midnight in /home/keolas_s//test/systeme_unix/midnight/sources
** 
** Made by souvisay keolasy
** Login   <keolas_s@epitech.net>
** 
** Started on  Fri Nov 22 22:04:36 2013 souvisay keolasy
** Last update Tue Nov 26 00:48:30 2013 souvisay keolasy
*/

#include "my_menu.h"
#include "tools.h"

t_item		*newitem(char *name)
{
  t_item	*item;

  if ((item = my_malloc(sizeof(*item))) == NULL)
    return (NULL);
  if ((item->name = my_strdup(name)) == NULL)
    return (NULL);
  return (item);
}
