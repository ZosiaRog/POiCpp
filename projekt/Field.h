#ifndef _FIELD_H_
#define _FIELD_H_

#include "Character.h"

class Field {
  private:
	int points_to_enter;
	char symbol;
	Character* occupied_by;

  protected:
	Field(char symbol, int points_to_enter) : symbol(symbol), points_to_enter(points_to_enter) {}

  public:
	virtual bool tryToEnter(Character* a) = 0;
	char getSymbol(){ return symbol; }
};



#endif
