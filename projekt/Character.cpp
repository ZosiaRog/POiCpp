#include "Character.h"
#include "FightingCharacter.h"

bool Character::recognize(FightingCharacter* a){ return a->decideEntry(this);}
