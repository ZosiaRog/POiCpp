#ifndef _CHARACTER_H_
#define _CHARACTER_H_
#include <utility>

using namespace std;

class Character {

  private:
	char symbol;
	int health;
	int strength;
	double armor;
	double weapon;		//TODO zmienić na ogólne przedmioty
	bool gift;
	int action_points_per_term;
	int actual_action_points;
	pair<int, int> position;
  protected:
	Character(char symbol, int action_points_per_term, int health, int strength, double armor, double weapon, bool gift, pair<int, int> position) : symbol(symbol), action_points_per_term(action_points_per_term), actual_action_points(action_points_per_term), health(health), strength(strength), armor(armor), weapon(weapon), gift(gift), position(position){}
	Character(char symbol, int action_points_per_term, pair<int, int> position) : symbol(symbol), action_points_per_term(action_points_per_term), actual_action_points(action_points_per_term), health(health), strength(1), armor(0), weapon(0), gift(false), position(position){}
	Character(char symbol, pair<int, int> position) : symbol(symbol), action_points_per_term(0), actual_action_points(0), health(health), strength(1), armor(0), weapon(0), gift(false), position(position){}

  public:
	int getHealth(){ return health; }
	int getStrength(){ return strength; }
	double getWeapon(){ return weapon; }
	double getArmor(){ return armor; }
	bool getGift(){ return gift; }
	char getSymbol(){ return symbol; }
	int getActionPoints(){ return actual_action_points; }
	void decreaseActionPoints(int a);
	bool verifyDeath();
	pair<int, int> getPosition(){ return position; }
	virtual void move() = 0;
};

#endif
