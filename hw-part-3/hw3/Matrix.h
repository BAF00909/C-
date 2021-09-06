#pragma once
#include <iostream>
#include <vector>

class Matrix {
private:
	std::vector< std::vector<int> >& matrix;

public:
	Matrix(std::vector< std::vector<int> >& m);
	~Matrix();

	int calculateDeterminant();
};
