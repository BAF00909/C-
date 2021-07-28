#include <iostream>
#include <locale>
#include "Date.h"
using namespace std;

template<typename T> void isEmpty(unique_ptr<T>& ptr, string name_ptr) {
	if (ptr)
		cout << "Указатель " << name_ptr << " не пустой" << endl;
	else
		cout << "Указатель " << name_ptr << " пуст" << endl;
}

/*task 2*/
unique_ptr<Date>& compareDate(unique_ptr<Date> &d1, unique_ptr<Date> &d2)
{

	if (
		(d1->getDay() > d2->getDay()) && (d1->getMonth() >= d2->getMonth()) && (d1->getYear() >= d2->getYear()) ||
		(d1->getDay() <= d2->getDay()) && (d1->getMonth() > d2->getMonth()) && (d1->getYear() >= d2->getYear()) ||
		(d1->getDay() <= d2->getDay()) && (d1->getMonth() <= d2->getMonth()) && (d1->getYear() > d2->getYear())
		)
	{
		return d1;
	}
	else
	{
		return d2;
	}
}

void exchangePtr(unique_ptr<Date>& d1, unique_ptr<Date>& d2)
{
	unique_ptr<Date> tmp;
	tmp = move(d1);
	d1 = move(d2);
	d2 = move(tmp);
}

int main()
{
	setlocale(LC_ALL, "Russian");

	unique_ptr<Date> today = make_unique<Date>(20, 07, 2021);
	unique_ptr<Date> date;
	
	today->setDay(24);
	today->setMonth(7);
	today->setYear(2021);

	/*cout << today->getDay() << endl;
	cout << today->getMonth() << endl;
	cout << today->getYear() << endl;
	cout << *today;
	isEmpty(today, "today");
	isEmpty(date, "date");
	date = move(today);
	cout << date->getDay() << endl;
	cout << date->getMonth() << endl;
	cout << date->getYear() << endl;
	cout << *date;
	isEmpty(today, "today");
	isEmpty(date, "date");*/

	/*Task 2*/
	unique_ptr<Date> date1 = make_unique<Date>(23, 7, 2021);
	unique_ptr<Date> date2 = make_unique<Date>(24, 7, 2021);

	cout << *compareDate(date1, date2) << endl;

	exchangePtr(date1, date2);
	cout << *date1 << endl;
	cout << *date2 << endl;

	return 0;
}

