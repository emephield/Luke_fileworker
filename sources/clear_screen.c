/*
** clear_screen.c for midnight in /home/keolas_s//git/Luke_fileworker
** 
** Made by souvisay keolasy
** Login   <keolas_s@epitech.net>
** 
** Started on  Sun Dec  8 14:04:25 2013 souvisay keolasy
** Last update Thu Dec 12 10:47:36 2013 souvisay keolasy
*/

#include <curses.h>
#include "my_menu.h"
#include "midnight.h"

void	clear_screen(t_menu *menu)
{
  int	i;
  int	j;

  i = 0;
  while (i < menu->limit[1] - menu->limit[0])
    {
      j = 0;
      wmove(menu->win, i + FIRST_P, 1);
      while (j <= WWIDTH - (NB_COLS + 1) - (TIME_WIDTH + 1))
	{
	  waddch(menu->win, (chtype) ' ');
	  j++;
	}
      wmove(menu->win, i + FIRST_P, 1 + j + 1);
      while (j <= WWIDTH - (NB_COLS + 1))
	{
	  waddch(menu->win, (chtype) ' ');
	  j++;
	}
      i++;
    }
}
