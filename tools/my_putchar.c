/*
** my_putchar.c for tools in /home/keolas_s//test/prog_elem/magic21/tools
** 
** Made by souvisay keolasy
** Login   <keolas_s@epitech.net>
** 
** Started on  Mon Sep 30 11:13:46 2013 souvisay keolasy
** Last update Mon Sep 30 11:15:54 2013 souvisay keolasy
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}
