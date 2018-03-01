#include "fantom.h"

int Fantom::check_dirIA(t_orientation dir)
{
  if (dir == UP && this->dir == DOWN)
    return (0);
  if (dir == DOWN && this->dir == UP)
    return (0);
  if (dir == LEFT && this->dir == RIGHT)
    return (0);
  if (dir == RIGHT && this->dir == LEFT)
    return (0);
  return (1);
}

t_orientation Fantom::move_randomIA(int **map)
{
  t_orientation dir;

  this->it += 1;
  dir = (t_orientation)(rand() % 4 + 1);
  if (check_dirIA(dir) == 1)
  {if (check_dir(map, dir) == 0)
    return (dir);}
  if (this->dir != LEFT)
  {if (check_dir(map, RIGHT) == 0)
    return (RIGHT);}
  if (this->dir != DOWN)
  {if (check_dir(map, UP) == 0)
    return (UP);}
  if (this->dir != UP)
  {if (check_dir(map, DOWN) == 0)
    return (DOWN);}
  if (this->dir != RIGHT)
  {if (check_dir(map, LEFT) == 0)
   return (LEFT);}
  return (this->dir);
}

int Fantom::calc_diff(int Fx, int Fy, int Px, int Py)
{
  int diff_x;
  int diff_y;

  diff_x = Px - Fx;
  diff_y = Py - Fy;
  if (diff_x < 0)
    diff_x = -diff_x;
  if (diff_y < 0)
    diff_y = -diff_y;
  return(diff_x + diff_y);
}

t_orientation Fantom::follow_pacman(int **map, int Px, int Py)
{
  t_orientation tmp_dir;
  int diff;
  int tmp_diff;

  diff = 1000;
  tmp_dir = this->dir;
  if (this->check_dir(map, UP) == 0)
    diff = calc_diff(x, y - 1, Px, Py);
  if (this->check_dir(map, RIGHT) == 0
    && (tmp_diff = calc_diff(x + 1, y, Px, Py)) < diff)
    {
      diff = tmp_diff;
      tmp_dir = RIGHT;
    }
  if (this->check_dir(map, DOWN) == 0
    && (tmp_diff = calc_diff(x, y + 1, Px, Py)) < diff)
    {
      diff = tmp_diff;
      tmp_dir = DOWN;
    }
  if (this->check_dir(map, LEFT) == 0
    && (tmp_diff = calc_diff(x - 1, y, Px, Py)) < diff)
    {
      diff = tmp_diff;
      tmp_dir = LEFT;
    }
  this->dir = tmp_dir;
  return (dir);
}

t_orientation Fantom::goIA(int **map, int Px, int Py, bool can_eat)
{
  t_orientation dir;

  if (calc_diff(x, y, Px, Py) < 8 && can_eat == false)
    dir = this->follow_pacman(map, Px, Py);
  else
    dir = this->move_randomIA(map);
  return (dir);
}
