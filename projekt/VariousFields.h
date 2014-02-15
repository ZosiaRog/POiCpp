#ifndef _VARIOUSFIELD_H_
#define _VARIOUSFIELD_H_

#include "Field.h"
#include "Character.h"
#include "const.h"

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
  public:
	SwampField(pair<int, int> position) : Field('&', 2, position){}
};

class TreasureField : public Field {
  public:
	TreasureField(pair<int, int> position) : Field('$', 1, position){}
};



#endif
