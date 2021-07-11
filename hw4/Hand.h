#pragma once
#include <vector>
#include "Card.h"
#include <cassert>
using namespace std;

class Hand {
protected:
	vector<Card> cards;
public:
	void add(Card card) {
		cards.push_back(card);
	}
	void clear() {
		cards.clear();
	}
	int getValue()  {
		assert(cards.size() != 0);
		int valSum = 0;
		for (size_t i = 0; i < cards.size(); i++)
		{
			if (cards[i].getValue() == 1 && valSum <= 21) {
				valSum += 11;
			}
			else {
				valSum += cards[i].getValue();
			}
		}
		return valSum;
	}
};
