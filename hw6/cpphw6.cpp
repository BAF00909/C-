/*
	Вынес задания связанные с игрой blackJack в одтельный проект
*/
#include <iostream>
#include <locale>
using namespace std;
/*Yandex parse*/
#include "YandexParse.h"
/*Task 1*/
#include "Task1.h"

/*Task 2*/
ostream& endll(ostream& stream)
{
	stream << "\n" << endl;
	return stream;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	/*Task 1*/
	readInt();

	/*Task 2*/
	cout << 123 << endll;

	/*Yandex parse*/
	YandexParse parser("yandex.html");


	return 0;
}

