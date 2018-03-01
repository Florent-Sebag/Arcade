//
// interface.cpp for interface in /home/benama_m/arcade_test
//
// Made by Mahdi Benamar
// Login   <benama_m@epitech.net>
//
// Started on  Fri Mar 17 17:14:55 2017 Mahdi Benamar
// Last update Sun Apr  9 20:19:09 2017 benamar
//

#include "lib_sfml.h"

lib_sf::lib_sf()
{
  this->key = RIGHT;
  this->init_windows();
}

lib_sf::~lib_sf()
{
}

void *lib_sf::getLib()
{
  return (this->lib);
}

lib_sf::lib_sf(lib_sf const &cl)
{
  this->key = cl.key;
}

lib_sf&          lib_sf::operator=(lib_sf const &clone)
{
  this->key = clone.key;
  return (*this);
}

t_orientation		lib_sf::get_touch()
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

t_orientation	lib_sf::get_key() const
{
  return (this->key);
}

sf::RenderWindow	*lib_sf::getWindow()
{
  return (this->window);
}

sf::RectangleShape	lib_sf::getScore()
{
  return (this->score);
}

sf::Text		lib_sf::getText()
{
  return (this->text);
}
sf::RectangleShape	lib_sf::getRec()
{
  return (this->rectangle);
}

void			lib_sf::disp_win()
{
  this->window->clear();
  this->window->draw(this->rectangle);
  this->window->draw(this->score);
  this->window->draw(this->text);
}

void          lib_sf::init_windows()
{
  this->window = new sf::RenderWindow(sf::VideoMode(2000, 1000), "SFML works!");
  this->rectangle.setSize(sf::Vector2f(580, 585));
  this->rectangle.setFillColor(sf::Color::Black);
  this->rectangle.setOutlineColor(sf::Color::Blue);
  this->rectangle.setOutlineThickness(8);
  this->rectangle.setPosition(10, 10);
  this->score.setSize(sf::Vector2f(200, 200));
  this->score.setFillColor(sf::Color::Black);
  this->score.setOutlineColor(sf::Color::Blue);
  this->score.setOutlineThickness(8);
  this->score.setPosition(820, 10);
  if (!this->font.loadFromFile("utils/ARCADE_I.ttf"))
    {
      return ;
    }
  this->text.setFont(this->font); // font est un sf::Font
  this->text.setString("Score");
  this->text.setCharacterSize(24); // exprimée en pixels, pas en points !
  this->text.setColor(sf::Color::Red);
  this->text.setStyle(sf::Text::Bold | sf::Text::Underlined);
  this->text.setPosition(860, 10);
  if (!this->texture.loadFromFile("utils/pomme.png"))
    {
      return ;
    }
  if (!this->power.loadFromFile("utils/kebab.png"))
    {
      return ;
    }
  if (!this->ghost.loadFromFile("utils/ghost.png"))
    {
      return ;
    }
  if (!this->ghost_scape.loadFromFile("utils/ghost_scape.png"))
    {
      return ;
    }
}

void			lib_sf::print_score(int scr)
{
  sf::Text the_score;
  const char *nbr;

  nbr = to_string(scr).c_str();
  the_score.setFont(this->font); // font est un sf::Font
  the_score.setString(nbr);
  the_score.setCharacterSize(24); // exprimée en pixels, pas en points !
  the_score.setColor(sf::Color::Red);
  the_score.setStyle(sf::Text::Bold);
  the_score.setPosition(910, 100);
  this->window->draw(the_score);
}

int			lib_sf::disp_head(int j, int i,  sf::RectangleShape shape)
{
  shape.setFillColor(sf::Color::Yellow);
  shape.setPosition(sf::Vector2f(j * 20, i * 20));
  shape.setOutlineColor(sf::Color::Yellow);
  shape.setOutlineThickness(2);
  this->window->draw(shape);
  return (0);
}

int			lib_sf::disp_body(int j, int i,  sf::RectangleShape shape)
{
  shape.setPosition(sf::Vector2f(j * 20, i * 20));
  shape.setOutlineColor(sf::Color::Green);
  shape.setOutlineThickness(2);
  this->window->draw(shape);
  return (0);
}

int			lib_sf::disp_eat(int j, int i,  sf::Sprite sprite)
{
  sprite.setPosition(j * 20, i * 20);
  this->window->draw(sprite);
  return (0);
}

int			lib_sf::disp_wall(int j, int i, sf::RectangleShape shap)
{
  shap.setFillColor(sf::Color::Blue);
  shap.setPosition(sf::Vector2f(j * 20, i * 20));
  this->window->draw(shap);
  return (0);
}

int			lib_sf::disp_power(int j, int i)
{
  sf::Sprite keb;

  keb.setTexture(this->power);
  keb.scale(0.1f, 0.1f);
  keb.setPosition(j * 20, i * 20);
  this->window->draw(keb);
  return (0);
}

int			lib_sf::disp_ghost(int j, int i)
{
  sf::Sprite keb;

  keb.setTexture(this->ghost);
  keb.scale(0.15f, 0.15f);
  keb.setPosition(j * 20, i * 20);
  this->window->draw(keb);
  return (0);
}

int			lib_sf::disp_ghost_scape(int j, int i)
{
  sf::Sprite keb;

  keb.setTexture(this->ghost_scape);
  keb.scale(0.2f, 0.2f);
  keb.setPosition(j * 20, i * 20);
  this->window->draw(keb);
  return (0);
}

int			lib_sf::display(board game)
{
  sf::RectangleShape shape(sf::Vector2f(10, 10));
  sf::RectangleShape shap(sf::Vector2f(10, 10));
  sf::RectangleShape body(sf::Vector2f(10, 10));
  sf::Sprite sprite;

  sprite.setTexture(this->texture);
  sprite.scale(0.1f, 0.1f);
  body.setFillColor(sf::Color::Green);
  this->disp_win();
  for (int i=1; i < 31 - 1; i++)
    for (int j=0; j < 30; j++)
      {
	if (game.map[i][j] == 1)
	  this->disp_head(j, i, shape);
	if (game.map[i][j] == 2)
	  this->disp_body(j, i, body);
	if (game.map[i][j] == 3)
	  this->disp_eat(j, i, sprite);
	if (game.map[i][j] == 4)
	  this->disp_wall(j, i, shap);
	if (game.map[i][j] == 5)
	  this->disp_power(j, i);
	if (game.map[i][j] == 8)
	  this->disp_ghost(j, i);
	if (game.map[i][j] == 9)
	  this->disp_ghost_scape(j, i);
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
  lib_sf *getObjSfml()
  {
    return (new lib_sf);
  }
}
