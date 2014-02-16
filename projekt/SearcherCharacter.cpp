#include "SearcherCharacter.h"

Field* SearcherCharacter::move(vector <Field*> neighbourhood){
	vector<Field*> possible;
	for(int i=0; i<4; i++){
		if((neighbourhood[i]->enoughActionPoints(this))&&(neighbourhood[i]->getOccupiedBy()==NULL)) possible.push_back(neighbourhood[i]);
	}
	if(possible.size()==0) return NULL;
	int direction = rand() % (possible.size());
	return possible[direction];
}
