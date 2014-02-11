#ifndef _1_QUACKDOCTORCHARACTER_H_
#define _1_QUACKDOCTORCHARACTER_H_

#include "1_Character.h"

class QuackDoctorCharacter : public Character {
  public:
	QuackDoctorCharacter(pair<int, int> position) : Character('Z', position) {}
	virtual void move() {}
};

#endif
