#pragma once

template <class T> class Pair1 {
private:
	T p1;
	T p2;
public:
	Pair1(T a, T b) : p1(a), p2(b) {};
	T first() const {
		return p1;
	}
	T second() const {
		return  p2;
	}
};
