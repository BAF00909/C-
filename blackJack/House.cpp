#include "House.h"

House::House(string n) : GenericPlayer(n) {};

bool House::isHitting() {
	if (GenericPlayer::getValue() < 16) return true;
	else false;
}

void House::flipFirstCard() {
	cards[0]->flip();
}