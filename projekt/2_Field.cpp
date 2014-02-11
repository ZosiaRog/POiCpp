#include "2_Field.h"
#include <iostream>

char Field::getSymbolToShow() {
	if(isOccupied()){
		return occupied_by->getSymbol();
	} else {
		return getSymbol();
	}
}
