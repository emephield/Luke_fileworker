/*
** printfield.c for midnight in /home/keolas_s//test/systeme_unix/midnight
** 
** Made by souvisay keolasy
** Login   <keolas_s@epitech.net>
** 
** Started on  Tue Nov 26 08:34:54 2013 souvisay keolasy
** Last update Fri Dec 13 08:07:11 2013 souvisay keolasy
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

  if (!str)
    return ;
  i = 0;
  while (str[i] != '\0' && i <= max)
    {
      waddch(g_menu[win].win, (chtype) str[i]);
      i++;
    }
  while (i <= max)
    {
      if (i == max + 1 && my_strlen(str) > max)
	waddch(g_menu[win].win, (chtype) '~');
      else
	waddch(g_menu[win].win, (chtype) ' ');
      i++;
    }
}
void	printfield(int line, t_item *item, int win)
{
  char		buff[12];
  char		*name;
  char		*temp;

  my_bzero(buff, 11);
  strftime(buff, 12, "%a %d %Y", localtime(&item->s_stat.st_mtime));
  name = item->name;
  if (S_ISDIR(item->s_stat.st_mode))
    temp = "/";
  else
    temp = " ";
  if ((name = my_stradd(temp, name)) == NULL)
    return ;
  wmove(g_menu[win].win, line, 1);
  my_nputnstr(name, win, WWIDTH - (NB_COLS + 1) - (TIME_WIDTH + 1));
  wmove(g_menu[win].win, line, WWIDTH - (TIME_WIDTH + 1));
  my_nputnstr(buff, win, TIME_WIDTH - 1);
  free(name);
}

t_bool	printfield_name(int win, char **path)
{
  char	*pwd;

  wattron(g_menu[win].win, A_BOLD);
  wmove(g_menu[win].win, 3, 1);
  my_nputnstr(NAME_COL, win, WWIDTH - (NB_COLS + 1) - (TIME_WIDTH + 1));
  wmove(g_menu[win].win, 3, WWIDTH - (TIME_WIDTH + 1));
  my_nputnstr(DATE_COL, win, TIME_WIDTH - 1);
  wmove(g_menu[win].win, 1, 1);
  if ((pwd = creat_path(path)) == FALSE)
    return (FALSE);
  my_nputnstr(pwd, win, WWIDTH - 3);
  if (my_strlen(pwd) != 1)
      free(pwd);
  wattroff(g_menu[win].win, A_BOLD);
  return (TRUE);
}

void	print_list(int focus)
{
  int	i;
  int	j;
  t_item **itab;

  i = 0;
  while (i < 2)
    {
      j = 0;
      itab = g_menu[i].list;
      while (itab[g_menu[i].limit[0]+ j] != NULL &&
	     g_menu[i].limit[0]+ j < g_menu[0].limit[1])
	{
	  if (i == focus && g_menu[i].cur ==  g_menu[i].limit[0]+ j)
	    wattron(g_menu[i].win, COLOR_PAIR(P_FORE));
	  printfield(j + FIRST_P, itab[g_menu[i].limit[0] + j], i);
	  if (i == focus && g_menu[i].cur == g_menu[i].limit[0] + j)
	    wattroff(g_menu[i].win, COLOR_PAIR(P_FORE));
	  j++;
	}
      printfield_name(i, g_menu[i].path);
      i++;
    }
}
