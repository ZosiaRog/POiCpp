#include <fstream>
#include <string>
#include <iostream>
#include <utility>
#include <iomanip>
#include <cstdlib>
#include <ctime>

#include "Game.h"
#include "IntelligentCharacters.h"
#include "WildCharacters.h"
#include "MiloszCharacter.h"
#include "SearcherCharacter.h"


using namespace std;

void Game::makeCharacter(char c, int x, int y){
	pair<int, int> position(x, y);
	switch(c){
		case 'B': addStaticCharacter(new BardCharacter(position, map)); break; //TODO dodać pozostałych i im zmienić konstruktory
		case 'Z': addStaticCharacter(new QuackDoctorCharacter(position)); break;
		case 'S': addStaticCharacter(new InnkeeperCharacter(position)); break;
		case 'M': milosz = new MiloszCharacter(position, &display); addFightingCharacter(milosz); break;
		case 'P': addFightingCharacter(new SearcherCharacter(position)); break;
		case 'N': addFightingCharacter(new NeutralCharacter(position)); break;
		case 'T': addFightingCharacter(new CowardCharacter(position)); break;
		case 'W': addFightingCharacter(new FussyCharacter(position)); break;
		case 'A': addFightingCharacter(new AgressiveCharacter(position)); break;
	}
}

void Game::addStaticCharacter(Character* character){
	static_characters.push_back(character);
	map->putCharacter(character, true);
}
void Game::addFightingCharacter(FightingCharacter* character){
	fighting_characters.push_back(character);
	map->putCharacter(character, false);
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

bool Game::gameOver(){
	if(milosz->isDead()) return true;
	return map->treasureFound();
}

void Game::run(){
	display.init();

	list<FightingCharacter*>::iterator current = fighting_characters.begin();	
	while(!gameOver() && !display.isEndGame()){
		if(!((*current)->isDead())){
			(*current)->resetNewTurn();
			while((*current)->getActionPoints() > 0 && !display.isEndGame()){
				display.refreshView(map, milosz);
				pair<int, int> position = (*current)->getPosition(); 
				Field* wanted_field = (*current)->move(map->getNeighbourhood(position));
				if(wanted_field == NULL){
					break;
				} else {
					if(wanted_field->tryToEnter(*current)) {
						if((*current)->isDead()) {
							map->buryDead(*current);
						} else {
							map->moveCharacter(*current, wanted_field);
						}
					}
				}
			}
		}
		current++;
		if(current == fighting_characters.end()) current = fighting_characters.begin();
	}

	if(!display.isEndGame()){
		if(milosz->getTreasureFound()){
			display.congratulations();
		} else {
			if(map->treasureFound()){
				display.treasureFound();
			} else {
				display.youDied();
			}
		}
	}
	display.stop();
}

bool Game::init(const string file){
	readMap(file);
	return true;
}


Game::~Game(){}
