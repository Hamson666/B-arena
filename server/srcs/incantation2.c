/*
** incantations2.c for incant2 in /home/cantin_t/rendu/PSU_2014_zappy/server/srcs
** 
** Made by Thomas Cantin
** Login   <cantin_t@epitech.net>
** 
** Started on  Tue Jun 30 20:36:15 2015 Thomas Cantin
** Last update Thu Jul  9 00:02:37 2015 François De Matos
*/

#include "server.h"

int     evolve_7(t_plyr *player)
{
  t_map         *node;
  t_plyr        *tmp;
  int           count_p;

  if (count_nb_objects(player->objs_perso, LINEMATE) < 1 ||
      count_nb_objects(player->objs_perso, DERAUMERE) < 2 ||
      count_nb_objects(player->objs_perso, SIBUR) < 3 ||
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
      if (count_p == 6)
        return (1);
    }
  return (0);
}

int     evolve_8(t_plyr *player)
{
  t_map         *node;
  t_plyr        *tmp;
  int           count_p;

  if (count_nb_objects(player->objs_perso, LINEMATE) >= 2 ||
      count_nb_objects(player->objs_perso, DERAUMERE) >= 2 ||
      count_nb_objects(player->objs_perso, SIBUR) >= 2 ||
      count_nb_objects(player->objs_perso, PHIRAS) >= 2 ||
      count_nb_objects(player->objs_perso, MENDIANE) >= 2 ||
      count_nb_objects(player->objs_perso, THYSTAME) >= 1)
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
      if (count_p == 6)
        return (1);
    }
  return (0);
}
