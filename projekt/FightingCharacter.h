#ifndef _FIGHTINGCHARACTER_H_
#define _FIGHTINGCHARACTER_H_

#include "Character.h"

#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <utility>
#include <vector>


class Field;
class IntelligentCharacter;
class HumanCharacter;

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
	void changeHealth(int wound) { health -= wound; }
	virtual Field* move(vector<Field*> neighbourhood) = 0;
	virtual bool decideEntry(FightingCharacter* native) = 0;
	virtual bool decideEntry(IntelligentCharacter* native) = 0;
	virtual bool decideEntry(HumanCharacter* native) = 0;
	virtual bool recognize(FightingCharacter* a) { a->decideEntry(this); }
};

class HumanCharacter : public FightingCharacter {
  public:
	HumanCharacter(char symbol, int action_points_per_term, pair<int, int> position) : FightingCharacter(symbol, action_points_per_term, position) {}
};



#endif
