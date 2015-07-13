/*
** main.c for Zappy in /home/de-mat_a/rendu/PSU_2014_zappy/server/src
** 
** Made by François De Matos
** Login   <de-mat_a@epitech.net>
** 
** Started on  Mon Jun  1 10:31:52 2015 François De Matos
** Last update Thu Jul  9 00:16:21 2015 François De Matos
*/

#include		"lib.h"
#include		"server.h"
#include		"players.h"
#include		"verify_args.h"

t_plyr			*players = NULL;
t_team			*teams = NULL;
t_map			*map = NULL;
t_serv			server;
char			*(objs[7]);

void			new_connection(int sockfd, fd_set *tmp)
{
  char			buff[4097];
  t_team		*team;
  int			a;

  FD_SET(sockfd, tmp);
  my_write(sockfd, "BIENVENUE\n", 10);
  write(1, "\nA new player connected\n", 24);
  usleep(500);
  if ((a = my_read(sockfd, buff, 4096)) > 0)
    {
      buff[a] = 0;
      if (strncmp(buff, "GRAPHIC\n", 8) == 0)
	server.graph_so = sockfd;
      else
	{
	  if ((team = find_team_by_name(buff)) != NULL)
	    accept_co(sockfd, team);
	  else
	    invalid_co(sockfd, tmp);
	}
    }
  server.maxfd = MAX(sockfd, server.maxfd);
}

void			read_cmds(int so, fd_set *fdset)
{
  char			cmds[12][50];
  void			(*func[12])(t_plyr*, char*);
  char			buff[4096];
  int			a;
  t_plyr		*tmp;

  fill_tabs(cmds, func);
  memset(&buff[0], 0, 4096);
  if ((a = my_read(so, buff, 4096)) > 0)
    {
      buff[a] = 0;
      a = 0;
      tmp = find_plyr_by_so(players, so);
      while (a < 12 && strncmp(cmds[a], buff, strlen(cmds[a])) != 0)
	++a;
      if (a != 12)
	push_queue(&(tmp->queue), cmds[a], &buff[strlen(cmds[a]) + 1]);
      else if (strncmp(buff, "quit", 4) == 0)
	mort(&tmp, fdset);
      else
	my_write(so, "ko", 2);
    }
}

int			my_connect(t_serv *serv, t_init *init)
{
  int			err;

  init->pro = getprotobyname("TCP");
  if ((init->so = socket(AF_INET, SOCK_STREAM, init->pro->p_proto)) == -1)
    exit_mess(2, "Error: Cannot get a socket");
  init->saddr.sin_family = AF_INET;
  init->saddr.sin_port = htons(serv->port);
  init->saddr.sin_addr.s_addr = INADDR_ANY;
  if ((err = bind(init->so, (const struct sockaddr*)&init->saddr,
		  sizeof(init->saddr))) == -1)
    exit_mess_close(3, "Error: Cannot bind", init->so);
  if ((err = listen(init->so, 10)) == -1)
    exit_mess_close(4, "Error: Cannot listen", init->so);
  return init->so;
}

void			loop(t_init *init)
{
  socklen_t		len;
  int			sockfd;
  int			ret;
  fd_set	        tmp;

  init->tv.tv_sec = 0;
  init->tv.tv_usec = 1000000 / server.time_delay;
  len = sizeof(init->caddr);
  tmp = init->fdset;
  if ((ret = select(server.maxfd + 1, &init->fdset,
		    NULL, NULL, &init->tv)) == -1)
    exit_mess(12, "Select failed.");
  if (ret > 0 && FD_ISSET(init->so, &init->fdset))
    {
      if ((sockfd = accept(init->so, (struct sockaddr*)&init->caddr, &len))
	  == -1)
	exit_mess_close(1, "Error: Cannot accept incoming connection", init->so);
      else
	new_connection(sockfd, &tmp);
    }
  else if (ret)
    read_cmds(get_fd(server.maxfd, &(init->fdset)), &tmp);
  execute_loop(&tmp);
  init->fdset = tmp;
}

int			main(int ac, char **av)
{
  t_init		init;

  fill_objs(objs);
  server.graph_so = -1;
  verify_args(ac, av, &server);
  init.so = my_connect(&server, &init);
  server.maxfd = init.so + 1;
  FD_ZERO(&init.fdset);
  FD_SET(init.so, &init.fdset);
  map = NULL;
  srand(time(NULL));
  gen_map(&map, server.width, server.height);
  while (42)
    loop(&init);
  close(init.so);
  return 0;
}
