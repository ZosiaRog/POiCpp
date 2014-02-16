#ifndef _DISPLAY_H_
#define _DISPLAY_H_

#include <ncurses.h>
#include <map>
using namespace std;

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
	void treasureFound();
	void youDied();
  private:
	WINDOW* status_window;
	bool end_game;
	map<char, int> symbColors;
};

#endif
