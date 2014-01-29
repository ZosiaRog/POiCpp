#ifndef _FUSSYCHARACTER_H_
#define _FUSSYCHARACTER_H_

#include "Character.h"

class FussyCharacter : public Character {
  public:
	FussyCharacter() : Character('W', 2){}
	virtual void move();
};

#endif

