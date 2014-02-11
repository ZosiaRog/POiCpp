#ifndef _1_SEARCHERCHARACTER_H_
#define _1_SEARCHERCHARACTER_H_

#include "1_Character.h"

class SearcherCharacter : public Character {
  public:
	SearcherCharacter(pair<int, int> position) : Character('P', 2, position){}
	virtual void move();
};

#endif

