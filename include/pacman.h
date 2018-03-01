#ifndef _PACMAN_H_
#define _PACMAN_H_

#include "IGame.hpp"

class Fantom;

class Character : public IGame
{
 protected:
    int x;
    int	y;
    t_orientation dir;
    time_t t;
    
 public:
    Character(){};
    ~Character(){};
    virtual void* getLib() = 0;
    int  check_dir(int **map, t_orientation dir);
    int  new_pos(int **map, int from);
    virtual int check_move(t_orientation dir) = 0;
    virtual board get_board() = 0;
    virtual t_orientation getDir();
    int collision(int **map, int from, int x, int y);  
};

class Pacman : public Character
{
  protected:
  int score;
  bool can_eat;
  Fantom **Fans;
  int			**map;
  int     speed;
  
  public:
  Pacman();
  ~Pacman();

  void	getmap(arcade::CommandType key);
  void	whereami(arcade::CommandType key);
  void *lib;
  virtual void* getLib();
  int	put_pac();
  int getScore();
  virtual int check_move(t_orientation dir);
  virtual board get_board();
  int check_collision();
  void init_map();
  int check_end_map();
};

extern "C" IGame *getObjPacman();

#endif
