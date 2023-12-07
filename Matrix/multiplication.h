#pragma once
#include <iostream>
#include <vector>

// ������� ��� ��������� ������� �� �����
void multiplyMatrixByNumber(std::vector<std::vector<double>>& myMatrix, int number) {
    for (auto& row : myMatrix) {
        for (auto& element : row) {
            element *= number;
        }
    }
}