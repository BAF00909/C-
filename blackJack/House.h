#pragma once
#include "GenericPlayer.h"

class House : public GenericPlayer
{
public:
	House(string n);
	bool isHitting();
	void flipFirstCard();
};
