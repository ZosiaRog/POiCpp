#include "Field.h"
#include "Character.h"

class RoadField : public Field {
  public:
	RoadField() : Field('=', 1){}
	virtual bool tryToEnter(Character* a);
};
