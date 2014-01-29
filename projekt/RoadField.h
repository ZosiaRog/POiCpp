#ifndef _ROADFIELD_H_
#define _ROADFIELD_H_

#include "Field.h"
#include "Character.h"

class RoadField : public Field {
  public:
	RoadField() : Field('=', 1){}		//sign, point_to_enter
	virtual bool tryToEnter(Character* a);
};

#endif
