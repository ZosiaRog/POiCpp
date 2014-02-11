#ifndef _GAME_H_
#define _GAME_H_

#include<string>
#include<vector>
#include<list>

#include "Map.h"
#include "1_Character.h"

using namespace std;

class Game {
  private:
	void makeCharacter(char c, int x, int y);
	void addCharacter(Character* character);
	bool readMap(const string filename);
	void initDisplay();
	void stopDisplay();
	void refreshView();

	Map* map;
	list<Character*> characters;

  public:
	void run();
	bool init(const string file);
	~Game();
};


#endif


