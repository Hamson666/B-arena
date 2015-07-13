/*
** incantation1.c for incant in /home/cantin_t/rendu/PSU_2014_zappy/server/srcs
** 
** Made by Thomas Cantin
** Login   <cantin_t@epitech.net>
** 
** Started on  Tue Jun 30 17:06:18 2015 Thomas Cantin
** Last update Thu Jul  9 00:02:24 2015 François De Matos
*/

#include "server.h"

int		evolve_2(t_plyr *player)
{
  if (count_nb_objects(player->objs_perso, LINEMATE) < 1)
    return (0);
  else
    return (1);
}

int		evolve_3(t_plyr *player)
{
  t_map		*node;
  t_plyr	*tmp;
  int		count_p;

  if (count_nb_objects(player->objs_perso, LINEMATE) < 1 ||
      count_nb_objects(player->objs_perso, DERAUMERE) < 1 ||
      count_nb_objects(player->objs_perso, SIBUR) < 1)
    return (0);
  else
    {
      node = get_map(&map, player->x, player->y);
      tmp = node->players;
      count_p = 0;
      while (tmp->next != NULL)
	{
	  tmp = tmp->next;
	  if (tmp->x == player->x && tmp->y == player->y)
	    ++count_p;
	}
      if (count_p == 2)
	return (1);
    }
  return (0);
}

int		evolve_4(t_plyr *player)
{
  t_map		*node;
  t_plyr	*tmp;
  int		count_p;

  if (count_nb_objects(player->objs_perso, LINEMATE) < 2 ||
      count_nb_objects(player->objs_perso, SIBUR) < 1 ||
     count_nb_objects(player->objs_perso, PHIRAS) < 2)
    return (0);
  else
    {
      node = get_map(&map, player->x, player->y);
      tmp = node->players;
      count_p = 0;
      while (tmp->next != NULL)
	{
	  tmp = tmp->next;
	  if (tmp->x == player->x && tmp->y == player->y)
	    ++count_p;
	}
      if (count_p == 2)
	return (1);
    }
  return (0);
}

int		evolve_5(t_plyr *player)
{
  t_map		*node;
  t_plyr	*tmp;
  int		count_p;

  if (count_nb_objects(player->objs_perso, LINEMATE) < 1 ||
      count_nb_objects(player->objs_perso, DERAUMERE) < 1 ||
      count_nb_objects(player->objs_perso, SIBUR) < 2 ||
      count_nb_objects(player->objs_perso, PHIRAS) < 1)
    return (0);
  else
    {
      node = get_map(&map, player->x, player->y);
      tmp = node->players;
      count_p = 0;
      while (tmp->next != NULL)
	{
	  tmp = tmp->next;
	  if (tmp->x == player->x && tmp->y == player->y)
	    ++count_p;
	}
      if (count_p == 4)
	return (1);
    }
  return (0);
}

int		evolve_6(t_plyr *player)
{
  t_map		*node;
  t_plyr	*tmp;
  int		count_p;

  if (count_nb_objects(player->objs_perso, LINEMATE) < 1 ||
      count_nb_objects(player->objs_perso, DERAUMERE) < 2 ||
      count_nb_objects(player->objs_perso, SIBUR) < 1 ||
      count_nb_objects(player->objs_perso, MENDIANE) < 3)
    return (0);
  else
    {
      node = get_map(&map, player->x, player->y);
      tmp = node->players;
      count_p = 0;
      while (tmp->next != NULL)
	{
	  tmp = tmp->next;
	  if (tmp->x == player->x && tmp->y == player->y)
	    ++count_p;
	}
      if (count_p == 4)
	return (1);
    }
  return (0);
}
