#pragma once
#include "GenericPlayer.h"

class Player : public GenericPlayer
{
public:
	Player(string n);
	bool isHitting();
	void win() const;
	void lose() const;
	void push() const;
};