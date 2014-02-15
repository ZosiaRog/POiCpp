#ifndef _MILOSZCHARACTER_H_
#define _MILOSZCHARACTER_H_

#include "FightingCharacter.h"
#include "IntelligentCharacters.h"
	

class MiloszCharacter : public HumanCharacter {
  private:
	double armor;
	bool gift;
	double weapon;
	
  public:
	MiloszCharacter(pair<int, int> position) : HumanCharacter('M', 3, position), armor(0), gift(false), weapon(0){
		health = 50;
		strength = 50;
	}

	Field* move(vector <Field*> neighbourhood);
	double getWeapon(){ return weapon; }
	double getArmor(){ return armor; }
	bool getGift(){ return gift; }
	virtual bool decideEntry(FightingCharacter* native) { return true; }
	virtual bool decideEntry(IntelligentCharacter* native) { return true; }
	virtual bool decideEntry(HumanCharacter* native) { return true; }
};

#endif
