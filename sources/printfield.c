/*
** printfield.c for midnight in /home/keolas_s//test/systeme_unix/midnight
** 
** Made by souvisay keolasy
** Login   <keolas_s@epitech.net>
** 
** Started on  Tue Nov 26 08:34:54 2013 souvisay keolasy
** Last update Fri Dec 13 17:18:14 2013 souvisay keolasy
*/

#include <curses.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include "midnight.h"
#include "my_menu.h"
#include "tools.h"
#include "boolean.h"

extern t_ctrl	g_ctrl;

void	my_nputnstr(char *str, int win, int max)
{
  int	i;

  if (!str)
    return ;
  i = 0;
  while (str[i] != '\0' && i <= max)
    {
      waddch(g_ctrl.menu[win].win, (chtype) str[i]);
      i++;
    }
  while (i <= max)
    {
      if (i == max + 1 && my_strlen(str) > max)
	waddch(g_ctrl.menu[win].win, (chtype) '~');
      else
	waddch(g_ctrl.menu[win].win, (chtype) ' ');
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
  wmove(g_ctrl.menu[win].win, line, 1);
  my_nputnstr(item->right, win, RIGHT_WIDTH - 3);
  wmove(g_ctrl.menu[win].win, line, 2 + RIGHT_WIDTH);
  my_nputnstr(name, win, WWIDTH - (NB_COLS + 1) -
	      (TIME_WIDTH + 1) - (RIGHT_WIDTH + 1));
  wmove(g_ctrl.menu[win].win, line, WWIDTH - (TIME_WIDTH + 1));
  my_nputnstr(buff, win, TIME_WIDTH - 1);
  free(name);
}

t_bool	printfield_name(int win, char **path)
{
  char	*pwd;

  wattron(g_ctrl.menu[win].win, A_BOLD);
  wmove(g_ctrl.menu[win].win, 3, 1);
  my_nputnstr(RIGHT_COL, win, RIGHT_WIDTH - 2);
  wmove(g_ctrl.menu[win].win, 3, 1 + RIGHT_WIDTH + 1);
  my_nputnstr(NAME_COL, win, WWIDTH - (NB_COLS + 1) - (TIME_WIDTH + 1)
	      - (RIGHT_WIDTH + 1));
  wmove(g_ctrl.menu[win].win, 3, WWIDTH - (TIME_WIDTH + 1));
  my_nputnstr(DATE_COL, win, TIME_WIDTH - 1);
  wmove(g_ctrl.menu[win].win, 1, 1);
  if ((pwd = creat_path(path)) == FALSE)
    return (FALSE);
  my_nputnstr(pwd, win, WWIDTH - 3);
  if (my_strlen(pwd) != 1)
      free(pwd);
  wattroff(g_ctrl.menu[win].win, A_BOLD);
  return (TRUE);
}

static int	select_attr(int focus, int i, int j)
{
  if (i != focus)
    return (COLOR_PAIR(P_NFOC));
  else if (g_ctrl.menu[i].cur ==  g_ctrl.menu[i].limit[0]+ j)
    return (COLOR_PAIR(P_FORE));
  else
    return (g_ctrl.menu[i].list[j]->color);
}

void		print_list(int focus)
{
  int		i;
  int		j;
  t_item	**itab;
  int		attr;

  i = 0;
  while (i < 2)
    {
      j = 0;
      itab = g_ctrl.menu[i].list;
      while (itab[g_ctrl.menu[i].limit[0]+ j] != NULL &&
	     g_ctrl.menu[i].limit[0]+ j < g_ctrl.menu[0].limit[1])
	{
	  attr = select_attr(focus, i, j);
	  wattron(g_ctrl.menu[i].win, attr);
	  printfield(j + FIRST_P, itab[g_ctrl.menu[i].limit[0] + j], i);
	  wattroff(g_ctrl.menu[i].win, attr);
	  j++;
	}
      printfield_name(i, g_ctrl.menu[i].path);
      i++;
    }
}
