#include "fantom.h"

Fantom::Fantom(int i)
{
  this->x = 14;
  this->y = 14;
  this->id = i;
  this->it = -1;
  this->tmp = 0;
  this->t = time(NULL);
  this->can_move = false;
  if (i < 2)
    this->x += i;
  else
  {
    this->y += 1;
    this->x += i - 2;
  }
  this->dir = UP;
}

void Fantom::GoFantom()
{
  time_t time_now;

  if (this->can_move == true)
    return ;
  time_now = time(NULL) - this->t;
  if (time_now >= 10)
    this->can_move = true;
}

void Fantom::reset()
{
  this->x = 14;
  this->y = 14;
  this->t = time(NULL);
  this->it = -1;
  this->can_move = false;
  this->tmp = 0;
  if (this->id < 2)
    this->x += this->id;
  else
  {
    this->y += 1;
    this->x += this->id - 2;
  }
  this->dir = UP;
  this->inc_score = 200;
}

int Fantom::check_collision(int **map, bool can_eat)
{
  if (map[y][x] == 1 && can_eat == false)
    return (-1);
  if (map[y][x] == 1 && can_eat == true)
    this->reset();
  return(0);
}

int Fantom::check_and_move_fantom(int **map, bool can_eat, int Px, int Py)
{
  int dir;

  this->inc_score = 0;
  this->GoFantom();
  if (this->can_move == true)
  {
    dir = goIA(map, Px, Py, can_eat);
    this->check_dir(map, (t_orientation)dir);
    if (map[y][x] == 1 && can_eat == true)
      this->reset();
    if (this->new_pos(map, this->tmp) == 1)
      this->tmp = map[this->y][this->x];
    if (this->check_collision(map, can_eat) == -1)
      return (-1);
  }
  if (can_eat == true)
    map[this->y][this->x] = 9;
  else
    map[this->y][this->x] = 8;
  return (this->inc_score);
}

int check_move(t_orientation dir);
board get_board();

int Fantom::check_move(t_orientation dir)
{
  (void)dir;
  return (0);
}

board Fantom::get_board()
{
  board tmp;
  return (tmp);
}
