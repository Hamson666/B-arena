/*
** server.h for zappy in /home/de-mat_a/rendu/PSU_2014_zappy/server/incs
** 
** Made by François De Matos
** Login   <de-mat_a@epitech.net>
** 
** Started on  Mon Jun  1 11:37:44 2015 François De Matos
** Last update Thu Jul  9 00:10:53 2015 François De Matos
*/

#ifndef			SERVER_H_
# define		SERVER_H_

#include		<sys/types.h>
#include		<sys/stat.h>
#include		<sys/socket.h>
#include		<sys/select.h>
#include		<netinet/in.h>
#include		<arpa/inet.h>
#include		<netdb.h>
#include		<unistd.h>
#include		<stdlib.h>
#include		<stdio.h>
#include		<string.h>
#include		<unistd.h>
#include		<fcntl.h>
#include		<math.h>

#include		"players.h"
#include		"map.h"

#define			ABS(x)		(x < 0) ? -x : x
#define			MAX(x, y)	(x > y) ? x : y
#define			SQR(x)		x * x

typedef struct		s_team
{
  int			id_team;
  char			*name;
  int			nb_eggs;
  struct s_team		*next;
}			t_team;

typedef struct		s_serv
{
  pthread_t		thr;
  int			port;
  int			width;
  int			height;
  t_team		*teams;
  int			clients_by_team;
  int			time_delay;
  int			graph_so;
  int			maxfd;
}			t_serv;

typedef struct		s_init
{
  struct protoent	*pro;
  struct sockaddr_in	saddr;
  struct sockaddr_in	caddr;
  struct timeval	tv;
  int			so;
  int			fd;
  fd_set		fdset;
  int			quit;
}			t_init;

extern t_plyr		*players;
extern t_team		*teams;
extern t_serv		server;
extern char		*(objs[7]);

void			execute_loop(fd_set*);

void			pushteam(t_team**, int, char*);
int			count_nb_players_in_team(t_team*);
t_team			*find_team_by_id(int);
t_team			*find_team_by_name(char*);
char			*dump_teams(t_team*);

void			avance(t_plyr*, char*);
void			droite(t_plyr*, char*);
void			gauche(t_plyr*, char*);
void			voir(t_plyr*, char*);
void			inventaire(t_plyr*, char*);

void			prend(t_plyr*, char*);
void			pose(t_plyr*, char*);
void			expulse(t_plyr*, char*);
void			broadcast(t_plyr*, char*);
void			incantation(t_plyr*, char*);

void			my_fork(t_plyr*, char*);
void			connect_nbr(t_plyr*, char*);
void			mort(t_plyr**, fd_set*);

void			accept_co(int, t_team*);
void			invalid_co(int, fd_set*);

void			fill_tabs(char (*cmds)[50], void (*func[13])(t_plyr*, char*));
void			fill_objs(char **objs);

int			my_write(int, char*, int);
int			my_read(int, char*, int);
char			*dump_objects(t_objs*);
char			*dump_players(t_plyr*);

e_id			pop_food();
e_id			pop_linemate();
e_id			pop_deraumere();
e_id			pop_sibur();
e_id			pop_mendiane();

e_id			pop_phiras();
e_id			pop_thystame();
e_id			pop_none();

int			incant(t_plyr *, int);
void			drop_for_incant(t_plyr *, int);
void			consume(int);

int			evolve_2(t_plyr *);
int			evolve_3(t_plyr *);
int			evolve_4(t_plyr *);
int			evolve_5(t_plyr *);
int			evolve_6(t_plyr *);
int			evolve_7(t_plyr *);
int			evolve_8(t_plyr *);

void			consum_2();
void			consum_3();
void			consum_4();
void			consum_5();
void			consum_6();
void			consum_7();
void			consum_8();

void			drop_2(t_plyr *);
void			drop_3(t_plyr *);
void			drop_4(t_plyr *);
void			drop_5(t_plyr *);
void			drop_6(t_plyr *);
void			drop_7(t_plyr *);
void			drop_8(t_plyr *);

#endif			/* !SERVER_H_ */
