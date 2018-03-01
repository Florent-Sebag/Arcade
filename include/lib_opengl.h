/*
** lib_opengl.h for opengl in /home/benamar/arcade_test/cpp_arcade/my_snake
**
** Made by benamar
** Login   <mahdi.benamar@epitech.eu>
**
** Started on  Wed Apr  5 17:00:12 2017 benamar
** Last update Sat Apr  8 15:43:40 2017 Florent Sebag
*/

#ifndef LIB_OPENGL_H_
#define LIB_OPENGL_H_

#include "IGui.hpp"

class           lib_opengl : public IGui
{
 protected:
  t_orientation key;
  sf::RenderWindow *window;
  sf::RectangleShape map;
  sf::Text	text;
  sf::Font	font;
 public:
  lib_opengl();
  ~lib_opengl();
  lib_opengl &operator=(lib_opengl const &eq);
  lib_opengl(lib_opengl const &clone);

  void *lib;
  t_orientation get_touch();
  t_orientation get_key() const;
  //void          retrieve_key();
  virtual void* getLib();
  int           display(board game);
  void          init_windows();
  void		disp_win();
  void		print_score(int scr);
  sf::RenderWindow *getWindow();
  void          draw_head(int i, int j);
  void          draw_eat(int i, int j);
  void          draw_body(int i, int j);
  void		disp_wall(int i, int j);
  void		disp_power(int i, int j);
  void		disp_ghost(int i, int j);
  void		disp_ghost_scape(int i, int j);
  void		ghost();
  void		ghost_scape();
  void		power();
  void		wall();
  void          body();
  void          head();
  void          eat();
};

extern "C" lib_opengl *getObjOgl();

#endif
