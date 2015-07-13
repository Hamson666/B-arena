/*
** queue.h for zappy in /home/de-mat_a/rendu/server/incs
** 
** Made by François De Matos
** Login   <de-mat_a@epitech.net>
** 
** Started on  Wed Jul  1 22:13:02 2015 François De Matos
** Last update Wed Jul  1 23:16:58 2015 François De Matos
*/

#ifndef		QUEUE_H_
# define	QUEUE_H_

typedef struct	s_queu
{
  char		*comm;
  char		*param;
  int		delay;
  struct s_queu	*next;
}		t_queu;

void		push_queue(t_queu**, char*, char*);
void		pop_queue(t_queu**);

#endif		/* !QUEUE_H_ */
