#pragma once

template <typename T> void SortPointers(T& vec) {
	std::cout << "Before sort: " << std::endl;
	for (size_t i = 0; i < vec.size(); i++)
	{
		std::cout << vec.at(i);
	}
	std::sort(vec.begin(), vec.end());
	std::cout << "\nAfter sort: " << std::endl;
	for (size_t i = 0; i < vec.size(); i++)
	{
		std::cout << vec.at(i);
	}
}