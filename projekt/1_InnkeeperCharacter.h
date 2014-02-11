#ifndef _1_INNKEEPERCHARACTER_H_
#define _1_INNKEEPERCHARACTER_H_

#include "1_Character.h"

class InnkeeperCharacter : public Character {
  public:
	InnkeeperCharacter(pair<int, int> position) : Character('S', position) {}
	virtual void move() {};
};

#endif
