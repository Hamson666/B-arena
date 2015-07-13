/*
** utils.c for zappy in /home/de-mat_a/rendu/PSU_2014_zappy/client/libs
** 
** Made by François De Matos
** Login   <de-mat_a@epitech.net>
** 
** Started on  Fri Jun 12 01:10:55 2015 François De Matos
** Last update Fri Jun 12 01:10:56 2015 François De Matos
*/

#include	"lib.h"

int		get_fd(int maxfd, fd_set *fdset)
{
  int		i;

  i = -1;
  while (++i <= maxfd)
    if (FD_ISSET(i, fdset))
      return (i);
  return (-1);
}

void		exit_mess(int e, char *message)
{
  printf("%s\n", message);
  exit(e);
}

void		exit_mess_close(int e, char *message, int so)
{
  printf("%s\n", message);
  exit(e);
  close(so);
}
