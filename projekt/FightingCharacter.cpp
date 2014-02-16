#include "FightingCharacter.h"

int FightingCharacter::calculateHitPoints(){
	double modifier = 1 + ((weapon != NULL) ? weapon->getStrength() : 0);
	return (double(strength*health)*modifier)/100;
}

void FightingCharacter::receiveHitPoints(int hit_points){
//	cout << "receiving " << hit_points << " hit points " << endl;
	double modifier = 1 + ((armor != NULL) ? armor->getStrength() : 0);
	health -= double(hit_points)/modifier;
}

bool FightingCharacter::meet(FightingCharacter* a){
//	cout << a->getSymbol() << "[h=" << a->health << " s=" << a->strength << "]" << " meets " << getSymbol() << "[h="<<health << " s=" << strength << "]"  << endl;
	int aHitsThisBy = a->calculateHitPoints();
	int thisHitsABy = calculateHitPoints();
	a->receiveHitPoints(thisHitsABy);
	receiveHitPoints(aHitsThisBy);
	return false;
}


bool FightingCharacter::isDead(){ return (health <= 0); }
