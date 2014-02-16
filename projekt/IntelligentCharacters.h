#ifndef _INTELLIGENTCHARACTERS_H_
#define _INTELLIGENTCHARACTERS_H_

#include "Character.h"
#include "FightingCharacter.h"
#include "MiloszCharacter.h"
#include "Map.h"
#include <cstdlib>
#include <ctime>

class IntelligentCharacter : public Character{
  public:
	IntelligentCharacter(char symbol, pair<int, int> position) : Character(symbol, position) {}
	virtual bool meet(FightingCharacter* a) {return false;}
	virtual bool recognize(FightingCharacter* a) { a->decideEntry(this); }
};


class BardCharacter : public IntelligentCharacter {
	Map* map;
  public:
	BardCharacter(pair<int, int> position, Map* map) : IntelligentCharacter('B', position), map(map) {}
	virtual bool meet(FightingCharacter* a) { 
		if(a->takeGift()){
			map->setTreasuresVisible(true);
		}
	}
};

class InnkeeperCharacter : public IntelligentCharacter {
  public:
	InnkeeperCharacter(pair<int, int> position) : IntelligentCharacter('S', position) {}
	virtual bool meet(FightingCharacter* a){
		srand(time(NULL));
		a->receiveItem(new Armor(double(rand()%100)/100));
		a->receiveItem(new Weapon(double(rand()%100)/100));
		a->receiveItem(new Gift());
	}
};

class QuackDoctorCharacter : public IntelligentCharacter {
  public:
	QuackDoctorCharacter(pair<int, int> position) : IntelligentCharacter('Z', position) {}
	virtual bool meet(FightingCharacter* a) { 
		if(a->takeGift()){
			a->setHealth(100); 
		}
	}
};

#endif
