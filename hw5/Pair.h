#pragma once

template <class T, class L> class Pair {
protected:
	T p1;
	L p2;
public:
	Pair(T a, L b) : p1(a), p2(b) {};
	T first() const {
		return p1;
	}
	L second() const {
		return  p2;
	}
};