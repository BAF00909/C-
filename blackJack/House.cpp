#include "House.h"

House::House(string n) : GenericPlayer(n) {};

bool House::isHitting() {
	return getValue() <= 16 ? true : false;
}

void House::flipFirstCard() {
	cards[0]->flip();
}