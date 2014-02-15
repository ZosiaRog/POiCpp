#ifndef _WILDCHARACTERS_H_
#define _WILDCHARACTERS_H_

#include "FightingCharacter.h"
#include "Field.h"

class WildCharacter : public FightingCharacter {
  public:
	WildCharacter(char symbol, pair<int, int> position)  : FightingCharacter(symbol, 2, position){}
	virtual Field* move(vector <Field*> neighbourhood);
};

class AgressiveCharacter : public WildCharacter {
  public:
	AgressiveCharacter(pair<int, int> position)  : WildCharacter('A', position){}
	//virtual Field* move(vector <Field*> neighbourhood);
};

class CowardCharacter : public WildCharacter {
  public:
	CowardCharacter(pair<int, int> position)  : WildCharacter('T', position){}
	//virtual Field* move(vector <Field*> neighbourhood);
};

class FussyCharacter : public WildCharacter {
  public:
	FussyCharacter(pair<int, int> position)  : WildCharacter('W', position){}
	//virtual Field* move(vector <Field*> neighbourhood);
};

class NeutralCharacter : public WildCharacter {
  public:
	NeutralCharacter(pair<int, int> position)  : WildCharacter('N', position){}
	//virtual Field* move(vector <Field*> neighbourhood);
};


#endif
