/*
** cmds4.c for cmds4 in /home/cantin_t/rendu/PSU_2014_zappy/server/srcs
** 
** Made by Thomas Cantin
** Login   <cantin_t@epitech.net>
** 
** Started on  Tue Jun 30 16:49:20 2015 Thomas Cantin
** Last update Wed Jul  8 16:11:59 2015 Guillaume Bovier-Lapierre
*/

#include "server.h"
#include "map.h"

int	incant(t_plyr *player, int aim_lvl)
{
  int	(*evolve[8])(t_plyr *);
  char	buff[50];

  evolve[0] = &evolve_2;
  evolve[1] = &evolve_3;
  evolve[2] = &evolve_4;
  evolve[3] = &evolve_5;
  evolve[4] = &evolve_6;
  evolve[5] = &evolve_7;
  evolve[6] = &evolve_8;
  if (aim_lvl - 1 != player->level)
    return (0);
  if (evolve[aim_lvl - 2](player))
    {
      if (server.graph_so != -1)
	sprintf(buff, "pie %d %d %d\n", player->x, player->y, 1);
      drop_for_incant(player, aim_lvl);
      player->level++;
      consume(aim_lvl);
      return (1);
    }
  return (0);
}

void	consume(int aim_lvl)
{
  void	(*consum[8])();

  consum[0] = &consum_2;
  consum[1] = &consum_3;
  consum[2] = &consum_4;
  consum[3] = &consum_5;
  consum[4] = &consum_6;
  consum[5] = &consum_7;
  consum[6] = &consum_8;
  consum[aim_lvl - 2]();
}

void	drop_for_incant(t_plyr *player, int level)
{
  void	(*drop[8])();

  drop[0] = &drop_2;
  drop[1] = &drop_3;
  drop[2] = &drop_4;
  drop[3] = &drop_5;
  drop[4] = &drop_6;
  drop[5] = &drop_7;
  drop[6] = &drop_8;
  drop[level - 2](player);
}

