#include "Player.h"

Player::Player(string n) : GenericPlayer(n) {};

bool Player::isHitting() {
	string answer;
	cout << "Вам нужна еще одна карта? Y - да, N - нет";
	cin >> answer;
	if (answer == "Y") return true;
	else return false;
};
void Player::win() const {
	cout << name << " выиграл!" << endl;
};
void Player::lose() const {
	cout << name << " проиграл!" << endl;
};
void Player::push() const {
	cout << name << " сыграл вничью!" << endl;
};