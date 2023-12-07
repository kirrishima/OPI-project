#include "input_matrix.h"
#include "multiplication.h"
#include "iostream"
#include <vector>

void MultiplicationMatrix() {
    ConfigSettings settings = configureSettings(); // ��������� ������� ��������
    std::vector<std::vector<double>> myMatrix = inputMatrix(settings);
    int number;
    std::cout << "������� ����� ��� ���������: ";
    std::cin >> number;
   

    // �������� ������� �� �����
    multiplyMatrixByNumber(myMatrix, number);

    // ������� ���������
    for (const auto& row : myMatrix) {
        for (int element : row) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }
}
