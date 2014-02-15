#ifndef _FIGHTINGCHARACTER_H_
#define _FIGHTINGCHARACTER_H_

#include "Character.h"

#include <iomanip>
#include <cstdlib>
#include <time.h>
#include <utility>
#include <vector>

#include "IntelligentCharacters.h"

class Field;
class FightingCharacter: public Character {

 protected:
	int health;
	int strength;

	FightingCharacter(char symbol, int action_points_per_turn, pair<int, int> position) : Character(symbol, position){
		this->action_points_per_turn = action_points_per_turn;
		this->actual_action_points = action_points_per_turn;
		srand(time(NULL));
		health = rand() % 101;
		strength = rand() % 101;
	}

  public:
	virtual bool meet(FightingCharacter* a);
	virtual bool isDead();
 	int calculateHitPoints();
	void receiveHitPoints(int hitPoints);
	int getHealth(){ return health; }
	int getStrength(){ return strength; }
	void decreaseActionPoints(int a);
	void changeHealth(int new_health) { health = new_health; }
	virtual Field* move(vector<Field*> neighbourhood) { return NULL; }
	virtual bool decideEntry(FightingCharacter* native){ return false; }
	virtual bool decideEntry(IntelligentCharacter* native){ return false; }
};


#endif
