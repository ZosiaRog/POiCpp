#include <iomanip>
#include <cstdlib>
#include <time.h>
#include <utility>
#include <vector>

#include "WildCharacters.h"

Field* WildCharacter::move(vector <Field*> neighbourhood){
	vector<Field*> possible;
	for(int i = 0; i < neighbourhood.size(); i++){
		if(neighbourhood[i]->enoughActionPoints(this)){
			if(!neighbourhood[i]->isOccupied() || neighbourhood[i]->getOccupiedBy()->recognize(this)){
				possible.push_back(neighbourhood[i]);
			}
		}
	}
	if(possible.size() == 0) return NULL;
	int direction = rand() % possible.size();
	return possible[direction];
}

bool WildCharacter::decideEntry(HumanCharacter* native){ return true; }
bool WildCharacter::decideEntry(IntelligentCharacter* native){ return false; }

bool AgressiveCharacter::decideEntry(FightingCharacter* native){ return true; }

bool CowardCharacter::decideEntry(FightingCharacter* native){ return (native->getHealth() < 50); }

bool FussyCharacter::decideEntry(FightingCharacter* native){ return false; }
bool FussyCharacter::decideEntry(HumanCharacter* native) { return true; }

bool NeutralCharacter::decideEntry(FightingCharacter* native){ return false; }
