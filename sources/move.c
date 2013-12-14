/*
** move.c for midnight in /home/keolas_s//git/Luke_fileworker
** 
** Made by souvisay keolasy
** Login   <keolas_s@epitech.net>
** 
** Started on  Thu Dec  5 14:19:31 2013 souvisay keolasy
** Last update Fri Dec 13 14:05:51 2013 souvisay keolasy
*/

#include <curses.h>
#include "midnight.h"
#include "my_menu.h"
#include "boolean.h"

static t_move	g_movetab[] =
  {
    {KEY_UP, &arrow_up, NULL},
    {KEY_DOWN, &arrow_down, NULL},
    {KEY_LEFT, &arrow_left, NULL},
    {KEY_RIGHT, &arrow_right, NULL},
    {KEY_F(1), NULL, SH_EDIT},
    {0, NULL, NULL}
  };

extern t_ctrl	g_ctrl;

t_bool	refresh_win(int focus)
{
  print_list(focus);
  wrefresh(g_ctrl.menu[0].win);
  wrefresh(g_ctrl.menu[1].win);
  refresh();
  return (TRUE);
}

t_bool		catch_key()
{
  int		i;
  int		key;

  keypad(stdscr, TRUE);
  i = -1;
  while (i == -1 || (key = getch()) != 'q')
    {
      i = 0;
      if (key == '\t')
	{
	  g_ctrl.focus = (g_ctrl.focus + 1) % 2;
	  wbkgd(g_ctrl.menu[g_ctrl.focus].win, COLOR_PAIR(P_FONT));
	  wbkgd(g_ctrl.menu[(g_ctrl.focus + 1) % 2].win, COLOR_PAIR(P_NFOC));
	}
      while (g_movetab[i].c != 0 && g_movetab[i].c != key)
	i++;
      if (g_movetab[i].fct != NULL)
	g_movetab[i].fct(&(g_ctrl.menu[g_ctrl.focus]));
      else if (g_movetab[i].sh != NULL)
	exec_sh(g_movetab[i].sh, &(g_ctrl.menu[g_ctrl.focus]));
      refresh_win(g_ctrl.focus);
    }
  return (TRUE);
}
