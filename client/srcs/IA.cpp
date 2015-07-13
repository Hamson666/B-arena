//
// IA.cpp for zappy in /home/bovier_g/rendu/PSU_2014_zappy/client/srcs
// 
// Made by Guillaume Bovier-Lapierre
// Login   <bovier_g@epitech.net>
// 
// Started on  Thu Jun 18 17:55:35 2015 Guillaume Bovier-Lapierre
// Last update Wed Jul  8 15:51:47 2015 Guillaume Bovier-Lapierre
//

#include "IA.hpp"

IA::IA(int id, int x, int y)
{
  this->_Id = id;
  this->_Lvl = 1;
  this->_Dir = 0;
  this->_X = x;
  this->_Y = y;
  this->_Life = 1260;
  this->_Lin = 0;
  this->_Der = 0;
  this->_Sib = 0;
  this->_Men = 0;
  this->_Phi = 0;
  this->_Thy = 0;
}

IA::~IA()
{

}

void	IA::stock()
{
  std::string	lf;
  std::string	line;
  int		x;

  std::cout << "inventaire" << std::endl;
  std::cin >> line;
  x = 0;
  while (line[x] != ',')
    {
      if (line[x] == ' ')
	{
	  x++;
	  while (line[x] != ',')
	    {
	      lf += line[x];
	      x++;
	    }
	}
      x++;
    }
  this->_Life = atoi(lf.c_str());
}

void	IA::needs()
{
  this->_Need = "";

  if (this->_Life <= 50 || this->_Lvl > 7)
    this->_Need = "nourriture";
  else
    {
      switch (this->_Lvl)
	{
	case 1:
	  e1();
	  break;
	case 2:
	  e2();
	  break;
	case 3:
	  e3();
	  break;
	case 4:
	  e4();
	  break;
	case 5:
	  e5();
	  break;
	case 6:
	  e6();
	  break;
	case 7:
	  e7();
	  break;
	default:
	  break;
	}
    }
  if (this->_Need == "")
    this->_Need = "incantation";
}

int	IA::pLine(int nb, int c)
{
  std::string	line;
  std::string	cmp;
  bool		find;
  int		x;

  std::cout << "voir" << std::endl;
  std::cin >> line;
  find = false;
  x = 0;
  while (line[x] != '\0')
    {
      while (line[x] != ' ' || line[x] != ',')
	{
	  cmp += line[x];
	  x++;
	}
      if (cmp == this->_Need)
	{
	  line[x] = '\0';
	  find = true;
	}
      else
	{
	  if (line[x] == ',')
	    c++;
	  cmp = "";
	  x++;
	}
    }
  if (find)
    return c;
  else if (nb == 4)
    return (-1);
  else
    {
      right();
      pLine(nb++, c);
    }
}

void	IA::take()
{
  std::string	line;

  if (this->_Need != "")
    {
      std::cout << "prend " << this->_Need << std::endl;
      std::cin >> line;
    }
  if (line == "ok")
    if (this->_Need == "nourriture")
      this->_Life += 126;
    else
      {
	switch (this->_Need[0])
	  {
	  case 'l':
	    this->_Lin++;
	    break;
	  case 'd':
	    this->_Der++;
	    break;
	  case 's':
	    this->_Sib++;
	    break;
	  case 'm':
	    this->_Men++;
	    break;
	  case 'p':
	    this->_Phi++;
	    break;
	  case 't':
	    this->_Thy++;
	    break;
	  default:
	    break;
	  }
      }
}

void	IA::left()
{
  std::string	line;

  std::cout << "gauche" << std::endl;
  std::cin >> line;
  if (line == "ok")
    if (this->_Dir != 0)
      this->_Dir--;
    else
      this->_Dir = 3;
}

void	IA::right()
{
  std::string	line;

  std::cout << "droite" << std::endl;
  std::cin >> line;
  if (line == "ok")
    if (this->_Dir != 3)
      this->_Dir++;
    else
      this->_Dir = 0;
}

void	IA::move()
{
  std::string	line;

  std::cout << "avance" << std::endl;
  std::cin >> line;
  if (line == "ok")
    switch (this->_Dir)
      {
      case 0:
	this->_Y--;
	break;
      case 1:
	this->_X++;
	break;
      case 2:
	this->_Y++;
	break;
      case 3:
	this->_X--;
	break;
      default:
	break;
      }
}

void	IA::expulse()
{
  std::string	line;

  std::cout << "expulse" << std::endl;
  std::cin >> line;
}

void	IA::goal(int c)
{
  int	nb;
  int	act;
  int	m;
  int	l;
  int	r;
  int	x;

  nb = 1;
  act = 333;
  x = 0;
  while (act == 333)
    {
      move();
      m = (nb * (nb + 1));
      l = m - nb;
      r = m + nb;
      if (m == c)
	act = 0;
      else if (c >= l && c <= r)
	{
	  if (c >= l && c <= m)
	    {
	      act = m;
	      while (act != c)
		{		
		  act--;
		  x++;
		}
	      act = -1;
	    }
	  else if (c <= r && c >= m)
	    {
	      act = m;
	      while (act != c)
		{
                  act++;
                  x++;
                }
	      act = 1;
	    }
	}
      nb++;
    }
  switch (act)
    {
    case -1:
      left();
      while (x != 0)
	{
	  move();
	  x--;
	}
      break;
    case 1:
      right();
      while (x != 0)
	{
	  move();
	  x--;
	}
      break;
    default:
      break;
    }
  take();
}

void	IA::IA_core()
{
  int	c;
  std::string	line;

  stock();
  needs();
  c = pLine(1, 0);
  if (this->_Need != "incantation")
    if (c == -1)
      move();
    else if (c == 0)
      take();
    else
      goal(c);
  else
    {
      if (this->_Lvl == 1)
	{
	  std::cout << "incantation" << std::endl;
	  std::cin >> line;
	  c = 0;
	  if (line == "elevation en cours")
	    {
	      std::cin >> line;
	      while (line[c] != '\0')
		c++;
	      this->_Lvl = atoi(line[c - 1]);
	    }
	}
      else
	search_player();
    }
}

void	IA::e1()
{
  if (this->_Lin < 1)
    this->_Need = "linemate";
}

void	IA::e2()
{
  if (this->_Lin < 1)
    this->_Need = "linemate";
  if (this->_Der < 1 && this->_Need == "")
    this->_Need = "deraumêre";
  if (this->_Sib < 1 && this->_Need == "")
    this->_Need = "sibur";
}

void	IA::e3()
{
  if (this->_Lin < 2)
    this->_Need = "linemate";
  if (this->_Sib < 1 && this->_Need == "")
    this->_Need = "sibur";
  if (this->_Phi < 2 && this->_Need == "")
    this->_Need = "phiras";
}

void	IA::e4()
{
  if (this->_Lin < 1)
    this->_Need = "linemate";
  if (this->_Der < 1 && this->_Need == "")
    this->_Need = "deraumêre";
  if (this->_Sib < 2 && this->_Need == "")
    this->_Need = "sibur";
  if (this->_Phi < 1 && this->_Need == "")
    this->_Need = "phiras";
}

void	IA::e5()
{
  if (this->_Lin < 1)
    this->_Need = "linemate";
  if (this->_Der < 2 && this->_Need == "")
    this->_Need = "deraumêre";
  if (this->_Sib < 1 && this->_Need == "")
    this->_Need = "sibur";
  if (this->_Men < 3 && this->_Need == "")
    this->_Need = "mendiane";
}

void	IA::e6()
{
  if (this->_Lin < 1)
    this->_Need = "linemate";
  if (this->_Der < 2 && this->_Need == "")
    this->_Need = "deraumêre";
  if (this->_Sib < 3 && this->_Need == "")
    this->_Need = "sibur";
  if (this->_Phi < 1 && this->_Need == "")
    this->_Need = "phiras";
}

void	IA::e7()
{
  if (this->_Lin < 2)
    this->_Need = "linemate";
  if (this->_Der < 2 && this->_Need == "")
    this->_Need = "deraumêre";
  if (this->_Sib < 2 && this->_Need == "")
    this->_Need = "sibur";
  if (this->_Men < 2 && this->_Need == "")
    this->_Need = "mendiane";
  if (this->_Phi < 2 && this->_Need == "")
    this->_Need = "phiras";
  if (this->_Thy < 1 && this->_Need == "")
    this->_Need = "thystam";
}
