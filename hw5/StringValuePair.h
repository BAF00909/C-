#pragma once
#include "Pair.h"
using namespace std;

template <class T> class Pair<string, T> {
protected:
	string p1;
	T p2;
public:
	Pair(string a, T b) : p1(a), p2(b) {};
	string first() const {
		return p1;
	}
	T second() const {
		return  p2;
	}
};

template <class S, class T> class StringValuePair : public Pair<S, T> {};

template<class T> class StringValuePair<string, T> {
private:
	string p1;
	T p2;
public:
	StringValuePair(string a, T b) : p1(a), p2(b) {};
	string first() const {
		return p1;
	}
	T second() const {
		return  p2;
	}
};

