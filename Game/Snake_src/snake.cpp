
//
// snake.cpp for snake in /home/benama_m/arcade_test
//
// Made by Mahdi Benamar
// Login   <benama_m@epitech.net>
//
// Started on  Mon Mar  6 20:24:07 2017 Mahdi Benamar
// Last update Sun Apr  9 12:19:45 2017 benamar
//

#include "snake.h"

Snake::Snake()
{
  position	pos;

  this->nbx = 31;
  this->nby = 30;
  this->x = this->nbx / 2;
  this->y = this->nby / 2;
  pos.x = this->x;
  pos.y = this->y;
  this->liste.push_back(pos);
  this->init_Map();
  this->init_direction();
  this->init_first_position();
  this->set_eat_position();
  this->score = 0;
  this->speed = 100000;
}

Snake::~Snake()
{
}

void *Snake::getLib()
{
  return (this->lib);
}

void		Snake::init_Map()
{
  this->tab = new int* [this->nbx];
  for (int i=0; i < this->nbx; i++)
    this->tab[i] = new int[this->nby];
  for (int i=0; i < this->nbx; i++)
    for (int j=0; j < this->nby; j++)
      this->tab[i][j] = 0;
}

int		**Snake::getMap() const
{
  return (this->tab);
}

void		Snake::remove(int x, int y)
{
  this->tab[x][y] = 0;
}

void		Snake::init_direction()
{
  this->dir.up = false;
  this->dir.down = false;
  this->dir.right = true;
  this->dir.left = false;
}

void		Snake::init_first_position()
{
  position	pos1;
  position	pos2;
  position	pos3;

  this->tab[this->x][this->y] = 1;
  pos1.x = this->x;
  pos1.y = this->y - 1;
  pos2.x = this->x;
  pos2.y = this->y - 2;
  pos3.x = this->x;
  pos3.y = this->y - 3;
  this->liste.push_back(pos1);
  this->liste.push_back(pos2);
  this->liste.push_back(pos3);
  this->tab[pos1.x][pos1.y] = 2;
  this->tab[pos2.x][pos2.y] = 2;
  this->tab[pos3.x][pos3.y] = 2;
}

void		Snake::move_head(int x, int y)
{
  std::list<position>::iterator it = this->liste.begin();
  int		i;
  position	tmp;
  position	temp;

  i = 0;
  while (it != this->liste.end())
    {
      if (i == 0)
	{
	  tmp = *(it);
	  this->remove(this->x, this->y);
	  it->x = x;
	  it->y = y;
	  this->tab[it->x][it->y] = 1;
	}
      else
      	{
	  temp = *(it);
	  this->remove(temp.x, temp.y);
	  it->x = tmp.x;
	  it->y = tmp.y;
	  this->tab[tmp.x][tmp.y] = 2;
	  tmp = *(it);
	  tmp = temp;
      	}
      i += 1;
      it++;
    }
  it = liste.begin();
}

Snake::Snake(Snake const &cl)
{
  this->x = cl.x;
  this->y = cl.y;
}

Snake&		Snake::operator=(Snake const &clone)
{
  this->x = clone.x;
  this->y = clone.y;
  return (*this);
}

int	Snake::get_nbX() const
{
  return (this->nbx);
}

int	Snake::get_nbY() const
{
  return (this->nby);
}


int	Snake::getX() const
{
  return (this->x);
}

int	Snake::getY() const
{
  return (this->y);
}

void	Snake::setPosition(int posx, int posy)
{
  this->x = posx;
  this->y = posy;
}

board	Snake::get_board()
{
  board		game;

  game.score = this->score;
  game.map = this->getMap();
  game.speed = speed;
  return (game);
}

int	Snake::eat_position(int x, int y)
{
  int		i;
  int		j;

  if (this->tab[x][y] == 3)
    {
      i = rand() % this->get_nbX();// + 1;
      j = rand() % this->get_nbX();// + 1;
      if (this->tab[i][j] == 0 && i >= 0 && i < 29)
	{
	  this->tab[i][j] = 3;
	  this->score += 1;
	  return (1);
	}
      else
	this->eat_position(x, y);
    }
  return (0);
}

void	Snake::set_eat_position()
{
  int	i;
  int	j;

  i = rand() % this->get_nbX() + 1;
  j = rand() % this->get_nbX() + 1;
  if (this->tab[i][j] == 0 && i >= 0)
    {
      this->tab[i][j] = 3;
      return;
    }
  else
    this->set_eat_position();
}

void	Snake::add_body()
{
  position	pos;

  pos = this->liste.back();
  liste.push_back(pos);
}

extern "C" Snake *getObjSnake()
{
  return (new Snake);
}
