#pragma once
#include "Card.h"
#include <cassert>
#include <vector>
using namespace std;

class Hand
{
protected:

public:
	vector<Card*> cards;
	void add(Card * card);
	void clear();
	int getValue();
};