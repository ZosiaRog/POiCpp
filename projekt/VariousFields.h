#ifndef _VARIOUSFIELD_H_
#define _VARIOUSFIELD_H_

#include "Field.h"
#include "Character.h"
#include "const.h"

#include <iomanip>
#include <cstdlib>
#include <ctime>

class CaveField : public Field {
  public:
	CaveField(pair<int, int> position) : Field('*', 1, position){}
};

class GrassField : public Field {
  public:
	GrassField(pair<int, int> position) : Field('.', 1, position){}	
};

class HillField : public Field {
  public:
	HillField(pair<int, int> position) : Field('^', 2, position){}		
};

class RiverField : public Field {
  public:
	RiverField(pair<int, int> position) : Field('~', 1, position){}	
	virtual void interactWith(FightingCharacter* a);
};

class RoadField : public Field {
  public:
	RoadField(pair<int, int> position) : Field('=', 1, position){}	
};

class RockField : public Field {
  public:
	RockField(pair<int, int> position) : Field('#', infinity, position){}
};

class SwampField : public Field {
  private:
	bool safe;
  public:
	SwampField(pair<int, int> position) : Field('&', 2, position){
		srand(time(NULL));
		int l = rand();
		safe = l % 2;
	}
	virtual void interactWith(FightingCharacter* a);
};

class TreasureField : public Field {
  private:
	bool visible;
  public:
	TreasureField(pair<int, int> position) : Field('$', 1, position), visible(false) {}
	virtual void interactWith(FightingCharacter* a);
	virtual char getSymbolToShow(){ if(!visible){ return '^';} else { return symbol;}}
	void ShowTreasure(){ visible = true;}
};

#endif
