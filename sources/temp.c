/*
** main.c for midnight in /home/keolas_s//test/systeme_unix/midnight/sources
** 
** Made by souvisay keolasy
** Login   <keolas_s@epitech.net>
** 
** Started on  Thu Nov 21 11:21:07 2013 souvisay keolasy
** Last update Tue Nov 26 06:15:07 2013 souvisay keolasy
*/

#include <curses.h>
#include "menu.h"
#include "midnight.h"
#include "boolean.h"
#include "my_errno.h"
#include "tools.h"

char	*choices[] = {

  "Choix 1",
  "Choix 2",
  "Choix 3",
  "Choix 4",
  "EXIT",
  "EXIT",
  "EXIT",
  "EXIT",
};

void	init_twice_win(t_ctrl *ctrl)
{
  ctrl->win[1] = newwin(LINES - 2, (COLS - 4 - 1) / 2 , 1, 2);
  ctrl->win[2] = newwin(LINES - 2, (COLS - 4 - 1) / 2 , 1, 2 + (COLS - 4 - 1) / 2 + 1);
  mvwhline(ctrl->win[1], 1, 1, 0, (COLS - 4 - 1) / 2) - 10;
  box(ctrl->win[1], 0, 0);
  box(ctrl->win[2], 0, 0);
  wbkgd(ctrl->win[1], COLOR_PAIR(P_FONT));
  wbkgd(ctrl->win[2], COLOR_PAIR(P_FONT));
  refresh();
  wrefresh(ctrl->win[1]);
  wrefresh(ctrl->win[2]);
}

void	my_init_color()
{
  start_color();
  init_pair(1, COLOR_YELLOW, COLOR_BLUE);
  init_pair(2, COLOR_YELLOW, COLOR_BLUE);
  init_pair(3, COLOR_BLUE, COLOR_CYAN);
}

t_bool	init_aff(t_ctrl *ctrl)
{
  initscr();
  cbreak();
  noecho();
  my_init_color();
  curs_set(0);
  init_twice_win(ctrl);
  return (TRUE);
}

int	main(int ac, char **av)
{
  t_ctrl	ctrl;

  UNUSED(av);
  if (ac == 1)
    {
      init_aff(&ctrl);
      getch();
      endwin();
    }
  else
    {
      print_error(USAGE);
      return (FALSE);
    }
  return (TRUE);
}
