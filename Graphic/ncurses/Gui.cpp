#include "Gui.h"

Gui::Gui()
{
  this->Screen = initscr();
  this->win = subwin(this->Screen, 32, 32, (LINES - 31) / 2, (COLS - 30) / 2);
  this->score_win = subwin(this->Screen, 10, 20, 1, 5);
  this->w = 30;
  this->h = 31;
  box(this->win, 0, 0);
  box(this->score_win, 0, 0);
  noecho();
  curs_set(false);
  start_color();
  use_default_colors();
  nodelay(Screen, TRUE);
	init_pair(1, COLOR_RED, COLOR_RED);
  init_pair(2, COLOR_BLUE, COLOR_BLUE);
}

Gui::~Gui()
{
  delwin(this->score_win);
  delwin(this->win);
  wclear(this->Screen);
  delwin(this->Screen);
  endwin();
}

void *Gui::getLib()
{
  return (this->lib);
}

int Gui::display(board game)
{
  int           x = w;
  int           y = h;

  for (int i=1; i < y; i++)
   {
     for (int j=0; j < x; j++)
       {
         if (game.map[i][j] == 0)
           mvwprintw(win, i, j + 1, " ");
         if (game.map[i][j] == 1)
           {
             wattron(win, COLOR_PAIR(1));
             mvwprintw(win, i, j + 1, "0");
             wattroff(win, COLOR_PAIR(1));
           }
         if (game.map[i][j] == 2)
           mvwprintw(win, i, j + 1, "o");
         if (game.map[i][j] == 3)
           mvwprintw(win, i, j + 1, ".");
         if (game.map[i][j] == 4)
           mvwprintw(win, i, j + 1, "|");
         if (game.map[i][j] == 5)
           mvwprintw(win, i, j + 1, "O");
         if (game.map[i][j] == 8)
           {
             wattron(win, COLOR_PAIR(2));
             mvwprintw(win, i, j + 1, "0");
             wattroff(win, COLOR_PAIR(2));
           }
         if (game.map[i][j] == 9)
           {
             wattron(win, COLOR_PAIR(1));
             mvwprintw(win, i, j + 1, "0");
             wattroff(win, COLOR_PAIR(1));
           }
       }
   }
  wrefresh(this->win);
  display_score(game.score);
  usleep(game.speed);
  refresh();
  return (0);
}

void Gui::display_score(int score)
{
  const char *str;

  str = std::to_string(score).c_str();
  mvwprintw(this->score_win, 1, 7, "SCORE");
  mvwprintw(this->score_win, 5, 9, str);
  wrefresh(this->score_win);
}

t_orientation		Gui::get_touch()
{
  int		kkey;

  kkey = getch();
  if (kkey == KEY_UP)
    this->key = UP;
  if (kkey == KEY_DOWN)
    this->key = DOWN;
  if (kkey == KEY_RIGHT)
    this->key = RIGHT;
  if (kkey == KEY_LEFT)
    this->key = LEFT;
  if (kkey == 'a')
    this->key = TWO;
  if (kkey == 'z')
    this->key = THREE;
  if (kkey == 'e')
    this->key = FOUR;
  if (kkey == 'r')
    this->key = FIVE;
  if (kkey == 't')
    this->key = EIGHT;
  if (kkey == 'u')
    this->key = NINE;
  if (kkey == 27)
    this->key = EXIT;
  return (this->key);
}

extern "C" Gui *getObjGui()
{
  return (new Gui);
}
