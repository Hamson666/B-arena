/*
** init_plyr.c for zappy in /home/de-mat_a/rendu/PSU_2014_zappy/server/srcs
** 
** Made by François De Matos
** Login   <de-mat_a@epitech.net>
** 
** Started on  Mon Jun 29 22:27:19 2015 François De Matos
** Last update Thu Jul  9 00:02:11 2015 François De Matos
*/

#include	"server.h"
#include	"players.h"

void		init_plyr(t_plyr *player, int id_team)
{
  t_map		*tmp;

  player->id_team = id_team;
  player->direction = rand() % 3;
  player->x = rand() % (server.width - 1);
  player->y = rand() % (server.height - 1);
  tmp = get_map(&map, player->x, player->y);
  push_plyr_copy(&(tmp->players), player);
}
