#include "Character.h"

bool Character::recognize(FightingCharacter* a){ return a->decideEntry(this);}
