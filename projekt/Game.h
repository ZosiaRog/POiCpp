#ifndef _GAME_H_
#define _GAME_H_

#include<string>
#include<vector>
#include<list>

#include "Map.h"
#include "Character.h"
#include "MiloszCharacter.h"
#include "Display.h"

using namespace std;

class Game {
  private:
	void makeCharacter(char c, int x, int y);
	void addStaticCharacter(Character* character);
	void addFightingCharacter(FightingCharacter* character);
	bool readMap(const string filename);
	bool gameOver();

	MiloszCharacter* milosz;
	Map* map;
	list<Character*> static_characters;
	list<FightingCharacter*> fighting_characters;
	Display display;

  public:
	void run();
	bool init(const string file);
	~Game();
};


#endif


