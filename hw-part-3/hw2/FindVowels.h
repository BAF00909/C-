#pragma once
#include <iostream>
#include <fstream>
#include "Timer.h"

class FindVowels : public Timer
{
private:
	std::string vowels = "AEIOUaeiou";
	std::string text;
	size_t vowelsCount = 0;

public:
	FindVowels(std::ifstream& file);
	void findVowels1();
	void findVowels2();
	void findVowels3();
	void findVowels4();

};
