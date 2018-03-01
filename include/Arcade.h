#ifndef ARCADE_H_
# define ARCADE_H_

#include "Gui.h"
#include "pacman.h"
#include "lib_sfml.h"
#include "lib_opengl.h"
#include "snake.h"
#include <my_menu.h>

Snake *load_libsnake();
Pacman *load_libpacman();
Gui *load_libncurses();
lib_sf *load_libsfml();
lib_opengl *load_libogl();
int main_loop(IGame *Game, IGui *curse);
int launch_menu(int ac, char **av);

#endif
