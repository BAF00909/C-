#include <iostream>
#include <string>
using namespace std;

bool isNumber(string str) {
	for (size_t i = 0; i < str.size(); i++)
	{
		if (!isdigit(str[i]))
		{
			cout << "¬водить можно только цыфры!" << endl;
			return false;
		}
	}
	return true;
}

void readInt() {
	string num;
	while (true) {
		cout << "¬ведите число: ";
		getline(cin, num);
		if (isNumber(num))
			break;
	}
}