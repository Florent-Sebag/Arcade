//
// menu_opengl.cpp for Project-Master in /home/raphael/rendu/Cpp/cpp_arcade/menu
// 
// Made by anahor_r
// Login   <abel@epitech.eu>
// 
// Started on  Tue Apr  4 13:38:33 2017 anahor_r
// Last update Tue Apr  4 22:03:43 2017 anahor_r
//

#include <string>
#include <GL/glfw.h>
#include <GL/glu.h>
#include <GL/glew.h>
#include <my_menu.h>

std::string	menu_opengl()
{
  initSDL();
  initOpenGL();

  SDL_Quit();
  return ('\0');
}
