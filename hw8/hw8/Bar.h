#pragma once
#include "Ex.h"

template <typename T> class Bar
{
private:
	T y;
public:
	Bar() : y(0) {};
	void set(T a) {
		if (y + a > 100)
		{
			T param = a * y;
			throw Ex<T>(param);
		}
		else
		{
			y = a;
		}
	}
};