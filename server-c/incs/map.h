/*
** map.h for zappy in /home/de-mat_a/rendu/PSU_2014_zappy/server/incs
** 
** Made by François De Matos
** Login   <de-mat_a@epitech.net>
** 
** Started on  Mon Jun  1 11:44:44 2015 François De Matos
** Last update Wed Jul  8 23:55:56 2015 François De Matos
*/

#ifndef		MAP_H_
# define	MAP_H_

#include	"lib.h"
#include	"players.h"
#include	"server.h"

typedef struct	s_map
{
  int		x;
  int		y;
  t_objs	*objects;
  t_plyr	*players;
  struct s_map	*prev;
  struct s_map	*next;
}		t_map;

extern t_map	*map;

void		set_ressources(t_map **map, int width, int height);
void		gen_map(t_map**, int, int);
t_map           *get_map(t_map**, int, int);

#endif		/* !MAP_H_ */
