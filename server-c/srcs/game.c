/*
** game.c for zappy in /home/de-mat_a/rendu/PSU_2014_zappy/server/srcs
** 
** Made by François De Matos
** Login   <de-mat_a@epitech.net>
** 
** Started on  Thu Jul  2 22:59:41 2015 François De Matos
** Last update Wed Jul  8 22:54:46 2015 François De Matos
*/

#include	"server.h"

void		execute_loop_2(t_queu *queue, char (*cmds)[50],
			       void (*func[12])(t_plyr*, char*), t_plyr *tmp)
{
  t_queu	*comm;
  int		i;

  comm = queue;
  while (comm->next)
    comm = comm->next;
  if (comm->delay != 0)
    comm->delay--;
  else
    {
      i = 0;
      while (i < 12 && strncmp(cmds[i], comm->comm, strlen(cmds[i])) != 0)
	++i;
      func[i](tmp, comm->param);
      pop_queue(&(tmp->queue));
    }
}

void		execute_loop(fd_set *fdset)
{
  t_plyr	*tmp;
  char		cmds[12][50];
  void		(*func[12])(t_plyr*, char*);

  tmp = players;
  fill_tabs(cmds, func);
  while (tmp)
  {
    tmp->live--;
    if (tmp->live == 0)
      mort(&tmp, fdset);
    else if (tmp->queue)
      {
	execute_loop_2(tmp->queue, cmds, func, tmp);
	tmp = tmp->next;
      }
    else
      tmp = tmp->next;
  }
}

