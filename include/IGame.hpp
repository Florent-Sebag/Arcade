#ifndef IGAME_HPP_
# define IGAME_HPP_

#include "useful.h"

class IGame
{
  public:
  virtual ~IGame(){};
  virtual int check_move(t_orientation) = 0;
  virtual board get_board() = 0;
  virtual void* getLib() = 0;
};

#endif
