/*
** utils.c for zappy in /home/de-mat_a/rendu/PSU_2014_zappy/server/libs
** 
** Made by François De Matos
** Login   <de-mat_a@epitech.net>
** 
** Started on  Mon Jun  1 17:09:55 2015 François De Matos
** Last update Sun Jul  5 18:38:26 2015 François De Matos
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
  printf("\n\e[1;31m/!\\ ERROR /!\\ -> %s\e[m\n", message);
  exit(e);
}

void		exit_mess_close(int e, char *message, int so)
{
  printf("\n\e[1;31m/!\\ ERROR /!\\ -> %s\e[m\n\n", message);
  exit(e);
  close(so);
}

int		distance(int x1, int y1, int x2, int y2)
{
  int		tmpx;
  int		tmpy;

  tmpx = x1 > x2 ? x1 - x2 : x2 - x1;
  tmpy = y1 > y2 ? y1 - y2 : y2 - y1;
  return (sqrt(SQR(tmpx) + SQR(tmpy)));
}

char		*my_strcat(char *dest, char *src)
{
  char		*ret;

  if (src == NULL)
    return (dest);
  if (dest == NULL)
    return (strdup(src));
  if ((ret = malloc(sizeof(char) * (strlen(dest) + strlen(src) + 1))) == NULL)
    exit_mess(666, "Error: Bad malloc");
  ret[0] = 0;
  strcat(ret, dest);
  strcat(ret, src);
  return (ret);
}
