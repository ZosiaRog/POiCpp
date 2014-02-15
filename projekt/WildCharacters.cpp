#include <iomanip>
#include <cstdlib>
#include <time.h>
#include <utility>
#include <vector>

#include "WildCharacters.h"

Field* AgressiveCharacter::move(vector <Field*> neighbourhood){
	vector<Field*> possible;
	for(int i=0; i<4; i++){
		if(neighbourhood[i]->enoughActionPoints(this)) possible.push_back(neighbourhood[i]);
	}
	int direction = rand() % (possible.size()+1);
	return possible[direction];
}

Field* CowardCharacter::move(vector <Field*> neighbourhood){
	vector<Field*> possible;
	for(int i=0; i<4; i++){
		if(neighbourhood[i]->enoughActionPoints(this)) possible.push_back(neighbourhood[i]);
	}
	int direction = rand() % (possible.size()+1);
	return possible[direction];
}

Field* FussyCharacter::move(vector <Field*> neighbourhood){
	vector<Field*> possible;
	for(int i=0; i<4; i++){
		if(neighbourhood[i]->enoughActionPoints(this)) possible.push_back(neighbourhood[i]);
	}
	int direction = rand() % (possible.size()+1);
	return possible[direction];
}

Field* NeutralCharacter::move(vector <Field*> neighbourhood){
	vector<Field*> possible;
	for(int i=0; i<4; i++){
		if(neighbourhood[i]->enoughActionPoints(this)) possible.push_back(neighbourhood[i]);
	}
	int direction = rand() % (possible.size()+1);
	return possible[direction];
}

