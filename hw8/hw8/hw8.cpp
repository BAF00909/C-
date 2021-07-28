#include <iostream>
#include <locale>
#include <stdexcept>

/*Task 3*/
#include "Robot.h"
#include "IllegalCommand.h"
#include "DivisionByZero.h"

/*Task 2*/
#include "Bar.h"

/*Task 1*/
template <typename T> T div(T a, T b) {
    if (b == 0)
        throw std::runtime_error("На ноль делить нельзя!\n");
    else
        return a / b;
}


int main()
{
    setlocale(LC_ALL, "Russian");

    /*Task 1*/
    std::cout << "Task 1" << std::endl;
    try {
        double res = div(3.0, 2.0);
        std::cout << res << std::endl;
    }catch(std::runtime_error& e) {
        std::cerr << e.what();
    }
    std::cout << "\n\nTask 2" << std::endl;

    /*Task 2*/
    Bar<int> bar;
    int n;
    do {
        try
        {
            std::cout << "\nВведите число" << std::endl;
            std::cin >> n;
            bar.set(n);
        }
        catch (Ex<int>& e) {
            std::cerr<< "Исключение: " << e.x;
        }
    } while (n != 0);

    /*Task 3*/
    std::cout << "\n\nTask 3" << std::endl;
    Robot r;
    try {
        r.move();
    }
    catch (IllegalCommand& err) {
        err.errMassage();
    }
    catch (DivisionByZero& err) {
        err.errorGetMessage();
    }

}

