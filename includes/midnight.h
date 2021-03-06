/*
** midnight.h for midnight in /home/keolas_s//test/systeme_unix/midnight/includes
** 
** Made by souvisay keolasy
** Login   <keolas_s@epitech.net>
** 
** Started on  Tue Nov 19 19:03:37 2013 souvisay keolasy
** Last update Sun Jan 12 14:39:31 2014 keolas_s
*/

#ifndef		MIDNIGHT_H_
# define	MIDNIGHT_H_

# include	<curses.h>
# include	"boolean.h"
# include	"my_menu.h"

# define	USAGE	"./midnight\n"

# define	P_FONT	1
# define	P_FORE	3
# define	P_NFOC	4
# define	P_DIRE	5
# define	P_ERR	8

# define	WWIDTH	((COLS - 4 - 1) / 2)
# define	WHEIGHT	(LINES - 2 - 1)

# define	NB_COLS		2
# define	TIME_WIDTH	11
# define	RIGHT_WIDTH	11
# define	FIRST_P		5
# define	SIZE_PWD	1024
# define	RIGHT_COL	"Right"
# define	NAME_COL	"Name"
# define	DATE_COL	"Last Modify"

# define	SH_EDIT		"emacs"

t_bool		sort_item(t_item **tab);
t_item		**get_file(char **src_path);
t_bool		printfield_name(int win, char **path);
t_bool		catch_key();
char		*creat_path(char **path);
void		printw_error(char *str);
t_bool		init_aff();

#endif		/* MIDNIGHT_H_ */
