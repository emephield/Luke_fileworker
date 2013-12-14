/*
** exec_sh.c for midnight in /home/keolas_s//git/Luke_fileworker
** 
** Made by souvisay keolasy
** Login   <keolas_s@epitech.net>
** 
** Started on  Fri Dec 13 08:51:00 2013 souvisay keolasy
** Last update Fri Dec 13 18:09:54 2013 souvisay keolasy
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <curses.h>
#include "boolean.h"
#include "my_menu.h"
#include "midnight.h"
#include "tools.h"

extern t_ctrl	g_ctrl;

t_bool	exec_sh(char *sh, t_menu *menu)
{
  char	**temp;
  char	*path;
  int	status;

  if ((temp = add_tab(menu->list[menu->cur]->name, menu->path)) == NULL)
    return (FALSE);
  if ((path = creat_path(temp)) == NULL)
    return (FALSE);
  def_prog_mode();
  if (fork() == 0)
    {
      if (my_strcmp(sh, "emacs") == 0)
	execlp(sh, sh, "-nw", path);
      else
	execlp(sh, sh, path);	
    }
  else
    {
      wait(&status);
      reset_prog_mode();
      clear();
      init_aff();
      wrefresh(g_ctrl.menu[0].win);
      wrefresh(g_ctrl.menu[1].win);
      refresh();
   }
  return (TRUE);
}
