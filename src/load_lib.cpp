#include "Arcade.h"

Snake *load_libsnake()
{
  void *gameLib;
  void	*(*fct)();
  Snake *res;

  gameLib = dlopen("./games/lib_arcade_snake.so", RTLD_LAZY);
  fct = (void*(*)())dlsym(gameLib, "getObjSnake");
  res = (Snake *)fct();
  res->lib = gameLib;
  return (res);
}

Pacman *load_libpacman()
{
  void *gameLib;
  void	*(*fct)();
  Pacman *res;

  gameLib = dlopen("./games/lib_arcade_pacman.so", RTLD_LAZY);
  fct = (void*(*)())dlsym(gameLib, "getObjPacman");
  res = (Pacman *)fct();
  res->lib = gameLib;
  return (res);
}

Gui *load_libncurses()
{
  void *lib;
  void	*(*fct)();
  Gui *res;

  lib = dlopen("./lib/lib_arcade_ncurses.so", RTLD_LAZY);
  fct = (void*(*)())dlsym(lib, "getObjGui");
  res = (Gui *)fct();
  res->lib = lib;
  return (res);
}

lib_sf *load_libsfml()
{
  void *lib;
  void	*(*fct)();
  lib_sf *res;

  lib = dlopen("./lib/lib_arcade_sfml.so", RTLD_LAZY);
  fct = (void*(*)())dlsym(lib, "getObjSfml");
  res = (lib_sf *)fct();
  res->lib = lib;
  return (res);
}

lib_opengl *load_libogl()
{
  void *lib;
  void	*(*fct)();
  lib_opengl *res;

  lib = dlopen("./lib/lib_arcade_opengl.so", RTLD_LAZY);
  fct = (void*(*)())dlsym(lib, "getObjOgl");
  res = (lib_opengl *)fct();
  res->lib = lib;
  return (res);
}
