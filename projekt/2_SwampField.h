#ifndef _2_SWAMPFIELD_H_
#define _2_SWAMPFIELD_H_

#include "2_Field.h"
#include "1_Character.h"

class SwampField : public Field {
  public:
	SwampField() : Field('&', 2){}		//sign, point_to_enter
	virtual bool tryToEnter(Character* a);
};

#endif
