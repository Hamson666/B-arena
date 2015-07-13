/*
** connection.c for zappy in /home/de-mat_a/rendu/PSU_2014_zappy/server/srcs
** 
** Made by François De Matos
** Login   <de-mat_a@epitech.net>
** 
** Started on  Thu Jul  9 00:07:48 2015 François De Matos
** Last update Thu Jul  9 00:11:08 2015 François De Matos
*/

#include	"server.h"

void		accept_co(int sockfd, t_team *team)
{
  char		buff[4097];

  push_plyr_empty(&players, sockfd);
  init_plyr(players, team->id_team);
  sprintf(buff, "%d\n", server.clients_by_team);
  my_write(sockfd, buff, strlen(buff));
  usleep(500);
  sprintf(buff, "%d %d", server.width, server.height);
  my_write(sockfd, buff, strlen(buff));
}

void		invalid_co(int sockfd, fd_set *tmp)
{
  my_write(sockfd, "Invalid team name", 17);
  FD_CLR(sockfd, tmp);
  close(sockfd);
}
