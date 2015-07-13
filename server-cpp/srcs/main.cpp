//
// main.cpp for B-arena in /home/de-mat_a/rendu/B-arena/server-cpp/srcs
// 
// Made by François De Matos
// 
// Started on  Mon Jul 13 23:44:31 2015 François De Matos
// Last update Mon Jul 13 23:54:02 2015 François De Matos
//

#include	"Core.hpp"

int		main(int ac, char **av)
{
  int		port;
  Core		*core;

  if (ac == 2)
    {
      av[1] >> port;
      core = new Core();
      core->connect(port);
    }
}
