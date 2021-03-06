/*
** mkbox.c for midnight in /home/keolas_s//test/systeme_unix/midnight/sources
** 
** Made by souvisay keolasy
** Login   <keolas_s@epitech.net>
** 
** Started on  Tue Nov 26 07:55:41 2013 souvisay keolasy
** Last update Fri Dec 13 17:03:58 2013 souvisay keolasy
*/

#include <curses.h>
#include "menu.h"
#include "midnight.h"
#include "boolean.h"
#include "tools.h"

extern t_ctrl	g_ctrl;

void	mk_subcol(int menu, int col, int inter, int start)
{
  mvwaddch(g_ctrl.menu[menu].win, start - 1, col, ACS_TTEE);
  mvwvline(g_ctrl.menu[menu].win, start, col, 0, WHEIGHT - 1);
  mvwaddch(g_ctrl.menu[menu].win, inter, col, ACS_PLUS);
  mvwaddch(g_ctrl.menu[menu].win, WHEIGHT - 1, col, ACS_BTEE);
}

void	mk_subline(int menu, int line)
{
  mvwaddch(g_ctrl.menu[menu].win, line, 0, ACS_LTEE);
  mvwhline(g_ctrl.menu[menu].win, line, 1, 0, WWIDTH);
  mvwaddch(g_ctrl.menu[menu].win, line, WWIDTH - 1, ACS_RTEE);
}

void	mkbox()
{
  int	i;

  i = 0;
  refresh();
  while (i < 2)
    {
      box(g_ctrl.menu[i].win, 0, 0);
      mk_subline(i, 2);
      mk_subline(i, 4);
      mk_subcol(i, WWIDTH - 13 , 4, 3);
      mk_subcol(i, RIGHT_WIDTH + 1, 4, 3);
      i++;
    }
}
