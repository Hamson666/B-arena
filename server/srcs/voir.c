/*
** voir.c for zappy in /home/de-mat_a/rendu/PSU_2014_zappy/server/srcs
** 
** Made by François De Matos
** Login   <de-mat_a@epitech.net>
** 
** Started on  Sat Jun 27 18:17:38 2015 François De Matos
** Last update Wed Jul  8 23:57:08 2015 François De Matos
*/

#include	"server.h"

char		*parcours_line(t_plyr *player, t_map *tmp, int *c, int i)
{
  int		j;
  char		*ret;

  ret = NULL;
  j = -i - 1;
  while (++j < (i * 2) + 1 - i)
    {
      if (player->direction == 0 || player->direction == 2)
	{
	  if (player->direction == 0)
	    tmp = get_map(&map, player->x + c[1] + j, player->y + c[0]);
	  else
	    tmp = get_map(&map, player->x - c[1] - j, player->y + c[0]);
	}
      else
	{
	  if (player->direction == 1)
	    tmp = get_map(&map, player->x + c[0], player->y + c[1] + j);
	  else
	    tmp = get_map(&map, player->x + c[0], player->y - c[1] - j);
	}
      ret = my_strcat(my_strcat(ret, ", "), dump_players(tmp->players));
      ret = my_strcat(ret, dump_objects(tmp->objects));
    }
  return (ret);
}

void            voir(t_plyr *player, char *param __attribute__((unused)))
{
  int           i;
  int           c[2];
  t_map         *tmp;
  char		*ret;

  ret = NULL;
  i = 0;
  c[0] = 0;
  c[1] = 0;
  tmp = get_map(&map, player->x, player->y);
  ret = my_strcat(ret, "{");
  ret = my_strcat(ret, dump_players(tmp->players));
  ret = my_strcat(ret, dump_objects(tmp->objects));
  while (i < player->level)
    {
      ++i;
      if (player->direction == 0 || player->direction == 3)
	c[0]--;
      else
	c[0]++;
      strcat(ret, parcours_line(player, tmp, c, i));
    }
  ret = my_strcat(ret, "}");
  my_write(player->so, ret, strlen(ret));
}
