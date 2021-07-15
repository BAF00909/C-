#pragma once
#include "Hand.h"

class GenericPlayer : public Hand {
private:
	string name;
public:
	GenericPlayer(string n){
		name = n;
	}
	virtual void isHitting() = 0;
	bool isBoosted() {
		if (getValue() > 21) return true;
		else return false;
	}
	void bust () const {
		cout << name << "перебор";
	}
};

