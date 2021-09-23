#include <iostream>
#include <algorithm>
#include <chrono>
#include <thread>
#include <vector>
#include <mutex>
#include <math.h>
#include <map>

//Task1
#include "Pcout.h"
//Task2
#include "Primes.h"
//Task3
#include "Task3.h"


int main()
{
    //Task 1
    /*std::vector<std::thread> workers_pcout;
    size_t worker(0);
    size_t threads(5);

    for (size_t i = 0; i < threads; ++i)
    {
        workers_pcout.emplace_back([&]
            {
                pcout() << "This is worker " << ++worker << " in thread "
                    << std::this_thread::get_id() << std::endl;
            });
    }
    for (auto& w : workers_pcout)
    {
        w.join();
    }*/

    //Task 2
    //getPrime(10);
   /* int result;
    std::thread task2([&result]() {getPrime(10, result); });
    task2.join();
    std::cout << "Result = " << result << std::endl;*/

    //Task 3
    std::map<std::string, int> shelf;
    shelf.insert({ "gold ring", 1000 });
    shelf.insert({ "silver ring", 50 });


    std::thread owner{ [&shelf]() {putOnShelf("diamond", 500, shelf); } };
    std::thread thif{ [&shelf]() {popOnShelf(shelf); } };
    owner.join();
    thif.join();

    return 0;
}

