/*
** objects.c for zappy in /home/de-mat_a/rendu/PSU_2014_zappy/server/srcs
** 
** Made by François De Matos
** Login   <de-mat_a@epitech.net>
** 
** Started on  Thu Jun  4 21:03:09 2015 François De Matos
** Last update Sun Jul  5 22:52:57 2015 François De Matos
*/

#include	"server.h"
#include	"objects.h"

void		push_obj(t_objs **objects, e_id id)
{
  t_objs	*tmp;

  if ((tmp = malloc(sizeof(t_objs))) == NULL)
    exit_mess(666, "Error: Bad malloc");
  tmp->id = id;
  tmp->next = *objects;
  *objects = tmp;
}

int		rm_obj(t_objs **objects, e_id id)
{
  t_objs	*tmp;
  t_objs	*tmp2;

  if (*objects != NULL)
    {
      tmp = *objects;
      if (tmp->id == id)
	*objects = (*objects)->next;
      else
	{
	  while (tmp->next && tmp->next->id != id)
	    tmp = tmp->next;
	  if (!(tmp->next))
	    return (1);
	  else
	    {
	      tmp2 = tmp->next;
	      tmp->next = tmp->next->next;
	      free(tmp2);
	    }
	}
      return (0);
    }
  return (1);
}

void		dump_objs(t_objs *objects)
{
  t_objs	*tmp;
  char		*(objs[7]);

  objs[0] = strdup("Nourriture");
  objs[1] = strdup("Linemate");
  objs[2] = strdup("Deraumère");
  objs[3] = strdup("Sibur");
  objs[4] = strdup("Mendiane");
  objs[5] = strdup("Phiras");
  objs[6] = strdup("Thystame");
  tmp = objects;
  while (tmp)
    {
      printf("%s\n", objs[tmp->id]);
      tmp = tmp->next;
    }
}

int		count_nb_objects(t_objs *objects, e_id id)
{
  int		i;
  t_objs	*tmp;

  i = 0;
  tmp = objects;
  while (tmp)
    {
      if (tmp->id == id)
	++i;
      tmp = tmp->next;
    }
  return (i);
}

int		rm_nbr_obj(t_objs **list, e_id objet, int nb)
{
  int		i;
  int		ret;

  i = -1;
  ret = 0;
  while (++i < nb && ret != 1)
    ret = rm_obj(list, objet);
  return (ret);
}
