#pragma once

#include <vector>
#include "Card.h"
#include <cassert>
using namespace std;

class Hand {
protected:
	vector<Card*> cards;
public:
	void add(Card *card) {
		cards.push_back(card);
	}
	void clear() {
		for (auto const& card : cards) {
			delete card;
		}
		delete &cards;
	}
	int getValue()  {
		assert(cards.size() != 0);
		int valSum = 0;
		
		for (auto const& card : cards) {
			if (card->getValue() == 1 && valSum <= 21) {
				valSum += 11;
			}
			else {
				valSum += card->getValue();
			}
		}
		return valSum;
	}
};