#ifndef _2_CAVEFIELD_H_
#define _2_CAVEFIELD_H_

#include "2_Field.h"
#include "1_Character.h"

class CaveField : public Field {
  public:
	CaveField() : Field('*', 1){}		//sign, point_to_enter
	virtual bool tryToEnter(Character* a);
};

#endif
