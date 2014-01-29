#ifndef _AGRESSIVECHARACTER_H_
#define _AGRESSIVECHARACTER_H_

#include "Character.h"

class AgressiveCharacter : public Character {
  public:
	AgressiveCharacter() : Character('A', 2){} 
	virtual void move();
};

#endif

