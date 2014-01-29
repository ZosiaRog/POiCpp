#ifndef _CAVEFIELD_H_
#define _CAVEFIELD_H_

#include "Field.h"
#include "Character.h"

class CaveField : public Field {
  public:
	CaveField() : Field('*', 1){}		//sign, point_to_enter
	virtual bool tryToEnter(Character* a);
};

#endif
