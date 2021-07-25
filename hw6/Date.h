#pragma once
#include <iostream>
#include <memory>
using namespace std;

class Date {
private:
	int day;
	int month;
	int year;

public:
	Date(int d, int m, int y);
	int getDay() const;
	int getMonth() const;
	int getYear() const;

	void setDay(int d);
	void setMonth(int m);
	void setYear(int y);

	friend ostream& operator<<(ostream& const stream, const Date& date);
};