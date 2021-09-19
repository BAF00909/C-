#include <iostream>
// Задание 3 из дз№3 - Реализовать собственный класс итератора
#include "Iterator.h"
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>

//Task 1
#include "Insert-Sorted.h"
//Task 2
#include "Task2.h"

int main()
{
    list_of_ints list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);

    /*for (auto it = list.begin(); it != list.end(); ++it)
    {
        std::cout << *it << std::endl;
    }*/

    //Task1
    std::vector<int> vec{ 1, 2, 3, 4, 5, 7 };
    std::vector<int> result = insert_sorted(vec, 6);
   /* for (auto it = result.begin(); it != result.end(); ++it)
    {
        std::cout << *it << std::endl;
    }*/

    //Task2 
    Task2();
    



    return 0;
}

