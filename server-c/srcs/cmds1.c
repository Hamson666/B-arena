/*
** cmds1.c for zappy in /home/de-mat_a/rendu/PSU_2014_zappy/server/srcs
** 
** Made by François De Matos
** Login   <de-mat_a@epitech.net>
** 
** Started on  Wed Jun 17 00:53:14 2015 François De Matos
** Last update Thu Jul  9 00:02:01 2015 François De Matos
*/

#include	"server.h"

void		avance(t_plyr *player, char *param __attribute__((unused)))
{
  t_map		*tmp;
  char          buff[50];

  tmp = get_map(&map, player->x, player->y);
  rm_plyr(&(tmp->players), player->so);
  if (player->direction == 3)
    player->x = player->x == 0 ? server.width - 1 : player->x - 1;
  else if (player->direction == 1)
    player->x = player->x == server.width - 1 ? 0 : player->x + 1;
  if (player->direction == 0)
    player->y = player->y == 0 ? server.width - 1 : player->y - 1;
  else if (player->direction == 2)
    player->y = player->y == server.width - 1 ? 0 : player->y + 1;
  tmp = get_map(&map, player->x, player->y);
  push_plyr_copy(&(tmp->players), player);
  my_write(player->so, "ok", 2);
  if (server.graph_so != -1)
    sprintf(buff, "ppo %d %d %d %d\n",
	    player->so, player->x, player->y, player->direction);
}

void		droite(t_plyr *player, char *param __attribute__((unused)))
{
  char          buff[50];

  if (player->direction == 3)
    player->direction = 0;
  else
    (player->direction)++;
  my_write(player->so, "ok", 2);
  if (server.graph_so != -1)
    sprintf(buff, "ppo %d %d %d %d\n",
	    player->so, player->x, player->y, player->direction);
}

void		gauche(t_plyr *player, char *param __attribute__((unused)))
{
  char          buff[50];

  if (player->direction == 0)
    player->direction = 3;
  else
    (player->direction)--;
  my_write(player->so, "ok", 2);
  if (server.graph_so != -1)
    sprintf(buff, "ppo %d %d %d %d\n",
	    player->so, player->x, player->y, player->direction);
}

void		inventaire(t_plyr *player, char *param __attribute__((unused)))
{
  int		i;
  char		nb[250];
  char		tmp[50];
  char		tmp2[250];

  i = 0;
  memcpy(&nb[0], "{\0", 2);
  sprintf(tmp, "nourriture %d", player->live / 126);
  strcat(nb, tmp);
  if (server.graph_so != -1)
    sprintf(tmp2, "pin %d %d %d" , player->so, player->x, player->y);
  while (++i < 7)
    {
      strcat(nb, ", ");
      strcat(nb, objs[i]);
      strcat(nb, " ");
      sprintf(tmp, "%d", count_nb_objects(player->objs_perso, (e_id)i));
      if (server.graph_so != -1)
	sprintf(tmp2, "%d ", count_nb_objects(player->objs_perso, (e_id)i));
      strcat(nb, tmp);
    }
  strcat(nb, "}");
  my_write(player->so, nb, strlen(nb));
}
