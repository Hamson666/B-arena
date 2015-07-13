/*
** client.h for zappy in /home/de-mat_a/rendu/PSU_2014_zappy/client/incs
** 
** Made by François De Matos
** Login   <de-mat_a@epitech.net>
** 
** Started on  Fri Jun 12 01:04:41 2015 François De Matos
** Last update Wed Jul  8 15:55:46 2015 Guillaume Bovier-Lapierre
*/

#ifndef		CLIENT_H_
# define	CLIENT_H_

#include	<sys/types.h>
#include	<sys/stat.h>
#include	<sys/socket.h>
#include	<sys/select.h>
#include	<netinet/in.h>
#include	<arpa/inet.h>
#include	<netdb.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>
#include	<unistd.h>
#include	<fcntl.h>
#include	<signal.h>

#define		MAX(x, y)	x > y ? x : y

extern int	so;
extern fd_set	fdset;

typedef struct	s_client
{
  int		port;
  char		*lhost;
  char		*team;
  struct hostent	*host;
}		t_client;

#endif		/* !CLIENT_H_ */
