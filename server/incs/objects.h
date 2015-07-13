/*
** objects.h for Zappy in /home/de-mat_a/rendu/PSU_2014_zappy/server/incs
** 
** Made by François De Matos
** Login   <de-mat_a@epitech.net>
** 
** Started on  Mon Jun  1 11:48:49 2015 François De Matos
** Last update Wed Jul  8 16:04:05 2015 Guillaume Bovier-Lapierre
*/

#ifndef		OBJECTS_H_
# define	OBJECTS_H_

#include	<stdlib.h>
#include	"lib.h"

typedef enum	s_id
{
  FOOD,
  LINEMATE,
  DERAUMERE,
  SIBUR,
  MENDIANE,
  PHIRAS,
  THYSTAME
}		e_id;

typedef struct	s_objs
{
  e_id		id;
  struct s_objs	*next;
}		t_objs;

void		push_obj(t_objs**, e_id);
int		rm_obj(t_objs**, e_id);
void		dump_objs(t_objs*);
int		count_nb_objects(t_objs*, e_id);
int		rm_nbr_obj(t_objs **, e_id, int);

#endif		/* !OBJECTS_H_ */
