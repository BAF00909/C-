#include "GenericPlayer.h"

GenericPlayer::GenericPlayer(string n) {
	name = n;
};
bool GenericPlayer::isBoosted() {
	if (getValue() > 21) return true;
	else return false;
};
void GenericPlayer::bust()const {
	cout << name << " перебор";
};