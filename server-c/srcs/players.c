/*
** players.c for zappy in /home/de-mat_a/rendu/PSU_2014_zappy/server/srcs
** 
** Made by François De Matos
** Login   <de-mat_a@epitech.net>
** 
** Started on  Thu Jun  4 22:27:44 2015 François De Matos
** Last update Sun Jul  5 22:48:29 2015 François De Matos
*/

#include	"players.h"

void		push_plyr(t_plyr **players, int infos[6], int so)
{
  t_plyr	*tmp;

  if ((tmp = malloc(sizeof(t_plyr))) == NULL)
    exit_mess(666, "Error: Bad malloc");
  tmp->so = so;
  tmp->id_team = infos[0];
  tmp->direction = infos[1];
  tmp->level = infos[2];
  tmp->x = infos[3];
  tmp->y = infos[4];
  tmp->forked = infos[5];
  tmp->live = 1260;
  tmp->objs_perso = NULL;
  tmp->queue = NULL;
  tmp->next = *players;
  *players = tmp;
}

void		push_plyr_copy(t_plyr **players, t_plyr *player)
{
  t_plyr	*tmp;

  if ((tmp = malloc(sizeof(t_plyr))) == NULL)
    exit_mess(666, "Error: Bad malloc");
  tmp->so = player->so;
  tmp->id_team = player->id_team;
  tmp->direction = player->direction;
  tmp->level = player->level;
  tmp->x = player->x;
  tmp->y = player->y;
  tmp->forked = player->forked;
  tmp->live = player->live;
  tmp->objs_perso = player->objs_perso;
  tmp->queue = player->queue;
  tmp->next = *players;
  *players = tmp;
}

void		push_plyr_empty(t_plyr **players, int so)
{
  t_plyr	*tmp;

  if ((tmp = malloc(sizeof(t_plyr))) == NULL)
    exit_mess(666, "Error: Bad malloc");
  tmp->so = so;
  tmp->id_team = 0;
  tmp->direction = 0;
  tmp->level = 1;
  tmp->x = 0;
  tmp->y = 0;
  tmp->forked = 0;
  tmp->live = 1260;
  tmp->objs_perso = NULL;
  tmp->queue = NULL;
  tmp->next = *players;
  *players = tmp;
}

void		rm_plyr(t_plyr **players, int so)
{
  t_plyr	*tmp;

  if (*players != NULL)
    {
      tmp = *players;
      if (tmp->so == so)
	*players = (*players)->next;
      else
	{
	  while (tmp->next && tmp->next->so != so)
	    tmp = tmp->next;
	  if (tmp->next)
	    tmp->next = tmp->next->next;
	}
    }
}

t_plyr		*find_plyr_by_so(t_plyr *players, int so)
{
  t_plyr	*tmp;

  tmp = players;
  while (tmp && tmp->so != so)
    tmp = tmp->next;
  return (tmp);
}
