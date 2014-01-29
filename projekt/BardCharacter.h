#ifndef _BARDCHARACTER_H_
#define _BARDCHARACTER_H_

#include "Character.h"

class BardCharacter : public Character {
  public:
	BardCharacter(pair<int, int> position) : Character('B', position) {}
	virtual void move() {}
};

#endif
