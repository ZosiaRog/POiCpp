#ifndef _MILOSZCHARACTER_H_
#define _MILOSZCHARACTER_H_

#include "FightingCharacter.h"
#include "IntelligentCharacters.h"
#include "Items.h"
	

class MiloszCharacter : public HumanCharacter {
  public:
	MiloszCharacter(pair<int, int> position) : HumanCharacter('M', 3, position){
		health = 50;
		strength = 50;
	}

	Field* move(vector <Field*> neighbourhood);
	virtual bool decideEntry(FightingCharacter* native) { return true; }
	virtual bool decideEntry(IntelligentCharacter* native) { return true; }
	virtual bool decideEntry(HumanCharacter* native) { return true; }
};

#endif
