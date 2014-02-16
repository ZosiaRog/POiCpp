#ifndef _FIELD_H_
#define _FIELD_H_

#include <utility>

#include "Character.h"
#include "FightingCharacter.h"

class Field {
  protected:
	int points_to_enter;
	char symbol;
	Character* occupied_by;
	pair<int, int> position;

	Field(char symbol, int points_to_enter, pair<int, int> position) : symbol(symbol), points_to_enter(points_to_enter), position(position), occupied_by(0) {}

  public:
	virtual void interactWith(FightingCharacter* a) {}
	virtual void interactWith(HumanCharacter* a) {}
	virtual bool tryToEnter(FightingCharacter* a);
	virtual char getSymbolToShow();
	bool isOccupied() { return occupied_by != 0; }
	bool enoughActionPoints(FightingCharacter* a);
	char getSymbol(){ return symbol; }
	Character* getOccupiedBy() { return occupied_by; }
	pair <int, int> getPosition() { return position; }
	void putCharacter(Character* character) { occupied_by = character; }
	void grabCharacter() { occupied_by = NULL; }
	void enter(FightingCharacter* a){ putCharacter(a); interactWith(a);}
	void flatten(){ points_to_enter = 1; }
	void buryDead();
};

#endif
