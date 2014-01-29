#ifndef _HILLFIELD_H_
#define _HILLFIELD_H_

#include "Field.h"
#include "Character.h"

class HillField : public Field {
  public:
	HillField() : Field('^', 2){}				//sign, points_to_enter
	virtual bool tryToEnter(Character* a);
};

#endif
