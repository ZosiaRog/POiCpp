#ifndef _2_ROCKFIELD_H_
#define _2_ROCKFIELD_H_

#include "2_Field.h"
#include "1_Character.h"
#include "const.h"

class RockField : public Field {
  public:
	RockField() : Field('#', infinity){}			//sign, points_to_enter
	virtual bool tryToEnter(Character* a);		
};

#endif
