#ifndef _1_NEUTRALCHARACTER_H_
#define _1_NEUTRALCHARACTER_H_

#include "1_Character.h"

class NeutralCharacter : public Character {
  public:
	NeutralCharacter(pair<int, int> position)  : Character('N', 2, position){}
	virtual void move();
};

#endif

