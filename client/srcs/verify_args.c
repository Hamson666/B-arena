/*
** verify_args.c for zappy in /home/limagn_v/rendu/PSU_2014_zappy/client/srcs
** 
** Made by Valentin Limagne
** Login   <limagn_v@epitech.net>
** 
** Started on  Mon Jun 15 13:12:34 2015 Valentin Limagne
** Last update Wed Jul  8 15:53:02 2015 Guillaume Bovier-Lapierre
*/

#include        <unistd.h>
#include	"client.h"
#include        "verify_args.h"

int		find_opt(char *buff)
{
  int		i;
  char		opt_tab[3][3] =
    {
      "-p",
      "-n",
      "-h",
    };
  i = 0;
  while (i < 3 && (strcmp(buff, opt_tab[i]) != 0))
    ++i;
  return (i);
}

int		print_error_client(int *bool)
{
  if (*bool == 0)
    {
      printf("Usage : ./client [-p port] [-h hostname] [-n team_name]\n");
      *bool = 1;
    }
  return (0);
}

int		opt(t_client *client, int ac, char **av)
{
  int		(*funct_tab[3])(t_client*, char **, int *);
  int		i;
  int		x;
  int		bool;

  funct_tab[0] =  &opt_p;
  funct_tab[1] =  &opt_n;
  funct_tab[2] =  &opt_h;
  i = 1;
  bool = 0;
  while (i < ac)
    {
      x = find_opt(av[i]);
      if (x >= 3)
	print_error_client(&bool);
      else
	funct_tab[x](client, av, &i);
      ++i;
    }
  return (0);
}

int		verify_args(int ac, char **av, t_client *client)
{
  client->port = 4242;
  client->host = gethostbyname("localhost");
  client->lhost = inet_ntoa(*(struct in_addr *)client->host->h_addr);
  client->team = NULL;
  opt(client, ac, av);
  return (0);
}
