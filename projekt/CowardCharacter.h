#ifndef _COWARDCHARACTER_H_
#define _COWARDCHARACTER_H_

#include "Character.h"

class CowardCharacter : public Character {
  public:
	CowardCharacter() : Character('T', 2){}
	virtual void move();
};

#endif

