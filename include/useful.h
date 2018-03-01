#ifndef USEFUL_H_
# define USEFUL_H_

#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <iostream>
#include <string>
#include <list>
#include <time.h>
#include <cstdlib>
#include <sstream>
#include "Protocol.hpp"
#include <dlfcn.h>

enum t_orientation
  {
    UP = 1,
    DOWN = 2,
    RIGHT = 3,
    LEFT = 4,
    TWO = 5,
    THREE = 6,
    FOUR = 7,
    FIVE = 8,
    EIGHT = 9,
    NINE = 10,
    ENTER = 11,
    EXIT = 12
  };
//VIRER LES INCLUDES POUR PROTOCOL
struct board
{
  int score;
  int **map;
	int speed;
};

template <typename T>
std::string to_string(T value)
{
  std::ostringstream os ;
  os << value ;
  return os.str() ;
}

#endif
