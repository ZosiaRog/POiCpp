#ifndef _MAP_H_
#define _MAP_H_

#include<vector>
#include<string>
#include <utility>

#include "Field.h"
#include "Character.h"

using namespace std;

class TreasureField;

class Map {

  private:
	vector<vector<Field*> > fields;
	int M;
	int N;
	vector<TreasureField*> treasures;

  public:
	int getN() { return N; };
	int getM() { return M; };
	Map(vector<string>, int N, int M);
	~Map();
	Field* getField(int x, int y) { return fields[x][y]; }
	void putCharacter(Character* character, bool flattenField);
	void grabCharacter(Character* character);
	void moveCharacter(FightingCharacter* character, Field* wanted_field);
	void buryDead(Character* character);
	vector<Field*> getNeighbourhood(pair<int, int> place);
	void setTreasuresVisible(bool visible);
	bool treasureFound();
};

#endif
