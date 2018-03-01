#include "pacman.h"

t_orientation opposite(t_orientation dir)
{
  t_orientation tmp;

  tmp = dir;
  if (dir == UP)
    tmp = DOWN;
  if (dir == DOWN)
    tmp = UP;
  if (dir == LEFT)
    tmp = RIGHT;
  if (dir == RIGHT)
    tmp = LEFT;
  dir = tmp;
  return (dir);
}

int Character::collision(int **map, int from, int x, int y)
{
  if (from == -1)
    return (0);
  if (map[y][x] == 8 || map[y][x] == 9)
    {
      this->dir = opposite(this->dir);
      return (1);
    }
  return (0);
}

int Character::new_pos(int **map, int from)
{
  if (from == 3 || from == 5)
    map[y][x] = from;
  else
    map[this->y][this->x] = 0;
  if (this->dir == UP && map[this->y - 1][this->x] != 4
    && collision(map, from, x, y - 1) == 0)
    this->y -= 1;
  else if (this->dir == RIGHT && map[this->y][this->x + 1] != 4
    && collision(map, from, x + 1, y) == 0)
    this->x += 1;
  else if (this->dir == DOWN && map[this->y + 1][this->x] != 4
    && collision(map, from, x, y + 1) == 0)
    this->y += 1;
  else if (this->dir == LEFT && map[this->y][this->x - 1] != 4
    && collision(map, from, x - 1, y) == 0)
    this->x -= 1;
  else
    return (0);
  if (this->x == -1 && this->y == 14)
    this->x = 29;
  else if (this->x == 29 && this->y == 14)
    this->x = 0;
  return (1);
}

int Character::check_dir(int **map, t_orientation dir)
{
  if (dir == UP && map[this->y - 1][this->x] != 4)
    this->dir = UP;
  else if (dir == RIGHT && map[this->y][this->x + 1] != 4)
    this->dir = RIGHT;
  else if (dir == DOWN && map[this->y + 1][this->x] != 4)
    this->dir = DOWN;
  else if (dir == LEFT && map[this->y][this->x - 1] != 4)
    this->dir = LEFT;
  else
    return (-1);
  return (0);
}

t_orientation Character::getDir()
{
  return (this->dir);
}
