/*
** consum2.c for consum in /home/cantin_t/rendu/PSU_2014_zappy/server/srcs
** 
** Made by Thomas Cantin
** Login   <cantin_t@epitech.net>
** 
** Started on  Wed Jul  1 17:22:08 2015 Thomas Cantin
** Last update Thu Jul  2 20:10:59 2015 Thomas Cantin
*/

#include "objects.h"
#include "map.h"

void	consum_6()
{
  rm_nbr_obj(&(map->objects), LINEMATE, 1);
  rm_nbr_obj(&(map->objects), DERAUMERE, 2);
  rm_nbr_obj(&(map->objects), SIBUR, 1);
  rm_nbr_obj(&(map->objects), MENDIANE, 3);
}

void	consum_7()
{
  rm_nbr_obj(&(map->objects), LINEMATE, 1);
  rm_nbr_obj(&(map->objects), DERAUMERE, 2);
  rm_nbr_obj(&(map->objects), SIBUR, 3);
  rm_nbr_obj(&(map->objects), PHIRAS, 1);
}

void	consum_8()
{
  rm_nbr_obj(&(map->objects), LINEMATE, 2);
  rm_nbr_obj(&(map->objects), DERAUMERE, 2);
  rm_nbr_obj(&(map->objects), SIBUR, 2);
  rm_nbr_obj(&(map->objects), MENDIANE, 2);
  rm_nbr_obj(&(map->objects), PHIRAS, 2);
  rm_nbr_obj(&(map->objects), THYSTAME, 1);
}
