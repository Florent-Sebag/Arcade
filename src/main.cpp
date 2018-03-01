#include "Arcade.h"

// void options_touch(IGame *Game, IGui *curse, int touch)
// {
//   std::string next_gui;
//   std::string next_game;
//
//   if (touch == 5)
//     next_gui = curse->get_prev_lib();
//   if (touch == 6)
//     next_gui = curse->get_next_lib();
//   if (touch == 7)
//     next_game = Game->get_prev_lib();
//   if (touch == 8)
//     next_game = Game->get_next_lib();
//   if (touch == 9)
//     {
//       delete curse;
//       delete Game;
//     }
//   if (touch == 10)
//
// }

int main_loop(IGame *Game, IGui *curse)
{
  board	game;
  t_orientation dir;
  int		k = 0;

  while (k == 0)
    {
      dir = curse->get_touch();
      if (dir > 4)
        return (dir);
      k = Game->check_move(dir);
      game = Game->get_board();
      if (curse->display(game) == -1)
        return (0);
    }
  delete curse;
  delete Game;
  return (0);
}

int main(int ac, char **av)
{
  launch_menu(ac, av);
  return (0);
}
