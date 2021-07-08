/*
    Домашняя работа №3
    Выполнил: Бреус Александр
*/
#include <iostream>
#include <locale>
using namespace std;

/*Task 1*/
#include "Figure.h"
/*Task 2*/
#include "Car.h"
/*Task 3*/
#include "Fraction.h"
/*Task 4*/
#include "Card.h"

int main()
{
    setlocale(LC_ALL, "Russian");

    cout << "Task 1" << endl;
    Parallelogram par(5.0, 5.0);
    par.area();
    Rectangle rec(10.0, 10.0);
    rec.area();
    Circle cir(0.5);
    cir.area();
    Square sq(5.0, 5.0);
    sq.area();
    Rhombus rm(2.0, 3.0);
    rm.area();

    cout << "\nTask 2" << endl;
    Car car("Лада", "2110");
    PassengerCar pass("Chevrolet", "Cruze");
    Bus bus("MAN", "Lion's City");
    Minivan mini("Hyundai", "Staria");

    cout << "\nTask 3" << endl;
    Fraction fract1(3, 15);
    Fraction fract2(1, 3);

    Fraction fract3 = fract1 + fract2;
    cout << fract3.getX() << "/" << fract3.getY() << endl;
    Fraction fract4 = fract1 - fract2;

    cout << fract4.getX() << "/" << fract4.getY() << endl;
    Fraction fract5 = fract1 * fract2;
    cout << fract5.getX() << "/" << fract5.getY() << endl;

    Fraction fract6 = fract1 / fract2;
    cout << fract6.getX() << "/" << fract6.getY() << endl;

    cout << (fract1 > fract2) << endl;
    cout << (fract1 < fract2) << endl;
    cout << (fract1 >= fract2) << endl;
    cout << (fract1 <= fract2) << endl;
    cout << (fract1 != fract2) << endl;

    Fraction fract7 = -fract1;
    cout << fract7.getX() << "/" << fract7.getY() << endl;

    cout << "\nTask 4" << endl;
    Card aceClubs(ACE, CLUBS, false);
    cout << "Значение карты: " << aceClubs.getValue() << endl;
    aceClubs.flip();

    return 0;
}
