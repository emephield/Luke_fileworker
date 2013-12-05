/*
** main.c for midnight in /home/keolas_s//test/systeme_unix/midnight/sources
** 
** Made by souvisay keolasy
** Login   <keolas_s@epitech.net>
** 
** Started on  Fri Nov 22 21:49:13 2013 souvisay keolasy
** Last update Thu Dec  5 17:27:36 2013 souvisay keolasy
*/

#include <curses.h>
#include <unistd.h>
#include "menu.h"
#include "midnight.h"
#include "boolean.h"
#include "my_errno.h"
#include "tools.h"

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
  printfield_name(0, NULL);
  printfield_name(1, NULL);
  return (TRUE);
}

void	cacahuete()
{
  int	i;
  int	j;
  t_item **itab;

  i = g_menu[0].limit[0];
  j = 0;
  itab = g_menu[0].list;
  while (itab[i + j] != NULL && i + j < g_menu[0].limit[1])
    {
      if (g_menu[0].cur == i + j)
      	wattron(g_menu[0].win, COLOR_PAIR(P_FORE));
      printfield(j + FIRST_P, itab[i + j]->name, time(NULL), 0);
      printfield(j + FIRST_P, itab[i + j]->name, time(NULL), 1);
      if (g_menu[0].cur == i + j)
      	wattroff(g_menu[0].win, COLOR_PAIR(P_FORE));
      j++;
    }
  printw("%d/", g_menu[0].cur);
}

t_bool	init_menu()
{
  int	i;
  char	*pwd;
  int	j;

  j = 0;
  while (j < 2)
    {
      i = 0;
      if ((g_menu[i].list = get_file()) == NULL)
	return (FALSE);
      if ((pwd = my_malloc((SIZE_PWD * sizeof(*pwd)) + 1)) == NULL)
	return (FALSE);
      while (getcwd(pwd, i * SIZE_PWD) == NULL)
	{
	  i++;
	  free(pwd);
	  if ((pwd = my_malloc((i * SIZE_PWD * sizeof(*pwd)) + 1)) == NULL)
	    return (FALSE);
	}
      g_menu[j].path = strtok_tab(pwd, "/\n");
      g_menu[j].limit[1] = WHEIGHT - 6;
      j++;
    }
  return (TRUE);
}

int		main(int ac, char **av)
{
  UNUSED(av);
  if (ac == 1)
    {
      init_aff();
      if (init_menu() == FALSE)
	return (FALSE);
      /* cacahuete(g_menu[0].list); */
      catch_key();
      endwin();
    }
  else
    {
      print_error(USAGE);
      return (FALSE);
    }
  return (TRUE);
}
