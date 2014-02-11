#ifndef _1_FUSSYCHARACTER_H_
#define _1_FUSSYCHARACTER_H_

#include "1_Character.h"

class FussyCharacter : public Character {
  public:
	FussyCharacter(pair<int, int> position)  : Character('W', 2, position){}
	virtual void move();
};

#endif
