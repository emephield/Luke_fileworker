/*
** sort_item.c for midnight in /home/keolas_s//test/systeme_unix/midnight
** 
** Made by souvisay keolasy
** Login   <keolas_s@epitech.net>
** 
** Started on  Fri Nov 22 22:23:57 2013 souvisay keolasy
** Last update Tue Nov 26 00:51:45 2013 souvisay keolasy
*/

#include "tools.h"
#include "boolean.h"
#include "my_menu.h"

static void	my_swap(t_item **a, t_item **b)
{
  void	*temp;

  temp = *a;
  *a = *b;
  *b = temp;
}

t_bool	sort_item(t_item **tab)
{
  int	i;

  i = 0;
  while (tab[i + 1] != NULL)
    {
      if (my_strcmp_case(tab[i]->name, tab[i + 1]->name) > 0)
	{
	  my_swap(tab + i, tab + i + 1);
	  i = 0;
	}
      else
	i++;
    }
  return (TRUE);
}
