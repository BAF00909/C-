#pragma once
using namespace std;


class Fraction {
private:
	int x = 1;
	int y = 1;
public:
	Fraction(int a, int b) : x(a), y(b){}
	int getX() const {
		return x;
	}
	int getY() const {
		return y;
	}
	friend Fraction operator+(const Fraction& fract1, const Fraction& fract2);
	friend Fraction operator-(const Fraction& fract1, const Fraction& fract2);
	friend Fraction operator*(const Fraction& fract1, const Fraction& fract2);
	friend Fraction operator/(const Fraction& fract1, const Fraction& fract2);
	friend bool operator>(const Fraction& fract1, const Fraction& fract2);
	friend bool operator<(const Fraction& fract1, const Fraction& fract2);
	friend bool operator==(const Fraction& fract1, const Fraction& fract2);
	friend bool operator>=(const Fraction& fract1, const Fraction& fract2);
	friend bool operator<=(const Fraction& fract1, const Fraction& fract2);
	friend bool operator!=(const Fraction& fract1, const Fraction& fract2);
	friend Fraction operator-(const Fraction& fract1);
	// todo дописать метод сокращени€ дробей
};



Fraction operator+(const Fraction& fract1, const Fraction& fract2) {
	if (fract1.y == 0 || fract2.y == 0) {
		cout << "¬ знаменателе не должно быть чисел равных 0 !" << endl;
		return Fraction(0, 0);
	}
	if(fract1.y == fract2.y)
		return Fraction(fract1.x + fract2.x, fract1.y);
	else {
		int numerator = (fract1.x * fract2.y) + (fract1.y * fract2.x);
		int denomenator = (fract1.y * fract2.y);
		return Fraction(numerator, denomenator);
	}
};

Fraction operator-(const Fraction& fract1, const Fraction& fract2) {
	if (fract1.y == 0 || fract2.y == 0) {
		cout << "¬ знаменателе не должно быть чисел равных 0 !" << endl;
		return Fraction(0, 0);
	}
	if (fract1.y == fract2.y)
		return Fraction(fract1.x - fract2.x, fract1.y);
	else {
		int numerator = (fract1.x * fract2.y) - (fract1.y * fract2.x);
		int denomenator = (fract1.y * fract2.y);
		return Fraction(numerator, denomenator);
	}
};

Fraction operator*(const Fraction& fract1, const Fraction& fract2) {
	if (fract1.y == 0 || fract2.y == 0) {
		cout << "¬ знаменателе не должно быть чисел равных 0 !" << endl;
		return Fraction(0, 0);
	}
	int numerator = (fract1.x * fract2.x);
	int denomenator = (fract1.y * fract2.y);
	return Fraction(numerator, denomenator);
};

Fraction operator/(const Fraction& fract1, const Fraction& fract2) {
	if (fract1.y == 0 || fract2.y == 0) {
		cout << "¬ знаменателе не должно быть чисел равных 0 !" << endl;
		return Fraction(0, 0);
	}
	int numerator = (fract1.x * fract2.y);
	int denomenator = (fract1.y * fract2.x);
	return Fraction(numerator, denomenator);
};

bool operator>(const Fraction& fract1, const Fraction& fract2) {
	return fract1.x * fract2.y > fract2.x * fract1.y ? true : false;
};

bool operator<(const Fraction& fract1, const Fraction& fract2) {
	return fract1.x * fract2.y < fract2.x * fract1.y ? true : false;
};

bool operator==(const Fraction& fract1, const Fraction& fract2) {
	return fract1.x * fract2.y == fract2.x* fract1.y ? true : false;
};

bool operator>=(const Fraction& fract1, const Fraction& fract2) {
	if (fract1 > fract2 || fract1 == fract2)
		return  true;
	else
		return false;
};

bool operator<=(const Fraction& fract1, const Fraction& fract2) {
	if (fract1 < fract2 || fract1 == fract2)
		return  true;
	else
		return false;
};

bool operator!=(const Fraction& fract1, const Fraction& fract2) {
	if ( !(fract1 == fract2) )
		return  true;
	else
		return false;
};

Fraction operator-(const Fraction& fract1) {
	if (fract1.y == 0) {
		cout << "¬ знаменателе не должно быть чисел равных 0 !" << endl;
		return Fraction(0, 0);
	}
	return Fraction(-fract1.x, -fract1.y);
};

