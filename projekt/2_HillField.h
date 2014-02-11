#ifndef _2_HILLFIELD_H_
#define _2_HILLFIELD_H_

#include "2_Field.h"
#include "1_Character.h"

class HillField : public Field {
  public:
	HillField() : Field('^', 2){}				//sign, points_to_enter
	virtual bool tryToEnter(Character* a);
};

#endif
