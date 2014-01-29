#ifndef _MILOSZCHARACTER_H_
#define _MILOSZCHARACTER_H_

#include "Character.h"

class MiloszCharacter : public Character {
  public:
	MiloszCharacter() : Character('M', 3, 50, 1, 0, 0, false){}		//(char symbol, action_points, health)
	virtual void move();
};

#endif
