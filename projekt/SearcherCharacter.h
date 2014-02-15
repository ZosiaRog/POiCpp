#ifndef _SEARCHERCHARACTER_H_
#define _SEARCHERCHARACTER_H_

#include "FightingCharacter.h"
#include "Field.h"

class SearcherCharacter : public FightingCharacter {
  public:
	SearcherCharacter(pair<int, int> position) : FightingCharacter('P', 2, position){}
	virtual Field* move(vector <Field*> neighbourhood);
};

#endif

