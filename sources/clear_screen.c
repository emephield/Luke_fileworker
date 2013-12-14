/*
** clear_screen.c for midnight in /home/keolas_s//git/Luke_fileworker
** 
** Made by souvisay keolasy
** Login   <keolas_s@epitech.net>
** 
** Started on  Sun Dec  8 14:04:25 2013 souvisay keolasy
** Last update Fri Dec 13 17:36:28 2013 souvisay keolasy
*/

#include <curses.h>
#include "my_menu.h"
#include "midnight.h"

int	field_clear(int start, int size, t_menu *menu, int line)
{
  int	i;

  i = 0;
  wmove(menu->win, line + FIRST_P, start);
  while (i < size)
    {
      waddch(menu->win, (chtype) ' ');
      i++;
    }
  return (i + 1);
}

void	clear_screen(t_menu *menu)
{
  int	i;
  int	j;

  i = 0;
  while (i < menu->limit[1] - menu->limit[0])
    {
      j = 0;
      j += field_clear(1 + j, RIGHT_WIDTH, menu, i);
      j += field_clear(1 + j, WWIDTH - (RIGHT_WIDTH + 1) -
		      (TIME_WIDTH + 1) - 2, menu, i);
      j += field_clear(1 + j, RIGHT_WIDTH, menu, i);
      i++;
    }
  mvprintw(LINES - 1, 0 , "\n");
}

