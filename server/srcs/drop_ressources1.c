/*
** drop_ressources1.c for drop_ressources in /home/cantin_t/rendu/PSU_2014_zappy/server/srcs
** 
** Made by Thomas Cantin
** Login   <cantin_t@epitech.net>
** 
** Started on  Wed Jul  1 18:46:07 2015 Thomas Cantin
** Last update Thu Jul  2 20:11:26 2015 Thomas Cantin
*/

#include	"map.h"
#include	"players.h"

void	drop_2(t_plyr *player)
{
  pose(player, "Linemate");
}

void	drop_3(t_plyr *player)
{
  pose(player, "Linemate");
  pose(player, "Deraumere");
  pose(player, "Sibur");
}

void	drop_4(t_plyr *player)
{
  pose(player, "Linemate");
  pose(player, "Linemate");
  pose(player, "Sibur");
  pose(player, "Phiras");
  pose(player, "Phiras");
}

void	drop_5(t_plyr *player)
{
  pose(player, "Linemate");
  pose(player, "Linemate");
  pose(player, "Sibur");
  pose(player, "Sibur");
  pose(player, "Phiras");
}
