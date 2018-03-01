#ifndef _GUI_H_
# define _GUI_H_

#include "IGui.hpp"

class Gui : public IGui
{
	protected:
    WINDOW  *Screen;
    WINDOW	*win;
    WINDOW	*score_win;
    t_orientation key;
    int 		w;
    int 		h;
  public:
    Gui();
    ~Gui();

		void *lib;
    virtual void* getLib();
    int	 **getMap();
    virtual int display(board);
    virtual t_orientation	get_touch();
	  void display_score(int score);
};

extern "C" Gui *getObjGui();

#endif
