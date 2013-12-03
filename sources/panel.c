/*
** main.c for midnight in /home/keolas_s//test/systeme_unix/midnight/sources
** 
** Made by souvisay keolasy
** Login   <keolas_s@epitech.net>
** 
** Started on  Tue Nov 19 19:04:56 2013 souvisay keolasy
** Last update Thu Nov 21 10:43:45 2013 souvisay keolasy
*/

#include <curses.h>
#include "panel.h"

#define	NLINES	10
#define	NCOLS	40

void	print_in_middle(WINDOW *win, int starty, int startx, int width, char *string, chtype color)
{
  int	lenght, x, y;
  float	temp;

  if (win == NULL)
    win = stdscr;
  getyx(win, y, x);
  if (startx != 0)
    x = startx;
  if (starty != 0)
    y = starty;
  if (width == 0)
    width = 80;
  lenght = strlen(string);
  temp = (width - lenght) / 2;
  x = startx + (int) temp;
  mvwprintw(win, y, x, "%s", string);
  wattron(win, color);
  refresh();
}


void	win_show(WINDOW *win, char *label, int label_color)
{
  int	startx, starty, height, width;

  getbegyx(win, starty, startx);
  getmaxyx(win, height, width);

  box(win, 0, 0);
  mvwaddch(win, 2, 0, ACS_LTEE);
  mvwhline(win, 2, 1, ACS_HLINE, width - 2);
  mvwaddch(win, 2, width - 1, ACS_RTEE);

  print_in_middle(win, 1, 0, width, label, COLOR_PAIR(label_color));
}

void	init_win(WINDOW **wins, int n)
{
  int	x, y, i;
  char	label[80];

  y = 2;
  x = 10;
  for (i = 0; i < n; ++i)
    {
      wins[i] = newwin(NLINES, NCOLS, y, x);
      sprintf(label, "Window Number %d", i + 1);
      win_show(wins[i], label, i + 1);
      y += 3;
      x += 7;
    }
}

int	main()
{
  WINDOW	*my_wins[3];
  PANEL		*my_panels[3];
  PANEL		*top;
  int		ch;

  initscr();
  cbreak();
  noecho();
  start_color();

  init_pair(1, COLOR_RED, COLOR_BLACK);
  init_pair(2, COLOR_GREEN, COLOR_BLACK);
  init_pair(3, COLOR_BLUE, COLOR_BLACK);
  init_pair(4, COLOR_CYAN, COLOR_BLACK);

  init_win(my_wins, 3);

  my_panels[0] = new_panel(my_wins[0]);
  my_panels[1] = new_panel(my_wins[1]);
  my_panels[2] = new_panel(my_wins[2]);

  set_panel_userptr(my_panels[0], my_panels[1]);
  set_panel_userptr(my_panels[1], my_panels[2]);
  set_panel_userptr(my_panels[2], my_panels[0]);

  update_panels();

  doupdate();

  top = my_panels[2];
  while (((ch = getch())) != KEY_F(1))
    {
      switch (ch)
	{
	case 9:
	  top = (PANEL *) panel_userptr(top);
	  top_panel(top);
	  break;
	}
      update_panels();
      doupdate();
    } 

  endwin();
  return (0);
}
