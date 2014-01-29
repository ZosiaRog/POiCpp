#ifndef _ROCKFIELD_H_
#define _ROCKFIELD_H_

#include "Field.h"
#include "Character.h"
#include "const.h"

class RockField : public Field {
  public:
	RockField() : Field('#', infinity){}			//sign, points_to_enter
	virtual bool tryToEnter(Character* a);		
};

#endif
