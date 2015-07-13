/*
** opt2.c for zappy in /home/limagn_v/rendu/PSU_2014_zappy/server/srcs
** 
** Made by Valentin Limagne
** Login   <limagn_v@epitech.net>
** 
** Started on  Thu Jun 11 16:19:39 2015 Valentin Limagne
** Last update Sat Jul  4 15:36:40 2015 François De Matos
*/

#include "server.h"
#include "verify_args.h"

int		opt_n(t_serv *serv __attribute__((unused)), char **av, int *i)
{
  int		x;
  int		y;

  x = 0;
  y = 0;
  (*i)++;
  if (av[*i] == NULL || av[*i][x] == '-')
    {
      printf("No team have been set\n");
      return (0);
    }
  while (av[(*i)] && av[*i][x] != '-')
    {
      pushteam(&teams, y, av[*i]);
      (*i)++;
      ++y;
    }
  (*i)--;
  return (0);
}
