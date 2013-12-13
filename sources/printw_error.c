/*
** printw_error.c for midnight in /home/keolas_s//git/Luke_fileworker
** 
** Made by souvisay keolasy
** Login   <keolas_s@epitech.net>
** 
** Started on  Fri Dec 13 08:03:23 2013 souvisay keolasy
** Last update Fri Dec 13 08:09:43 2013 souvisay keolasy
*/

#include <curses.h>
#include "midnight.h"

void	printw_error(char *str)
{
  attron(COLOR_PAIR(P_ERR));
  mvprintw(LINES - 1, 0 , "%s", str);
  attroff(COLOR_PAIR(P_ERR));
}
