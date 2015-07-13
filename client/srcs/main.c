/*
** main.c for zappy in /home/de-mat_a/rendu/PSU_2014_zappy/client/srcs
** 
** Made by François De Matos
** Login   <de-mat_a@epitech.net>
** 
** Started on  Fri Jun 12 01:03:07 2015 François De Matos
** Last update Sun Jul  5 11:13:40 2015 François De Matos
*/

#include		"client.h"
#include		"verify_args.h"
#include		"lib.h"
#include		"connection.h"

int			so;
fd_set			fdset;

void			read_cmds()
{
  char			buff[4097];
  int			a;

  if ((a = read(0, buff, sizeof(buff))) > 0)
    {
      buff[a] = '\0';
      if (strncmp(buff, "/quit", 5) == 0)
        my_disconnect(0);
      else
	write(so, buff, a + 1);
    }
}

void			loop()
{
  fd_set		tmp;
  int			ret;
  struct timeval	tv;
  int			a;
  char			buff[4096];

  tv.tv_usec = 6000000000000;
  tmp = fdset;
  write(1, "> ", 2);
  if ((ret = select(so + 1, &fdset, NULL, NULL, &tv)) == -1)
    write(1, "Select a fait de la merde !\n", 28);
  if (ret && FD_ISSET(0, &fdset))
    read_cmds();
  else if (ret)
    {
      usleep(10000);
      if ((a = read(so, buff, 4096)) > 0)
	{
	  memcpy(&buff[a], "\n\0", 2);
	  write(1, buff, a + 2);
	}
      else
	my_disconnect(0);
    }
  fdset = tmp;
}

int			main(int ac, char **av __attribute__((unused)))
{
  t_client		client;

  verify_args(ac, av, &client);
  signal(SIGINT, my_disconnect);
  so = 0;
  FD_ZERO(&fdset);
  FD_SET(0, &fdset);
  my_connect(&client);
  while (7)
    loop();
  return 0;
}
