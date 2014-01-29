#ifndef _NEUTRALCHARACTER_H_
#define _NEUTRALCHARACTER_H_

#include "Character.h"

class NeutralCharacter : public Character {
  public:
	NeutralCharacter() : Character('N', 2){}
	virtual void move();
};

#endif

