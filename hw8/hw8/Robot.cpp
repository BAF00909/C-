#include "Robot.h"
#include "IllegalCommand.h"
#include "DivisionByZero.h"

Robot::Robot() {}

char Robot::getLastCommand()
{
	return command;
}
int Robot::getStepRight() {
	return stepRight;
}
int Robot::getStepForward() {
	return stepForward;
}
void Robot::validateStep(int step) {
	if (step >= 10 || step <= 0)
	{
		throw DivisionByZero(*this);
	}
}


void Robot::move() {
	do {
		std::cout << "Введите направление движения: (r - right,l - left,f - forward,b - back)" << std::endl;
		std::cin >> command;

		if (command != 'r' && command != 'l' && command != 'f' && command != 'b' && command != 'x') {
			throw IllegalCommand(*this);
		}

		if (command == 'r') {
			validateStep(stepRight);
			stepRight++;
		}
		if (command == 'f')
		{
			validateStep(stepForward);
			stepForward++;
		}
		if (command == 'l') {
			validateStep(stepRight);
			stepRight--;
		}
		if (command == 'b')
		{
			validateStep(stepForward);
			stepForward--;
		}
		if (command == 'x')
		{
			isFinish = true;
		}

	} while (!isFinish);
}


