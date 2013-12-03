/*
** main.c for midnight in /home/keolas_s//test/systeme_unix/midnight/sources
** 
** Made by souvisay keolasy
** Login   <keolas_s@epitech.net>
** 
** Started on  Tue Nov 19 21:26:57 2013 souvisay keolasy
** Last update Thu Nov 21 12:41:38 2013 souvisay keolasy
*/

#include <curses.h>
#include <stdlib.h>
#include "menu.h"

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

char	*choices2[] = {

  "Choix 1",
  "Choix 2",
  "Choix 3",
  "Choix 4",
  "EXIT",
  "EXIT",
  "EXIT",
  "EXIT",
};

#define	TEST(a)	(sizeof(a) / sizeof(a[0]))

void	print_in_middle(WINDOW *win, int starty, int startx, int width, char *string, chtype color)
{
  int	lenght, x, y;
  float	temp;

  wattron(win, color);
  if (win == NULL)
    win = stdscr;
  x = startx;
  y = starty;
  if (width == 0)
    width = 80;
  lenght = strlen(string);
  temp = (width - lenght) / 2;
  x = startx + (int) temp;
  mvwprintw(win, y, x, "%s", string);
  refresh();
}

int	main()
{
  ITEM	**my_items, **my_items2;
  int	c;
  MENU	*my_menu;
  int	n_choices, n_choices2, i;
  ITEM	*cur_item;
  WINDOW	*win_menu;

  initscr();
  cbreak();
  noecho();
  start_color();

  
  init_pair(1, COLOR_YELLOW, COLOR_BLUE);
  init_pair(2, COLOR_CYAN, COLOR_WHITE);
  init_pair(3, COLOR_BLUE, COLOR_CYAN);
  

  bkgd(COLOR_PAIR(1));

  n_choices = /* TEST(choices) */8;
  my_items = (ITEM **) calloc(n_choices + 1, sizeof(ITEM *));

  for (i = 0; i < n_choices; ++i)
    my_items[i] = new_item(choices[i], NULL);
  my_items[n_choices] = NULL;

  my_menu = new_menu(my_items);
  win_menu = newwin(20, 40, 2, 2);
  wbkgd(win_menu, COLOR_PAIR(1));
  set_menu_fore(my_menu, COLOR_PAIR(3));
  set_menu_back(my_menu, COLOR_PAIR(1));


  set_menu_win(my_menu, win_menu);
  set_menu_sub(my_menu, derwin(win_menu, 8, 38, 3, 1));
  wbkgdset(win_menu, COLOR_PAIR(1));
  set_menu_mark(my_menu, "* ");
  box(win_menu, 0, 0);



  print_in_middle(win_menu, 1, 0, 40, "My menu", COLOR_PAIR(1));
  mvprintw(LINES - 2, 0, "F1 to EXIT");
  post_menu(my_menu);
  keypad(/* win_menu */stdscr, TRUE);
  refresh();
  wrefresh(win_menu);

  while ((c = getch()) != KEY_F(1))
    {
      if (c == KEY_DOWN)
	menu_driver(my_menu, REQ_DOWN_ITEM);
      else if (c == KEY_UP)
	menu_driver(my_menu, REQ_UP_ITEM);
      wrefresh(win_menu);
    }
  free_item(my_items[0]);
  free_item(my_items[1]);
  free_menu(my_menu);
  endwin();
}
