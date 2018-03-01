//
// for_protocole.cpp for protocol in /home/benamar/arcade_test/cpp_arcade/my_snake
// 
// Made by benamar
// Login   <mahdi.benamar@epitech.eu>
// 
// Started on  Thu Apr  6 02:21:20 2017 benamar
// Last update Sun Apr  9 22:27:54 2017 benamar
//

#include "snake.h"
#include <iostream>

extern "C" void Play(void)
{
  Snake snake;
  arcade::CommandType my_key;
  t_orientation dir;

  dir = RIGHT;
  snake.direction_right();
  while (std::cin.read((char *)&my_key, sizeof(arcade::CommandType)))
    {
      switch (my_key)
	{
        case arcade::CommandType::WHERE_AM_I:
	  snake.whereami(my_key);
	  break;
	case arcade::CommandType::GET_MAP:
	    snake.getmap(my_key);
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
	case arcade::CommandType::PLAY:
	  snake.check_move(dir);
	  break;
	case arcade::CommandType::GO_FORWARD:
	  break;
	}
    }
};

void		Snake::getmap(arcade::CommandType key)
{
  size_t	size = sizeof(arcade::GetMap) + sizeof(arcade::TileType) * this->nbx * this->nby;
  arcade::GetMap *map = new arcade::GetMap [size];

  int	       zebi = 0;
  map->type = key;
  map->width = this->nbx;
  map->height = this->nby;
  for (int i = 0; i < this->nbx ; i += 1) {
    for (int j = 0 ; j < this->nby; j+= 1) {
      if (this->tab[i][j] == 0)
	map->tile[zebi] = arcade::TileType::EMPTY;
      else if (this->tab[i][j] == 3)
	map->tile[zebi] = arcade::TileType::POWERUP;
      zebi += 1;
    }
  }
  std::cout.write((const char *)map, ((this->nbx * this->nby * sizeof(arcade::TileType)) + sizeof(arcade::GetMap)));
  delete (map);
}

void		Snake::whereami(arcade::CommandType key)
{
  arcade::WhereAmI *iAm = new arcade::WhereAmI [sizeof(arcade::WhereAmI) + sizeof(arcade::Position) * this->liste.size()];
  int	i = 0;
  std::list<position>::iterator it = this->liste.begin();
  iAm->type = key;
  iAm->lenght = this->liste.size();
  while (it != this->liste.end())
    {
      iAm->position[i].x = it->y;
      iAm->position[i].y = it->x;
      i++;
      it++;
    }
  std::cout.write((const char *)iAm, (sizeof(arcade::WhereAmI) + sizeof(arcade::Position) * this->liste.size()));
  delete (iAm);
}
