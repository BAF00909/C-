#include "Card.h"

Card::Card(valueCard val, cardSuit s, bool open) : value(val), suit(s), isOpen(open) {}

void Card::flip() {
	isOpen = !isOpen;
};

Card::valueCard Card::getValue() const {
	return value;
}
Card::cardSuit Card::getSuit() const {
	return suit;
};

bool Card::getIsOpen()const {
	return isOpen;
};

ostream& operator<< (ostream& out, const Card& c) {
	if (c.isOpen) {
		switch (int(c.getSuit()))
		{
		case 0 : out << int(c.getValue()) << "-\6";
			break;
		case 1: out << int(c.getValue()) << "-\3";
			break;
		case 2: out << int(c.getValue()) << "-\4";
			break;
		case 3: out << int(c.getValue()) << "-\5";
			break;
		default:
			break;
		}
	}
	else out << "XX";
	return out;
}
