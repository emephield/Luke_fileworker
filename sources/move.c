/*
** move.c for midnight in /home/keolas_s//git/Luke_fileworker
** 
** Made by souvisay keolasy
** Login   <keolas_s@epitech.net>
** 
** Started on  Thu Dec  5 14:19:31 2013 souvisay keolasy
** Last update Thu Dec 12 13:37:53 2013 souvisay keolasy
*/

#include <curses.h>
#include "midnight.h"
#include "my_menu.h"
#include "boolean.h"

static t_move	g_movetab[] =
  {
    {KEY_UP, &arrow_up},
    {KEY_DOWN, &arrow_down},
    {KEY_LEFT, &arrow_left},
    {KEY_RIGHT, &arrow_right},
    {0, NULL}
  };

extern t_menu	g_menu[2];

t_bool	refresh_win(int focus)
{
  print_list(focus);
  wrefresh(g_menu[0].win);
  wrefresh(g_menu[1].win);
  refresh();
  return (TRUE);
}

t_bool		catch_key()
{
  int		i;
  int		key;
  static int	focus = 0;

  keypad(stdscr, TRUE);
  i = -1;
  while (i == -1 || (key = getch()) != 'q')
    {
      i = 0;
      if (key == '\t')
	{
	  focus = (focus + 1) % 2;
	  wbkgd(g_menu[focus].win, COLOR_PAIR(P_FONT));
	  wbkgd(g_menu[(focus + 1) % 2].win, COLOR_PAIR(P_NFOC));
	}
      while (g_movetab[i].fct != NULL && g_movetab[i].c != key)
	i++;
      if (g_movetab[i].fct != NULL)
	g_movetab[i].fct(&(g_menu[focus]));
      refresh_win(focus);
    }
  return (TRUE);
}
