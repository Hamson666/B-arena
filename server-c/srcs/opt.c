/*
** opt.c for zappy in /home/limagn_v/rendu/PSU_2014_zappy/server/srcs
** 
** Made by Valentin Limagne
** Login   <limagn_v@epitech.net>
** 
** Started on  Thu Jun 11 16:05:16 2015 Valentin Limagne
** Last update Tue Jun 16 15:17:30 2015 Valentin Limagne
*/

#include "server.h"
#include "verify_args.h"

int		opt_p(t_serv *serv, char **av, int *i)
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
  serv->port = atoi(av[*i]);
  return (0);
}

int		opt_x(t_serv *serv, char **av, int *i)
{
  int		x;

  x = 0;
  (*i)++;
  if (av[*i] == NULL || av[*i][x] == ' ')
    {
      printf("Invalide Width, 20 set as default\n");
      return (0);
    }
  while (av[*i][x])
    {
      if (av[*i] && (av[*i][x] < '0' || av[*i][x] > '9'))
	{
	  printf("Invalide Width, 20 set as default\n");
	  return (0);
	}
      x++;
    }
  serv->width = atoi(av[*i]);
  return (0);
}

int		opt_y(t_serv *serv, char **av, int *i)
{
  int		x;

  x = 0;
  (*i)++;
  if (av[*i] == NULL || av[*i][x] == ' ')
    {
      printf("Invalide Height, 20 set as default\n");
      return (0);
    }
  while (av[*i][x])
    {
      if (av[*i] && (av[*i][x] < '0' || av[*i][x] > '9'))
	{
	  printf("Invalide Height, 20 set as default\n");
	  return (0);
	}
      x++;
    }
  serv->height = atoi(av[*i]);
  return (0);
}

int		opt_c(t_serv *serv, char **av, int *i)
{
  int		x;

  x = 0;
  (*i)++;
  if (av[*i] == NULL || av[*i][x] == ' ')
    {
      printf("Invalide client by team, 5 set as default\n");
      return (0);
    }
  while (av[*i][x])
    {
      if (av[*i] && (av[*i][x] < '0' || av[*i][x] > '9'))
	{
	  printf("Invalide client by team, 5 set as default\n");
	  return (0);
	}
      x++;
    }
  serv->clients_by_team = atoi(av[*i]);
  return (0);
}

int		opt_t(t_serv *serv, char **av, int *i)
{
  int		x;

  x = 0;
  (*i)++;
  if (av[*i] == NULL || av[*i][x] == ' ')
    {
      printf("Invalide time delay, 100 set as default\n");
      return (0);
    }
  while (av[*i][x])
    {
      if (av[*i] && (av[*i][x] < '0' || av[*i][x] > '9'))
	{
	  printf("Invalide time delay, 100 set as default\n");
	  return (0);
	}
      x++;
    }
  serv->time_delay = atoi(av[*i]);
  return (0);
}
