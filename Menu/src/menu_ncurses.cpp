//
// menu.cpp for menu in /home/anahor_r/rendu/Cpp/cpp_arcade/anahor
//
// Made by anahor_r
// Login   <raphael.anahory@epitech.eu>
//
// Started on  Tue Mar 14 14:22:36 2017 anahor_r
// Last update Sat Apr  8 04:03:08 2017 Florent Sebag
//

#include "my_menu.h"

#define ARRAY_SIZE(tab) (sizeof(tab) / sizeof(tab[0]))

void	aff_title()
{

  mvprintw(5, 90, "     ___   _____    _____       ___   _____   _____");
  mvprintw(6, 90, "    /   | |  _  \\  /  ___|     /   | |  _  \\ | ____|");
  mvprintw(7, 90, "   / /| | | |_| |  | |        / /| | | | | | | |__  ");
  mvprintw(8, 90, "  / / | | |  _  /  | |       / / | | | | | | |  __| ");
  mvprintw(9, 90, " / /  | | | | \\ \\  | |___   / /  | | | |_| | | |___ ");
  mvprintw(10, 90, "/_/   |_| |_|  \\_\\ \\_____| /_/   |_| |_____/ |_____|");

}

std::string	take_game()
{
  WINDOW	*game;
  MENU		*menu;
  ITEM		**my_item;
  int		c, i, p;
  const char	*name_game = "Snake";
  const char	*name_g = "PacMan";
  const char	*posibility[2] = {name_game, name_g};

  my_item = (ITEM **)calloc(2 + 1, sizeof(ITEM *));
  my_item[0] = new_item(name_game, NULL);
  my_item[1] = new_item(name_g, NULL);
  my_item[2] = (ITEM *)NULL;

  game = subwin(stdscr, LINES / 2 - 2, COLS / 2 - 2, LINES / 4, COLS / 4);
  box(game, 0, 0);
  mvwprintw(game, 2, 20, "CHOISI TON JEU !!!");
  menu = new_menu((ITEM **)my_item);
  set_menu_win(menu, game);
  set_menu_sub(menu, derwin(game, 10, 40, 5, 3));
  post_menu(menu);
  wrefresh(game);
  p = 0;
  while((c = getch()) != 10)
    {
      switch(c)
	{
	case KEY_DOWN:
	  menu_driver(menu, REQ_DOWN_ITEM);
	  if (p != 1)
	    p = p + 1;
	  break;
	case KEY_UP:
	  menu_driver(menu, REQ_UP_ITEM);
	  if (p != 0)
	    p = p - 1;
	  break;
	}
    }
  for(i = 0; i < 3; ++i)
    free_item(my_item[i]);
  free_menu(menu);
  wrefresh(game);
  delwin(game);
  return ((std::string)posibility[p]);
}

std::string	menu_ncurses()
{
  std::string game;
  WINDOW *Screen;

  Screen = initscr();
  cbreak();
  noecho();
  keypad(stdscr, TRUE);
  aff_title();
  game = take_game();
  refresh();
  wclear(Screen);
  delwin(Screen);
  endwin();
  return (game);
}
