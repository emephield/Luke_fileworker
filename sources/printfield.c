/*
** printfield.c for midnight in /home/keolas_s//test/systeme_unix/midnight
** 
** Made by souvisay keolasy
** Login   <keolas_s@epitech.net>
** 
** Started on  Tue Nov 26 08:34:54 2013 souvisay keolasy
** Last update Thu Dec  5 17:30:45 2013 souvisay keolasy
*/

#include <curses.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include "midnight.h"
#include "my_menu.h"
#include "tools.h"
#include "boolean.h"

extern t_menu	g_menu[2];

void	my_nputnstr(char *str, int win, int max)
{
  int	i;

  i = 0;
  while (str[i] != '\0' && i < max)
    {
      waddch(g_menu[win].win, (chtype) str[i]);
      i++;
    }
  if (my_strlen(str) > max)
    waddch(g_menu[win].win, '~');
}

void	printfield(int line, char *name, time_t date, int win)
{
  char		buff[12];

  my_bzero(buff, 11);
  strftime(buff, 12, "%a %d %Y", localtime(&date));
  wmove(g_menu[win].win, line, 1);
  my_nputnstr(name, win, WWIDTH - (NB_COLS + 1) - (TIME_WIDTH + 1));
  if (date != 0)
    {
      wmove(g_menu[win].win, line, WWIDTH - (TIME_WIDTH + 1));
      my_nputnstr(buff, win, TIME_WIDTH);
    }
}

t_bool	printfield_name(int win, char **path)
{
  wmove(g_menu[win].win, 3, 1);
  my_nputnstr(NAME_COL, win, WWIDTH - (NB_COLS + 1) - (TIME_WIDTH + 1));
  wmove(g_menu[win].win, 3, WWIDTH - (TIME_WIDTH + 1));
  my_nputnstr(DATE_COL, win, TIME_WIDTH);
  /* wmove(g_menu[win].win, 1, 1); */
  /* my_nputnstr(pwd, win, WWIDTH - 3); */
  /* free(pwd); */
  return (TRUE);
}
