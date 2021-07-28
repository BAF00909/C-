#include "Hand.h"

void Hand::add(Card* card)
{
	cards.push_back(card);
}

void Hand::clear()
{
	vector<Card*>::iterator iter = cards.begin();
	for (iter = cards.begin(); iter != cards.end(); ++iter)
	{
		delete* iter;
		*iter = 0;
	}

	cards.clear();
}

int Hand::getValue()
{
	assert(cards.size() != 0);
	int valSum = 0;
	for (auto const* card : cards) {
		if (int(card->getValue()) == 1 && valSum <= 21) {
			valSum += 11;
		} 
		else 
		{
			valSum += int(card->getValue());
		}
	}
	return valSum;
}