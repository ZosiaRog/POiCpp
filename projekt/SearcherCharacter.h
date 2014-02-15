#ifndef _SEARCHERCHARACTER_H_
#define _SEARCHERCHARACTER_H_

#include "FightingCharacter.h"
#include "IntelligentCharacters.h"
#include "Field.h"

class SearcherCharacter : public HumanCharacter {
  public:
	SearcherCharacter(pair<int, int> position) : HumanCharacter('P', 2, position){}
	virtual Field* move(vector <Field*> neighbourhood);
	virtual bool decideEntry(FightingCharacter* native) { return false; }
	virtual bool decideEntry(IntelligentCharacter* native) { return false; }
	virtual bool decideEntry(HumanCharacter* native) { return false; }
};

#endif

