/*
** newmenu.c for midnight in /home/keolas_s//test/systeme_unix/midnight
** 
** Made by souvisay keolasy
** Login   <keolas_s@epitech.net>
** 
** Started on  Sat Nov 23 01:22:09 2013 souvisay keolasy
** Last update Sat Nov 23 01:29:27 2013 souvisay keolasy
*/

#include <stdio.h>
#include "tools.h"
#include "my_menu.h"

t_menu		*newnemu(t_item **items)
{
  t_menu	*ret;

  if ((ret = my_malloc(sizeof(*ret))) == NULL)
    return (NULL);
}
