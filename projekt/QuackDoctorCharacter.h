#ifndef _QUACKDOCTORCHARACTER_H_
#define _QUACKDOCTORCHARACTER_H_

#include "Character.h"

class QuackDoctorCharacter : public Character {
  public:
	QuackDoctorCharacter() : Character('Z'){}		//(char symbol, action_points, health)
	virtual void move() {}
};

#endif
