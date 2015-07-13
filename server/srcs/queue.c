/*
** queue.c for zappy in /home/de-mat_a/rendu/server/srcs
** 
** Made by François De Matos
** Login   <de-mat_a@epitech.net>
** 
** Started on  Wed Jul  1 23:10:19 2015 François De Matos
** Last update Sun Jul  5 10:17:37 2015 François De Matos
*/

#include	"server.h"
#include	"queue.h"

void		push_queue(t_queu **queue, char *comm, char *param)
{
  t_queu	*tmp;

  if ((tmp = malloc(sizeof(t_queu))) == NULL)
    exit_mess(666, "Error: Bad malloc");
  tmp->comm = strdup(comm);
  tmp->param = strdup(param);
  if (strncmp(comm, "fork", 4) == 0)
    tmp->delay = 42;
  else if (strncmp(comm, "incantation", 11) == 0)
    tmp->delay = 300;
  else
    tmp->delay = strncmp(comm, "connect_nbr", 11) == 0 ? 0 : 7;
  tmp->next = *queue;
  *queue = tmp;
}

void		pop_queue(t_queu **queue)
{
  t_queu	*tmp;
  t_queu	*to_free;

  tmp = *queue;
  if (tmp->next)
    {
      while (tmp->next->next)
	tmp = tmp->next;
      to_free = tmp->next;
      tmp->next = NULL;
      free(to_free);
    }
  else
    {
      free(tmp);
      *queue = NULL;
    }
}
