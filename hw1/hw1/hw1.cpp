/*
Домашняя работа №1
Выполнил: Бреус Александр
*/
#include <iostream>
#include <cstdint>

#define ARR_LENGTH 10

/*Task 1*/
class Power {

public:
	Power(float n1, float n2) : num1(n1), num2(n2) {};
	Power() : num1(2.0), num2(2.0) {};

	void setNumbers(float n1, float n2) {
		num1 = n1;
		num2 = n2;
	}
	void calculate() {
		float result = 1;
		for (size_t i = 0; i < num2; i++)
		{
			result = result * num1;
		}

		std::cout << "Result: " << result << std::endl;
	}
private:
	float num1;
	float num2;
};
/*Task 2*/
class RGBA {
private:
	std::uint8_t m_red;
	std::uint8_t m_green;
	std::uint8_t m_blue;
	std::uint8_t m_alpha;

public:
	RGBA(std::uint8_t red, std::uint8_t green, std::uint8_t blue, std::uint8_t alpha) : m_red(red), m_green(green), m_blue(blue), m_alpha(alpha) {};
	
	RGBA() : m_red(0), m_green(0), m_blue(0), m_alpha(255) {};

	void print() {
		std::cout << "\nR: " << unsigned(m_red) << " G: " << unsigned(m_green) << " B: " << unsigned(m_blue) << " A: " << unsigned(m_alpha) <<std::endl;
	}
};

/*Task 3*/
class Stack {
private: 
	int arr[ARR_LENGTH];
	int stackCount = 0;

public:
	void reset()
	{
		for (size_t i = 0; i < ARR_LENGTH; i++)
		{
			arr[i] = 0;
		}
		stackCount = 0;
	}
	bool push(int newValue)
	{
		if (stackCount == ARR_LENGTH) return false;
		arr[stackCount] = newValue;
		stackCount++;
		return true;
	}
	int pop()
	{
		if (stackCount == 0) {
			std::cout << "Stack is empty" << std::endl;
			return -1;
		}
		int elem = arr[stackCount];
		arr[stackCount-1] = 0;
		stackCount--;
		return elem;
	}
	void print()
	{
		std::cout << "( ";
		for (size_t i = 0; i < stackCount; i++)
		{
			std::cout << arr[i] << " ";
		}
		std::cout << ")";
		std::cout << std::endl;
	}
};

int main()
{
	Power pow;
	pow.setNumbers(4.0,2.0);
	pow.calculate();

	RGBA paint(154, 200, 230, 254);
	paint.print();

	Stack stack;
	stack.reset();
	stack.push(0);
	stack.push(1);
	stack.push(2);
	stack.push(3);
	stack.push(4);
	stack.push(5);
	stack.push(6);
	stack.push(7);
	stack.push(8);
	stack.push(9);
	stack.print();
	stack.pop();
	stack.print();
	stack.pop();
	stack.print();

	return 0;
}