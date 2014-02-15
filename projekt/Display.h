#ifndef _DISPLAY_H_
#define _DISPLAY_H_

#include <ncurses.h>
#include "MiloszCharacter.h"

class Map;
class Display {
  public:	
	void init();
	void stop();
	void refreshView(Map* map, MiloszCharacter* milosz);
  private:
	WINDOW* status_window;
};

#endif
