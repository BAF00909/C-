#pragma once
using namespace std;

enum valueCard {
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

enum cardSuit {
	SPADES,   
	HEARDS,   
	DIAMONDS, 
	CLUBS     
};

class Card {
protected:
	valueCard val;
	cardSuit suit;
	bool isOpen;
public:
	Card(valueCard v, cardSuit s, bool o) : val(v), suit(s), isOpen(o) {};
	void flip() {
		isOpen = !isOpen;
	}
	valueCard getValue() const {
		return val;
	}
};