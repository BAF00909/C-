#include <iostream>
#include <string>
using namespace std;

bool isNumber(string str) {
	for (size_t i = 0; i < str.size(); i++)
	{
		if (!isdigit(str[i]))
		{
			cout << "������� ����� ������ �����!" << endl;
			return false;
		}
	}
	return true;
}

void readInt() {
	string num;
	while (true) {
		cout << "������� �����: ";
		getline(cin, num);
		if (isNumber(num))
			break;
	}
}