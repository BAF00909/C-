#include <iostream>
#include <string>
#include <set>
#include <vector>

#include "Task1.h"


int main()
{
    /*Task1*/
    std::vector<std::string> input_string = { "Hello", "Hello", "World", "and", "World", "you" };
    printUniqueWords(input_string.begin(), input_string.end());
    std::vector<int> input_numbers = { 1,1,2,3,4,4,4,6 };
    printUniqueWords(input_numbers.begin(), input_numbers.end());

    /*Task2*/
    auto my_string_compare = [](const std::string& lhs, const std::string& rhs) {
        return lhs.size() < rhs.size();
    };

    std::set<std::string, decltype(my_string_compare)> sentences(my_string_compare);
    std::string sent("not empty");
    while (std::getline(std::cin, sent) && !sent.empty()) {
        std::cout << sent << std::endl;
        typename std::string::size_type pos_start{}, pos_end{};
        while (pos_start != sent.npos && pos_end != sent.npos) {
            pos_end = sent.find_first_of(".!?", pos_start);
            sentences.insert(sent.substr(pos_start, (pos_end - pos_start) + 1));
            pos_start = sent.find_first_not_of(" .!?", pos_end);
        }
    }
    sentences.erase(std::string());
    for (auto& str : sentences) {
        std::cout << str << std::endl;
    }

    return 0;
}

