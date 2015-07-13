/*
** map.c for zappy in /home/de-mat_a/rendu/PSU_2014_zappy/server/srcs
** 
** Made by François De Matos
** Login   <de-mat_a@epitech.net>
** 
** Started on  Thu Jun  4 22:42:28 2015 François De Matos
** Last update Thu Jul  9 00:00:17 2015 François De Matos
*/

#include	"map.h"

static void	push_map(t_map **map, int x, int y)
{
  t_map		*tmp;

  if ((tmp = malloc(sizeof(t_map))) == NULL)
    exit_mess(666, "Error: Bad malloc");
  tmp->x = x;
  tmp->y = y;
  tmp->objects = NULL;
  tmp->players = NULL;
  if (*map == NULL)
    {
      tmp->next = tmp;
      tmp->prev = tmp;
      *map = tmp;
    }
  else
    {
      tmp->prev = (*map)->prev;
      tmp->next = *map;
    }
  (*map)->prev->next = tmp;
  (*map)->prev = tmp;
  *map = tmp;
}

t_map		*get_map(t_map **map, int x, int y)
{
  t_map		*tmp;

  while (x < 0)
    x = x + server.width;
  while (y < 0)
    y = y + server.width;
  while (x >= server.width)
    x = x - server.width;
  while (y >= server.width)
    y = y - server.width;
  tmp = *map;
  while (tmp && (tmp->x != x || tmp->y != y))
    tmp = tmp->next;
  return (tmp);
}

void		gen_map(t_map **map, int width, int height)
{
  int		x;
  int		y;

  y = height;
  write(1, "Generation de la map en cours...", 32);
  while (y > 0)
    {
      y--;
      x = width;
      while (x > 0)
	{
	  x--;
	  push_map(map, x, y);
	  push_obj(&((*map)->objects), (e_id)((rand() % 8) - 1));
	}
    }
  write(1, " Termine !\n", 11);
}
