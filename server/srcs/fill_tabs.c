/*
** fill_tabs.c for zappy in /home/de-mat_a/rendu/PSU_2014_zappy/server/srcs
** 
** Made by François De Matos
** Login   <de-mat_a@epitech.net>
** 
** Started on  Wed Jun 17 00:12:25 2015 François De Matos
** Last update Wed Jul  8 21:07:53 2015 François De Matos
*/

#include	"server.h"

void		fill_tabs(char (*cmds)[50], void (*func[13])(t_plyr*, char*))
{
  func[0] = &avance;
  func[1] = &droite;
  func[2] = &gauche;
  func[3] = &voir;
  func[4] = &inventaire;
  func[5] = &prend;
  func[6] = &pose;
  func[7] = &expulse;
  func[8] = &broadcast;
  func[9] = &incantation;
  func[10] = &my_fork;
  func[11] = &connect_nbr;
  strcpy(cmds[0], "avance");
  strcpy(cmds[1], "droite");
  strcpy(cmds[2], "gauche");
  strcpy(cmds[3], "voir");
  strcpy(cmds[4], "inventaire");
  strcpy(cmds[5], "prend");
  strcpy(cmds[6], "pose");
  strcpy(cmds[7], "expulse");
  strcpy(cmds[8], "broadcast");
  strcpy(cmds[9], "incantation");
  strcpy(cmds[10], "fork");
  strcpy(cmds[11], "connect_nbr");
}

void		fill_objs(char **objs)
{
  objs[0] = strdup("nourriture");
  objs[1] = strdup("linemate");
  objs[2] = strdup("deraumère");
  objs[3] = strdup("sibur");
  objs[4] = strdup("mendiane");
  objs[5] = strdup("phiras");
  objs[6] = strdup("thystame");
}
