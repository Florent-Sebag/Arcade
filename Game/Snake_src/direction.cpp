//
// direction.cpp for direction in /home/benama_m/arcade_test
// 
// Made by Mahdi Benamar
// Login   <benama_m@epitech.net>
// 
// Started on  Tue Mar 14 23:22:23 2017 Mahdi Benamar
// Last update Fri Mar 24 17:52:35 2017 Mahdi Benamar
//

#include "snake.h"
//#include "game.h"

void            Snake::direction_up()
{
  this->dir.up = true;
  this->dir.down = false;
  this->dir.left = false;
  this->dir.right = false;
}

void            Snake::direction_down()
{
  this->dir.down = true;
  this->dir.up = false;
  this->dir.left = false;
  this->dir.right = false;
}

void            Snake::direction_right()
{
  this->dir.up = false;
  this->dir.down = false;
  this->dir.left = false;
  this->dir.right = true;
}

void            Snake::direction_left()
{
  this->dir.up = false;
  this->dir.down = false;
  this->dir.left = true;
  this->dir.right = false;
}
