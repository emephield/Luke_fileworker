/*
** main.c for midnight in /home/keolas_s//test/systeme_unix/midnight/sources
** 
** Made by souvisay keolasy
** Login   <keolas_s@epitech.net>
** 
** Started on  Fri Nov 22 21:49:13 2013 souvisay keolasy
** Last update Tue Nov 26 13:55:12 2013 souvisay keolasy
*/

#include <curses.h>
#include "menu.h"
#include "midnight.h"
#include "boolean.h"
#include "my_errno.h"
#include "tools.h"

#include <time.h>

t_menu	g_menu[2];

void	my_init_color()
{
  start_color();
  init_pair(P_FONT, COLOR_YELLOW, COLOR_BLUE);
  init_pair(P_BACK, COLOR_YELLOW, COLOR_BLUE);
  init_pair(P_FORE, COLOR_BLUE, COLOR_CYAN);
}

t_bool	init_aff()
{
  initscr();
  cbreak();
  noecho();
  my_init_color();
  curs_set(0);
  g_menu[0].win = newwin(WHEIGHT, WWIDTH, 1, 2);
  g_menu[1].win = newwin(WHEIGHT, WWIDTH, 1, 2 + (COLS - 4 - 1) / 2 + 1);
  wbkgd(g_menu[0].win, COLOR_PAIR(P_FONT));
  wbkgd(g_menu[1].win, COLOR_PAIR(P_FONT));
  mkbox();
  printfield_name(0);
  printfield_name(1);
  return (TRUE);
}

void	cacahuete(t_item **itab)
{
  int	i;

  i = 0;
  while (itab[i] != NULL && i < WHEIGHT - 1)
    {
      printfield(i + FIRST_P, itab[i]->name, time(NULL), 0);
      printfield(i + FIRST_P, itab[i]->name, time(NULL), 1);
      i++;
    }
}

int		main(int ac, char **av)
{
  t_item	**itab;

  UNUSED(av);
  if (ac == 1)
    {
      if ((itab = get_file()) == NULL)
	return (FALSE);
      init_aff();
      cacahuete(itab);
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
