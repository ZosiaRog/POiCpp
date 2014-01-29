#ifndef _GRASSFIELD_H_
#define _GRASSFIELD_H_

#include "Field.h"
#include "Character.h"

class GrassField : public Field {
  public:
	GrassField() : Field('.', 1){}				//sign, points_to_enter
	virtual bool tryToEnter(Character* a);
};

#endif
