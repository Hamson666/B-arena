/*
** connection.c for zappy in /home/de-mat_a/rendu/PSU_2014_zappy/client/srcs
** 
** Made by François De Matos
** Login   <de-mat_a@epitech.net>
** 
** Started on  Fri Jun 12 01:06:43 2015 François De Matos
** Last update Wed Jul  8 15:57:25 2015 Guillaume Bovier-Lapierre
*/

#include		"lib.h"
#include		"client.h"

void			my_disconnect(int sig __attribute__((unused)))
{
  write(so, "quit\n", 5);
  FD_CLR(so, &fdset);
  close(so);
  so = 0;
  exit_mess(1, "SIGINT !");
}

void			my_connect(t_client *client)
{
  struct protoent	*pro;
  struct sockaddr_in	saddr;
  int			co;

  co = -1;
  pro = getprotobyname("TCP");
  if ((so = socket(AF_INET, SOCK_STREAM, pro->p_proto)) == -1)
    exit_mess(1, "Error: Cannot get a socket");
  saddr.sin_family = AF_INET;
  saddr.sin_port = htons(client->port);
  client->lhost = inet_ntoa(*(struct in_addr *)client->host->h_addr);
  saddr.sin_addr.s_addr = inet_addr(client->lhost);
  if ((co = connect(so, (const struct sockaddr*)&saddr, sizeof(saddr))) == -1)
    {
      printf("Cannot connect to %s:%d\n",
	     inet_ntoa(saddr.sin_addr), client->port);
      exit(-1);
    }
  FD_SET(so, &fdset);
}
