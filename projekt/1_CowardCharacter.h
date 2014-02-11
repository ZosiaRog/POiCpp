#ifndef _1_COWARDCHARACTER_H_
#define _1_COWARDCHARACTER_H_

#include "1_Character.h"

class CowardCharacter : public Character {
  public:
	CowardCharacter(pair<int, int> position)  : Character('T', 2, position){}

	virtual void move();
};

#endif

