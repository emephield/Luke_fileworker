/*
** my_fd_func.c for magic21 in /home/keolas_s//test/prog_elem/magic21/tools
** 
** Made by souvisay keolasy
** Login   <keolas_s@epitech.net>
** 
** Started on  Wed Sep 25 15:35:46 2013 souvisay keolasy
** Last update Wed Sep 25 23:35:39 2013 souvisay keolasy
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "tools.h"
#include "my_errno.h"

int	my_read(const int fd, void *buf, const int count)
{
  int	ret;

  if (count <= 0)
    return (0);
  if (!buf)
    {
      print_errno(ENPTR);
      return (-1);
    }
  if ((ret = read(fd, buf, count)) == -1)
    {
      print_errno(EREAD);
      return (-1);
    }
  if (ret == 0)
    return (FD_EOF);
  return (ret);
}

int	my_open(char *path, int flags)
{
  int	fd;

  if (!path)
    {
      print_errno(ENPTR);
      return (-1);
    }
  if ((fd = open(path, flags)) == -1)
    {
      my_putstr(path);
      print_errno(EOPEN);
      return (-1);
    }
  else
    return (fd);
}

int	my_create(char *path, int flags, int mode)
{
  int	fd;

  if (!path)
    {
      print_errno(ENPTR);
      return (-1);
    }
  if ((fd = open(path, flags | O_CREAT, mode)) == -1)
    {
      print_errno(ECREAT);
      return (-1);
    }
  else
    return (fd);
}

int	my_close(int fd)
{
  int	ret;

  if (fd < 0 || (ret = close(fd)) == -1)
    {
      print_errno(EBADFD);
      return (-1);
    }
  return (ret);
}

