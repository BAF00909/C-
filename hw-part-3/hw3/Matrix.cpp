#include <iostream>
#include <vector>
#include "Matrix.h"


Matrix::Matrix(std::vector<std::vector<int>>&  m) : matrix(m) {};

Matrix::~Matrix(){}

int Matrix::calculateDeterminant()
{
    int n = matrix.size();

    for (int col = 0; col < n; ++col) {

        bool found = false;
        for (int row = col; row < n; ++row) {
            if (matrix[row][col]) {
                if (row != col)
                {
                    matrix[row].swap(matrix[col]);
                }
                else
                found = true;
                break;
            }
        }

        if (!found) {
            std::cout << "Did not find a non-zero row. Column: " << col << "\n";
            return 0;
        }

        for (int row = col + 1; row < n; ++row) {
            while (true) {
                int del = matrix[row][col] / matrix[col][col];
                for (int j = col; j < n; ++j) {
                    matrix[row][j] -= del * matrix[col][j];
                }
                if (matrix[row][col] == 0)
                {
                    break;
                }
                else
                {
                    matrix[row].swap(matrix[col]);
                }
            }
        }
    }

    int res = 1;

    for (int i = 0; i < n; ++i) {
        res *= matrix[i][i];
    }
    return res;
}


