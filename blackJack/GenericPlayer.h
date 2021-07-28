#pragma once
#include "Hand.h"

class GenericPlayer : public Hand
{
protected:
	string name;
public:
	GenericPlayer(string n);
	virtual bool isHitting() = 0;
	bool isBoosted();
	void bust()const;
	string getName();
};
