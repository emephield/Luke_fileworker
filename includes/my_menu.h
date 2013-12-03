/*
** my_menu.h for midnight in /home/keolas_s//test/systeme_unix/midnight/includes
** 
** Made by souvisay keolasy
** Login   <keolas_s@epitech.net>
** 
** Started on  Fri Nov 22 21:31:11 2013 souvisay keolasy
** Last update Tue Nov 26 11:53:35 2013 souvisay keolasy
*/

#ifndef		MY_MENU_H_
# define	MY_MENU_H_

# include	<curses.h>
# include	<time.h>

typedef struct	s_item
{
  char		*name;
}		t_item;

typedef struct	s_menu
{
  WINDOW	*win;
  int		rows;
  int		namelen;
  int		fieldlen[2];
  t_item	**list;
  int		cur;
}		t_menu;

t_item	*newitem(char *name);
void	mkbox();
void	printfield(int line, char *name, time_t date, int win);

#endif		/* MY_MENU_H_ */
