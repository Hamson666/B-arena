/*
** list_teams.c for zappy in /home/de-mat_a/rendu/PSU_2014_zappy/server/libs
** 
** Made by François De Matos
** Login   <de-mat_a@epitech.net>
** 
** Started on  Mon Jun  1 16:17:55 2015 François De Matos
** Last update Sun Jul  5 20:49:54 2015 François De Matos
*/

#include	"server.h"
#include	"players.h"

void		pushteam(t_team **teams, int id_team, char *name)
{
  t_team	*tmp;

  if ((tmp = malloc(sizeof(t_team))) == NULL)
    exit_mess(1, "Error: Bad malloc");
  tmp->id_team = id_team;
  tmp->name = strdup(name);
  tmp->nb_eggs = 0;
  tmp->next = *teams;
  *teams = tmp;
}

int		count_nb_players_in_team(t_team *team)
{
  t_plyr	*tmp;
  int		i;

  tmp = players;
  i = 0;
  while (tmp)
    {
      if (tmp->id_team == team->id_team)
	++i;
      tmp = tmp->next;
    }
  return (i);
}

t_team		*find_team_by_id(int id_team)
{
  t_team	*tmp;

  tmp = teams;
  while (tmp && tmp->id_team != id_team)
    tmp = tmp->next;
  return (tmp);
}

t_team		*find_team_by_name(char *name)
{
  t_team	*tmp;

  tmp = teams;
  while (tmp && strncmp(tmp->name, name, strlen(tmp->name)) != 0)
    tmp = tmp->next;
  return (tmp);
}

char		*dump_teams(t_team *teams)
{
  t_team	*tmp;
  char		*ret;

  tmp = teams;
  if ((ret = malloc(sizeof(char))) == NULL)
    exit_mess(666, "Error: Bad malloc");
  ret[0] = 0;
  while (tmp)
    {
      if ((ret = realloc(ret, sizeof(char) * (strlen(tmp->name) + 1))) == NULL)
	exit_mess(666, "Error: Bad malloc");
      strcat(ret, " ");
      strcat(ret, tmp->name);
      tmp = tmp->next;
    }
  return (ret);
}
