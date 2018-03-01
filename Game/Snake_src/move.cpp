//
// main.cpp for main in /home/benama_m/arcade_test
// 
// Made by Mahdi Benamar
// Login   <benama_m@epitech.net>
// 
// Started on  Sat Mar  4 03:46:28 2017 Mahdi Benamar
// Last update Sun Apr  9 18:59:07 2017 benamar
//

#include "snake.h"

int             Snake::check_move(t_orientation key)
{
  if ((key == UP) && this->dir.down != true)// || this->dir.up == true) && this->dir.down != true) //up
    {
      if (this->error_move_up() != 1)
	this->move_up();
      else
	return (1);
    }
    if (key == DOWN && this->dir.up != true)// || this->dir.down == true) && this->dir.up != true)//down
    {
      if (this->error_move_down() != 1)
	this->move_down();
      else
	return (1);
    }
    if (key == RIGHT && this->dir.left != true)// || this->dir.right == true) && this->dir.left != true)//right
    {
      if (this->error_move_right() != 1)
	this->move_right();
      else
	return (1);
    }
    if (key == LEFT && this->dir.right != true)// || this->dir.left == true) && this->dir.right != true)//left
    {
      if (this->error_move_left() != 1)
	this->move_left();
      else
	return (1);
    }
  return (0);
}


int		Snake::move_up()
{
  int		i = 0;
  
  direction_up();
  if (this->eat_position(this->getX() - 1, this->getY()) == 1)
    {
      this->add_body();
      i = 1;
    }
  this->move_head(this->getX() - 1, this->getY());
  this->setPosition(this->getX() - 1, this->getY());
  return (i);
}
int		Snake::move_down()
{
  int		i = 0;
  
  direction_down();
  if (this->eat_position(this->getX() + 1, this->getY()) == 1)
    {
      i = 1;
      this->add_body();
    }
  this->move_head(this->getX() + 1, this->getY());
  this->setPosition(this->getX() + 1, this->getY());
  return (i);
}
int		Snake::move_right()
{
  int		i = 0;
  
  direction_right();
  if (this->eat_position(this->getX(), this->getY() + 1) == 1)
    {
      this->add_body();
      i = 1;
    }
  this->move_head(this->getX(), this->getY() + 1);
  this->setPosition(this->getX(), this->getY() + 1);
  return (i);
}
int		Snake::move_left()
{
  int		i = 0;
  
  direction_left();
  if (this->eat_position(this->getX(), this->getY() - 1) == 1)
    {
      this->add_body();
      i = 1;
    }
  this->move_head(this->getX(), this->getY() - 1);
  this->setPosition(this->getX(), this->getY() - 1);
  return (i);
}
