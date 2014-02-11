#ifndef _1_BARDCHARACTER_H_
#define _1_BARDCHARACTER_H_

#include "1_Character.h"

class BardCharacter : public Character {
  public:
	BardCharacter(pair<int, int> position) : Character('B', position) {}
	virtual void move() {}
};

#endif
