#ifndef _2_ROADFIELD_H_
#define _2_ROADFIELD_H_

#include "2_Field.h"
#include "1_Character.h"

class RoadField : public Field {
  public:
	RoadField() : Field('=', 1){}		//sign, point_to_enter
	virtual bool tryToEnter(Character* a);
};

#endif
