#ifndef _IGUI_HPP_
# define _IGUI_HPP_

#include "useful.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <SFML/OpenGL.hpp>
#include <SFML/Graphics.hpp>
#include <ncurses.h>
#include <curses.h>

class IGui
{
  public:
    virtual ~IGui(){};
    virtual t_orientation get_touch() = 0;
    virtual int display(board game) = 0;
    virtual void* getLib() = 0;
};

#endif
