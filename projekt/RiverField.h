#ifndef _RIVERFIELD_H_
#define _RIVERFIELD_H_

#include "Field.h"
#include "Character.h"

class RiverField : public Field {
  public:
	RiverField() : Field('~', 1){}		//sign, point_to_enter
	virtual bool tryToEnter(Character* a);
};

#endif
