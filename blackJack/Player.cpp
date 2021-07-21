#include "Player.h"

Player::Player(string n) : GenericPlayer(n) {};

bool Player::isHitting() {
	string answer;
	cout << "��� ����� ��� ���� �����? Y - ��, N - ���";
	cin >> answer;
	if (answer == "Y") return true;
	else return false;
};
void Player::win() const {
	cout << name << " �������!" << endl;
};
void Player::lose() const {
	cout << name << " ��������!" << endl;
};
void Player::push() const {
	cout << name << " ������ ������!" << endl;
};