#include "VariousFields.h"

void RiverField::interactWith(FightingCharacter* a) {
	a->changeHealth(20);
}

void SwampField::interactWith(FightingCharacter* a) {
	
}

void TreasureField::interactWith(FightingCharacter* a) {
	//wchodzi poszukiwacz -> treasure_found
}
