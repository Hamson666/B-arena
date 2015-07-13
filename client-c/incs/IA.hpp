//
// IA.hpp for zappy in /home/bovier_g/rendu/PSU_2014_zappy/client/incs
// 
// Made by Guillaume Bovier-Lapierre
// Login   <bovier_g@epitech.net>
// 
// Started on  Thu Jun 18 15:48:05 2015 Guillaume Bovier-Lapierre
// Last update Wed Jul  8 15:52:21 2015 Guillaume Bovier-Lapierre
//

#ifndef IA_HPP_
#define IA_HPP_

#include <iostream>
#include <list>
#include "client.h"

class	IA
{
public:
  IA(int id, int x, int y);
  ~IA();

  void		IA_core();
  void		stock();
  void		needs();
  int		pLine(int nb, int c);
  void		move();
  void		right();
  void		left();
  void		take();
  void		goal(int c);
  void		expulse();

  void		e1();
  void		e2();
  void		e3();
  void		e4();
  void		e5();
  void		e6();
  void		e7();

protected:
  int		_Id;
  int		_Lvl;
  int		_Dir;
  int		_X;
  int		_Y;
  int		_Life;

  std::string	_Need;
  
  int		_Lin;
  int		_Der;
  int		_Sib;
  int		_Men;
  int		_Phi;
  int		_Thy;
};

#endif /* IA_HPP_ */
