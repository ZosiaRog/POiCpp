#ifndef _SWAMPFIELD_H_
#define _SWAMPFIELD_H_

#include "Field.h"
#include "Character.h"

class SwampField : public Field {
  public:
	SwampField() : Field('&', 2){}		//sign, point_to_enter
	virtual bool tryToEnter(Character* a);
};

#endif
