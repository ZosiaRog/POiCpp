#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include <iostream>
#include <utility>

using namespace std;

class FightingCharacter;
class MiloszCharacter;

class Character {

  protected:
	char symbol;
	pair<int, int> position;
	int action_points_per_turn;
	int actual_action_points;
	Character(char symbol, pair<int, int> position) : symbol(symbol), position(position), action_points_per_turn(0), actual_action_points(0) {}

  public:
	pair<int, int> getPosition(){ return position; }
	char getSymbol(){ return symbol; }
	int getActionPoints(){ return actual_action_points; }
	void setPosition(pair<int, int> new_position){ position = new_position;}
	virtual bool meet(FightingCharacter* a){ return false; }
	virtual bool isDead(){ return false; }
	virtual bool recognize(FightingCharacter* a) = 0;
};

#endif
