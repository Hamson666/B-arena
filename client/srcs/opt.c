/*
** opt.c for zappy in /home/limagn_v/rendu/PSU_2014_zappy/client/srcs
** 
** Made by Valentin Limagne
** Login   <limagn_v@epitech.net>
** 
** Started on  Mon Jun 15 13:26:26 2015 Valentin Limagne
** Last update Mon Jun 15 21:11:31 2015 Valentin Limagne
*/

#include	"client.h"
#include	"verify_args.h"

int		opt_p(t_client *client, char **av, int *i)
{
  int		x;

  x = 0;
  (*i)++;
  if (av[*i] == NULL || av[*i][x] == ' ')
    {
      printf("Invalid Port Number, 4242 set as default\n");
      return (0);
    }
  while (av[*i][x])
    {
      if (av[*i] && (av[*i][x] < '0' || av[*i][x] > '9'))
        {
          printf("Invalid port Number, 4242 set as default\n");
          return (0);
        }
      x++;
    }
  client->port = atoi(av[*i]);
  printf("port : %i\n", client->port);
  return (0);
}

int		opt_n(t_client *client, char **av, int *i)
{
  int		x;

  x = 0;
  (*i)++;
  if (av[*i] == NULL || av[*i][x] == ' ')
    {
      printf("No team have been set\n");
      return (0);
    }
  client->team = av[(*i)];
  printf("name : %s\n", client->team);
  return (0);
}

int		opt_h(t_client *client, char **av, int *i)
{
  int		x;

  x = 0;
  (*i)++;
  if (av[*i] == NULL || av[*i][x] == ' ')
    {
      printf("This host's name is invalid\n");
      return (0);
    }
  client->host = gethostbyname("localhost");
  client->lhost = inet_ntoa(*(struct in_addr *)client->host->h_addr);
  printf("host : %s, %s\n", client->host->h_name, client->lhost);
  return (0);
}
