//
// Core.hpp for B-arena in /home/de-mat_a/rendu/B-arena/server-cpp/incs
// 
// Made by Hamson
// 
// Started on  Mon Jul 13 17:20:21 2015 Hamson
// Last update Mon Jul 13 18:24:59 2015 Hamson
//

#ifndef			CORE_HPP_
# define		CORE_HPP_

# define		MAX(x, y)	x > y ? x : y 

#include		<string>
#include		<iostream>

class			Core {
private:
  struct protoent	*_pro;
  struct sockaddr_in	saddr;
  struct sockaddr_in	caddr;

  const int		_port;
  int			_so;
  int			_maxfd;
  fd_set		_fdset;

  //std::vector<Client>	_clients;

public:
  Core(void);
  ~Core(void);

  void			connect(int);
  void			addClient(int);
  void			readClient(int);
};

#endif		/* !CORE_HPP_ */
