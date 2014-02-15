#ifndef _MILOSZCHARACTER_H_
#define _MILOSZCHARACTER_H_

#include "FightingCharacter.h"

class MiloszCharacter : public FightingCharacter {
  private:
	double armor;
	bool gift;
	double weapon;
	
  public:
	MiloszCharacter(pair<int, int> position) : FightingCharacter('M', 3, position), armor(0), gift(false), weapon(0){
		health = 50;
		strength = 50;
	}

	Field* move(vector <Field*> neighbourhood);
	double getWeapon(){ return weapon; }
	double getArmor(){ return armor; }
	bool getGift(){ return gift; }
};

#endif
