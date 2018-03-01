//
// menu_sfml.cpp for Project-Master in /home/raphael/rendu/Cpp/cpp_arcade/anahor
//
// Made by anahor_r
// Login   <abel@epitech.eu>
//
// Started on  Sat Apr  1 23:00:11 2017 anahor_r
// Last update Sat Apr  8 02:38:21 2017 Florent Sebag
//

#include "my_menu.h"

Menu::Menu()
{
    if (!font.loadFromFile("./utils/arial.ttf"))
    {
      return;
    }
  this->my_menu[0].setFont(font);
  this->my_menu[0].setColor(sf::Color::Red);
  this->my_menu[0].setString("Snake");
  this->my_menu[0].setPosition(300, 300);
  this->my_menu[1].setFont(font);
  this->my_menu[1].setColor(sf::Color::Red);
  this->my_menu[1].setString("PacMan");
  this->my_menu[1].setPosition(300, 350);
  this->select = 0;
}

Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow &window)
{
  int i = 0;

  while (i < 2)
    {
      window.draw(this->my_menu[i]);
      i = i + 1;
    }
}

void Menu::up()
{
  if (this->select - 1 >= 0)
    {
      this->my_menu[this->select].setColor(sf::Color::Red);
      this->select = this->select - 1;
      this->my_menu[this->select].setColor(sf::Color::Blue);
    }
}

void Menu::dawn()
{
  if (this->select + 1 < 2)
    {
      this->my_menu[this->select].setColor(sf::Color::Red);
      this->select = this->select + 1;
      this->my_menu[this->select].setColor(sf::Color::Blue);
    }
}

std::string menu_sfml()
{
  sf::RenderWindow window(sf::VideoMode(800, 800), "ARCADE !");
  sf::Texture Image;
  sf::Sprite sprite;
  int nbr;

  Menu my_menu;
  Image.loadFromFile("./utils/titre.png");
  sprite.setTexture(Image);
  sprite.scale(0.5f, 0.5f);
  sprite.setPosition(200, 50);
  while (window.isOpen())
    {
      sf::Event event;
      while (window.pollEvent(event))
        {
	  if (event.type == sf::Event::KeyPressed)
	    {
	      if (event.key.code == sf::Keyboard::Up)
		my_menu.up();
	      else if (event.key.code == sf::Keyboard::Down)
		my_menu.dawn();
	      else if (event.key.code == sf::Keyboard::Return)
		{
		  nbr = my_menu.getItem();
		  if (nbr == 0)
		    return ("Snake");
		  else
		    return ("PacMan");
		}
	      else if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape)
		window.close();
	    }
	}
      window.clear();
      window.draw(sprite);
      my_menu.draw(window);
      window.display();
    }
  return ('\0');
}
