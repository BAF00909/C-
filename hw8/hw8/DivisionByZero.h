#pragma once
#include <iostream>

class DivisionByZero
{
public:
	Robot error;
	DivisionByZero(Robot &r) : error(r) {};
	void errorGetMessage()
	{
		std::cout << "Текущая позиция: " << error.getStepForward() <<","<< error.getStepRight() << std::endl;
		std::cout << "Выход за пределы сетки 10 x 10 !" << std::endl;
	}
};