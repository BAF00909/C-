#pragma once

bool isPrime(int value)
{
    for (int i = 2; i < value; i++) {
        if (value % i == 0)
        {
            std::cout << value << " % " << i << "==" << value % i << std::endl;
            return false;
        }
        else 
        { 
            std::cout << value << " % " << i << "==" << value % i << " continue" << std::endl;
            continue;
        }
    }
    return true;
}

int getPrime(int input, int& saveResult)
{
    std::cout << "User input = " << input << std::endl;
    int result = 2;//���������
    int count = 1;//������� ����������� ����� � ������������������
    while (count < input) {
        result++;
        std::cout << "result = " << result << std::endl;
        if (isPrime(result)) count++; //�������� �������� �� ������� ���� �������
    }
    saveResult = result;
    return result;
}