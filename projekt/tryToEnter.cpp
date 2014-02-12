TRY TO ENTER:

if(!isOccupied()) return true;

if(occupied_by->getSymbol() == 'P'){
	return false;
}

if(((occupied_by->getSymbol() == 'Z')||(occupied_by->getSymbol() == 'B')||(occupied_by->getSymbol() == 'S'))&&(occupied_by->getSymbol() == 'M'))) return false;

if(a->getSymbol() == 'M'){
	if((occupied_by->getSymbol() == 'Z'){
		if(a->getGift() ){
			a->changeHealth(100);
		}
		return false;
	}

	if((occupied_by->getSymbol() == 'B'){
		if((a->getGift() ){
				SHOW TREASURE();
		}
		return false;
	}

	if((occupied_by->getSymbol() == 'S'){
			a->weapon = occupied_by->getWeapon();
			a->armor = occupied_by->getArmor();
			a->gift = true;
		return false;
	}

	return(battleResult());
}

//pole jest zajęte:

if(a->getSymbol() == 'P') return false;

if(a->getSymbol() == 'N') return false;

if(a->getSymbol() == 'A'){
	return(battleResult());
}

if(a->getSymbol() == 'T'){
	if(occupied_by->getHealth() > 50) return false;
	return(battleResult());
}

if(a->getSymbol() == 'W'){
	if((occupied_by->getSymbol() == 'P')||(occupied_by->getSymbol() == 'M')) return (battleResult());
	return false;
}


