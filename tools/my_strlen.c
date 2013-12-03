/*
** my_strlen.c for magic21 in /home/keolas_s//test/prog_elem/magic21
** 
** Made by souvisay keolasy
** Login   <keolas_s@epitech.net>
** 
** Started on  Wed Sep 25 09:06:14 2013 souvisay keolasy
** Last update Wed Sep 25 09:06:58 2013 souvisay keolasy
*/

int	my_strlen(const char *str)
{
  int	i;

  i = 0;
  while (str && str[i])
    i++;
  return (i);
}

