/*
** verify_args.c for zappy in /home/de-mat_a/rendu/PSU_2014_zappy/server/srcs
** 
** Made by François De Matos
** Login   <de-mat_a@epitech.net>
** 
** Started on  Mon Jun  1 13:34:14 2015 François De Matos
** Last update Sun Jul  5 16:41:07 2015 Guillaume Bovier-Lapierre
*/

#include	<unistd.h>
#include	"server.h"
#include	"verify_args.h"

int		find_opt(char *buff)
{
  int		i;
  char		opt_tab[6][3] =
    {
      "-p",
      "-x",
      "-y",
      "-n",
      "-c",
      "-t",
    };
  i = 0;
  while (i < 6 && (strcmp(buff, opt_tab[i]) != 0))
    ++i;
  return (i);
}

int		 print_error_serv(int *bool)
{
  if (*bool == 0)
    {
      printf("Usage: ./server [-p port] [-x world_width]\
 [-y world_height] [-n team_name_1 [team_name_2...]]\
 [-c clients_allowed_by_team] [-t time_delay]\n");
      *bool = 1;
    }
  return (0);
}

int		opt(t_serv *serv, int ac, char **av)
{
  int		(*funct_tab[6])(t_serv*, char **, int *);
  int		i;
  int		x;
  int		bool;

  funct_tab[0] = &opt_p;
  funct_tab[1] = &opt_x;
  funct_tab[2] = &opt_y;
  funct_tab[3] = &opt_n;
  funct_tab[4] = &opt_c;
  funct_tab[5] = &opt_t;
  i = 1;
  bool = 0;
  while (i < ac)
    {
      x = find_opt(av[i]);
      if (x >= 6)
	print_error_serv(&bool);
      else
	funct_tab[x](serv, av, &i);
      i++;
    }
  return (0);
}

int		verify_args(int ac, char **av __attribute__((unused)), t_serv *serv)
{
  serv->port = 4242;
  serv->width = 20;
  serv->height = 20;
  serv->teams = NULL;
  serv->clients_by_team = 5;
  serv->time_delay = 100;
  opt(serv, ac, av);
  printf("\e[0;33mStarting server...\n\
Port : %i\nWorld's width : %i\nWorld's height : %i\nTeams name :%s\n\
Number of clients accepted by team : %i\nTime unity : %i\e[m\n\n",
	 serv->port, serv->width, serv->height, dump_teams(teams),
	 serv->clients_by_team, serv->time_delay);
  return 0;
}
