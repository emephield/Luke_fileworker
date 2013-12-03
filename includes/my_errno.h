/*
** my_errno.h for magic21 in /home/keolas_s//test/prog_elem/magic21
** 
** Made by souvisay keolasy
** Login   <keolas_s@epitech.net>
** 
** Started on  Tue Sep 24 13:20:16 2013 souvisay keolasy
** Last update Wed Sep 25 16:05:49 2013 souvisay keolasy
*/

#ifndef		 MY_ERRNO_H_
# define	 MY_ERRNO_H_

# include	"boolean.h"

#define		ENOMEM	0	/* Out of memory */
#define		ENPTR	1	/* NULL pointer */
#define		EREAD	2	/* Read error */
#define		EOPEN	3	/* Open error */
#define		ECREAT	4	/* Creat error */
#define		EBADFD	5	/* Bad fd */

t_bool	print_errno(int my_errno);
void	*print_error(const char *str);

#endif		/*  MY_ERRNO_H_ */
