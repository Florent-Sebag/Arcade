/*
** error_move.c for error_move in /home/benama_m
** 
** Made by Mahdi Benamar
** Login   <benama_m@epitech.net>
** 
** Started on  Wed Mar 15 00:19:46 2017 Mahdi Benamar
// Last update Sat Mar 18 20:29:05 2017 Mahdi Benamar
*/

#include "snake.h"
//#include "game.h"

int             Snake::error_move_up()
{
  if (this->tab[this->getX() - 1][this->getY()] == 2)
    return (1);
  else if (this->getX() -1 <= 0)
    return (1);
  else
    return (0);
}

int             Snake::error_move_down()
{
  if (this->tab[this->getX() + 1][this->getY()] == 2)
    return (1);
  else if (this->getX() + 1 >= this->get_nbX() - 1)
    return (1);
  return (0);
}

int             Snake::error_move_right()
{
  if (this->tab[this->getX()][this->getY() + 1] == 2)
    return (1);
  else if (this->getY() + 1 == this->get_nbY())
    return (1);
  else
    return (0);
}

int             Snake::error_move_left()
{
  if (this->tab[this->getX()][this->getY() - 1] == 2)
    return (1);
  else if (this->getY() == 0)
    return (1);
  else
    return (0);
}
