#pragma once
#include <iostream>
using namespace std;

class Card
{
public:
	enum class valueCard {
		ACE = 1,
		TWO = 2,
		THREE = 3,
		FOUR = 4,
		FIVE = 5,
		SIX = 6,
		SEVEN = 7,
		EIGHT = 8,
		NINE = 9,
		TEN = 10,
		JACK = 10,
		LADY = 10,
		KING = 10,
	};
	enum class cardSuit {
		SPADES,   // пики
		HEARDS,   // червы
		DIAMONDS, // бубны
		CLUBS     // трефы
	};

	Card(valueCard val, cardSuit suit, bool open);
	void flip();
	valueCard getValue() const;
	cardSuit getSuit() const;
	bool getIsOpen()const;

	friend ostream& operator<< (ostream& out, const Card& c);

protected:
	bool isOpen;
	valueCard value;
	cardSuit suit;
};



