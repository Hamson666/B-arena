/*
** broadcast.c for zappy in /home/de-mat_a/rendu/PSU_2014_zappy/server/srcs
** 
** Made by François De Matos
** Login   <de-mat_a@epitech.net>
** 
** Started on  Tue Jun 30 20:40:31 2015 François De Matos
** Last update Thu Jul  9 00:01:43 2015 François De Matos
*/

#include	"server.h"

int		shortest(t_plyr *player, t_plyr *tmp, int *x, int *y)
{
  int		dist;
  int		tmpx;
  int		tmpy;

  dist = sqrt(SQR(server.width) + SQR(server.height));
  tmpx = tmp->x - server.width;
  while (tmpx <= tmp->x + server.width)
    {
      tmpy = tmp->y - server.height;
      while (tmpy <= tmp->y + server.height)
	{
	  if (distance(player->x, player->y, tmpx, tmpy) < dist)
	    {
	      dist = distance(player->x, player->y, tmpx, tmpy);
	      *x = tmpx;
	      *y = tmpy;
	    }
	  tmpy += server.height;
	}
      tmpx += server.width;
    }
  return (dist);
}

int		direction_of_song(t_plyr *player, int x, int y)
{
  if (player->x == x && player->y == y)
    return (0);
  else if (ABS(x - player->x) == ABS(y - player->y))
    {

    }
  else
    {

    }
  return (0);
}

void		broadcast(t_plyr *player, char *param __attribute__((unused)))
{
  t_plyr	*tmp;

  tmp = players;
  while (tmp)
    {
      if (tmp->so != player->so)
        {

        }
      tmp = tmp->next;
    }
}
