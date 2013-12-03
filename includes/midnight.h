/*
** midnight.h for midnight in /home/keolas_s//test/systeme_unix/midnight/includes
** 
** Made by souvisay keolasy
** Login   <keolas_s@epitech.net>
** 
** Started on  Tue Nov 19 19:03:37 2013 souvisay keolasy
** Last update Tue Nov 26 11:58:55 2013 souvisay keolasy
*/

#ifndef		MIDNIGHT_H_
# define	MIDNIGHT_H_

# include	<curses.h>
# include	"boolean.h"
# include	"my_menu.h"

# define	USAGE	"./midnight\n"

# define	P_FONT	1
# define	P_BACK	2
# define	P_FORE	3

# define	WWIDTH	((COLS - 4 - 1) / 2)
# define	WHEIGHT	(LINES - 2)

# define	NB_COLS		2
# define	TIME_WIDTH	11
# define	FIRST_P		3
# define	NAME_COL	"Name"
# define	DATE_COL	"Date"

t_bool		sort_item(t_item **tab);
t_item		**get_file();
void		printfield_name(int win);

#endif		/* MIDNIGHT_H_ */