/*
** cmds2.c for zappy in /home/de-mat_a/rendu/PSU_2014_zappy/server/srcs
** 
** Made by François De Matos
** Login   <de-mat_a@epitech.net>
** 
** Started on  Wed Jun 17 00:54:31 2015 François De Matos
** Last update Thu Jul  9 00:01:06 2015 François De Matos
*/

#include	"server.h"

void		prend(t_plyr *player, char *param)
{
  char		*(objs[7]);
  int	        i;
  t_map		*node;

  i = 0;
  objs[0] = strdup("nourriture");
  objs[1] = strdup("linemate");
  objs[2] = strdup("deraumère");
  objs[3] = strdup("sibur");
  objs[4] = strdup("mendiane");
  objs[5] = strdup("phiras");
  objs[6] = strdup("thystame");
  while (strncmp(param, objs[i], strlen(objs[i])) != 0 && i < 7)
    ++i;
  node = get_map(&map, player->x, player->y);
  if (rm_obj(&(node->objects), (e_id)i) == 1)
    my_write(player->so, "ko", 2);
  else
    {
      if (i == 0)
	player->live += 126;
      else
	push_obj(&(player->objs_perso), (e_id)i);
      my_write(player->so, "ok", 2);
    }
}

void		pose(t_plyr *player, char *param)
{
  char		*(objs[7]);
  int	        i;
  t_map		*node;

  i = 1;
  objs[1] = strdup("linemate");
  objs[2] = strdup("deraumère");
  objs[3] = strdup("sibur");
  objs[4] = strdup("mendiane");
  objs[5] = strdup("phiras");
  objs[6] = strdup("thystame");
  while (strncmp(param, objs[i], strlen(objs[i])) != 0 && i < 7)
    ++i;
  node = get_map(&map, player->x, player->y);
  if (rm_obj(&(player->objs_perso), (e_id)i) == 1)
    my_write(player->so, "ko", 2);
  else
    {
      push_obj(&(node->objects), (e_id)i);
      my_write(player->so, "ok", 2);
    }
}

void		expulse(t_plyr *player, char *param __attribute__((unused)))
{
  t_map		*tmp;
  t_plyr	*tmp_plyr;
  t_plyr	*tmp_plyr2;

  tmp = get_map(&map, player->x, player->y);
  tmp_plyr = tmp->players;
  while (tmp_plyr)
    {
      if (tmp_plyr->so != player->so)
	{
	  tmp_plyr2 = find_plyr_by_so(players, tmp_plyr->so);
	  rm_plyr(&(tmp->players), tmp_plyr->so);
	  if (player->direction == 0)
	    (tmp_plyr2->y)--;
	  else if (player->direction == 2)
	    (tmp_plyr2->y)++;
	  if (player->direction == 3)
	    (tmp_plyr2->x)--;
	  else if (player->direction == 1)
	    (tmp_plyr2->x)++;
	  tmp = get_map(&map, tmp_plyr2->x, tmp_plyr2->y);
	  push_plyr_copy(&(tmp->players), tmp_plyr2);
	  tmp = get_map(&map, player->x, player->y);
	}
      tmp_plyr = tmp_plyr->next;
    }
  my_write(player->so, "ok", 2);
}

void		incantation(t_plyr *player, char *param __attribute__((unused)))
{
  if (incant(player, player->level + 1) == 0)
    my_write(player->so, "ok", 2);
  else
    my_write(player->so, "ko", 2);
}
