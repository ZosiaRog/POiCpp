#include "FightingCharacter.h"

int FightingCharacter::calculateHitPoints(){ return double(strength*health)/100; }

void FightingCharacter::receiveHitPoints(int hit_points){
	cout << "receiving " << hit_points << " hit points " << endl;
	health -= hit_points;
}

bool FightingCharacter::meet(FightingCharacter* a){
	cout << a->getSymbol() << "[h=" << a->health << " s=" << a->strength << "]" << " meets " << getSymbol() << "[h="<<health << " s=" << strength << "]"  << endl;
	int aHitsThisBy = a->calculateHitPoints();
	int thisHitsABy = calculateHitPoints();
	a->receiveHitPoints(thisHitsABy);
	receiveHitPoints(aHitsThisBy);
	return false;
}

bool FightingCharacter::isDead(){ return (health <= 0); }

//virtual bool FightingCharacter::decideEntry(FightingCharacter* native) : decideEntry(native) {return true;}
//virtual bool FightingCharacter::decideEntry(IntelligentCharacter* native) : decideEntry(native) {return false;}

