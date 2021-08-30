#include <iostream>
#include <list>
#include "Matrix.h"

void addElementToList(std::list<float>& l)
{
    float midleValue = 0;
    for (auto value : l)
    {
        midleValue += value;
    }
    l.push_back(midleValue / l.size());
}

int main()
{
    std::cout << "Task 1: " << std::endl;
    std::list<float> list{ 2.0, 5.0, 3.0, 7.0, 5.0, 4.0 };
    addElementToList(list);
    for (auto item : list)
    {
        std::cout << item << std::endl;
    }

    std::cout << "\n Task 2: " << std::endl;

    std::vector< std::vector<int> > v{ {5,3,2}, {1,2,3}, {4,7,9} };
    Matrix m(v);
    int d = m.calculateDeterminant();
    std::cout << "Determinant: " << d << std::endl;

    return 0;
}

