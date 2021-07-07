#pragma once
using namespace std;

class Car {
protected:
	string company;
	string model;
public:
	Car(string c, string m) : company(c), model(m) {
		cout << "Базовый класс: " << company << ", " << model << endl;
	};
};

class PassengerCar : virtual public Car {
public:
	PassengerCar(string c, string m) : Car(c, m) {
		cout << "Легковой авто: " << company << ", " << model << endl;
	};
};

class Bus : virtual public Car {
public:
	Bus(string c, string m) : Car(c, m) {
		cout << "Автобус: " << company << ", " << model << endl;
	};
};

class Minivan : public PassengerCar, public Bus {
public:
	Minivan(string c, string m) : PassengerCar(c, m), Bus(c, m), Car(c,m) {
		cout << "Минивен: " << company << ", " << model << endl;
	};
};
