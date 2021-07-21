#pragma once
#include "Card.h"
#include <cassert>
#include <vector>
using namespace std;

class Hand
{
protected:
	vector<Card*> cards;
public:
	void add(Card * card);
	void clear();
	int getValue();
};