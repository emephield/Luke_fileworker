/*
** main.c for midnight in /home/keolas_s//test/systeme_unix/midnight/sources
** 
** Made by souvisay keolasy
** Login   <keolas_s@epitech.net>
** 
** Started on  Fri Nov 22 21:49:13 2013 souvisay keolasy
** Last update Sun Jan 12 14:57:19 2014 keolas_s
*/

#include <curses.h>
#include <stdlib.h>
#include <unistd.h>
#include "menu.h"
#include "midnight.h"
#include "boolean.h"
#include "my_errno.h"
#include "tools.h"

t_ctrl		g_ctrl;

void	my_init_color()
{
  start_color();
  init_pair(P_FONT, COLOR_WHITE, COLOR_BLUE);
  init_pair(P_FORE, COLOR_BLUE, COLOR_CYAN);
  init_pair(P_NFOC, COLOR_GREEN, COLOR_BLACK);
  init_pair(P_DIRE, COLOR_CYAN, COLOR_BLUE);
  init_pair(P_ERR, COLOR_RED, COLOR_BLACK);
  init_pair(P_MEN, COLOR_BLUE, COLOR_WHITE);
}

t_bool	init_aff()
{
  static t_bool	trigger = FALSE;

  if (trigger == FALSE)
    {
      slk_init(3);
      initscr();
      cbreak();
      noecho();
      my_init_color();
      curs_set(0);
      g_ctrl.menu[0].win = newwin(WHEIGHT, WWIDTH, 1, 2);
      g_ctrl.menu[1].win = newwin(WHEIGHT, WWIDTH, 1, 2 + (COLS - 4 - 1) / 2 + 1);
      slk_set(2, "Edit", 0);
      slk_refresh();
    }
  trigger = TRUE;
  wbkgd(g_ctrl.menu[g_ctrl.focus].win, COLOR_PAIR(P_FONT));
  wbkgd(g_ctrl.menu[(g_ctrl.focus + 1) % 2].win, COLOR_PAIR(P_NFOC));
  mkbox();
  return (TRUE);
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
      if ((pwd = my_malloc((SIZE_PWD * sizeof(*pwd)) + 1)) == NULL)
	return (FALSE);
      while (getcwd(pwd, i * SIZE_PWD) == NULL)
	{
	  i++;
	  free(pwd);
	  if ((pwd = my_malloc((i * SIZE_PWD * sizeof(*pwd)) + 1)) == NULL)
	    return (FALSE);
	}
      if ((g_ctrl.menu[j].path = strtok_tab(pwd, "/\n")) == NULL)
	return (FALSE);
      g_ctrl.menu[j].limit[1] = WHEIGHT - 6;
      if ((g_ctrl.menu[j].list = get_file(g_ctrl.menu[j].path)) == NULL)
	return (FALSE);
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
      catch_key();
      endwin();
      reset_shell_mode();
    }
  else
    {
      print_error(USAGE);
      return (FALSE);
    }
  return (TRUE);
}
