#ifndef _DISPLAY_H_
#define _DISPLAY_H_

#include <ncurses.h>
#include <map>
using namespace std;


/*
     COLOR_BLACK   0
        COLOR_RED     1
        COLOR_GREEN   2
        COLOR_YELLOW  3
        COLOR_BLUE    4
        COLOR_MAGENTA 5
        COLOR_CYAN    6
        COLOR_WHITE   7
*/

class Map;
class MiloszCharacter;
class Display {
  public:
	void initColors();
	void init();
	void stop();
	void refreshView(Map* map, MiloszCharacter* milosz);
	int getCommand();
	bool isEndGame(){ return end_game; }
	void drawField(int x, int y, char c);
	void congratulations();
	void gameOver();
  private:
	WINDOW* status_window;
	bool end_game;
	map<char, int> symbColors;
};

#endif
