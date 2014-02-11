#ifndef _2_GRASSFIELD_H_
#define _2_GRASSFIELD_H_

#include "2_Field.h"
#include "1_Character.h"

class GrassField : public Field {
  public:
	GrassField() : Field('.', 1){}				//sign, points_to_enter
	virtual bool tryToEnter(Character* a);
};

#endif
