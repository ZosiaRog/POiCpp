#ifndef _TREASUREFIELD_H_
#define _TREASUREFIELD_H_

#include "Field.h"
#include "Character.h"

class TreasureField : public Field {
  public:
	TreasureField() : Field('$', 1){}		//sign, point_to_enter
	virtual bool tryToEnter(Character* a);
};

#endif
