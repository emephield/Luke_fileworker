/*
** my_putnbr.c for tools in /home/keolas_s//test/prog_elem/magic21/tools
** 
** Made by souvisay keolasy
** Login   <keolas_s@epitech.net>
** 
** Started on  Mon Sep 30 11:12:22 2013 souvisay keolasy
** Last update Mon Sep 30 11:15:04 2013 souvisay keolasy
*/

#include "tools.h"

void	my_putnbr(unsigned int nb)
{
  if (nb > 9)
    my_putnbr(nb / 10);
  my_putchar(nb % 10 + '0');
}
