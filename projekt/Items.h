#ifndef _ITEMS_H_
#define _ITEMS_H_


class Item {
};

class Weapon : public Item {
	private:
		double strength;
	public:
		Weapon(double strength): strength(strength){}
		double getStrength() { return strength; }
};

class Armor : public Item {
	private:
		double strength;
	public:
		Armor(double strength): strength(strength){}
		double getStrength() { return strength; }
};

class Gift : public Item {
};
#endif

