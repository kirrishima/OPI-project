#pragma once
#include <iostream>
#include <vector>

// Функция для умножения матрицы на число
void multiplyMatrixByNumber(std::vector<std::vector<double>>& myMatrix, int number) {
    for (auto& row : myMatrix) {
        for (auto& element : row) {
            element *= number;
        }
    }
}
