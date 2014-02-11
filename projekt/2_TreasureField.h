#ifndef _2_TREASUREFIELD_H_
#define _2_TREASUREFIELD_H_

#include "2_Field.h"
#include "1_Character.h"

class TreasureField : public Field {
  public:
	TreasureField() : Field('$', 1){}		//sign, point_to_enter
	virtual bool tryToEnter(Character* a);
};

#endif
