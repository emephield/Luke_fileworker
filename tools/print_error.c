/*
** print_error.c for genealfs in /home/keolas_s//test/systeme_unix/genealf
** 
** Made by souvisay keolasy
** Login   <keolas_s@epitech.net>
** 
** Started on  Thu Jun 20 21:01:37 2013 souvisay keolasy
** Last update Sun Oct 13 22:23:03 2013 souvisay keolasy
*/

#include <unistd.h>
#include "boolean.h"
#include "tools.h"

static const char	*(str_error[6]) =
  {
    "Out of memory\n",
    "Null pointer given too a function that need an alocated one\n",
    "Error on read\n",
    "Error on open\n",
    "Error on create\n",
    "Wrong file descriptor\n"
  };

void	*print_error(const char *str)
{
  write(2, str, my_strlen(str));
  return (NULL);
}

t_bool	print_errno(int my_errno)
{
  write(2, str_error[my_errno], my_strlen(str_error[my_errno]));
  return (FALSE);
}
