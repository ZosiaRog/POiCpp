#ifndef _SEARCHERCHARACTER_H_
#define _SEARCHERCHARACTER_H_

#include "Character.h"

class SearcherCharacter : public Character {
  public:
	SearcherCharacter() : Character('P', 2){}		//(char symbol, action_points, health)
	virtual void move();
};

#endif

