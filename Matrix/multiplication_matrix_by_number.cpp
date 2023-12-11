#include <iostream>
#include <vector>
#include "multiplication_matrix_by_number.h"

std::vector<std::vector<double>> multiplyMatrixByNumber(const std::vector<std::vector<double>>& matrixToBeMultiplied) {
    std::vector<std::vector<double>> multipliedMatrix(matrixToBeMultiplied);

    int number;
    std::cout << "¬ведите число, на которое нужно умножить матрицу: ";
    std::cin >> number;

    for (auto& row : multipliedMatrix) {
        for (auto& num : row) {
            num *= number;
        }
    }

    return multipliedMatrix;
}
