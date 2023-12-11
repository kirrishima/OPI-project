#include "input_matrix.h"
#include "multiplication.h"
#include "iostream"
#include <vector>

void MultiplicationMatrix() {
    ConfigSettings settings = configureSettings(); // Получение текущих настроек
    std::vector<std::vector<double>> myMatrix = inputMatrix(settings);
    int number;
    std::cout << "Введите число для умножения: ";
    std::cin >> number;
   

    // Умножаем матрицу на число
    multiplyMatrixByNumber(myMatrix, number);

    // Выводим результат
    for (const auto& row : myMatrix) {
        for (int element : row) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }
}
