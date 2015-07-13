//
// Core.cpp for B-arena in /home/de-mat_a/rendu/B-arena/server-cpp/srcs
// 
// Made by Hamson
// 
// Started on  Mon Jul 13 17:19:55 2015 Hamson
// Last update Mon Jul 13 18:34:30 2015 Hamson
//

#include	"Core.hpp"

Core::Core()
{
  _port = -1;
  _maxfd = 3;
  FD_ZERO(_fdset);
}

Core::~Core()
{
  close(_so);
}

void		Core::connect(int port)
{
  _port = port;
  _pro = getprotobyname("TCP");
  if ((_so = socket(AF_INET, SOCK_STREAM, _pro->p_proto)) == -1)
    throw 1;
  _saddr.sin_family = AF_INET;
  _saddr.sin_port = htons(_port);
  _saddr.sin_addr.s_addr = INADDR_ANY;
  if (bind(_so, (const struct sockaddr*)_saddr, sizeof(_saddr)) == -1)
    throw 2;
  if (listen(_so, 10) == -1)
    throw 3;
  FD_SET(_so, &_fdset);
}

void		Core::addClient(int sockfd)
{
  FD_SET(sockfd, &_fdset);
  sockfd << "Bienvenue" << std::endl;
  std::cout << "New connection from : " << std::endl;
  _maxfd = MAX(sockfd, _maxfd);
}

void		Core::readClient(int sockfd)
{
  std::string	buff;

  sockfd >> buff;
  std::cout << "Client n°" << sockfd << " sent : \"" << buff << "\"" << std::endl;
  sockfd << "Received" << std::endl;
}
