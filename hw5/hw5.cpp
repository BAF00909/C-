#include <iostream>
#include <locale>
using namespace std;

/*task 1*/
#include "Pair1.h"

/*task 2*/
/*task3*/
#include "StringValuePair.h"
/*task 4*/
#include "GenericPlayer.h"



int main()
{
    setlocale(LC_ALL, "Russian");

    Pair1<int> p1(2,5);
    cout << p1.first() << " " << p1.second() << endl;

    Pair<int, double> p(3, 6.9);
    cout << p.first() << " " << p.second() << endl;

    Pair<string, int> svp("Amazing", 7);
    cout << "Pair: " << svp.first() << ' ' << svp.second() << endl;

    StringValuePair<string, int> svp1("Amazing", 7);
    std::cout << "Pair: " << svp1.first() << ' ' << svp1.second() << '\n';

    
    return 0;
}


