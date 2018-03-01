/*
** my_menu.h for Project-Master in /home/raphael/rendu/Cpp/cpp_arcade/anahor
** 
** Made by anahor_r
** Login   <abel@epitech.eu>
** 
** Started on  Mon Apr  3 13:51:06 2017 anahor_r
** Last update Tue Apr  4 18:19:50 2017 anahor_r
*/

#ifndef MY_MENU_H_
# define MY_MENU_H_

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <curses.h>
#include <ncurses.h>
#include "menu.h"

class Menu
{
 private:
  int		select;
  sf::Font	font;
  sf::Text	my_menu[2];
  
 public:
  Menu();
  ~Menu();

  void	draw(sf::RenderWindow &window);
  void	up();
  void	dawn();
  int	getItem() { return select; }
};

int		main(int argc, char **argv);
std::string	menu_ncurses();
std::string	menu_sfml();
std::string	menu_opengl();

#endif /* !MY_MENU_H_ */
