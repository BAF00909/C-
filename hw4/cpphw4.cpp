#include <iostream>
#include <algorithm>
#include<vector>
#include <locale>
using namespace std;

/*Task 1*/
#include "ArrayInt.h"
/*Task 3*/
#include "Hand.h"


int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Задание 1: \n";

    ArrayInt arr(7);

	arr[0] = 23;
	arr[1] = 1;
	arr[2] = 7;
	arr[3] = 34;
	arr[4] = 9;
	arr[5] = 2;
	arr[6] = 44;

	arr.print();
	arr.pop_back();
	arr.print();
	arr.pop_front();
	arr.print();
	arr.sort();
	arr.print();

	cout << "\nЗадание 2: \n";
	/*task 2*/
	vector<int> numbers = { 3, 3, 6, 2, 3, 3 };
	vector<int>::iterator it;
	sort(numbers.begin(), numbers.end());
	numbers.erase(unique(numbers.begin(), numbers.end()), numbers.end());
	for (it = numbers.begin(); it != numbers.end(); it++) {
		cout << *it << endl;
	}
	cout << "Всего уникальных: " << numbers.size() << endl;

	cout << "\nЗадание 3: \n";
	/*task 3*/
	Card c1(ACE, HEARDS, 0);
	Card c2(JACK, SPADES, 0);
	Card c3(LADY, DIAMONDS, 0);
	Card c4(ACE, CLUBS, 0);

	Hand pl1;
	pl1.add(c1);
	pl1.add(c2);
	pl1.add(c3);
	pl1.add(c4);
	cout << "Игрок 1, на руках: " << pl1.getValue() << endl;

    return 0;
}

