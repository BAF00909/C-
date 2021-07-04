/*
* Домашняя работа 2
* Выполнил: Бреус Александр
*/
#include <iostream>
#include <locale>
using namespace std;

/*Task 1*/
class Person
{
public:
	Person(string n, int a, string s, float w): name(n), age(a), sex(s), weight(w){};
	~Person() {};
	void setName(string newName) {
		name = newName;
	}
	void setAge(int newAge) {
		age = newAge;
	}
	void setWeight(float newWeight) {
		weight = newWeight;
	}
	string getName() const {
		return name;
	}
	int getAge() const {
		return age;
	}
	string getSex() const {
		return sex;
	}
	float getWeight() const {
		return weight;
	}
protected:
	string name;
	int age;
	string sex;
	float weight;
};

class Student : public Person {
public:
	Student(string dl, string n, int a, string s, float w): dateLearning(dl), Person(n, a, s, w) {
		countStudents++;
	}
	~Student() {
		countStudents--;
	}
	void setDateLearning(string newDateLearning) {
		dateLearning = newDateLearning;
	};
	void getStudentInfo() const {
		cout << "Имя: " << name << "\n" << "Возраст: " << age << "\n" << "Пол: " << sex << "\n" << "Вес: " << weight << endl;
	}
	static int getCountStudents() {
		return countStudents;
	}
private:
	string dateLearning;
	static int countStudents;
};

int Student::countStudents = 0;

/*Task 2*/
class Fruit {
protected:
	string name;
	string color;
public:
	Fruit(string n, string c) : name(n), color(c) {};
	string getName() const {
		return name;
	}
	string getColor() const {
		return color;
	}
};

class Apple: public Fruit {
public:
	Apple(string c = "зеленое") : Fruit("Яблоко", c) {};
};

class Bananna : public Fruit {
public:
	Bananna( string c = "желтый" ) : Fruit("Банан", c) {};
};

class GrannySmith : public Apple {
public:
	GrannySmith() : Apple() {};
};

/*Task3*/
/*
* Описание классов игры Блэк-Джек:
* 
* Player - класс содержит описание игрока:
* Свойства:
* name - Имя
* chips - Фишки(эквивалент денег для осуществления ставок)
* hand - "Рука"(набор карт полученных игроком при сдаче и после добора)
* score - сумма очков которые дают карты
* Методы:
* setRate - сделать ставку
* getCard - взять еще карту
* hold - отказ от добора карт
* 
* Dealer - класс описывает крупье(диллера) наследуется от класса Player:
* методы:
* checkScore - проверка на минимальное число очков
* 
* Card - класс описывает игральные карты
* Свойства:
* name - символ карты
* score - номинал карты в очках
* 
* Game - класс описывает общие правила игры(игральный стол):
* Свойства:
* process - свойство содержит состояние игры(в игре, игра окончена)
* won - победитель
* totalChip - общее кол-во фишек поставленных на кон
* turn - ход игры(чей сейчас ход)
* decksOfCards - кол-во колод карт
* cardsInDesk - кол-во карт в одной колоде
* Методы:
* cardsGenerate - генерирует карты согласно заданному кол-ву
* desksGenerate - генерирует установленное кол-во колод
* giveCards - раздача карт
* mixCards - перетасовка карт
* checkWiner - определение победителя
* 
*/


int main()
{
	setlocale(LC_ALL, "Russian");
	Student s1 = Student("01.06.2021", "Бреус Александр", 33, "мужской", 72.5);
	Student s2 = Student("05.03.2020", "Иванов Иван", 22, "мужской", 80.0);
	s1.getStudentInfo();
	cout << "Всего студентов: " << Student::getCountStudents() << endl;

	Apple a("красное");
	Bananna b;
	GrannySmith c;

	cout << "Мое " << a.getName()<< " " << a.getColor() << endl;
	cout << "Мой " << b.getName()<< " " << b.getColor() << endl;
	cout << "Мое " << c.getName()<< " "  << c.getColor() << endl;
}

