#ifndef _FANTOM_H_
#define _FANTOM_H_

#include "pacman.h"

class Fantom : public Character
{
  protected:
    int id;
    bool can_move;
    int	tmp;
    int it;
    int inc_score;
	public:
	  Fantom(){};
	  ~Fantom(){};
    Fantom(int);
    virtual void* getLib(){return (NULL);};
    virtual int check_move(t_orientation dir);
    virtual board get_board();
	  int check_and_move_fantom(int **map, bool can_eat, int Px, int Py);
    void init_pos(int i);
    void GoFantom();
    void reset();
    t_orientation goIA(int **map, int Px, int Py, bool can_eat);
    int check_dirIA(t_orientation dir);
    int check_collision(int **map, bool can_eat);
    t_orientation follow_pacman(int **map, int Px, int Py);
    int calc_diff(int Fx, int Fy, int Px, int Py);
    t_orientation move_randomIA(int **map);
};

#endif
