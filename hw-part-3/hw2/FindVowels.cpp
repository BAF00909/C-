#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include "FindVowels.h"
#include "Timer.h"


FindVowels::FindVowels(std::ifstream& file)
{
	if (file.is_open())
	{
		std::getline(file, text);
	}
	else
	{
		std::cout << "File didn't open!" << std::endl;
	}
}

void FindVowels::findVowels1() {
	vowelsCount = 0;
	vowelsCount = std::count_if(text.begin(), text.end(), [this](char elem) {
		return vowels.find(elem) != std::string::npos;
		});
	std::cout<< "Count: " << vowelsCount << std::endl;
}

void FindVowels::findVowels2() {
	vowelsCount = 0;
	vowelsCount = std::count_if(text.begin(), text.end(), [this](char elem) {
		bool isFinded = false;
		for (size_t i = 0; i < vowels.size(); i++)
		{
			if (vowels[i] == elem)
			{
				isFinded = true;
				break;
			}
			else
				continue;
		}
		return isFinded;
		});
	std::cout << "Count: " << vowelsCount << std::endl;
}

void FindVowels::findVowels3() {
	vowelsCount = 0;
	for (size_t i = 0; i < text.size(); i++)
	{
		if (vowels.find(text[i]) != std::string::npos) {
			vowelsCount++;
		}
	}
	std::cout << "Count: " << vowelsCount << std::endl;
}

void FindVowels::findVowels4() {
	vowelsCount = 0;
	for (size_t i = 0; i < text.size(); i++)
	{
		for (size_t j = 0; j < vowels.size(); j++)
		{
			if (text[i] == vowels[j])
			{
				vowelsCount++;
			}
		}
	}
	std::cout << "Count: " << vowelsCount << std::endl;
}