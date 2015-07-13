/*
** cmds3.c for zappy in /home/de-mat_a/rendu/PSU_2014_zappy/server/srcs
** 
** Made by François De Matos
** Login   <de-mat_a@epitech.net>
** 
** Started on  Wed Jun 17 00:56:03 2015 François De Matos
** Last update Wed Jul  8 16:11:42 2015 Guillaume Bovier-Lapierre
*/

#include	"server.h"

void		my_fork(t_plyr *player, char *param __attribute__((unused)))
{
  t_team	*tmp;
  int		infos[6];
  char		buff[50];

  tmp = find_team_by_id(player->id_team);
  (tmp->nb_eggs)++;
  infos[0] = tmp->id_team;
  infos[1] = rand();
  infos[2] = 1;
  infos[3] = player->x;
  infos[4] = player->y;
  push_plyr(&players, infos, -1);
  if (server.graph_so != -1)
    {
      sprintf(buff, "pfk %d\n", player->so);
      sprintf(buff, "enw %d %d %d %d\n",
	      tmp->nb_eggs, player->so, player->x, player->y);
      sprintf(buff, "eht %d\n", tmp->nb_eggs);
    }
  my_write(player->so, "ok", 2);
}

void		connect_nbr(t_plyr *player, char *param __attribute__((unused)))
{
  t_team	*tmp;
  int		nb;
  char		nb_char[5];

  tmp = find_team_by_id(player->id_team);
  nb = server.clients_by_team + tmp->nb_eggs - count_nb_players_in_team(tmp);
  sprintf(nb_char, "%d", nb);
  my_write(player->so, nb_char, strlen(nb_char));
}

void		mort(t_plyr **player, fd_set *fdset)
{
  t_plyr	*tmp;
  t_plyr	*tmp2;
  int		so;

  tmp = *player;
  tmp2 = tmp->next;
  so = tmp->so;
  my_write(so, "mort", 4);
  FD_CLR(so, fdset);
  close(so);
  rm_plyr(&players, so);
  write(1, "Disconnection.\n", 15);
  tmp = players;
  while (tmp)
    {
      server.maxfd = tmp->so > server.maxfd ? tmp->so : server.maxfd;
      tmp = tmp->next;
    }
  *player = tmp2;
}
