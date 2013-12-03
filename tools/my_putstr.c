/*
** my_putstr.c for tools in /home/keolas_s//test/prog_elem/magic21/tools
** 
** Made by souvisay keolasy
** Login   <keolas_s@epitech.net>
** 
** Started on  Sat Sep 28 13:48:05 2013 souvisay keolasy
** Last update Wed Oct 16 11:43:59 2013 souvisay keolasy
*/

#include <unistd.h>
#include "tools.h"

void	my_putstr(const char *str)
{
  write(1, str, my_strlen(str));
}
