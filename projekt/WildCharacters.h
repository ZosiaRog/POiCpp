#ifndef _WILDCHARACTERS_H_
#define _WILDCHARACTERS_H_

#include "FightingCharacter.h"
#include "Field.h"

class AgressiveCharacter : public FightingCharacter {
  public:
	AgressiveCharacter(pair<int, int> position)  : FightingCharacter('A', 2, position){}
	virtual Field* move(vector <Field*> neighbourhood){}
};

class CowardCharacter : public FightingCharacter {
  public:
	CowardCharacter(pair<int, int> position)  : FightingCharacter('T', 2, position){}
	virtual Field* move(vector <Field*> neighbourhood){}
};

class FussyCharacter : public FightingCharacter {
  public:
	FussyCharacter(pair<int, int> position)  : FightingCharacter('W', 2, position){}
	virtual Field* move(vector <Field*> neighbourhood){}
};

class NeutralCharacter : public FightingCharacter {
  public:
	NeutralCharacter(pair<int, int> position)  : FightingCharacter('N', 2, position){}
	virtual Field* move(vector <Field*> neighbourhood);
};


#endif
