//
// main.cpp for Project-Master in /home/raphael/rendu/Cpp/cpp_arcade/menu/src
//
// Made by anahor_r
// Login   <abel@epitech.eu>
//
// Started on  Tue Apr  4 17:36:54 2017 anahor_r
// Last update Sat Apr  8 17:23:51 2017 Florent Sebag
//

#include "Arcade.h"

IGui *get_graphic_lib(std::string choice_gui)
{
  if (choice_gui == "sfml")
    return (load_libsfml());
  else if (choice_gui == "ncurses")
    return (load_libncurses());
  else
    return (load_libogl());
}

IGame *get_game_lib(std::string choice_game)
{
  if (choice_game == "Snake")
    return (load_libsnake());
  else
    return (load_libpacman());
}

std::string get_next_lib(std::string name, int ret)
{
  if (name == "ncurses")
    {
      if (ret == 5)
        return ("opengl");
      return ("sfml");
    }
  if (name == "sfml")
    {
      if (ret == 5)
        return ("ncurses");
      return ("opengl");
    }
  if (name == "opengl")
    {
      if (ret == 5)
        return ("sfml");
      return ("ncurses");
    }
  if (name == "Snake")
    return ("PacMan");
  else
    return ("Snake");
}

int launch_game(IGame *Game, IGui *Gui, std::string choice_game, std::string choice_graphic)
{
  int ret;
  void *to_close;

  std::cout << "Game = " << choice_game << std::endl;
  std::cout << "Graphic = " << choice_graphic << std::endl;
  while ((ret = main_loop(Game, Gui)) != 0)
    {
      to_close = Game->getLib();
      if (ret == 5 || ret == 6)
        {
          choice_graphic = get_next_lib(choice_graphic, ret);
          to_close = Gui->getLib();
          delete Gui;
          dlclose(to_close);
          Gui = get_graphic_lib(choice_graphic);
        }
      if (ret == 7 || ret == 8)
        {
          choice_game = get_next_lib(choice_game, ret);
          delete Game;
          dlclose(to_close);
          to_close = Gui->getLib();
          delete Gui;
          dlclose(to_close);
          Game = get_game_lib(choice_game);
          Gui = get_graphic_lib(choice_graphic);
        }
      if (ret == 9)
        {
          delete Game;
          dlclose(to_close);
          to_close = Gui->getLib();
          delete Gui;
          dlclose(to_close);
          Game = get_game_lib(choice_game);
          Gui = get_graphic_lib(choice_graphic);
        }
      if (ret == 10)
        {
          delete Game;
          dlclose(to_close);
          to_close = Gui->getLib();
          delete Gui;
          dlclose(to_close);
          return (-1);
        }
    }
  return (0);
}

int launch_menu(int ac, char **av)
{
  IGame *Game;
  IGui *Gui;
  std::string choice_game;
  std::string choice_gui;

  if (ac < 2)
    {
      choice_game = menu_sfml();
      choice_gui = "sfml";
    }
  else
    {
      choice_gui = std::string(av[1]);
      if (choice_gui != "sfml" && choice_gui != "ncurses" && choice_gui != "opengl")
        {
          std::cout << "You need to choose a graphic lib between this : ncurses | sfml | opengl" << std::endl;
          return (0);
        }
      if (choice_gui == "sfml")
        choice_game = menu_sfml();
      else if (choice_gui == "ncurses")
        choice_game = menu_ncurses();
      else
        choice_game = menu_sfml();
    }
  Game = get_game_lib(choice_game);
  Gui = get_graphic_lib(choice_gui);
  if (launch_game(Game, Gui, choice_game, choice_gui) == -1)
    launch_menu(ac, av);
  return (0);
}
