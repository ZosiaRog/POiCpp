#ifndef _FIELD_H_
#define _FIELD_H_

#include "Character.h"

class Field {
  private:
	int points_to_enter;
	char symbol;
	Character* occupied_by;
	bool isOccupied() { return occupied_by != 0; }

  protected:
	Field(char symbol, int points_to_enter) : symbol(symbol), points_to_enter(points_to_enter), occupied_by(0) {}

  public:
	virtual bool tryToEnter(Character* a) = 0;
	char getSymbol(){ return symbol; }
	char getSymbolToShow();
	void putCharacter(Character* character) { occupied_by = character; }
};



#endif
