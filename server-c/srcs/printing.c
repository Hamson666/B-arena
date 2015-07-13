/*
** printing.c for zappy in /home/de-mat_a/rendu/PSU_2014_zappy/server/srcs
** 
** Made by François De Matos
** Login   <de-mat_a@epitech.net>
** 
** Started on  Sat Jun 27 14:21:29 2015 François De Matos
** Last update Wed Jul  8 20:34:43 2015 François De Matos
*/

#include	"server.h"
#include	"players.h"
#include	"objects.h"

int		my_write(int so, char *buff, int len)
{
  char		tmp[50];

  sprintf(tmp, "\e[1;34mSending to %d : ", so);
  write(1, tmp, strlen(tmp));
  write(1, buff, len);
  write(1, "\n\e[m", 5);
  return (write(so, buff, len));
}

int		my_read(int so, char *buff, int len)
{
  int		ret;
  char		tmp[50];

  sprintf(tmp, "\e[1;31mReceiving from %d : ", so);
  write(1, tmp, strlen(tmp));
  ret = read(so, buff, len);
  write(1, buff, ret);
  write(1, "\e[m", 4);
  return (ret);
}

char		*dump_objects(t_objs *objects)
{
  t_objs	*tmp;
  int		i;
  char		*ret;

  ret = NULL;
  tmp = objects;
  while (tmp)
    {
      i = 0;
      while (i < 7 && i != (int)(tmp->id))
	++i;
      if (i < 7)
	ret = my_strcat(my_strcat(ret, " "), objs[i]);
      tmp = tmp->next;
    }
  return (ret);
}

char		*dump_players(t_plyr *players)
{
  t_plyr	*tmp;
  char		*ret;

  ret = NULL;
  tmp = players;
  while (tmp)
    {
      ret = my_strcat(ret, " ");
      ret = my_strcat(ret, "joueur");
      tmp = tmp->next;
    }
  return (ret);
}

