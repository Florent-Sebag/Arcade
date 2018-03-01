/*
** lib_sfml.h for lib_sfml in /home/benamar/arcade_test/cpp_arcade/my_snake
**
** Made by benamar
** Login   <mahdi.benamar@epitech.eu>
**
** Started on  Wed Apr  5 16:57:17 2017 benamar
** Last update Sat Apr  8 15:43:45 2017 Florent Sebag
*/

#ifndef LIB_SFML_H_
#define LIB_SFML_H_

#include "IGui.hpp"

class           lib_sf : public IGui
{
 protected:
  t_orientation key;
  sf::RenderWindow *window;
  sf::RectangleShape rectangle;
  sf::RectangleShape score;
  sf::Font font;
  sf::Text text;
  sf::Texture texture;
  sf::Texture power;
  sf::Texture ghost;
  sf::Texture ghost_scape;

 public:
  lib_sf();
  ~lib_sf();
  lib_sf &operator=(lib_sf const &eq);
  lib_sf(lib_sf const &clone);

  void *lib;
  t_orientation get_touch();
  t_orientation get_key() const;
  //void          retrieve_key();
  virtual void* getLib();
  int           display(board game);
  void          init_windows();
  sf::RenderWindow *getWindow();
  sf::RectangleShape getRec();
  sf::RectangleShape getScore();
  sf::Text getText();
  int           disp_head(int i, int j, sf::RectangleShape e);
  int           disp_body(int i, int j, sf::RectangleShape e);
  int           disp_eat(int i, int j, sf::Sprite  e);
  void          disp_win();
  void          print_score(int);
  int		disp_wall(int i, int j, sf::RectangleShape e);
  int           disp_power(int i, int j);
  int           disp_ghost(int i, int j);
  int           disp_ghost_scape(int i, int j);
};

extern "C" lib_sf *getObjSfml();

#endif
