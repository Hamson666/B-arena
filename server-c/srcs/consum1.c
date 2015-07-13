/*
** consum1.c for consum in /home/cantin_t/rendu/PSU_2014_zappy/server/srcs
** 
** Made by Thomas Cantin
** Login   <cantin_t@epitech.net>
** 
** Started on  Wed Jul  1 17:09:43 2015 Thomas Cantin
** Last update Thu Jul  2 20:07:28 2015 Thomas Cantin
*/

#include "map.h"
#include "objects.h"

void	consum_2()
{
  rm_nbr_obj(&(map->objects), LINEMATE, 1);
}

void	consum_3()
{
  rm_nbr_obj(&(map->objects), LINEMATE, 1);
  rm_nbr_obj(&(map->objects), DERAUMERE, 1);
  rm_nbr_obj(&(map->objects), SIBUR, 1);
}

void	consum_4()
{
  rm_nbr_obj(&(map->objects), LINEMATE, 2);
  rm_nbr_obj(&(map->objects), SIBUR, 1);
  rm_nbr_obj(&(map->objects), PHIRAS, 2);
}

void	consum_5()
{
  rm_nbr_obj(&(map->objects), LINEMATE, 1);
  rm_nbr_obj(&(map->objects), DERAUMERE, 1);
  rm_nbr_obj(&(map->objects), SIBUR, 2);
  rm_nbr_obj(&(map->objects), PHIRAS, 1);
}
