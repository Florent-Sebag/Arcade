//
// for_protocole.cpp for protocol in /home/benamar/arcade_test/cpp_arcade/my_snake
// 
// Made by benamar
// Login   <mahdi.benamar@epitech.eu>
// 
// Started on  Thu Apr  6 02:21:20 2017 benamar
// Last update Sun Apr  9 22:38:13 2017 benamar
//


#include "pacman.h"
#include <iostream> 

extern "C" void Play(void)
{
  Pacman pacman;
  arcade::CommandType my_key;
  t_orientation dir;
  
  while (std::cin.read((char *)&my_key, sizeof(arcade::CommandType)))
    {
      switch (my_key)
	{
        case arcade::CommandType::WHERE_AM_I:
	  pacman.whereami(my_key);
	  break;
	case arcade::CommandType::GET_MAP:
	    pacman.getmap(my_key);
	    break;
	case arcade::CommandType::GO_UP:
	    dir = UP;
	    break;
	case arcade::CommandType::GO_DOWN:
	  dir = DOWN;
	  break;
	case arcade::CommandType::GO_LEFT:
	  dir = LEFT;
	  break;
	case arcade::CommandType::GO_RIGHT:
	  dir = RIGHT;
	  break;
	case arcade::CommandType::SHOOT:
	  break;
	case arcade::CommandType::ILLEGAL:
	  break;
	case arcade::CommandType::GO_FORWARD:
	  break;
	case arcade::CommandType::PLAY:
	  pacman.check_move(dir);
	  break;
	}
    }
};

void		Pacman::getmap(arcade::CommandType key)
{
  size_t	size = sizeof(arcade::GetMap) + sizeof(arcade::TileType) * 30 * 30;
  arcade::GetMap *map = new arcade::GetMap [size];

  int	       zebi = 0;
  map->type = key;
  map->width = 30;
  map->height = 30;
  for (int i = 0; i < 30; i += 1) {
    for (int j = 0 ; j < 30; j+= 1) {
      if (this->map[i][j] == 0)
	map->tile[zebi] = arcade::TileType::EMPTY;
      else if (this->map[i][j] == 3)
	map->tile[zebi] = arcade::TileType::POWERUP;
      else if (this->map[i][j] == 4)
	map->tile[zebi] = arcade::TileType::BLOCK;
      else if (this->map[i][j] == 8 || this->map[i][j] == 9)
	map->tile[zebi] = arcade::TileType::EVIL_DUDE;
      zebi += 1;
    }
  }
  std::cout.write((const char *)map, ((30 * 30 * sizeof(arcade::TileType)) + sizeof(arcade::GetMap)));
  delete (map);
}

void		Pacman::whereami(arcade::CommandType key)
{
  arcade::WhereAmI *iAm = new arcade::WhereAmI [sizeof(arcade::WhereAmI) + sizeof(arcade::Position) * 4];

  iAm->type = key;
  iAm->lenght = 1;
  iAm->position[0].x = this->y;
  iAm->position[0].y = this->x;
  std::cout.write((const char *)iAm, (sizeof(arcade::WhereAmI) + sizeof(arcade::Position) * 4));
  delete (iAm);
}
