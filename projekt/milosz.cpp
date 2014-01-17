#include <iostream>

#include "Game.h"

using namespace std;

int main(int argc, char* argv[])
{
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " map.file" << std::endl;
        return 1;
    }

	char* map_file = argv[1];

	Game game;
	if(game.init(map_file)){
		game.run();
	} else {
		std::cerr << "Blad przy uruchamianiu gry." << std::endl;
		return 2;
	}
    return 0;
}
