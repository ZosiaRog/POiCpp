#include<vector>
#include<string>
#include <utility>

#include "Field.h"
#include "Character.h"

using namespace std;

class Map {

  private:
	vector<vector<Field*> > fields;
	int M;
	int N;
	bool treasure_found;
	Field* treasure_field;

  public:
	int getN() { return N; };
	int getM() { return M; };
	Map(vector<string>, int N, int M);
	~Map();
	Field* getField(int x, int y) { return fields[x][y]; }
	void putCharacter(Character* character);
	void grabCharacter(Character* character);
	void moveCharacter(FightingCharacter* character, Field* wanted_field);
	void buryDead(Character* character);
	bool treasureFound(){ return treasure_found;}
	Field* getTreasureField(){ return treasure_field;}
	vector<Field*> getNeighbourhood(pair<int, int> place);
};
