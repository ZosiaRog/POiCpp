#include "VariousFields.h"

void RiverField::interactWith(FightingCharacter* a) {
	a->changeHealth(20);
	buryDead();
}

void SwampField::interactWith(FightingCharacter* a) {
	if(!safe){
		a->setHealth(-5);
	}
}

void TreasureField::interactWith(HumanCharacter* a) {
	found = true;
	a->setTreasureFound();
}
