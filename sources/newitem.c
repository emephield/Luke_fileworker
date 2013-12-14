/*
** newitem.c for midnight in /home/keolas_s//test/systeme_unix/midnight/sources
** 
** Made by souvisay keolasy
** Login   <keolas_s@epitech.net>
** 
** Started on  Fri Nov 22 22:04:36 2013 souvisay keolasy
** Last update Fri Dec 13 18:11:30 2013 souvisay keolasy
*/

#define	 _GNU_SOURCE
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "midnight.h"
#include "my_menu.h"
#include "tools.h"

t_scolor	g_attrtab[] = 
  {
    {S_IFDIR, COLOR_PAIR(P_DIRE)},
    {0, COLOR_PAIR(P_FONT)}
  };

t_bool	select_attr(t_item *item)
{
  int	i;

  i = 0;
  while (g_attrtab[i].cmp != 0 &&
	 (int)(item->s_stat.st_mode & g_attrtab[i].cmp) != g_attrtab[i].cmp)
    i++;
  item->color = g_attrtab[i].color;
  return (TRUE);
}

void	fill_right(t_item *item)
{
  int	i;
  char	c;

  i = 0;
  my_memset(item->right, '-', 10);
  if (item->color == COLOR_PAIR(P_DIRE))
    item->right[i] = 'd';
  while (i < 10)
    {
      if ((i - 1) % 3 == 0)
	c = 'r';
      else if ((i - 1) % 3 == 1)
	c = 'x';
      else
	c = 'w';
      if ((item->s_stat.st_mode & (1 << (i - 1))) != 0)
	item->right[10 - (i - 1)] = c;
      i++;
    }
}

t_item		*newitem(char *name, char **src_path)
{
  t_item	*item;
  char		*temp;

  if ((item = my_malloc(sizeof(*item))) == NULL)
    return (NULL);
  if ((item->name = my_strdup(name)) == NULL)
    return (NULL);
  item->pwd = src_path;
  temp = creat_path(src_path);
  temp = my_stradd(temp, "/");
  temp = my_stradd(temp, name);
  stat(temp, &item->s_stat);
  select_attr(item);
  fill_right(item);
  free(temp);
  return (item);
}
