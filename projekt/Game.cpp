#include <fstream>
#include <string>
#include <iostream>
#include <utility>

#include "Game.h"

#include "1_BardCharacter.h"
#include "1_QuackDoctorCharacter.h"
#include "1_InnkeeperCharacter.h"
#include "1_NeutralCharacter.h"
#include "1_CowardCharacter.h"
#include "1_FussyCharacter.h"
#include "1_AgressiveCharacter.h"
#include "1_MiloszCharacter.h"
#include "1_SearcherCharacter.h"


using namespace std;

void Game::makeCharacter(char c, int x, int y){
	pair<int, int> position(x, y);
	switch(c){
		case 'B': addCharacter(new BardCharacter(position)); break; //TODO dodać pozostałych i im zmienić konstruktory
		case 'Z': addCharacter(new QuackDoctorCharacter(position)); break;
		case 'S': addCharacter(new InnkeeperCharacter(position)); break;
		case 'M': addCharacter(new MiloszCharacter(position)); break;
		case 'P': addCharacter(new SearcherCharacter(position)); break;
		case 'N': addCharacter(new NeutralCharacter(position)); break;
		case 'T': addCharacter(new CowardCharacter(position)); break;
		case 'W': addCharacter(new FussyCharacter(position)); break;
		case 'A': addCharacter(new AgressiveCharacter(position)); break;
	}
}

void Game::addCharacter(Character* character){
	characters.push_back(character);
	map->putCharacter(character);
}

bool Game::readMap(const string filename){
	ifstream file(filename.c_str());

	if (file.is_open())
    {
		int N, M;
		file >> N >> M;

		string line;
		vector<string> map_lines;
		for(int i = 0; i < N; i++){
			file >> line;
			map_lines.push_back(line);
		}

		map = new Map(map_lines, N, M);

		string c;
		int x, y;
		while(file >> c)
		{
			file >> x >> y;
			makeCharacter(c[0], x, y);
		}

		return true;
	}
	return false;
}

void Game::run(){
	initDisplay();

	/*while(gramy )*/
		refreshView();
	stopDisplay();
}

bool Game::init(const string file){
	readMap(file);
}

void Game::initDisplay(){}
void Game::stopDisplay(){}
void Game::refreshView(){
	int N = map->getN();
	int M = map->getM();
	for (int i = 0; i < N+2; i++){
		for (int j = 0; j < M+2; j++){
			cout << map->getField(i, j)->getSymbolToShow();
		}
		cout << endl;
	}
}

Game::~Game(){
	// TODO: usuń mapę i charactersy
}
