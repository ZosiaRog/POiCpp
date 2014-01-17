//TODO dodaj w każdym pliku headera ifn takie jak w field.h
#include <fstream>
#include <string>
#include <iostream>

#include "Game.h"

using namespace std;

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
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			cout << map->getField(i, j)->getSymbol();
		}
		cout << endl;
	}
}

Game::~Game(){
	// TODO: usuń mapę i charactersy
}
