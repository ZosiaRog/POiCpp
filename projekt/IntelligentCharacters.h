#ifndef _INTELLIGENTCHARACTERS_H_
#define _INTELLIGENTCHARACTERS_H_

#include "Character.h"
#include "FightingCharacter.h"

class IntelligentCharacter : public Character{
  public:
	IntelligentCharacter(char symbol, pair<int, int> position) : Character(symbol, position) {}
	virtual bool recognize(FightingCharacter* a) { a->decideEntry(this); }
};


class BardCharacter : public IntelligentCharacter {
  public:
	BardCharacter(pair<int, int> position) : IntelligentCharacter('B', position) {}
};

class InnkeeperCharacter : public IntelligentCharacter {
  public:
	InnkeeperCharacter(pair<int, int> position) : IntelligentCharacter('S', position) {}
};

class QuackDoctorCharacter : public IntelligentCharacter {
  public:
	QuackDoctorCharacter(pair<int, int> position) : IntelligentCharacter('Z', position) {}
};

#endif
