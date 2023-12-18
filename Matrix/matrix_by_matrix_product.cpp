#include <iostream>
#include <vector>
#include "matrix_by_matrix_product.h"
using namespace std;

double MAT_PRODUCT(int row, int column, int size, const std::vector<std::vector<double>>& matrix_a, const std::vector<std::vector<double>>& matrix_b) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += matrix_a[row][i] * matrix_b[i][column];
    }
    return sum;
}

std::vector<std::vector<double>> multiplyMatrixByMatrix(const std::vector<std::vector<double>>& matrix_a, const std::vector<std::vector<double>>& matrix_b) {
    std::vector<std::vector<double>> multipliedMatrix;

    if (matrix_a[0].size() != matrix_b.size() ){
        cerr << "Ошибка: Некорректный формат размерности матрицы." << endl;
    }

    

    for (int i = 0; i < matrix_a.size(); i++) {
        std::vector<double> temprow;
        for (int j = 0; j < matrix_b[0].size(); j++) {
            temprow.push_back(MAT_PRODUCT(i, j, matrix_b.size(), matrix_a, matrix_b));
        }
        multipliedMatrix.push_back(temprow);
    }

    return multipliedMatrix;
}