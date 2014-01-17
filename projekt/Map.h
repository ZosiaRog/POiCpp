#include<vector>
#include<string>

#include "Field.h"

using namespace std;

class Map {

  private:
	vector<vector<Field*> > fields;
	int M;
	int N;

  public:
	int getN() { return N; };
	int getM() { return M; };
	Map(vector<string>, int N, int M);
	~Map();
	Field* getField(int x, int y) { return fields[x][y]; }
};
