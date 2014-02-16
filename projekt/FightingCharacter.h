#ifndef _FIGHTINGCHARACTER_H_
#define _FIGHTINGCHARACTER_H_

#include "Character.h"

#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <utility>
#include <vector>
#include "Items.h"


class Field;
class IntelligentCharacter;
class HumanCharacter;

class FightingCharacter: public Character {
 protected:
	bool treasure_found;
	int health;
	int strength;
	Armor* armor;
	Gift* gift;
	Weapon* weapon;

	FightingCharacter(char symbol, int action_points_per_turn, pair<int, int> position) : Character(symbol, position), armor(NULL), gift(NULL), weapon(NULL), treasure_found(false){
		this->action_points_per_turn = action_points_per_turn;
		resetNewTurn();
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
	void setHealth(int newHealth){ health = newHealth; }
	int getStrength(){ return strength; }
	void useActionPoints(int a) { actual_action_points -= a; }
	void resetNewTurn() { this->actual_action_points = action_points_per_turn; }
	void changeHealth(int wound) { health -= wound; }
	virtual Field* move(vector<Field*> neighbourhood) = 0;
	virtual bool decideEntry(FightingCharacter* native) = 0;
	virtual bool decideEntry(IntelligentCharacter* native) = 0;
	virtual bool decideEntry(HumanCharacter* native) = 0;
	virtual bool recognize(FightingCharacter* a) { a->decideEntry(this); }

	virtual void receiveItem(Gift* item){ gift = item; }
	virtual void receiveItem(Armor* item){ armor = item; }
	virtual void receiveItem(Weapon* item){ weapon = item; }
	Weapon* getWeapon(){ return weapon; }
	Armor* getArmor(){ return armor; }
	Gift* getGift(){ return gift; }
	Gift* takeGift(){ Gift* toGive = gift; gift = NULL; return toGive; }
	void setTreasureFound(){ treasure_found = true; }
	bool getTreasureFound(){ return treasure_found; }
};

class HumanCharacter : public FightingCharacter {
  public:
	HumanCharacter(char symbol, int action_points_per_term, pair<int, int> position) : FightingCharacter(symbol, action_points_per_term, position) {}
};



#endif
