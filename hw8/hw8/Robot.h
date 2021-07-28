#pragma once
#include <iostream>
#include <vector>

class Robot
{
private:
	bool isFinish = false;
	int stepRight = 1;
	int stepForward = 1;
	char command;
public:
	Robot();
	void move();
	char getLastCommand();
	int getStepRight();
	int getStepForward();
	void validateStep(int step);
};
