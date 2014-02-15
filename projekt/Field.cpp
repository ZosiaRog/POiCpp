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
		cout << "not enough action points." << endl;
		return false;
	} else {
		return true;
	}
}

bool Field::tryToEnter(FightingCharacter* a){
	cout << a->getSymbol() << " tries to enter " << getSymbol() << endl;

	if(!enoughActionPoints(a)) return false;
	if(isOccupied()) { 
		cout << "is occupied by " << occupied_by->getSymbol() << endl;
		occupied_by->meet(a);
	} else {
		cout << "not occupied" << endl;
	}
	buryDead();
	return !isOccupied();
}
