#ifndef _INNKEEPERCHARACTER_H_
#define _INNKEEPERCHARACTER_H_

#include "Character.h"

class InnkeeperCharacter : public Character {
  public:
	InnkeeperCharacter() : Character('S'){}
	virtual void move() {};
};

#endif
