#ifndef _1_MILOSZCHARACTER_H_
#define _1_MILOSZCHARACTER_H_

#include "1_Character.h"

class MiloszCharacter : public Character {
  public:
	MiloszCharacter(pair<int, int> position) : Character('M', 3, 50, 50, 0, 0, false, position) {}
	virtual void move();
};

#endif
