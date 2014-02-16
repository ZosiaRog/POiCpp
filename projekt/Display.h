#ifndef _DISPLAY_H_
#define _DISPLAY_H_

#include <ncurses.h>

class Map;
class MiloszCharacter;
class Display {
  public:	
	void init();
	void stop();
	void refreshView(Map* map, MiloszCharacter* milosz);
	int getCommand();
	bool isEndGame(){ return end_game; }
  private:
	WINDOW* status_window;
	bool end_game;
};

#endif
