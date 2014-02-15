#include "Field.h"
#include <iostream>

char Field::getSymbolToShow() {
	if(isOccupied()){
		return occupied_by->getSymbol();
	} else {
		return getSymbol();
	}
}

void Field::buryDead(){
	if(isOccupied() && occupied_by->isDead()){
		grabCharacter();
	}	
}

bool Field::enoughActionPoints(FightingCharacter* a){
	if(a->getActionPoints() < points_to_enter) { 
		return false;
	} else {
		return true;
	}
}

bool Field::tryToEnter(FightingCharacter* a){
	if(!enoughActionPoints(a)) return false;
	if(isOccupied()) { 
		occupied_by->meet(a);
	} else {
	}
	buryDead();
	return !isOccupied();
}
