#include "input_matrix.h"
#include "multiplication.h"
#include "iostream"
#include <vector>

void MultiplicationMatrix(std::vector<std::vector<double>>& matrix) {

    int number;
    std::cout << "Введите число для умножения: ";
    std::cin >> number;
    for (auto& row : matrix) {
        for (auto& element : row) {
            element *= number;
        }
    }

    // Умножаем матрицу на число
}

