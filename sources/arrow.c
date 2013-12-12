/*
** arrow.c for midnight in /home/keolas_s//git/Luke_fileworker
** 
** Made by souvisay keolasy
** Login   <keolas_s@epitech.net>
** 
** Started on  Thu Dec  5 16:20:14 2013 souvisay keolasy
** Last update Sun Dec  8 14:20:55 2013 souvisay keolasy
*/

#include <curses.h>
#include <stdlib.h>
#include "my_menu.h"
#include "midnight.h"
#include "boolean.h"

t_bool	arrow_up(t_menu *menu)
{
  if (menu->cur > 0)
    {
      if (menu->cur == menu->limit[0])
	{
	  menu->limit[0]--;
	  menu->limit[1]--;
	}
      menu->cur--;
    }
  return (TRUE);
}

t_bool	arrow_down(t_menu *menu)
{
  if (menu->list[menu->cur + 1] != NULL)
    {
      if (menu->cur == menu->limit[1] - 1)
	{
	  menu->limit[0]++;
	  menu->limit[1]++;
	}
      menu->cur++;
    }
  return (TRUE);
}

t_bool	arrow_left(t_menu *menu)
{
  int	i;

  i = 0;
  while (menu->path[i] != NULL)
    i++;
  if (i > 0)
    i--;
  free(menu->path[i]);
  menu->path[i] = NULL;
  if ((menu->list = get_file(menu->path)) == NULL)
    return (FALSE);
  clear_screen(menu);
  menu->cur = 0;
  menu->limit[0] = 0;
  menu->limit[1] = WHEIGHT - 6;
  return (TRUE);
}

