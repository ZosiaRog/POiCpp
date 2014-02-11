#ifndef _2_RIVERFIELD_H_
#define _2_RIVERFIELD_H_

#include "2_Field.h"
#include "1_Character.h"

class RiverField : public Field {
  public:
	RiverField() : Field('~', 1){}		//sign, point_to_enter
	virtual bool tryToEnter(Character* a);
};

#endif
