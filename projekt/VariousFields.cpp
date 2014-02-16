#include "VariousFields.h"

void RiverField::interactWith(FightingCharacter* a) {
	a->changeHealth(20);
	buryDead();
}

void SwampField::interactWith(FightingCharacter* a) {
	
}

void TreasureField::interactWith(FightingCharacter* a) {
	found = true;
	a->setTreasureFound();
}
