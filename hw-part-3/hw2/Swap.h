#pragma once

template <typename T> void Swap(T& ptr1, T& ptr2) {
	std::cout << "Before swap: \nPTR1: " << ptr1 << " ,PTR2: " << ptr2 << std::endl;
	T temp(ptr1);
	ptr1 = ptr2;
	ptr2 = temp;
	std::cout << "After swap: \nPTR1: " << ptr1 << " ,PTR2: " << ptr2 << std::endl;

};