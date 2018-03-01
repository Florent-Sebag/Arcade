//
// lib_opengl.cpp for lib in /home/benamar/arcade_test/cpp_arcade/my_snake
//
// Made by benamar
// Login   <mahdi.benamar@epitech.eu>
//
// Started on  Wed Apr  5 12:10:41 2017 benamar
// Last update Sun Apr  9 20:19:08 2017 benamar
//

#include "lib_opengl.h"

lib_opengl::lib_opengl()
{
  this->key = RIGHT;
  this->init_windows();
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity( );
  glClearColor(0.3f, 0.3f, 0.3f, 0.f);
  gluOrtho2D(0,900,800,0);
  srand(time(NULL));
}

lib_opengl::~lib_opengl()
{
}

void *lib_opengl::getLib()
{
  return (this->lib);
}

lib_opengl::lib_opengl(lib_opengl const &cl)
{
  this->key = cl.key;
}

lib_opengl&	lib_opengl::operator=(lib_opengl const &clone)
{
  this->key = clone.key;
  return (*this);
}

t_orientation           lib_opengl::get_touch()
{
  sf::Event event;

  while (this->window->pollEvent(event))
    {
      switch (event.type)
	{
	case sf::Event::Closed:
	  this->window->close();
	  break;
	case sf::Event::KeyPressed:
	  {
	    if (event.key.code == sf::Keyboard::Escape)
	      this->window->close();
	    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	      {
		this->key = LEFT;
		return (this->get_key());
	      }
	    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	      {
		this->key = RIGHT;
		return (this->get_key());
	      }
	    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	      {
		this->key = UP;
		return (this->get_key());
	      }
	    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	      {
		this->key = DOWN;
		return (this->get_key());
	      }
	    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	      {
		this->key = TWO;
		return (this->get_key());
	      }
	    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
	      {
		this->key = THREE;
		return (this->get_key());
	      }
	    if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
	      {
		this->key = FOUR;
		return (this->get_key());
	      }
	    if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
	      {
		this->key = FIVE;
		return (this->get_key());
	      }
	    if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
	      {
		this->key = EIGHT;
		return (this->get_key());
	      }
	    if (sf::Keyboard::isKeyPressed(sf::Keyboard::U))
	      {
		this->key = NINE;
		return (this->get_key());
	      }
	  default:
	    return (this->get_key());
	  }
	}
    }
  return (this->get_key());
}

t_orientation		lib_opengl::get_key() const
{
  return (this->key);
}

sf::RenderWindow	*lib_opengl::getWindow()
{
  return (this->window);
}

void			lib_opengl::init_windows()
{
  this->window = new sf::RenderWindow(sf::VideoMode(2000, 1000), "SFML works!");
  this->map.setSize(sf::Vector2f(595, 585));
  this->map.setFillColor(sf::Color::Black);
  this->map.setOutlineColor(sf::Color::White);
  this->map.setOutlineThickness(2);
  this->map.setPosition(10, 10);
  if (!this->font.loadFromFile("utils/ARCADE_I.ttf"))
    {
      return ;
    }
  this->text.setFont(this->font); // font est un sf::Font
  this->text.setString("Score");
  this->text.setCharacterSize(50); // exprimée en pixels, pas en points !
  this->text.setColor(sf::Color::White);
  this->text.setStyle(sf::Text::Bold);
  this->text.setPosition(860, 50);
}

void			lib_opengl::print_score(int scr)
{
  sf::Text the_score;
  const char *nbr;

  nbr = to_string(scr).c_str();
  the_score.setFont(this->font); // font est un sf::Font
  the_score.setString(nbr);
  the_score.setCharacterSize(40); // exprimée en pixels, pas en points !
  the_score.setColor(sf::Color::White);
  the_score.setStyle(sf::Text::Bold);
  the_score.setPosition(940, 150);
  this->window->draw(the_score);
}

void			lib_opengl::disp_win()
{
  this->window->clear();
  this->window->draw(this->map);
  this->window->draw(this->text);
}

void			lib_opengl::draw_body(int i, int j)
{
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glPushMatrix();
  glTranslated(j, i, 0);
  glColor3ub(0,255,0);
  this->body();
  glFlush();
  glPopMatrix();
}

void			lib_opengl::body()
{
  glBegin(GL_QUADS);
  glVertex2d(0,-15/2);
  glVertex2d(0,15/2);
  glVertex2d(15,15/2);
  glVertex2d(15,-15/2);
  glEnd();
}

void			lib_opengl::draw_eat(int i, int j)
{
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glPushMatrix();
  glTranslated(j, i, 0);
  glColor3ub(255,255,0);
  this->eat();
  glFlush();
  glPopMatrix();
}

void			lib_opengl::eat()
{
  glBegin(GL_QUADS);
  glVertex2d(0,-5/2);
  glVertex2d(0,5/2);
  glVertex2d(10,5/2);
  glVertex2d(10,-5/2);
  glEnd();
}

void			lib_opengl::draw_head(int i, int j)
{
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glPushMatrix();
  glTranslated(j, i, 0);
  glColor3ub(255,255,2);
  this->head();
  glFlush();
  glPopMatrix();
}

void			lib_opengl::disp_wall(int i, int j)
{
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glPushMatrix();
  glTranslated(j, i, 0);
  glColor3ub(0, 0, 255);
  this->wall();
  glFlush();
  glPopMatrix();
}

void			lib_opengl::wall()
{
  glBegin(GL_QUADS);
  glVertex2d(0,-10/2);
  glVertex2d(0,10/2);
  glVertex2d(10,10/2);
  glVertex2d(10,-10/2);
  glEnd();
}

void			lib_opengl::disp_power(int i, int j)
{
  int		x;
  int		w;
  int		z;

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glPushMatrix();
  glTranslated(j, i, 0);
  x = rand() % 255;
  w = rand() % 255;
  z = rand() % 255;
  glColor3ub(x, w, z);
  this->wall();
  glFlush();
  glPopMatrix();
}

void			lib_opengl::power()
{
  glBegin(GL_QUADS);
  glVertex2d(0,-15/2);
  glVertex2d(0,15/2);
  glVertex2d(15,15/2);
  glVertex2d(15,-15/2);
  glEnd();
}

void			lib_opengl::disp_ghost(int i, int j)
{
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glPushMatrix();
  glTranslated(j, i, 0);
  glColor3ub(255, 0, 0);
  this->ghost();
  glFlush();
  glPopMatrix();
}

void			lib_opengl::ghost()
{
  glBegin(GL_QUADS);
  glVertex2d(0,-20/2);
  glVertex2d(0,20/2);
  glVertex2d(20,20/2);
  glVertex2d(20,-20/2);
  glEnd();
}

void			lib_opengl::disp_ghost_scape(int i, int j)
{
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glPushMatrix();
  glTranslated(j, i, 0);
  glColor3ub(0, 255, 255);
  this->ghost_scape();
  glFlush();
  glPopMatrix();
}

void			lib_opengl::ghost_scape()
{
  glBegin(GL_QUADS);
  glVertex2d(0,-20/2);
  glVertex2d(0,20/2);
  glVertex2d(20,20/2);
  glVertex2d(20,-20/2);
  glEnd();
}


void			lib_opengl::head()
{
  glBegin(GL_QUADS);
  glVertex2d(0,-20/2);
  glVertex2d(0,20/2);
  glVertex2d(20,20/2);
  glVertex2d(20,-20/2);
  glEnd();
}

int			lib_opengl::display(board game)
{
  this->disp_win();
  for(int i=1; i < 31 - 1; i++)
    for(int j=0; j < 30; j++)
      {
	if (game.map[i][j] == 1)
	  this->draw_head(i * 20, j* 20 + 10);
	if (game.map[i][j] == 2)
	  this->draw_body(i * 20, j* 20 + 10);
	if (game.map[i][j] == 3)
	  this->draw_eat(i * 20, j* 20 + 10);
	if (game.map[i][j] == 4)
	  this->disp_wall(i * 20, j * 20 + 10);
	if (game.map[i][j] == 5)
	  this->disp_power(i * 20, j * 20 + 10);
	if (game.map[i][j] == 8)
	  this->disp_ghost(i * 20, j * 20 + 10);
	if (game.map[i][j] == 9)
	  this->disp_ghost_scape(i * 20, j * 20 + 10);
      }
  usleep(game.speed);
  this->print_score(game.score);
  this->window->display();
  if (!window->isOpen())
    {
      window->close();
      return (-1);
    }
  return (0);
}

extern "C"
{
  lib_opengl *getObjOgl()
  {
    return (new lib_opengl);
  }
}
