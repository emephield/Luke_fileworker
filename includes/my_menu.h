/*
** my_menu.h for midnight in /home/keolas_s//test/systeme_unix/midnight/includes
** 
** Made by souvisay keolasy
** Login   <keolas_s@epitech.net>
** 
** Started on  Fri Nov 22 21:31:11 2013 souvisay keolasy
** Last update Fri Dec 13 17:02:13 2013 souvisay keolasy
*/

#ifndef		MY_MENU_H_
# define	MY_MENU_H_

# include	<curses.h>
# include	<time.h>
#include	<sys/stat.h>
# include	"boolean.h"

typedef struct	s_item
{
  char		right[11];
  char		*name;
  char		**pwd;
  struct stat	s_stat;
  int		color;
}		t_item;

typedef struct	s_menu
{
  WINDOW	*win;
  t_item	**list;
  char		**path;
  int		cur;
  int		limit[2];
  int		rows;
  int		namelen;
  int		fieldlen[2];
  t_bool	chdir;
}		t_menu;

typedef	struct	s_move
{
  int		c;
  t_bool	(*fct)(t_menu *menu);
  char		*sh;
}		t_move;

typedef	struct	s_scolor
{
  int		cmp;
  int		color;
}		t_scolor;

typedef struct	s_ctrl
{
  t_menu	menu[2];
  int		focus;
}		t_ctrl;

t_item	*newitem(char *name, char **src_path);
void	mkbox();
void	printfield(int line, t_item *item, int win);
void	print_list(int focus);
void	clear_screen(t_menu *menu);

t_bool	arrow_up(t_menu *menu);
t_bool	arrow_down(t_menu *menu);
t_bool	arrow_left(t_menu *menu);
t_bool	arrow_right(t_menu *menu);
t_bool	exec_sh(char *sh, t_menu *menu);

#endif		/* MY_MENU_H_ */
