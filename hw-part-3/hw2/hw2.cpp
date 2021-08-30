#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include "Swap.h"
#include "SortPointers.h"
#include "FindVowels.h"

int main()
{
    std::cout << "Task 1: " << std::endl;
    /*Task 1*/
    int* ptr1 = new int(1);
    int* ptr2 = new int(2);
    Swap(ptr1, ptr2);
    delete ptr1;
    delete ptr2;

    std::cout << "\n Task 2: " << std::endl;

    /*Task2*/
    std::vector<int> numbers{ 2,5,7,1,9,2 };
    SortPointers(numbers);

    std::cout << "\n\n Task 3: " << std::endl;
    /*Task 3*/
    std::ifstream file("book.txt");

    FindVowels book(file);
    book.start("Find 1");
    book.findVowels1();
    book.print();

    book.start("Find 2");
    book.findVowels2();
    book.print();

    book.start("Find 3");
    book.findVowels3();
    book.print();

    book.start("Find 4");
    book.findVowels4();
    book.print();

    return 0;
}

