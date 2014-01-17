#include<string>
#include<vector>

#include "Map.h"
#include "Character.h"


using namespace std;

class Game {
  private:
	bool readMap(const string filename);
	void initDisplay();
	void stopDisplay();
	void refreshView();

	Map* map;
	vector<Character*> characters;

  public:
	void run();
	bool init(const string file);
	~Game();
};

