#pragma once
#include <iostream>

class IllegalCommand
{
public:
	Robot errObj;
	IllegalCommand(Robot &r) : errObj(r) {};
	void errMassage() {
		std::cout<< errObj.getLastCommand() << " Не верная команда!" << std::endl;
	}
};
