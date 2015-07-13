/*
** players.h for zappy in /home/de-mat_a/rendu/PSU_2014_zappy/server/incs
** 
** Made by François De Matos
** Login   <de-mat_a@epitech.net>
** 
** Started on  Mon Jun  1 12:19:48 2015 François De Matos
** Last update Sat Jul  4 17:53:14 2015 François De Matos
*/

#ifndef		PLAYERS_H_
# define	PLAYERS_H_

#include	"objects.h"
#include	"queue.h"

typedef struct	s_plyr
{
  int		so;
  int		id_team;
  int		direction;
  int		level;
  int		x;
  int		y;
  int		forked;
  int		live;
  t_objs	*objs_perso;
  t_queu	*queue;
  struct s_plyr	*next;
}		t_plyr;

void		push_plyr(t_plyr**, int[5], int);
void		push_plyr_copy(t_plyr**, t_plyr*);
void		push_plyr_empty(t_plyr**, int);
void		rm_plyr(t_plyr**, int);
t_plyr		*find_plyr_by_so(t_plyr*, int);

void		init_plyr(t_plyr*, int);

#endif		/* !PLAYERS_H_ */
