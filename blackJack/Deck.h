#pragma once
#include "Hand.h"
#include "GenericPlayer.h"

class Deck : public Hand
{
protected:
	Hand deck;
	int curentCardCount = 0;
public:
	Deck();
	void Populate();
	void Shuffle();
	void Deal(Hand& aHand);
	void AddItionalCards(GenericPlayer& aGenerlcPlayer);
};
