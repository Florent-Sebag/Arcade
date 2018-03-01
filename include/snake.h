/*
** snake.h for snake in /home/benama_m/arcade_test
**
** Made by Mahdi Benamar
** Login   <benama_m@epitech.net>
**
** Started on  Mon Mar  6 20:13:22 2017 Mahdi Benamar
** Last update Sun Apr  9 23:38:41 2017 Florent Sebag
*/

#ifndef _SNAKE_H_
#define _SNAKE_H_

#include "IGame.hpp"

struct position
{
  int   x;
  int   y;
};

struct  direction
{
  bool up;
  bool down;
  bool right;
  bool left;
};

class		Snake : public IGame
{
 protected:
  int x;
  int y;
  int nbx;
  int nby;
  std::list<position> liste;
  int **tab;
  int	score;
  int speed;

 public:
  direction dir;
  Snake();
  Snake(Snake const &clone);
  Snake &operator=(Snake const &clone);
  ~Snake();

  void *lib;
  virtual void* getLib();
  void		getmap(arcade::CommandType key);
  void		whereami(arcade::CommandType key);
  int		getX() const;
  int		getY() const;
  int		get_nbX() const;
  int		get_nbY()const;
  int		**getMap() const;
  void		remove(int x, int y);
  void		move_head(int x, int y);
  void		setPosition(int x, int y);
  void		init_first_position();
  void		init_first_body();
  // void		change_score(WINDOW *score);
  void		init_direction();
  void		init_Map();
  int		eat_position(int x, int y);
  void		set_eat_position();
  void		add_body();
  board		get_board();
  int		check_move(t_orientation l);
  void            direction_up();
  void            direction_down();
  void            direction_right();
  void            direction_left();
  int             move_up();
  int             move_down();
  int             move_right();
  int             move_left();
  int             error_move_up();
  int             error_move_down();
  int             error_move_right();
  int             error_move_left();
};

int		lanch_sfml();
int		lanch_opengl();
// void            check_position(int x, int y, WINDOW *disp);
// int             display_map(WINDOW *lol, Snake *snake);
int		lanch_game();
// int             make_map(WINDOW *win, Snake *snake);

extern "C" Snake *getObjSnake();

#endif
