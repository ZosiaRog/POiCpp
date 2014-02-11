#ifndef _1_AGRESSIVECHARACTER_H_
#define _1_AGRESSIVECHARACTER_H_

#include "1_Character.h"

class AgressiveCharacter : public Character {
  public:
	AgressiveCharacter(pair<int, int> position)  : Character('A', 2, position){}
	virtual void move();
};

#endif

