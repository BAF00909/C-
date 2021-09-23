#pragma once

std::mutex a;

void putOnShelf(std::string name, int price, std::map<std::string, int>& shelf )
{
	std::lock_guard<std::mutex> lg(a);
	shelf.insert({ name, price });
	for (auto thing : shelf)
	{
		std::cout << " Item: " << thing.first << " -- price: " << thing.second << std::endl;
	}
	std::cout << "Owner put thing" << std::endl;
}

bool compair(std::pair<std::string, int> a, std::pair<std::string, int> b)
{
	return a.second < b.second;
}

void popOnShelf(std::map<std::string, int>& shelf)
{
	std::lock_guard<std::mutex> lg(a);
	auto maxPrice = std::max_element(shelf.begin(), shelf.end(), compair);
	shelf.erase(maxPrice->first);

	for (auto thing : shelf)
	{
		std::cout << " Item: " << thing.first << " -- price: " << thing.second << std::endl;
	}
	std::cout << "Thif take thing" << std::endl;
}
