/*
** my_getnbr.c for getnbr in /u/all/keolas_s/rendu/piscine_rattrapage/Jour_03AM/bonus
** 
** Made by souvisay keolasy
** Login   <keolas_s@epitech.net>
** 
** Started on  Wed Sep 18 10:20:01 2013 souvisay keolasy
** Last update Wed Nov  6 22:37:21 2013 souvisay keolasy
*/

#include <stdlib.h>
#include "tools.h"
#include "my_errno.h"

static void	gere_sign(char *nbr, int *sign, int type, int *ret)
{
  int	i;

  i = 0;
  *ret = 0;
  *sign = 1;
  if (!nbr)
    return ;
  while (type == SIGNED && nbr[i] != '\0' && (nbr[i] == '-' || nbr[i] == '+'))
    {
      if (nbr[i] == '-')
	*sign *= -1;
      i++;
    }
}

int	my_getnbr(char *nbr, int type)
{
  int	sign;
  int	ret;

  gere_sign(nbr, &sign, type, &ret);
  while (nbr && *nbr != '\0' && *nbr >= '0' && *nbr <= '9')
    {
      if (((sign == -1) &&
	   ((ret > ((1 << 31) / 10 * -1)) ||
	    ((ret == ((1 << 31) / 10 * -1)) &&
	     (*nbr - '0' > ((1 << 31) % 10 * -1)))))
	  || ((sign == 1) &&
	   ((ret > (~(1 << 31) / 10)) ||
	    ((ret == (~(1 << 31) / 10)) &&
	     (*nbr - '0' > (~(1 << 31) % 10))))))
	{
	  print_error("Overflow\n");
	  exit(EXIT_FAILURE);
	}
      ret = (ret * 10) + *nbr - '0';
      nbr += 1;
    }
  return (ret * sign);
}
